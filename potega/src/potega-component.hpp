#ifndef OROCOS_POTEGA_COMPONENT_HPP
#define OROCOS_POTEGA_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Potega : public RTT::TaskContext{
  public:
    Potega(std::string const& name);
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
