/*
* Copyright 2012 Gwenael Pluchon <gwenael.pluchon@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef DEBUG_HPP
#define DEBUG_HPP

#include "../language_tools/JsonParser/libjsoncpp/json.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

class Dbg
{
public: 
	static void init(std::string configFile)
	{
		std::ifstream ifs(configFile.c_str());

		Json::Value root;   // will contains the root value after parsing.
		Json::Reader reader;
		bool parsingSuccessful = reader.parse( ifs, root );
		if ( !parsingSuccessful )
		{
			std::cout  	<< "Failed to parse configuration\n"
						<< reader.getFormattedErrorMessages();
			return;
		}

		const Json::Value print = root["print"];
		for ( int index = 0; index < print.size(); ++index )
		{
			Dbg::_printCategories.push_back(print[index].asString());
		}
	};

	
	class Out {
	public:
		Out& operator ()(std::string category){
			Dbg::_activeCategory = category;
			return *this;
		};

		template< typename T >
		friend Out& operator<<( Out& out, const T& obj){
			if (std::find(Dbg::_printCategories.begin(), Dbg::_printCategories.end(), Dbg::_activeCategory) != Dbg::_printCategories.end())
			{
				std::cout << obj;
			}
			return out;
		};
		friend Out& operator<<( Out& out, std::ostream& (*manip)(std::ostream&) )
		{
			if (std::find(Dbg::_printCategories.begin(), Dbg::_printCategories.end(), Dbg::_activeCategory) != Dbg::_printCategories.end())
			{
				std::cout << manip;
			}
			return out;
		};


	};

	static Out out;

	static std::string _activeCategory;
	static std::vector<std::string> _printCategories;
};
#endif /* DEBUG_HPP */