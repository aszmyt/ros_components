#ifndef OROCOS_ABS_COMPONENT_HPP
#define OROCOS_ABS_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Abs : public RTT::TaskContext{
  public:
    Abs(std::string const& name);
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
