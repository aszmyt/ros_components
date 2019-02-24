#include "potega-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>
#include <math.h>

Potega::Potega(std::string const& name) : TaskContext(name){
  std::cout << "Potega constructed !" <<std::endl;

  ports()->addEventPort("inPort", _inPort).doc("Component input port");
  ports()->addPort("outPort", _outPort).doc("Component output port");
}


bool Potega::configureHook(){
  std::cout << "Potega configured !" <<std::endl;
  return true;
}

bool Potega::startHook(){
  std::cout << "Potega started !" <<std::endl;
  return true;
}

void Potega::updateHook(){

    double msg;

    if(_inPort.read(msg) == RTT::NewData){
        msg=msg*msg;
      _outPort.write(msg);
      std::cout << "potega: " << msg << std::endl;
    }
}

void Potega::stopHook() {
  std::cout << "Potega executes stopping !" <<std::endl;
}

void Potega::cleanupHook() {
  std::cout << "Potega cleaning up !" <<std::endl;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Potega)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Potega)
