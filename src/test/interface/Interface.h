#ifndef INTERFACE_H_
#define INTERFACE_H_

class Interface
{
  private:
    short int var;
    int distance;

  public:
  	Interface();
  	~Interface();
  	void writeNumber(int value);
  	int readNumber(void);
    void track(int avgPos);
    void monitor(int avgPos);
};

#endif  // INTERFACE_H_