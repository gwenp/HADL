#ifndef CONNECTABLEELEMENT_HPP
#define CONNECTABLEELEMENT_HPP

#include <cstdlib>
#include "Element.hpp"
//Classe servant a lier la configuration avec un connecteur ou un composant

class Configuration;

class ConnectableElement : public Element
{
public:
	void addToConfiguration(Configuration* c);
	Configuration* getParentConfiguration();
	void setParentConfiguration(Configuration* cfg);

	void linkConfiguration(Configuration* c, bool _internal);
private:
	Configuration* _linkedConfiguration;
	Configuration* _parentConfiguration;
};

#endif /* CONNECTABLEELEMENT_HPP */