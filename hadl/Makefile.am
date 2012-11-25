bin_PROGRAMS = hadl

hadl_LDADD = $(LIBSIGC_LIBS) $(LIBHADL_LIBS) $(PROTOBUF_LIBS)
hadl_CPPFLAGS = $(LIBSIGC_CFLAGS) $(LIBHADL_CFLAGS) $(PROTOBUF_CFLAGS)

sc = src/server_configuration
server_config_files = $(sc)/ConnectionManager.cpp $(sc)/ConnectionManager.hpp \
$(sc)/SecurityManager.cpp $(sc)/SecurityManager.hpp \
$(sc)/DataBase.cpp $(sc)/DataBase.hpp \
$(sc)/ServerConfiguration.cpp $(sc)/ServerConfiguration.hpp



hadl_SOURCES = main.cpp \
				 src/Utils/Dbg.cpp src/Utils/Dbg.hpp \
				 src/language_tools/JsonParser/libjsoncpp/json_batchallocator.h \
				 src/language_tools/JsonParser/libjsoncpp/json_reader.cpp \
				 src/language_tools/JsonParser/libjsoncpp/json_valueiterator.inl \
				 src/language_tools/JsonParser/libjsoncpp/json_internalarray.inl \
				 src/language_tools/JsonParser/libjsoncpp/json_tool.h \
				 src/language_tools/JsonParser/libjsoncpp/json_writer.cpp \
				 src/language_tools/JsonParser/libjsoncpp/json_internalmap.inl \
				 src/language_tools/JsonParser/libjsoncpp/json_value.cpp \
				 src/language_tools/LanguageManager.cpp src/language_tools/LanguageManager.hpp \
				 src/language_tools/JsonParser/JsonParser.cpp src/language_tools/JsonParser/JsonParser.hpp \
				 src/language_tools/ComponentFactory.cpp src/language_tools/ComponentFactory.hpp \
				 src/language_tools/ConnectorFactory.cpp src/language_tools/ConnectorFactory.hpp \
				 src/factories/ClientComponentFactory.cpp src/factories/ClientComponentFactory.hpp \
				 src/factories/ServerComponentFactory.cpp src/factories/ServerComponentFactory.hpp \
				 src/factories/CS_ConnectorFactory.cpp src/factories/CS_ConnectorFactory.hpp \
				 src/factories/DatabaseFactory.cpp src/factories/DatabaseFactory.hpp \
				 src/factories/ConnectionManagerFactory.cpp src/factories/ConnectionManagerFactory.hpp \
				 src/factories/SecurityManagerFactory.cpp src/factories/SecurityManagerFactory.hpp \
				 src/factories/DefaultConnectorFactory.cpp src/factories/DefaultConnectorFactory.hpp \
				 src/Client.cpp src/Client.hpp \
 				 src/Server.cpp src/Server.hpp \
 				 src/CS_Connector.cpp src/CS_Connector.hpp \
 				 $(server_config_files) \
 				 src/networking.c src/networking.h



