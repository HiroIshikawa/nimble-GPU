#include "Measure.h"
#include <opencv2/opencv.hpp>


std::pair<int, int> Measure::CenteringImg(cv::Mat img) {
	std::pair<int, int> center (img.cols()/2, img.rows()/2);
	return center;
}


std::pair<int, int> Measure::SizingBox(cv::Rect rect) {
	std::pair<int, int> boxSize (rect.width, rect.height);
	return boxSize;
}


std::pair<int, int> Measure::CenteringBox(cv::Rect rect) {
	std::pair<int, int> boxCenter (std::abs(rect.width)/2 + rect.tl().x, std::abs(rect.height)/2 + rect.br().y);
	return boxCenter;	
}


std::pair<int, int> Measure::PosFromCenter(std::pair<int, int> imgCenter, std::pair<int, int> boxCenter) {
	std::pair<int, int> boxRelPos ((boxCenter.first-imgCenter.first),(boxCenter.first-imgCenter.first));
	return boxRelPos;
}


void Measure::RunMeasure(cv::Mat img, std::vector<cv::Rect> rects, &std::vector<std::pair<int, int>> candidates) {
	std::pair<int, int> imgCenter;
	imgCenter = CenteringImg(img);
	int nBoxes = rects.size();
	std::vector<std::map<std::string, std::pair<int, int>>> boxes;
	for (int i = 0; i < nBoxes; ++i) {
		boxes.push_back(
			std::map<std::string, std::pair<int,int>> {
				{
					{"boxSize", std::pair<int,int>(0,0)},
					{"boxCenter", std::pair<int,int>(0,0)},
					{"boxToCenter", std::pair<int,int>(0,0)}
				}
			}
		)
	}
	for (int i = 0; i < nBoxes; ++i) {
		boxes[i]["boxSize"] = SizingBox(rects[i]);
		boxes[i]["boxCenter"] = CenteringImg(rects[i]);
		boxes[i]["boxToCenter"] = PosFromCenter(imgCenter, boxes[i]["boxCenter"]);
	}
	if (boxes.size() > 0) {
		std::map<std::string, std::pair<int, int>> maxItem;
		int maxSize = 0;
		int curSize = 0;
		for (int i = 0; i < nBoxes; ++i) {
			curSize = boxes[i]["boxSize"].first * boxes[i]["boxSize"].second;
			if (maxSize < curSize) {
				maxSize = curSize;
				maxSizeItem = boxes[i];
			}
		}
		candidates.push_back(maxSizeItem["boxToCenter"].first);
	}
}