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

	class myIterator {

		T *_array;
		public:
		// defining tags

		typedef std::random_access_iterator_tag  iterator_category;
		typedef	std::ptrdiff_t	difference_type;
		typedef T value_type;
		typedef T*  pointer;
		typedef T& reference;
		myIterator( pointer array = NULL) : _array(array) {}
		myIterator( reference o) {
			_array = &o;
		}
		virtual ~myIterator(void) {}
		reference operator=( reference o) {
		
			_array = o;
			return (*this);
		}
		T	*getptr() const { return _array;}
		reference operator*() const { return *_array; }
		pointer operator->() { return _array; }

		friend bool operator== ( myIterator& a,  myIterator& b) {

			return a._array == b._array;
		}
		bool operator!=( myIterator const & b) {
			
			return _array != b.getptr();
		}
		myIterator &operator++() {
		
			_array++;
			return *this;
		}
		myIterator &operator--() {
		
			_array--;
			return *this;
		}
		myIterator operator++(int) {
		
			myIterator tmp = *this;
			++(*this);
			return tmp;
		}
		myIterator operator--(int) {
		
			myIterator tmp = *this;
			--(*this);
			return tmp;
		}
		friend value_type operator+(value_type v, myIterator& val) {
		
			v += val;
			return (v);
		}
		friend value_type operator-(value_type v, myIterator& val) {
		
			v -= val;
			return (v);
		}
		inline bool operator< (reference rval){ 

			return (rval < *_array);	
		}
		inline bool operator> (reference rval) {
			
			return rval < *_array;
		}
		
		inline bool operator<=(reference rval) {
		
			return !(*_array > rval);
		}
		
		inline bool operator>=(reference rval) {
		
			return !(*_array < rval);
		}
	};
	myIterator begin() {

		return (myIterator(_elements[0]));
	}

	myIterator end() {

		return (myIterator(_elements[_size]));
	}
	typedef  T value_type;
	typedef Allocator allocator_type;
	typedef size_t size_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef  T& reference;
	typedef const T& const_reference;
	typedef myIterator iterator;
	typedef const myIterator const_iterator;
	// typedef /// reverse_iterator;
	// typedef /// const_reserve_iterator;

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
		_capacity = n;
		if (val)
			_size = n;
		for (int i=0; i < n ; i++) {
			_alloc.construct(_elements + i, val);
		}
	}

	~Vector( void ) {
	
		for (int i=0; i < _size ; i++) {

			_alloc.destroy(_elements + i);
		}
		_alloc.deallocate(_elements, _capacity);
	}

	Vector& operator=(const Vector& x) {

		_alloc.deallocate(_elements, _capacity);
		_alloc.allocate(x.size());
		for (int i=0;i < x.size(); i++) {
		
			_alloc.construct(_elements + i, x[i]);
		}
		return (*this);
	}
// //	range (3)
	template <class inputIterator>
	Vector (inputIterator first, inputIterator last, const allocator_type& alloc = allocator_type()) {
	
		size_t size = std::distance(first, last);
		size_t index = 0;
		_elements = _alloc.allocate(size);
		for (inputIterator i = first; i < last; i++) {
		
			_alloc.construct(_elements + index, *i);
		}
	}
	
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

	size_type size( void ) const {
	
		return _size;
	}
	size_type max_size( void ) const {
	
		return _alloc.max_size();
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

		if (n > _size) {

			int current;
		
			current = n - _size;
			reserve(n);
			if (_size == 0) {
				current = 0;
			}
			for (int i=(_size ); i < n ; i++) {
				_alloc.construct(_elements + i, val);
				_size++;
			}
			
		}
		else {

			int current;
		
			current = _size - n;
			for (int i=current; i < _size; i++) {
			
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
		_alloc.construct(_elements + _size, val);
		_size++;
	}

	void pop_back() {
	
		if (_size >= 1) {
			
			_alloc.destroy(_elements + _size);
			_size--;
		}
	}
	// 	range (1)
	template <typename inputIter>
	void assign (inputIter first, inputIter last) {
	
		size_t size = std::distance(first, last);
		// for (myIterator i = first; i <  last; i++) {
			
		// }
		if (_capacity < size) {
		
			resize(size);
		}
		// _elements = _alloc.allocate(size);
		for ( int i=0;i<size;i++) {
		
			_alloc.construct(_elements + i, *first);
			first++;
		}
	}
	// fill (2)	
	void assign (size_type n, const value_type& val) {
	
		if (_capacity < n) {

			resize(n);
		}
		for ( int i=0;i<n;i++) {
		
			_alloc.construct(_elements + i, val);
		}
	}



// 	single element (1)	
iterator insert (iterator position, const value_type& val);
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

			_alloc.destroy(_elements + i);
		}
		if (_elements != NULL) {

			_alloc.deallocate(_elements, _size);
			_size = 0;
			_capacity = 0;
			_elements = NULL;
		}
	}
};	

