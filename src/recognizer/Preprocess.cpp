#include "Preprocess.h"
#include <opencv2/opencv.hpp>


cv::Mat Preprocess::regionOfInterest(cv::Mat img, std::vector<cv::Point> vertices) {
	return img;
}

cv::Mat Preprocess::preprocess(cv::Mat img) {
	int width = img.cols;
	int height = img.rows;
	std::vector<cv::Point> vertices;
	vertices.push_back(cv::Point(0, height));
	vertices.push_back(cv::Point(0, height/2));
	vertices.push_back(cv::Point(width, height));
	vertices.push_back(cv::Point(width, height/2));
	return regionOfInterest(img, vertices);
}

int main() {
	return 0;
}