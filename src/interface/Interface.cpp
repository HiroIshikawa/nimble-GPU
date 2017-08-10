#include <ctime>
#include <unistd.h>
#include "Interface.h"


int Interface::readNumber()
{
	return -1; // arbitrary number for test
}


int Interface::writeNumber(int number)
{
	std::cout << "Sending command No. " << number << endl;
}


void Interface::track(int avgPos)
{
  if (avgPos > 300)
  {
    std::cout << "Detected at +" << avgPos << " units, Rotate Right." << endl;
    var = 4;
    this->writeNumber()
  }
  else if (avgPos < -300)
  {
  	std::cout << "Detected at " << avgPos << " units, Rotate Left." << endl;
  	var = 3;
  	// write number
  }
  else if (avgPos > 40)
  {
  	std::cout << "Detected at +" << avgPos << " units, Tilt Right." << endl;
  	var = 7;
  	// write number
  }
  else if (avgPos < -40)
  {
    std::cout << "Detected at " << avgPos << " units, Tilt Left." << endl;
    var = 6;
  	// write number
  }
  else
  {
    std::cout << "Detected at " << avgPos << " units, Go Straight." << endl;
    var = 1;
  	// write number
  }
}


void Interface::monitor(int avgPos)
{
	time_t startTime;
	time_t currentTime;
	short int isComplete;

	if (avgPos < 150 || avgPos > -150)
	{
		distance = readNumber();
	}
	else
	{
		distance = -1;
	}
	if (distance > 0 && distance < 29 && distance != 1 && disance != 25)
	{
		startTime = std::time(0);
		writeNumber(8)
		while 1
		{

			if (std::time(0)-startTime > 1.)
			{
				isComplete = readNumber();
				std::cout << "Complete?: " << isComplete << endl;
				if (isComplete == 1)
				{
					std::cout << "Received Complete Signal from Kinematics Control Unit" << endl;
					writeNumber(0);
					usleep(5 * 1000);
				  break
				}
				startTime = std::time(0);
			}
		}
	}
}