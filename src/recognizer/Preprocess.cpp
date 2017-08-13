#include "Preprocess.h"
#include <opencv2/opencv.hpp>


cv::Mat Preprocess::RegionOfInterest(cv::Mat img, int width, int height, std::vector<cv::Point> vertices) {
	cv::Mat mask = cv::Mat(height,width, CV_64F, 0);

	//if 
	if (img.depth() > 0) {
		int channelCount = img.depth();
		cv::Scalar ignoreMaskColor = cv::Scalar(0,0,255*channelCount);
	}
	else {
		cv::Scalar ignoreMaskColor = cv::Scalar(0,0,255);
	}

	cv::fillPoly(mask, vertices, ignoreMaskColor);

	cv::Mat maskedImage = cv::bitwise_and(img, mask);
	return maskedImage;
}

cv::Mat Preprocess::Preprocess(cv::Mat img) {
	int width = img.cols;
	int height = img.rows;
	std::vector<cv::Point> vertices;
	vertices.push_back(cv::Point(0, height));
	vertices.push_back(cv::Point(0, height/2));
	vertices.push_back(cv::Point(width, height));
	vertices.push_back(cv::Point(width, height/2));
	return RegionOfInterest(img, width, height, vertices);
}

int main() {
	return 0;
}