////
//// Created by Eli Levinkopf on 01/01/2022.
////
//
//#ifndef _VL_VECTOR_H_
//#define _VL_VECTOR_H_
//#include<cmath>
//#include <algorithm>
//#include <stdexcept>
//#define INITIAL_CAPACITY 16
//#define INITIAL_SIZE 0
//
//using std::copy;
//
//template<typename T, size_t StaticCapacity = INITIAL_CAPACITY>
//class vl_vector {
// public:
//  //****************************************//
//  //************** Typedefs  ***************//
//  //****************************************//
//  typedef T *iterator;
//  typedef const T *const_iterator;
//  typedef std::reverse_iterator<iterator> reverse_iterator;
//  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
//
//  //****************************************//
//  //******* Constructors & Destructor ******//
//  //****************************************//
//  vl_vector () : _capacity (StaticCapacity)
//  {}
//
//  vl_vector (const vl_vector &other) : _size (other._size),
//									   _capacity (other._capacity)
//  {
//	current_vector_type ();
//	copy (other.cbegin (), other.cend (), begin ());
//  }
//
//  template<class InputIterator>
//  vl_vector (InputIterator first, InputIterator last)
//	  : _size (std::distance (first, last)),
//		_capacity (calculate_capacity (0))
//  {
//	current_vector_type ();
//	copy (first, last, begin ());
//  }
//
//  vl_vector (size_t count, const T &value) : _size (count),
//											 _capacity (calculate_capacity (0))
//  {
//	current_vector_type ();
//	iterator it = begin ();
//	while (it != begin () + count)
//	  {
//		*it++ = value;
//	  }
//  }
//
//  virtual ~vl_vector ()
//  { delete[] _dynamic_vector; }
//
//  //****************************************//
//  //*************** Methods ****************//
//  //****************************************//
//  size_t size () const
//  { return _size; }
//
//  size_t capacity () const
//  { return _capacity; }
//
//  bool empty () const
//  { return size() == 0; }
//
//  T &at (const size_t &index)
//  {
//	if (index >= _size || index < 0)
//	  {
//		throw std::out_of_range ("Error: Invalid index");
//	  }
//	return _cur_vector[index];
//  }
//
//  T at (const size_t index) const
//  {
//	if (index >= _size || index < 0)
//	  {
//		throw std::out_of_range ("Error: Invalid index");
//	  }
//	return _cur_vector[index];
//  }
//
//  void push_back (const T &value)
//  {
//	check_capacity (1);
//	_cur_vector[_size++] = value;
//  }
//
//  iterator insert (const_iterator position, T value)
//  {
//	T tmp[1] = {value};
//	iterator first = tmp, last = tmp + 1;
//	return insert (position, first, last);
//  }
//
//  template<class InputIterator>
//  iterator insert (const_iterator position, InputIterator first,
//				   InputIterator last)
//  {
//	size_t k = std::distance (first, last);
//	size_t position_index = std::distance (cbegin (), position);
//	check_capacity (k);
//	T *tmp = new T[_capacity];
//	copy (cbegin (), cbegin () + position_index, tmp);
//	copy (first, last, tmp + position_index);
//	copy (cbegin () + position_index, cend (), tmp + position_index + k);
//	_size += k;
//	copy (tmp, tmp + _size, begin ());
//	delete[] tmp;
//	tmp = nullptr;
//	return begin () + position_index;
//  }
//
//  void pop_back ()
//  {
//	if (_size > 0)
//	  {
//		_size--;
//		check_if_still_dynamic ();
//	  }
//  }
//
//  iterator erase (const_iterator position)
//  {
//	return erase (position, position + 1);
//  }
//
//  iterator erase (const_iterator first, const_iterator last)
//  {
//	size_t k = std::distance (first, last);
//	size_t pos_to_start_erase = std::distance (cbegin (), first);
//	copy (cbegin (), cbegin () + pos_to_start_erase, _cur_vector);
//	copy (cbegin () + pos_to_start_erase + k, cend (),
//		  _cur_vector + pos_to_start_erase);
//	_size -= k;
//	check_if_still_dynamic ();
//	return begin () + pos_to_start_erase;
//  }
//
//  void clear ()
//  {
//	_size = 0;
//	if (_cur_vector == _dynamic_vector)
//	  {
//		delete[] _dynamic_vector;
//		_dynamic_vector = nullptr;
//		_cur_vector = _static_vector;
//		_capacity = StaticCapacity;
//	  }
//  }
//
//  bool contains ( T &value) const
//  {
//	T * cur_value = _cur_vector;
//	while (cur_value != _cur_vector + size())
//	  {
//		if (*cur_value == value)
//		  {
//			return true;
//		  }
//		++cur_value;
//	  }
//	return false;
//  }
//
//  T *data () const
//  { return _cur_vector; }
//
//  T *data ()
//  { return _cur_vector; }
//
//  iterator begin ()
//  { return _cur_vector; }
//
//  iterator end ()
//  { return _cur_vector + _size; }
//
//  const_iterator begin () const
//  { return _cur_vector; }
//
//  const_iterator end () const
//  { return _cur_vector + _size; }
//
//  const_iterator cbegin () const
//  { return _cur_vector; }
//
//  const_iterator cend () const
//  { return _cur_vector + _size; }
//
//  reverse_iterator rbegin ()
//  { return reverse_iterator (end ()); }
//
//  reverse_iterator rend ()
//  { return reverse_iterator (begin ()); }
//
//  const_reverse_iterator rbegin () const
//  { return const_reverse_iterator (end ()); }
//
//  const_reverse_iterator rend () const
//  { return const_reverse_iterator (begin ()); }
//
//  const_reverse_iterator crbegin () const
//  { return const_reverse_iterator (end ()); }
//
//  const_reverse_iterator crend () const
//  { return const_reverse_iterator (begin ()); }
//
//  //****************************************//
//  //************** Operators ***************//
//  //****************************************//
//  vl_vector &operator= (const vl_vector &other)
//  {
//	if (this != &other)
//	  {
//		delete[] _dynamic_vector;
//		_dynamic_vector = nullptr;
//		if (other._size > StaticCapacity)
//		  {
//			_dynamic_vector = new T[other._capacity];
//			_cur_vector = _dynamic_vector;
//		  }
//		else
//		  {
//			_cur_vector = _static_vector;
//		  }
//		_size = other._size;
//		_capacity = other._capacity;
//	  }
//	copy (other.cbegin (), other.cend (), begin ());
//	return *this;
//  }
//
//  T operator[] (const size_t index) const
//  {
//	return *(cbegin () + index);
//  }
//
//  T &operator[] (const size_t index)
//  {
//	return *(begin () + index);
//  }
//
//  bool operator== (const vl_vector &other) const
//  {
//	if (_size == other._size && _capacity == other._capacity)
//	  {
//		for (size_t i = 0; i < _size; ++i)
//		  {
//			if ((*this)[i] != other[i])
//			  {
//				return false;
//			  }
//		  }
//		return true;
//	  }
//	return false;
//  }
//
//  bool operator!= (vl_vector &other) const
//  {
//	return !(*this == other);
//  }
//
// private:
//  size_t _size = 0;
//  size_t _capacity;
//  T *_dynamic_vector = nullptr;
//  T _static_vector[StaticCapacity];
//  T *_cur_vector = _static_vector;
//  size_t calculate_capacity (size_t k)
//  {
//	if (_size + k > StaticCapacity)
//	  {
//		return floor (3 * (_size + k) / 2);
//	  }
//	return StaticCapacity;
//  }
//
//  void current_vector_type ()
//  {
//	if (_capacity > StaticCapacity)
//	  {
//		_dynamic_vector = new T[_capacity];
//		_cur_vector = _dynamic_vector;
//	  }
//	else
//	  {
//		_cur_vector = _static_vector;
//	  }
//  }
//
//  void check_capacity (size_t k)
//  {
//	if (_size + k > _capacity) // Dynamic case
//	  {
//		size_t old_capacity = _capacity;
//		_capacity = calculate_capacity (k);
//		if (_capacity != old_capacity) // Increase _capacity
//		  {
//			T *tmp = new T[_capacity];
//			copy (cbegin (), cend (), tmp);
//			delete[] _dynamic_vector;
//			_dynamic_vector = tmp;
//			_cur_vector = _dynamic_vector;
//		  }
//	  }
//  }
//
//  void check_if_still_dynamic ()
//  {
//	if (_size <= StaticCapacity)
//	  {
//		copy (cbegin (), cend (), _static_vector);
//		_capacity = StaticCapacity;
//		_cur_vector = _static_vector;
//		delete[] _dynamic_vector;
//		_dynamic_vector = nullptr;
//	  }
//  }
//
//};
//
//#endif //_VL_VECTOR_H_
