#ifndef OROCOS_CALKA_COMPONENT_HPP
#define OROCOS_CALKA_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Calka : public RTT::TaskContext{
  public:
    Calka(std::string const& name);
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
