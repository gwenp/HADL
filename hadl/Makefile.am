bin_PROGRAMS = hadl

hadl_LDADD = $(LIBJSONCPP_LIBS) $(LIBSIGC_LIBS) $(LIBHADL_LIBS) $(PROTOBUF_LIBS)
hadl_CPPFLAGS = $(LIBJSONCPP_CFLAGS) $(LIBSIGC_CFLAGS) $(LIBHADL_CFLAGS) $(PROTOBUF_CFLAGS)

sc = src/server_configuration
server_config_files = $(sc)/CM_DB_Connector.cpp $(sc)/CM_DB_Connector.hpp \
$(sc)/SM_DB_Connector.cpp $(sc)/SM_DB_Connector.hpp \
$(sc)/SM_CM_Connector.cpp $(sc)/SM_CM_Connector.hpp \
$(sc)/ConnectionManager.cpp $(sc)/ConnectionManager.hpp \
$(sc)/SecurityManager.cpp $(sc)/SecurityManager.hpp \
$(sc)/DataBase.cpp $(sc)/DataBase.hpp \
$(sc)/ServerConfiguration.cpp $(sc)/ServerConfiguration.hpp



hadl_SOURCES = main.cpp \
				 src/language_tools/LanguageManager.cpp src/language_tools/LanguageManager.hpp \
				 src/language_tools/JsonParser/JsonParser.cpp src/language_tools/JsonParser/JsonParser.hpp \
				 src/language_tools/ComponentFactory.cpp src/language_tools/ComponentFactory.hpp \
				 src/language_tools/ConnectorFactory.cpp src/language_tools/ConnectorFactory.hpp \
				 src/factories/ClientComponentFactory.cpp src/factories/ClientComponentFactory.hpp \
				 src/factories/ServerComponentFactory.cpp src/factories/ServerComponentFactory.hpp \
				 src/factories/CS_ConnectorFactory.cpp src/factories/CS_ConnectorFactory.hpp \
				 src/Client.cpp src/Client.hpp \
 				 src/Server.cpp src/Server.hpp \
 				 src/CS_Connector.cpp src/CS_Connector.hpp \
 				 src/PortRequiedCS.hpp \
 				 src/PortProvidedCS.hpp \
 				 $(server_config_files)
