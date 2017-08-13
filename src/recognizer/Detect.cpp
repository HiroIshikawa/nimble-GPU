#include "Detect.h"
#include <opencv2/opencv.hpp>


// std::tuple<vector<cv::Rect>, cv::Mat> Detect::MultiDetect(vector<string> cascadeList, cv::Mat img) {
// }


std::tuple<vector<cv::Rect>, cv::Mat> Detect::RunDetect(cv::Mat img, double scaleFactor, int minNeighs, int objW, int objH) {
	cv::CascadeClassifier cascade = cv::CascadeClassifier("model/cascade.xml");
	cascade.detectMultiScale(img, rects, scaleFactor, minNeighs, 0|cv::CV_HAAR_SCALE_IMAGE, cv::Size(objW, objH));
	std::tuple<vector<cv::Rect>, cv::Mat> result(,img);
	if (rects.size == 0) {
		return result;
	}
	result.first = rects;
	result.second = img;
	return result;
}


cv::Mat Detect::Box(vector<cv::Rect> rects, cv::Mat img) {
	for (int i = 0; i < rects.size(); ++i) {
		cv::rectangle(img, rects[i].tl(), rects[i].br(), (127, 255, 0), 2);
	}
	return img;
}