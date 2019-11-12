#include "Element/Vehicle.h"
#include "Element/Boat.h"
#include "Element/Car.h"
#include "Element/Train.h"
#include "Visitor/Human.h"
#include "Visitor/Object.h"
#include "Visitor/Animal.h"
#include <array>

int main()
{
  // construct a animal (visitor) and boat (element)
  AbstractVehicle *vehicles[] = {
    new Boat("Santa-Maria", 1460),
    new Train("Amtrak", 1920),
    new Car("Toyota", 2018)
  };
  int vehicle_length = sizeof(vehicles)/sizeof(vehicles[0]);
  Human h("Samuel", 29);
  Object o("Toaster", 2009);
  Animal a("Dog", 2015);
  // demonstrate relationship
  for (int i = 0; i < vehicle_length; i++) {
    std::cout << "size: " << vehicle_length << " index: " << i << "\n";
    vehicles[i]->accept(h);
    vehicles[i]->accept(o);
    vehicles[i]->accept(a);
  }
  return 0;
}
