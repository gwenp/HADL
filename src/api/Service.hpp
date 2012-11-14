#ifndef SERVICE_HPP
#define SERVICE_HPP

#include <vector>

class Service
{
public:
	Service();
	~Service();


private:
	std::vector<Port*> _ports;
};

#endif /* SERVICE_HPP */