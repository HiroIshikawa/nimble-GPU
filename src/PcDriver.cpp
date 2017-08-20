#include "recognizer/Detect.h"
#include "recognizer/Measure.h"
#include "recognizer/Preprocess.h"
#include "interface/Interface.h"

#include <ctime>
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


void nabigate(vector<float> candidates) {

}


int main(int argc, char *argv[]) {
	bool trackFlag = false;
	bool monitorFlag = false;
	float avgPos = 0.;
	vector<float> candidates;

	time_t startTime = time(0);

	Video vs();
	Detect de();
	Measure mes();
	Interface inter();
	try {
		while (true) {
			
			cv::Mat img = vs.read();
			double scaleFactor = argv[1];
			int minNeighs = argv[2];
			int objW = img.col();
			int objH = img.row();
 
			std::tuple<vector<cv::Rect>, cv::Mat> detected = de.RunDetect(img, scaleFactor, minNeighs, objW, objH);
			vector<cv::Rect> rects = std::get<0>(detected);
			cv::Mat = std::get<1>(detected);
			de.Box(rects, img);
			cv::imshow();

			mes.runMeasure(img, rects, candidates);

			if (time(0) - startTime > .5) {
				if (candidates.size() > 0) {
					avgPos = mean(candidates);
					trackFlag = true;
					candidates.clear();
					startTime = time(0);
				}
				else {
					;
				}
			}

			if (trackFlag) {
				std::cout << "Tracking activated" << std::endl;
				inter.Track(avgPos);
				monitorStartTime = time(0);
				trackFlag = false;
			}

			if (time(0)-monitorStartTime < 5.) {
				inter.Track(avgPos);
			}

			if (cv::waitKey(19) == 27) {
				std::cout << "Stopping.." << std::endl;
				vs.stop();
				cv::destroyAllWindow();
				break;
			}
		}
	}
	except (KeyboardInterrupt) {
		vs.stop();
		cv::destroyAllWindow();
	}
}