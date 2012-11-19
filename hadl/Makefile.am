bin_PROGRAMS = hadl

hadl_LDADD = $(LIBJSONCPP_LIBS) $(LIBSIGC_LIBS) $(LIBHADL_LIBS)
hadl_CPPFLAGS = $(LIBJSONCPP_CFLAGS) $(LIBSIGC_CFLAGS) $(LIBHADL_CFLAGS) -lhadl


hadl_SOURCES = main.cpp \
				 src/Client.cpp src/Client.hpp \
 				 src/Server.cpp src/Server.hpp \
 				 src/CS_Connector.cpp src/CS_Connector.hpp \
 				 src/PortRequiedCS.hpp \
 				 src/PortProvidedCS.hpp
