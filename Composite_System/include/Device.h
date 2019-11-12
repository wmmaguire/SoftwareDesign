#ifndef DEVICE_H
#define DEVICE_H
#include "Component.h"
#include <string>
#include <iostream>

class Device : public Component {
  public:
    static const double Ck;
    // Constructor / Destructor
    Device(std::string component_name, int component_id, int limit = 10);
    ~Device(){};
    // define composite operation
    void operation();
    // overload base-class methods
    void printInfo();
    void reset();
  private:
    std::string msg;
    int capacity;
    double critical_level;
};
const double Device::Ck = 0.8;
#endif // DEVICE_H
