#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <iostream>
//#include "Package.h"

class AbstractPackage;
/* AbstractVehicle (Element)
 * Description:
 *  Accept packages (visitors)
 */

class AbstractVehicle {
  public:
    // Constructor
    AbstractVehicle(std::string vehicle_model, int vehicle_year)
    {
      model  = vehicle_model;
      year   = vehicle_year;
    };
    // abstract methods
    virtual ~AbstractVehicle(){}; // virtual destructor for polymorphic delete
    virtual void accept(class AbstractPackage  &p) = 0;
    // base-class methods
    void printInfo() { std::cout << model << " - " << year << " "; };
    std::string getModel() { return model; };
    int getYear() { return year; };
  private:
    std::string model;
    int year;
};
#endif // VEHICLE_H
