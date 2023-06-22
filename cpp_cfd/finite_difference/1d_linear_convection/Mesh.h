using std::vector;

class Mesh
{
public:
	Mesh();
	// Over-loaded constructor
	Mesh(int&, double&);

	virtual ~Mesh();

	int NumberofNodes;
	double lengthx;
	double dx1d;
	vector<double> xpts;

	void discretized1dgrid(vector<double>&);
};

#endif // MESH_H