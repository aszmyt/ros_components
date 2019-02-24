#include "abs-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>
#include <math.h>

Abs::Abs(std::string const& name) : TaskContext(name){
  std::cout << "Abs constructed !" <<std::endl;
  ports()->addEventPort("inPort", _inPort).doc("Component input port");
  ports()->addPort("outPort", _outPort).doc("Component output port");
}

bool Abs::configureHook(){
  std::cout << "Abs configured !" <<std::endl;
  return true;
}

bool Abs::startHook(){
  std::cout << "Abs started !" <<std::endl;
  return true;
}

void Abs::updateHook(){
    double msg;

    if(_inPort.read(msg) == RTT::NewData){
        msg=abs(msg);
        std::cout << "przesuniecie: " << msg << std::endl;
      _outPort.write(msg);

    }
}

void Abs::stopHook() {
  std::cout << "Abs executes stopping !" <<std::endl;
}

void Abs::cleanupHook() {
  std::cout << "Abs cleaning up !" <<std::endl;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Abs)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Abs)
