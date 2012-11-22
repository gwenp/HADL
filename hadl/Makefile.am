bin_PROGRAMS = hadl

hadl_LDADD = $(LIBJSONCPP_LIBS) $(LIBSIGC_LIBS) $(LIBHADL_LIBS)
hadl_CPPFLAGS = $(LIBJSONCPP_CFLAGS) $(LIBSIGC_CFLAGS) $(LIBHADL_CFLAGS) -lhadl

sc = src/server_configuration
server_config_files = $(sc)/CM_DB_Connector.cpp $(sc)/CM_DB_Connector.hpp \
$(sc)/SM_DB_Connector.cpp $(sc)/SM_DB_Connector.hpp \
$(sc)/SM_CM_Connector.cpp $(sc)/SM_CM_Connector.hpp \
$(sc)/ConnectionManager.cpp $(sc)/ConnectionManager.hpp \
$(sc)/SecurityManager.cpp $(sc)/SecurityManager.hpp \
$(sc)/DataBase.cpp $(sc)/DataBase.hpp \
$(sc)/ServerConfiguration.cpp $(sc)/ServerConfiguration.hpp



hadl_SOURCES = main.cpp \
				 src/Client.cpp src/Client.hpp \
 				 src/Server.cpp src/Server.hpp \
 				 src/CS_Connector.cpp src/CS_Connector.hpp \
 				 src/PortRequiedCS.hpp \
 				 src/PortProvidedCS.hpp \
 				 $(server_config_files)
