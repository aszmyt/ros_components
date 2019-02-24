#include "generator-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Generator::Generator(std::string const& name) : TaskContext(name){
  std::cout << "Generator constructed !" <<std::endl;
  ports()->addEventPort("inPort", _inPort).doc("Component input port");
  ports()->addPort("outPort", _outPort).doc("Component output port");
}

bool Generator::configureHook(){
  std::cout << "Generator configured !" <<std::endl;
  return true;
}

bool Generator::startHook(){
  std::cout << "Generator started !" <<std::endl;
  Generator::time=0;
  return true;
}

void Generator::updateHook(){

  double msg;
  double fi;
  double omega;
  fi=0;
  omega=2;
  msg=sin((omega*Generator::time)+fi);
    _outPort.write(msg);
    std::cout << "mam to: " << msg << std::endl;
    Generator::time+=0.01;
}

void Generator::stopHook() {
  std::cout << "Generator executes stopping !" <<std::endl;
}

void Generator::cleanupHook() {
  std::cout << "Generator cleaning up !" <<std::endl;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Generator)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Generator)
