#pragma comment(lib, "libmpfr-4.lib")
#pragma comment(lib, "libgmp-10.lib")
#include "GVD_RVD.hpp"
#include<vector>
#include <iostream>
using namespace std;
using namespace GVD;

void GvdExample() {
	Model3D::CRichModel model("bunny.obj");
	model.LoadModel();
	model.PrintInfo(std::cerr);

	set<int>sources;

	int ApproSitesNum = 500;
	for (int i = 0; i < model.GetNumOfVerts(); ++i) {
		if (i % (model.GetNumOfVerts() / ApproSitesNum) == 0) {
			sources.insert(i);
		}
	}

	double t = GetTickCount64();
	auto res2 = GetGVD_Bisectors(model, sources);
	t = GetTickCount64() - t;
	cerr << "GVD total time: " << t / 1000.0 << "  seconds..." << endl;
	WriteLineObjFile(res2, "gvd_rersult.obj");
}

void EDBVDExample() {
	Model3D::CRichModel model("bunny.obj");

	model.LoadModel();
	model.PrintInfo(std::cerr);

	vector<tuple<double, double, double, int>> sources;

	// source points are the first vertex of every (# faces / 1000) face
	// - also storing the face id as the (source id?)
	int ApproSitesNum = 1000;
	for (int fid = 0; fid < model.GetNumOfFaces(); ++fid) {
		if(fid%(model.GetNumOfFaces()/ ApproSitesNum)==0)
			sources.push_back(make_tuple(model.Vert(model.Face(fid)[0]).x, model.Vert(model.Face(fid)[0]).y, model.Vert(model.Face(fid)[0]).z, fid));
	}

	double t = GetTickCount64();

	// Bisectors = vector of  3D positions pairs (ie lines)
	auto res2 = GetLRVD_Bisectors(model, sources);
	
	t = GetTickCount64() - t;
	cerr << "EDBVD total time: " << t / 1000.0 << "  seconds..." << endl;
	WriteLineObjFile(res2.first, "EDBVD_rersult.obj");

}

int main() {
	std::cout << "Hello World! 3" << std::endl;

	// Geodesic Voronoi Diagram
	//GvdExample();

	// Euclidean Distance based Voronoi Diagram
	EDBVDExample();

	return 0;
}
