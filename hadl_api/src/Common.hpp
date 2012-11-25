#ifndef COMMON_HPP
#define COMMON_HPP
class Component;
class PortComposantProvided;
typedef std::vector<std::string> (Component::*ComponentMethod)(PortComposantProvided*,std::vector<std::string>);
typedef std::vector<std::string> str_v;
#endif