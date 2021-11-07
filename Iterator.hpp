#pragma once

# include <iostream>
# include <string>

template<typename T> 
class MyIterator : public std::iterator<std::random_access_iterator_tag, int>
{

public:

	T	*_p;

	// Default constructible
	MyIterator( void ) {
	
		_p = NULL;
	};
	// Copy constructible
 	MyIterator(const MyIterator& mit) : _p(mit.p) {}

	// Copy assignable
	MyIterator &operator=(const MyIterator &o): _p(o._p) {}	

	// Destructible
	~MyIterator( void ) {}
	
	// Dereferenceable
	T	operator*() {return *_p;}
	
	// Pre-incrementable 
	MyIterator& operator++() {++_p;return *this;}
	
	// Post-incrementable
	MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;}
	
	// Pre-decrementable
	MyIterator& operator--() {--_p;return *this;}

	// Post-decrementable
	MyIterator operator--(int) {MyIterator tmp(*this); operator--(); return tmp;}

	// Equality
	bool operator==(const MyIterator& rhs) const {return _p==rhs._p;}
	
	// Inequality
	bool operator!=(const MyIterator& rhs) const {return _p!=rhs._p;}

	std::ptrdiff_t
	T	*operator->() {return _p;}
	// Addition
	MyIterator	operator+(const  MyIterator& o) {

		_p += lo._p;
		return (_p);
	};
	MyIterator	operator-(const  MyIterator& o) {

		_p -= o._p;
		return (_p);
	};
	// Everything from Bidirectional Iterator
	// Compound addition assignment - operator+=
	// Compound subtraction assignment - operator-=
	// Addition - operator+
	// Subtraction - operator-
	// Relational less-than - operator<
	// Relational greather-than - operator>
	// Relational less-than-or-equal - operator<=
	// Relational greater-than-or-equal - operator>=
	// Subscripting - operator[]

};