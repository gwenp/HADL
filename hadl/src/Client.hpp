#ifndef M1_CLIENT_HPP
#define M1_CLIENT_HPP

#include <HADL/Component.hpp>

//typedef struct key_fun_s {
//	std::string key;
//	ComponentMethod method;
//} key_fun_t;


class Client : public Component {
public:
	Client();
	~Client();

	void onInit();

	virtual std::vector<std::string> callback_method( PortComposantProvided* provided_port, std::vector<std::string>& args );
	std::vector<std::string> test_method(std::vector<std::string> args);

};

#endif