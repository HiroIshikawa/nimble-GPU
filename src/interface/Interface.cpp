#include "Interface.h"
#include <ctime>
#include <iostream>
#include <unistd.h>


Interface::Interface() {
}


Interface::~Interface() {
}


int Interface::readNumber(void) {
	return -1; // arbitrary number for test
}


void Interface::writeNumber(int number) {
	std::cout << "Sending command No. " << number << std::endl;
}


void Interface::track(int avgPos) {
  if (avgPos > 300) {
    std::cout << "Detected at +" << avgPos << " units, Rotate Right." << std::endl;
    var = 4;
    writeNumber(var);
  }
  else if (avgPos < -300) {
  	std::cout << "Detected at " << avgPos << " units, Rotate Left." << std::endl;
  	var = 3;
  	writeNumber(var);
  }
  else if (avgPos > 40) {
  	std::cout << "Detected at +" << avgPos << " units, Tilt Right." << std::endl;
  	var = 7;
  	writeNumber(var);
  }
  else if (avgPos < -40) {
    std::cout << "Detected at " << avgPos << " units, Tilt Left." << std::endl;
    var = 6;
  	writeNumber(var);
  }
  else {
    std::cout << "Detected at " << avgPos << " units, Go Straight." << std::endl;
    var = 1;
  	writeNumber(var);
  }
}


void Interface::monitor(int avgPos) {
	time_t startTime;
	time_t currentTime;
	short int isComplete;

	if (avgPos < 150 || avgPos > -150) {
		distance = readNumber();
	}
	else {
		distance = -1;
	}
	if (distance > 0 && distance < 29 && distance != 1 && distance != 25) {
		startTime = std::time(0);
		writeNumber(8);
		while (1) {
			if (std::time(0)-startTime > 1.) {
				isComplete = readNumber();
				std::cout << "Complete?: " << isComplete << std::endl;
				if (isComplete == 1) {
					std::cout << "Received Complete Signal from Kinematics Control Unit" << std::endl;
					writeNumber(0);
					usleep(5 * 1000);
				  break;
				}
				startTime = std::time(0);
			}
		}
	}
}
