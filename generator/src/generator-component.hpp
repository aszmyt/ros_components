#ifndef OROCOS_GENERATOR_COMPONENT_HPP
#define OROCOS_GENERATOR_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Generator : public RTT::TaskContext{
  public:
    Generator(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
    double time;
private:
    RTT::InputPort<double>  _inPort;
    RTT::OutputPort<double>  _outPort;
};
#endif
