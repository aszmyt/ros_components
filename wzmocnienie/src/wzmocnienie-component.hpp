#ifndef OROCOS_WZMOCNIENIE_COMPONENT_HPP
#define OROCOS_WZMOCNIENIE_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Wzmocnienie : public RTT::TaskContext{
  public:
    Wzmocnienie(std::string const& name);
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
