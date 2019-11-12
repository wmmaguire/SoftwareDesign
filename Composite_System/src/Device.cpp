#include "../include/Device.h"
#include <iostream>
#include <string>

Device::Device(std::string component_name, int component_id, int limit)
  : Component(component_name, component_id), capacity(10)
{
  capacity = limit;
  critical_level = limit * Ck;
}

// perform system operation
void Device::operation()
{ 
  std::cout << "- Executing Device : (" << Component::getName() <<
    " " << Component::getID() << ") " << std::endl;
  Component::operation();
  // evaluate state of component
  int noperation = Component::getOperationCount();
  if (noperation > critical_level) {
    Component::setState(Component::Status::WARN);
      msg = "Approaching limit in " + std::to_string(capacity - noperation);
    if (noperation >= capacity ) {
      Component::setState(Component::Status::ERROR);
      msg = "EXCEEDED LIMIT BY " + std::to_string(noperation - capacity);
    }
  }
}

// overload base-class methods
void Device::reset() {Component::reset(); msg = "";}
void Device::printInfo()
{
  Component::printInfo(); 
  std::cout << Component::getOperationCount() << " operations " << std::endl;
  // print additional information about device state if critical 
  Component::Status state = Component::getState();
  if( state > Component::Status::OK ) 
  {
    if ( state == Component::Status::WARN ) std::cout << " [WARN] - " << msg << std::endl;
    else if (state == Component::Status::ERROR ) std::cout << " [ERROR] - " << msg << std::endl;
  }
}
