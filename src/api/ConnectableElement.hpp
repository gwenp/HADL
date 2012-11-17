#ifndef CONNECTABLEELEMENT_HPP
#define CONNECTABLEELEMENT_HPP

#include <cstdlib>
#include "Element.hpp"
//Classe servant a lier la configuration avec un connecteur ou un composant

class Configuration;

class ConnectableElement : public Element
{
public:
	void linkConfiguration(Configuration* c, bool _internal);
private:
	Configuration* _linkedConfiguration;
};

#endif /* CONNECTABLEELEMENT_HPP */