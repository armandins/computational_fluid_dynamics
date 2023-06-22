/* Arman Dindar Safa */ 
// 1-D Linear Convection
// du/dt + c*(du/dx) = 0 

#include <iostream>
#include "Mesh.h"
#include "extrafunctions.h"
using namespace std;

int main(int argc, char **argv)
{
	int N = 10;
	double totallength = 1.0;

	Mesh mesh_(N,totallength);
	print1dvec(mesh_.xpts);

	return 0;
}