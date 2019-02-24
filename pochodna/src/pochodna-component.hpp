#ifndef OROCOS_POCHODNA_COMPONENT_HPP
#define OROCOS_POCHODNA_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Pochodna : public RTT::TaskContext{
  public:
    Pochodna(std::string const& name);
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
