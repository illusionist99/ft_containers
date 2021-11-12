# pragma once 

# include <iostream>
# include <string>

template<
    class T,
    class Allocator = std::allocator<T>
> class Vector
{
	T *		_elements;
	size_t	_size;
	size_t	_capacity;
	std::allocator<T> _alloc;

	public:

	typedef  T value_type;
	typedef Allocator allocator_type;
	typedef size_t size_type;

	typedef  T& reference;
	typedef const T& const_reference;
//	default (1)	
	explicit Vector (const allocator_type& alloc = allocator_type()) {
	
		std::cout << "default constructor" << std::endl;
		_elements = NULL;
		_size = 0;
		_capacity = 0;
	}
//	fill (2)	
	explicit Vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
	
		std::cout << "default constructor with size" << std::endl;
		_elements = _alloc.allocate(n);
		_size = n;
		_capacity = n;
		for (int i=0; i < n ; i++) {
			// std::cout << val << std::endl;
			_alloc.construct(_elements + i, val);
		}
	}
	~Vector() {
	
		// for (int i=0; i < n ; i++) {
		// 	std::cout << val << std::endl;
		// 	_alloc.destroy(_elements + i, val);
		// }
		_alloc.deallocate(_elements, _capacity);
	}

	Vector& operator= (const Vector& x) {

		_alloc.deallocate(_elements, _capacity);
		_alloc.allocate(x.size());
		for (int i=0;i < x.size(); i++) {
		
			_alloc.construct(_elements + i, x[i]);
		}
		return (*this);
	}
// //	range (3)	
	// template <class InputIterator>
	// Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {
	
		
	// }

// //	copy (4)	
	Vector (const Vector& x) {
	
		for (int i=0;i < _size;i++) {
			_alloc.destroy(_elements + i);
		}
		_alloc.deallocate(_elements, _capacity);
		_alloc.allocate(x.size());
		for (int i=0;i < x.size(); i++) {
			_alloc.construct(_elements + i, x[i]);
		}
	}

	size_type size() const {
	
		return _size;
	}
	size_type max_size() const {
	
		return _alloc.max_size() / sizeof(T);
	}

	void reserve (size_type n) {
	
		if (n > _capacity) {

			T * new_container;
		
			new_container =  _alloc.allocate(n);
			int i;
			for (i=0; i < _size; i++) {
			
				_alloc.construct(new_container + i , _elements[i]);
				_alloc.destroy(_elements + i);
			}
			_alloc.deallocate(_elements, _size);
			_elements = NULL;
			_size = i;
			_capacity = n;
			_elements = new_container;
		}
	}

	void resize (size_type n, value_type val = value_type()) {
	
		if (_size == 0)
			_elements = _alloc.allocate(n);
		// std::cout << "n is " << n <<  " size is " << _size << std::endl;
		if (n > _size) {

			int current;
		
			current = n - _size;
			reserve(n);
			if (_size == 0) {
				current = 0;
			}
			// _elements = _alloc.allocate(n);
			for (int i=(_size ); i < n ; i++) {
				// std::cout << val   << std::endl;
				_alloc.construct(_elements + i, val);
				_size++;
			}
			
		}
		else {

			int current;
		
			current = _size - n;
			for (int i=current; i < _size; i++) {
			
				// std::cout << val << std::endl;
				_alloc.destroy(_elements + i);
			}
			// _alloc.deallocate(_elements, _capacity);
		}
		// _size = n;
		_capacity = n;
	}
	size_type capacity() const {
		
		return _capacity;
	}
	bool empty() const {
	
		if (_size == 0)
			return true;
		return false;
	}

	class out_of_range : public std::exception {
	
		public:
			const char * what () const throw () {
		
				return "Out of range";
			}
	};

	reference operator[] (size_type n) {
	
		if (n > _size)
			throw Vector::out_of_range();
		return _elements[n];
	}

	const_reference operator[] (size_type n) const {
	
		if (n > _size)
			throw Vector::out_of_range();
		return _elements[n];
	}


	reference at (size_type n) {
	
		if (n > _size)
			throw Vector::out_of_range();
		return _elements[n];
	}
	const_reference at (size_type n) const {
	
		if (n > _size)
			throw Vector::out_of_range();
		return _elements[n];
	}
	reference front() {
	
		// if (_size > 0)
		return _elements[0];
	}
	const_reference front() const {
	
		return _elements[0];
	}


	reference back() {
	
		return _elements[_size - 1];
	}
	const_reference back() const {
	
		return _elements[_size - 1];
	}

	void push_back (const value_type& val) {
	
		if (_size == 0)
		{
			_elements = _alloc.allocate(2);
			_capacity = 2;
		}
		if (_size + 1 > _capacity) {
			reserve((_size + 1) * 2);
		}
		std::cout << "wslt hna" << std::endl;
		_alloc.construct(_elements, val);
		_size++;
	}

	void pop_back() {
	
		if (_size >= 1) {
			
			_alloc.destroy(_elements + _size);
			_size--;
		}
	}
	// 	range (1)	
	// template <class InputIterator>
	//   void assign (InputIterator first, InputIterator last);
	// fill (2)	
	// void assign (size_type n, const value_type& val); 



// 	single element (1)	
// iterator insert (iterator position, const value_type& val);
// fill (2)	
//     void insert (iterator position, size_type n, const value_type& val);
// range (3)	
// template <class InputIterator>
//     void insert (iterator position, InputIterator first, InputIterator last);

	// iterator erase (iterator position);
	// iterator erase (iterator first, iterator last);
	void swap (Vector& x) {
	
		T * c(*this);
		int v = _size;
		reserve(x.size());
		*this = x;
		x.reserve(v);
		x = c;
		for (int i=0;i < _size; i++) {
		
			_alloc.destroy(c + i);
		}
		_alloc.deallocate(c, v);
	}
	void clear() {
	
		for (int i=0;i < _size; i++) {
		
			std::cout << "destroyed  id " << i  << " value " << _elements[i] << std::endl;
			_alloc.destroy(_elements + i);
		}
		_alloc.deallocate(_elements, _size);
	}
};	

