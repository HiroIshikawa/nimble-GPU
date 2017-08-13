#ifndef DETECT_H_
#define DETECT_H_


#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

class Detect {
  public:
  	// std::tuple<vector<cv::Rect>, cv::Mat> MultiDetect(vector<string> cascadeList, cv::Mat img);
  	std::tuple<vector<cv::Rect>, cv::Mat> RunDetect(cv::Mat img, double scaleFactor, int minNeighs, int objW, int objH);
  	cv::Mat box(vector<cv::Rect> rects, cv::Mat img);
};

#endif  // DETECT_H_