#include <thread>
#include "Video.h"


Video::Video(int src, int winW, int winH) {
	this.stream(src);
	this.stream.set(3, winW);
	this.stream.set(4, winH);
	std::tuple<cv::Mat, cv::Mat> reading;
	reading = this.stream.read();
	this.grabbed = reading[0];
	this.frame = reading[1];
	this.stopped = false;
}


void start() {
	std::thread(this.update, args()).start();
	return this;
}


void update() {
	while (true) {
		if (this.stopped)
			return;
		std::tuple<cv::Mat, cv::Mat> reading;
		reading = this.stream.read();
		this.grabbed = reading[0];
		this.frame = reading[1];
	}
}


void read() {
	return this.frame;
}


void stop() {
	this.stopped = true;
}