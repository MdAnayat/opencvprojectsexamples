#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
	//String imageName("..C:/Users/Anayat/Documents/Visual Studio 2019/Backup Files/ConsoleApplication2/data/HappyFish.jpg"); // by default
	/*if (argc > 1)
	{
		imageName = argv[1];
	}*/
	Mat image;
	image = imread("C:/output/HappyFish.jpg", IMREAD_COLOR); // Read the file
	if (image.empty())                      // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	//image = Scalar(0);
	Mat grey;
	cvtColor(image, grey, COLOR_BGR2GRAY);
	Mat sobelx;
	Sobel(grey, sobelx, CV_32F, 1, 0);
	double minVal, maxVal;
	minMaxLoc(sobelx, &minVal, &maxVal); //find minimum and maximum intensities
	Mat draw;
	sobelx.convertTo(draw, CV_8U, 255.0 / (maxVal - minVal), -minVal * 255.0 / (maxVal - minVal));
	namedWindow("image", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("image", draw);  // Show our image inside it.
	//namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	//imshow("Display window", image);  // Show our image inside it.
	/*Vec3f intensity = image.at<Vec3f>(194, 259);
	float blue = intensity.val[0];
	float green = intensity.val[1];
	float red = intensity.val[2];*/
	waitKey();
	return 0;
}