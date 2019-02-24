#include "wzmocnienie-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Wzmocnienie::Wzmocnienie(std::string const& name) : TaskContext(name){
  std::cout << "Wzmocnienie constructed !" <<std::endl;

  ports()->addEventPort("inPort", _inPort).doc("Component input port");
  ports()->addPort("outPort", _outPort).doc("Component output port");
}

bool Wzmocnienie::configureHook(){
  std::cout << "Wzmocnienie configured !" <<std::endl;
  return true;
}

bool Wzmocnienie::startHook(){
  std::cout << "Wzmocnienie started !" <<std::endl;
  return true;
}

void Wzmocnienie::updateHook(){

    double msg;
    double k=4;

    if(_inPort.read(msg) == RTT::NewData){
        msg=msg*k;
        std::cout << "wzmocnienie: " << msg << std::endl;
      _outPort.write(msg);

    }
}

void Wzmocnienie::stopHook() {
  std::cout << "Wzmocnienie executes stopping !" <<std::endl;
}

void Wzmocnienie::cleanupHook() {
  std::cout << "Wzmocnienie cleaning up !" <<std::endl;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Wzmocnienie)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Wzmocnienie)
