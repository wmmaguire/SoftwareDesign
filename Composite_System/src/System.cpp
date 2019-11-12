#include "../include/System.h"
#include <iostream>
#include <string>
#include <vector>

System::~System()
{
  //Component::~Component(); 
  for ( unsigned int i = 0; i < children.size(); i++ )
  {
    delete children[ i ];
  }
}
// add component to system
void System::add(Component *component) {
  children.push_back(component);
}
// remove system sub-component
void System::remove(const unsigned int i)  
{ 
  Component *child = children[ i ]; 
  std::cout << " ** Removing: " << child->getName() << " " << child->getID() << std::endl;
  children.erase( children.begin() + i );
  delete child;
}
// perform system operation
void System::operation()
{
  std::cout << "# Executing aggregate operation of System : " << Component::getName()  << std::endl;
  for (unsigned int i = 0; i < children.size(); i++ ){
    children[i]->operation();
  }
}
// clean bad components from system
void System::clean() {
  for (unsigned int i = 0; i < children.size(); i++ ) {
    children[i]->clean();
    if ( children[i]->getState() == Component::Status::ERROR ) 
    {
      remove(i);
      i--;
    }
  }
}
// expanded printout statement
void System::printInfo()
{
  Component::printInfo();
  std::cout << " ( " << children.size() << " components)" << std::endl;
  for (unsigned int i = 0; i < children.size() ; i++ )
  {
    children[i]->printInfo();
    std::cout << " " << std::endl;
  }
}
