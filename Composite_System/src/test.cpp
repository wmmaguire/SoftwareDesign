#include "../include/System.h"
#include "../include/Device.h"
#include "../include/Component.h"
#include <string>
#include <libssh/libssh.h>
/*
 * test.cpp
 * Description: Unit test of Core System implementing omposite Design Pattern
 *
 */

System* createSystem()
{
  std::string system_name;
  int system_id;
  std::cout << "Define system name and system id" << std::endl;
  std::cin >> system_name >> system_id;
  return new System(system_name, system_id);
}

void addSystemDevices(System *sys_obj)
{
  int ndevices;
  int limit;
  std::cout << "select number of devices" << std::endl;
  std::cin >> ndevices;

  for ( int i = 0; i < ndevices; i++ )
  {
    limit = 10 * (i + 1);
    // append system devices [dynamically allocated space for ptr vectorization]
    sys_obj->add( new Device(sys_obj->getName() + " Device", i, limit ));
  }
}

int main() {
  int spin_cycle;
  
  // create main composite system
  System* sys = createSystem();
  // create sub-system [dynamically allocated space for ptr vectorization]
  System* sys1 = createSystem();
  System* sys2 = createSystem();  
  // add devices to subsystems 
  addSystemDevices(sys1);
  addSystemDevices(sys2);
  
  // build composite system out of subsystems
  sys->add( sys1);
  sys->add( sys2);
  sys->printInfo();
  
  // spin system (conduct n number of operations)
  std::cout << "\nselect spin cycle" << std::endl;
  std::cin >> spin_cycle;
  //std::cout << "Spinning System" << std::endl;
  for (int i = 0; i < spin_cycle; i++ )
  {
    sys->operation();
  }
  // conduct post operational clean-up
  sys->printInfo();
  std::cout << "\nPerforming clean up" << std::endl;
  sys->clean();
  sys->printInfo();

  // NOTE: destructor assumes children vector containing allocated ptrs [delete]
  // malloc error deconstructing sys object if children not properly allocated
  return 0;
}
