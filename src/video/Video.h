#ifndef VIDEO_H_
#define VIDEO_H_


class Video {
  private:
  	cv::VideoCapture stream;
  	cv::Mat grabbed;
  	cv::Mat frame;
  	bool stopped;
  
  public:
  	Video(int src, int winW, int winH);
  	void start();
  	void update();
  	void read();
  	void stop();
};

#endif  // VIDEO_H_