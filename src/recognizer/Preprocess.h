#ifndef PREPROCESS_H_
#define PREPROCESS_H_

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

class Preprocess {
  public:
  	cv::Mat preprocess(cv::Mat img);
  	cv::Mat regionOfInterest(cv::Mat img, std::vector<cv::Point> vertices);
};

#endif  // PREPROCESS_H_