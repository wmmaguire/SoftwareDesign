#ifndef TRAIN_H
#define TRAIN_H
#include <string>
#include <iostream>
#include "Visitor/Package.h"
#include "Vehicle.h"

/* Boat:  Derived vehicle class (visitor)
 * Description: A mode of transportation that transports a package to its destination
 */
class Train : public AbstractVehicle {
  public:
    // inherit base class constructor
    Train(std::string vehicle_model, int vehicle_year):AbstractVehicle(vehicle_model, vehicle_year){}
    // accept visitor (double dispatch)
    void accept(AbstractPackage &p) {p.visit(this);};
    // unique boat operation
    std::string trainOperation() {
      return "All Aboart! choo choo..";
    };
};
#endif // TRAIN_H
