/*
	Solution to 1D non-viscous Burgers' equation.
	Computed using Lax-Wendroff Scheme.
	https://en.wikipedia.org/wiki/Lax%E2%80%93Wendroff_method
	Author:     Arman Dindar Safa
	Date:       12 / 30 / 2023
	Version:    1.00
    Source:     Computational Fluid Dynamics: Principles and Applications, J. Blazek
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;


// ------------------
// 	Constants
// ------------------
const int8_t SP {8};        // Single - precision | 8 Decimal Numbers
const int8_t DP {17};       // Double - precision | 17 Decimal Numbers


//	-----------------------------------------------------------------------------------------------------
//		Function Control
//	-----------------------------------------------------------------------------------------------------

void initialCond    (double xa, double xb, vector<double>& x, vector<double>& u_init, int nx);
void BurgFD1D       (vector<double> u0, double endtime, double dt, vector<double> x, vector<double>& u, int nx);
void TECPLOTwriter(string filename, double endtime, int nx, vector<double>& x, vector<double>& u_init, vector<double>& u);

//  -----------------------------------------------------------------------------------------------------
//      MAIN PROGRAM
//  -----------------------------------------------------------------------------------------------------

int main(){
    // * Params. 
    int64_t nx          {81};
    double xa           {0.0}; 
    double xb           {1.0};
    double endtime      {0.5};
    double dt           {1.0e-2};

    vector<double> x(nx); 
    vector<double> u0(nx); 
    vector<double> u(nx);

    string TECPLOTDATA {"data"};

    x.assign    (nx, 0.0);
    u0.assign   (nx, 0.0);
    u.assign    (nx, 0.0);

    initialCond    (xa, xb, x, u0, nx);
    BurgFD1D       (u0, endtime, dt, x, u, nx);
    TECPLOTwriter  (TECPLOTDATA, endtime, nx, x, u0, u);

    cout << "X\t\tInitialU\t\tLaxWendroffU" << '\n';
    
    for (unsigned int i = 0; i < nx; i++)   cout << x[i] << "\t\t" << u0[i] << "\t\t" << u[i] << '\n';

    return 0.0;

}

//	-----------------------------------------------------------------------------------------------------
//		Initial Conditions Handler
//	-----------------------------------------------------------------------------------------------------

void initialCond(double xa, double xb, vector<double>& x, vector<double>& u_init, int nx) {
    double dx;
    dx = (xb - xa) / static_cast<double>(nx - 1);
    x[0] = xa;
    for (int i = 1; i < nx; i++)    x[i] = x[0] + (i * dx);
    for (int i = 0; i < nx; i++){
        if (x[i] <= 0.5)        u_init[i] = 1.0;
        else                    u_init[i] = 0.0;
     
    }
}

//	-----------------------------------------------------------------------------------------------------
//		Finite Difference Lax Scheme for Burgers Equation
//	-----------------------------------------------------------------------------------------------------

void BurgFD1D(vector<double> u0, double endtime, double dt, vector<double> x, vector<double>& u, int nx){
    vector<double>  uo(nx);
    u =             u0;
    uo =            u0;
    double          dx, 
                    time, 
                    m1, 
                    m2;
    dx =            x[1] - x[0];
    m1 =            0.5 * dt / dx;

    cout << "dt/dx: " << dt / dx << endl;
    m2 =            0.5 * (dt / dx) * (dt / dx);
    time =          0.0;
    while (time <= endtime) {
        for (int i = 1; i < nx - 1; i++) {
            u[i] = uo[i] - m1 * (0.5 * uo[i + 1] * uo[i + 1] - 0.5 * uo[i - 1] * uo[i - 1]) +
                   m2 * (0.5 * (uo[i] + uo[i + 1]) * (0.5 * u[i + 1] * u[i + 1] - 0.5 * u[i] * u[i]) -
                         0.5 * (u[i] + u[i - 1]) * (0.5 * u[i] * u[i] - 0.5 * u[i - 1] * u[i - 1]));
        }
        u[0] =      uo[0];
        u[nx - 1] = uo[nx - 1];
        uo =        u;
        time =      time + dt;
    }
}

//  -----------------------------------------------------------------------------------------------------
//      TECPLOT Data Writer
//  -----------------------------------------------------------------------------------------------------

void TECPLOTwriter(string filename, double endtime, int nx, vector<double>& x, vector<double>& u_init, vector<double>& u){
    // Create a file for storing the data
    ofstream        file(filename + ".dat");                        // Format : "filename.dat"
    file <<         setprecision(DP);                               // Precision set to double - precision
    file <<         "VARIABLES=x,u_init,u\n";                       // TECPLOT data header
    file <<         "ZONE T=\"Data\", I=" << nx << ", F=POINT\n";   // ZONES
    for (int i = 0; i < nx; i++)    file << x[i] << " " << u_init[i] << " " << u[i] << "\n";
    file <<         "DT=1.0e-2\n";
    file <<         "TIME=0.0," << endtime << "\n";
}