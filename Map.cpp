#include "Map.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Map::Map()
{
}

Map::Map( const Map & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Map::~Map()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Map &				Map::operator=( Map const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Map const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */