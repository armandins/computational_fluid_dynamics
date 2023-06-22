#include "Mesh.h"

Mesh::Mesh()
{

}

Mesh::Mesh(int& n, double& txlength)
:
NumberofNodes(n),
lengthx(txlength),
xpts(NumberofNodes, 0.0)
{
	dx1d = lengthx / (n - 1);
	descrtized1dgrid(xpts);
}
Mesh::~Mesh()
{

}

void Mesh::descrtized1dgrid(vector<double>& vec)
{
	for(int i = 1; i < vec.size(); i++)
	{
		vec[i] = vec[i-1] + dx1d;
	}
}
