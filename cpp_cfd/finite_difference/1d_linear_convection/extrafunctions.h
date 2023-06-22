#include <iostream>
#include <vector>
using namespace std;

void print1dvec(vector<double>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << ' ';
	}
}