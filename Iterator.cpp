#include "Iterator.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Iterator::Iterator()
{
}

Iterator::Iterator( const Iterator & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Iterator::~Iterator()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Iterator &				Iterator::operator=( Iterator const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Iterator const & i )
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