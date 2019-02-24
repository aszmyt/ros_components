#include "suma-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Suma::Suma(std::string const& name) : TaskContext(name){
  std::cout << "Suma constructed !" <<std::endl;

  ports()->addEventPort("inPort", _inPort).doc("Component input port");
  ports()->addPort("outPort", _outPort).doc("Component output port");
}

bool Suma::configureHook(){
  std::cout << "Suma configured !" <<std::endl;
  return true;
}

bool Suma::startHook(){
  std::cout << "Suma started !" <<std::endl;
  return true;
}

void Suma::updateHook(){
    double msg;
    double a=4;

    if(_inPort.read(msg) == RTT::NewData){
        msg=msg+a;
        std::cout << "przesuniecie: " << msg << std::endl;
      _outPort.write(msg);

    }
}

void Suma::stopHook() {
  std::cout << "Suma executes stopping !" <<std::endl;
}

void Suma::cleanupHook() {
  std::cout << "Suma cleaning up !" <<std::endl;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Suma)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Suma)
