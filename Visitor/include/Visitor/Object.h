#ifndef OBJECT_H
#define OBJECT_H
#include <string>
#include <iostream>
#include "Package.h"
#include "Element/Boat.h"
#include "Element/Car.h"
#include "Element/Train.h"

/* Object:  Derived class package (element)
 * Description: an element that requires a mode of transportation to reach its destination
 */
class Object : public AbstractPackage {
  public:
    // inherit base construtor
    Object(std::string pkg_name, int pkg_id) : AbstractPackage(pkg_name, pkg_id) {}

    void visit(Boat *vehicle){
      std::cout << "I'm an Object: " + getInfo() + "->" + vehicle->boatOperation() << "\n";
    };
    void visit(Car *vehicle){
      std::cout << "I'm an Object: " + getInfo() + "->" + vehicle->carOperation() << "\n";
    };

    void visit(Train *vehicle){
      std::cout << "I'm a Object: " + getInfo() + "->" + vehicle->trainOperation() << "\n";
    };
};
#endif // OBJECT_H
