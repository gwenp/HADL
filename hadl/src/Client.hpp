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

	str_v on_message( PortComposantProvided* provided_port, str_v args );
	str_v test_method( str_v args);

};

#endif