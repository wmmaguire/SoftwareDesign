#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>
#include <iostream>
//#include "Boat.h"
class Boat;
class Car;
class Train;
/* AbstractPackage (visitor)
 * Description:
 *  visit desintation via transportation modes (elements)
 */
class AbstractPackage {
  public:
    // Constructor
    AbstractPackage(std::string pkg_name, int pkg_id)
    {
      name = pkg_name;
      id   = pkg_id;
    };
    // abstract methods
    virtual ~AbstractPackage(){}; // virtual destructor for polymorphic delete
    virtual void visit(Boat  *vehicle) = 0;
    virtual void visit(Car  *vehicle) = 0;
    virtual void visit(Train  *vehicle) = 0;
    // base-class methods
    std::string getInfo() { return getName() + " - " + std::to_string(getID()) + "\n";};
    std::string getName() { return name; };
    int getID() { return id; };
  private:
    std::string name;
    int id;
};
#endif // PACKAGE_H
