#ifndef OROCOS_PRZESUNIECIE_COMPONENT_HPP
#define OROCOS_PRZESUNIECIE_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Przesuniecie : public RTT::TaskContext{
  public:
    Przesuniecie(std::string const& name);
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
