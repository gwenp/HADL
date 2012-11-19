#bin_PROGRAMS = hadlapi
lib_LTLIBRARIES = libhadl.la

libhadl_la_LIBADD = $(LIBJSONCPP_LIBS) $(LIBSIGC_LIBS) 
libhadl_la_CPPFLAGS = $(LIBJSONCPP_CFLAGS) $(LIBSIGC_CFLAGS)

library_includedir=$(includedir)/HADL
library_include_HEADERS = src/*.hpp

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libhadl.pc

libhadl_la_SOURCES = src/PortConfigProvided.cpp src/PortConfigProvided.hpp \
				src/Configuration.cpp src/Configuration.hpp \
				src/ConnectableElement.cpp src/ConnectableElement.hpp \
				src/Component.cpp src/Component.hpp \
				src/PortConfigRequired.cpp src/PortConfigRequired.hpp \
				src/Connector.cpp src/Connector.hpp \
				src/RoleConfig.cpp src/RoleConfig.hpp \
				src/Element.cpp src/Element.hpp \
				src/RoleConfigProvided.cpp src/RoleConfigProvided.hpp \
				src/InterfaceComposant.cpp src/InterfaceComposant.hpp \
				src/RoleConfigRequired.cpp src/RoleConfigRequired.hpp \
				src/InterfaceConfiguration.cpp src/InterfaceConfiguration.hpp \
				src/Role.cpp src/Role.hpp \
				src/InterfaceConnector.cpp src/InterfaceConnector.hpp \
				src/RoleProvided.cpp src/RoleProvided.hpp \
				src/Interface.cpp src/Interface.hpp \
				src/RoleRequired.cpp src/RoleRequired.hpp \
				src/PortComposant.cpp src/PortComposant.hpp \
				src/Service.cpp src/Service.hpp \
				src/PortComposantProvided.cpp src/PortComposantProvided.hpp \
				src/ServiceProvided.cpp src/ServiceProvided.hpp \
				src/PortComposantRequired.cpp src/PortComposantRequired.hpp \
				src/ServiceRequired.cpp src/ServiceRequired.hpp \
				src/PortConfig.cpp src/PortConfih.hpp
