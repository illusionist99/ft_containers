# pragma once

# include <iostream>
# include <string>

template < class T, class Alloc = std::allocator<T> >
class Vector
{

	public:

		Vector();
		Vector( Vector const & src );
		~Vector();

		Vector &		operator=( Vector const & rhs );

		// Iterators

		const_iterator begin( void ) const;
		const_iterator end( void ) const;

		const_reverse_iterator rbegin( void ) const;
		const_reverse_iterator rend( void ) const;
	
		// Capacity

		size_type size( void ) const;
		size_type max_size( void ) const;
		void resize (size_type n, value_type val = value_type());
		size_type capacity( void ) const;
		bool empty( void ) const;
		void reserve (size_type n);

		// Element access

		const_reference operator[] (size_type n) const;
		const_reference at (size_type n) const;
		const_reference front( void ) const;
		const_reference back( void ) const;


		// Modifiers

		template <class InputIterator>
  		void assign (InputIterator first, InputIterator last);
		
		void assign (size_type n, const value_type& val);
		void push_back (const value_type& val);
		void pop_back( void );
		
		iterator insert (iterator position, const value_type& val);
		void insert (iterator position, size_type n, const value_type& val);
		
		template <class InputIterator>
   		void insert (iterator position, InputIterator first, InputIterator last);


		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);

		void swap (vector& x);

		void clear( void );

		// Allocator
		allocator_type get_allocator( void ) const;

		// relational operators

		bool operator== (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
		bool operator!= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
		bool operator<  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
		bool operator<= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
		bool operator>  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
		bool operator>= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
};

//std::ostream &			operator<<( std::ostream & o, Vector const & i );
