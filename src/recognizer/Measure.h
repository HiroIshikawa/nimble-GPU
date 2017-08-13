#ifndef MEASURE_H_
#define MEASURE_H_

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdlib>
#include "Measure.h"

class Measure {
	public:
		std::pair<int, int> CenteringImg(cv::Mat img);
		std::pair<int, int> SizingBox(cv::Rect rect);
		std::pair<int, int> CenteringBox(cv::Rect rect);
		std::pair<int, int> PosFromCenter(std::pair<int, int> imgCenter, std::pair<int, int> boxCenter);
		void RunMeasure(cv::Mat img, std::vector<cv::Rect> rects, &std::vector<std::pair<int, int>> candidates);
};

#endif  // MEASURE_H_