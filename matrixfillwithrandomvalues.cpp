#include <opencv2/core/core.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat R = Mat(3, 2, CV_8UC3);
	randu(R, Scalar::all(0), Scalar::all(255));
	cout << "R = " << endl << " " << R << endl << endl;
	return 0;
}