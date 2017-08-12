#ifndef PREPROCESS_H_
#define PREPROCESS_H_

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

class Preprocess {
  public:
  	void preprocess(cv::Mat img);
};

#endif  // PREPROCESS_H_