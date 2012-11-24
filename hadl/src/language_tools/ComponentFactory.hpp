#ifndef COMPONENTFACTORY_HPP
#define COMPONENTFACTORY_HPP

#include <HADL/Component.hpp>


class ComponentFactory {
public:
	virtual Component* make() =0;
};

#endif