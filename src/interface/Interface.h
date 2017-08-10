#ifndef INTERFACE_H_
#define INTERFACE_H_

class Interface
{
  private:
    short int var;
    int distance;
  public:
  	void writeNumber(int value);
  	int readNumber();
    void track(int avgPos);
    void monitor(int avgPos);
}

#endif