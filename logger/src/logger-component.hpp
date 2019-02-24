#ifndef OROCOS_LOGGER_COMPONENT_HPP
#define OROCOS_LOGGER_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Logger : public RTT::TaskContext{
  public:
    Logger(std::string const& name);
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
