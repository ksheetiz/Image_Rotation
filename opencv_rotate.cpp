// opencv_rotate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include<opencv2\opencv.hpp>
#include<vector>

using namespace cv;
using namespace std;
int main()
{
	Mat image = imread("C:/Users/91941/Pictures/cartoon.jpg");
	
	if (image.empty()) {
		cout << "Could not open or find the image" << endl;
		cin.get();//wait for any key press
		return -1;
	}

	String windowName = "Original Photo";

	namedWindow(windowName, WINDOW_NORMAL);

	resizeWindow(windowName, 400, 600);

	imshow(windowName, image);

	double angle = 90;

	Point2f center((image.cols - 1) / 2.0, (image.rows - 1) / 2.0);

	Mat rot = getRotationMatrix2D(center, angle, 1.0);

	Rect2f bbox = RotatedRect(Point2f(), image.size(), angle).boundingRect2f();

	rot.at<double>(0, 2) += bbox.width / 2.0 - image.cols / 2.0;
	rot.at<double>(1, 2) += bbox.height / 2.0 - image.rows / 2.0;

	Mat dst;

	warpAffine(image, dst, rot, bbox.size());
	imwrite("rotated.jpg", dst);
	
	String windowName1 = "Rotated Photo";

	namedWindow(windowName1, WINDOW_NORMAL);

	resizeWindow(windowName1, 600, 400);

	imshow(windowName1, dst);

	waitKey(0);

	destroyWindow(windowName);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
