bin_PROGRAMS = hadl

hadl_LDADD = $(LIBJSONCPP_LIBS) $(LIBSIGC_LIBS) 
hadl_CPPFLAGS = $(LIBJSONCPP_CFLAGS) $(LIBSIGC_CFLAGS) -std=c++0x


hadl_SOURCES = 	src/main.cpp \
				src/api/Component.cpp \
				src/api/Port.cpp \
				src/api/PortRequired.cpp \
				src/api/PortProvided.cpp \
				src/api/Configuration.cpp \
				src/api/Role.cpp \
				src/api/RoleRequired.cpp \
				src/api/RoleProvided.cpp \
				src/api/Connector.cpp \
				src/api/Service.cpp \
				src/api/Element.cpp
