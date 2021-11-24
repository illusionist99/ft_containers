#pragma once 

# include <vector>
# include <iostream>
# include <string>

template <class T, class Container = std::vector<T> >
class stack {



	public:
		typedef  T value_type;
		typedef Container container_type;
		typedef size_t size_type;
	
	explicit stack (const container_type& ctnr = container_type()) {
	
		Container(ctnr);
		_size = ctnr.size();
	}

	bool empty() const {
	
		if (_size)
			return (false);
		return (true);
	}

	size_type size() const {
	
		return (_size);
	}

	value_type& top() {
	
		//the top element is the last element inserted into the stack.
		return ();
	}
	const value_type& top() const;

	void push (const value_type& val);

	private:

		size_type _size;
};

