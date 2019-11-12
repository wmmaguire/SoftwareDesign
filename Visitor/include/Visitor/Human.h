#ifndef HUMAN_H
#define HUMAN_H
#include <string>
#include <iostream>
#include "Package.h"
#include "Element/Boat.h"
#include "Element/Train.h"
#include "Element/Car.h"

/* Human:  Derived class package (element)
 * Description: an element that requires a mode of transportation to reach its destination
 */
class Human : public AbstractPackage {
  public:
    // inherit base construtor
    Human(std::string pkg_name, int pkg_id) : AbstractPackage(pkg_name, pkg_id) {}

    void visit(Boat *vehicle){
      std::cout << "I'm a Human. My name is " + getName() + ", how do you do? ->" + vehicle->boatOperation() << "\n";
    };

    void visit(Car *vehicle){
      std::cout << "I'm a Human. My name is " + getName() + ", how do you do? ->" + vehicle->carOperation() << "\n";
    };

    void visit(Train *vehicle){
      std::cout << "I'm a Human. My name is " + getName() + ", how do you do? ->" + vehicle->trainOperation() << "\n";
    };
};
#endif // HUMAN_H
