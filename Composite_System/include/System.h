#ifndef SYSTEM_H
#define SYSTEM_H
#include "Component.h"
#include <string>
#include <iostream>
#include <vector>

class System : public Component {
  public:
    // Constructor / Destructor
    System(std::string component_name, int component_id) : Component(component_name, component_id){};
    ~System();
    // Method definitions
    // add to children components
    void add(Component *component);
    // safely remove indexed component from composite
    void remove(const unsigned int i);
    // define composite operation
    void operation();
    // remove bad devices
    void clean();
    // extended printout statement
    void printInfo();
  private:
    std::vector<Component*> children;
};
#endif // COMPONENT_H
