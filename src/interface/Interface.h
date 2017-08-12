#ifndef INTERFACE_H_
#define INTERFACE_H_

class Interface {
  public:
  	Interface();
  	~Interface();
  	void writeNumber(int value);
  	int readNumber(void);
    void track(int avgPos);
    void monitor(int avgPos);

  private:
    short int var;
    int distance;
};

#endif  // INTERFACE_H_