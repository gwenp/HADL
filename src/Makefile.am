SUBDIRS = api/ .

bin_PROGRAMS = hadlm1

hadlm1_LDADD = $(LIBJSONCPP_LIBS) $(LIBSIGC_LIBS) 
hadlm1_CPPFLAGS = $(LIBJSONCPP_CFLAGS) $(LIBSIGC_CFLAGS)

hadlm1_SOURCES = main.cpp \
				 Client.cpp Client.hpp \
 				 Server.cpp Server.hpp \
 				 CS_Connector.cpp CS_Connector.hpp

