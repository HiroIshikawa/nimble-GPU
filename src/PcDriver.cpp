#include "recognizer/Detect.h"
#include "recognizer/Measure.h"
#include "recognizer/Preprocess.h"
#include "interface/Interface.h"

#include <thread>

#include "video/Video.h"


void command(int avgPos) {
	if (avgPos > 10) {
		std::cout << "Turn right: Rotate " << avgPos << " units" << std::endl;
	}
	else if (avgPos < -10) {
		std::cout << "Turn left: Rotate " << avgPos << " units" << std::endl;
	}
	else {
		std::cout << "Go Straight" << std::endl;
	}
}


float mean(vector<int> l) {
	if (l.size() == 0) {
		return 0.0;
	}
	return 1.0 * std::accumulate(l.begin(), l.end(), 0LL) / l.size();
}
