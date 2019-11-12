#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <iostream>
#include "Package.h"
#include "Element/Boat.h"
#include "Element/Train.h"
#include "Element/Car.h"

/* Human:  Derived class package (element)
 * Description: an element that requires a mode of transportation to reach its destination
 */
class Animal : public AbstractPackage {
  public:
    // inherit base construtor
    Animal(std::string pkg_name, int pkg_id) : AbstractPackage(pkg_name, pkg_id) {}

    void visit(Boat *vehicle){
      std::cout << "I'm an Animal: " + getInfo() + "->" + vehicle->boatOperation() << "\n";
    };

    void visit(Car *vehicle){
      std::cout << "I'm a Animal: " + getInfo() + "->"  + vehicle->carOperation() << "\n";
    };

    void visit(Train *vehicle){
      std::cout << "I'm a Animal: " + getInfo() + "->" + vehicle->trainOperation() << "\n";
    };
};
#endif // ANIMAL_H
