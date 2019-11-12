#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include <iostream>

class Component {
  public:
    enum class Status
    {
      INIT,
      OK,
      WARN,
      ERROR
    };
    // Constructor/ Destructor
    Component(std::string component_name, int component_id)
    {
      name = component_name;
      id   = component_id;
      reset();
    };
    virtual ~Component(){};
    // abstract methods
    virtual Component  *getChild(int) { return 0; };
    virtual void add( Component * ) { /* ... */ };
    virtual void remove( int ) { /* ... */ };
    // extendable methods
    virtual void operation() { ++noperation; };
    virtual void printInfo();
    virtual void clean(){};
    // base-class methods
    void reset();
    void setState(Status state_in) {state = state_in;};
    Status getState() { return state; };
    std::string getName() { return name; };
    int getOperationCount() { return noperation; };
    int getID() { return id; };
  private:
    int noperation;
    std::string name;
    int id;
    Status state;
};
// Basic Implementations
void Component::reset() { noperation = 0; state = Status::INIT;};
void Component::printInfo()
{
  std::cout << name << " - " << id << " ";
}
#endif // COMPONENT_H
