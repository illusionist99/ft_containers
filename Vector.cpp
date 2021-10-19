#include "Vector.hpp"

template< class T, class Alloc >
Vector<T, Alloc>::Vector()
{
}

template< class T, class Alloc >
Vector<T, Alloc>::Vector( const Vector & src )
{
}

template< class T, class Alloc >
Vector<T, Alloc>::~Vector()
{
}


template< class T, class Alloc >
Vector<T, Alloc> &				Vector<T, Alloc>::operator=( Vector const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

template< class T, class Alloc >
std::ostream &			operator<<( std::ostream & o, Vector<T, Alloc> const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}
