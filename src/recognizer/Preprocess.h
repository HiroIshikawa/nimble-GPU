#ifndef PREPROCESS_H_
#define PREPROCESS_H_

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

class Preprocess {
  public:
  	cv::Mat Preprocess(cv::Mat img);
  	cv::Mat RegionOfInterest(cv::Mat img, int width, int height, std::vector<cv::Point> vertices);
};

#endif  // PREPROCESS_H_