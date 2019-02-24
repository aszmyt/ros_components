#ifndef OROCOS_SUMA_COMPONENT_HPP
#define OROCOS_SUMA_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Suma : public RTT::TaskContext{
  public:
    Suma(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
private:
    RTT::InputPort<double>  _inPort;
    RTT::OutputPort<double>  _outPort;
};
#endif
