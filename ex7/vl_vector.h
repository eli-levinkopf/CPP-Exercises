//
// Created by Eli Levinkopf on 01/01/2022.
//

#ifndef _VL_VECTOR_H_
#define _VL_VECTOR_H_
#include<cmath>
#include <algorithm>
#include <stdexcept>
#define INITIAL_CAPACITY 16
#define INITIAL_SIZE 0

#define DEFAULT_K 0
#define INDEX_ERROR "Error: Invalid index"
#define K_1 1
#define CAPACITY_GROWTH_FACTOR 3
using std::copy;

template<typename T, size_t StaticCapacity = INITIAL_CAPACITY>
class vl_vector {
 public:
  //****************************************//
  //************** Typedefs  ***************//
  //****************************************//
  typedef T *iterator;
  typedef const T *const_iterator;
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

  //****************************************//
  //******* Constructors & Destructor ******//
  //****************************************//
  /**
   * default constructor.
   */
  vl_vector () : _capacity (StaticCapacity)
  {}

  /**
   * Copy constructor.
   * @param other Reference to other vl_vector instance.
   */
  vl_vector (const vl_vector &other) : _size (other._size),
									   _capacity (other._capacity)
  {
	current_vector_type ();
	copy (other.cbegin (), other.cend (), begin ());
  }

  /**
   * Initializes new instance with values from first to last
   * @param first Iterator to first value
   * @param last Iterator to last value
   */
  template<class InputIterator>
  vl_vector (InputIterator first, InputIterator last)
	  : _size (std::distance (first, last)),
		_capacity (calculate_capacity (DEFAULT_K))
  {
	current_vector_type ();
	copy (first, last, begin ());
  }

  /**
   * Initializes new instance with count elements with the given value
   * @param count The number of elements
   * @param value Value to be added
   */
  vl_vector (size_t count, const T &value) : _size (count),
								_capacity (calculate_capacity (DEFAULT_K))
  {
	current_vector_type ();
	iterator it = begin ();
	while (it != begin () + count)
	  {
		*it++ = value;
	  }
  }

  /**
   * Delete the vector resources
   */
  virtual ~vl_vector ()
  { delete[] _dynamic_vector; }

  //****************************************//
  //*************** Methods ****************//
  //****************************************//
  /**
   * @return The number of elements in the current vector.
   */
  size_t size () const
  { return _size; }

  /**
   * @return The capacity of the current vector.
   */
  size_t capacity () const
  { return _capacity; }

  /**
   * @return True if the vector is empty, false otherwise.
   */
  bool empty () const
  { return size () == 0; }

  /**
   * @param index Index of the item to be returned
   * @return Reference to the item in vector[index]
   */
  T &at (const size_t &index)
  {
	if (index >= size () || index < 0)
	  {
		throw std::out_of_range (INDEX_ERROR);
	  }
	return _cur_vector[index];
  }

  /**
 * @param index Index of the item to be returned
 * @return  The item in vector[index]
 */
  T at (const size_t index) const
  {
	if (index >= _size || index < 0)
	  {
		throw std::out_of_range (INDEX_ERROR);
	  }
	return _cur_vector[index];
  }

  /**
   * Push a new element with value to the vector.
   * @param value Value to push to the vector
   */
  void push_back (const T &value)
  {
	check_capacity (K_1);
	_cur_vector[_size++] = value;
  }

  /**
   * Insert a new element with value to the vector[position].
   * @param position The position to insert the new element.
   * @param value Value to insert to the vector.
   * @return Iterator to new element.
   */
  iterator insert (const_iterator position, T value)
  {
	T tmp[1] = {value};
	iterator first = tmp, last = tmp + 1;
	return insert (position, first, last);
  }

  /**
   * Insert element into the vector.
   * @param position The position to start inserting the element.
   * @param first Whether to insert the first element
   * @param last Whether to insert the last element
   * @return Iterator for the elements before the first new element.
   */
  template<class InputIterator>
  iterator insert (const_iterator position, InputIterator first,
				   InputIterator last)
  {
	size_t k = std::distance (first, last);
	size_t position_index = std::distance (cbegin (), position);
	check_capacity (k);
	T *tmp = new T[capacity ()];
	copy (cbegin (), cbegin () + position_index, tmp);
	copy (first, last, tmp + position_index);
	copy (cbegin () + position_index, cend (), tmp + position_index + k);
	_size += k;
	copy (tmp, tmp + _size, begin ());
	delete[] tmp;
	tmp = nullptr;
	return begin () + position_index;
  }

  /**
   * Delete the element from the the end of the vector.
   */
  void pop_back ()
  {
	if (size () > 0)
	  {
		_size--;
		check_if_still_dynamic ();
	  }
  }

  /**
   * Delete the element in vector[position].
   * @param position The position to delete
   * @return Iterator to the element in the right-hand side of the deleted
   * element.
   */
  iterator erase (const_iterator position)
  {
	return erase (position, position + 1);
  }

  /**
   *  Delete the elements from first to last element
   * @param first The first element to delete
   * @param last The last element to delete
   * @return Iterator to the element in the right-hand side of the first
   * deleted element.
   */
  iterator erase (const_iterator first, const_iterator last)
  {
	size_t k = std::distance (first, last);
	size_t pos_to_start_erase = std::distance (cbegin (), first);
	copy (cbegin (), cbegin () + pos_to_start_erase, _cur_vector);
	copy (cbegin () + pos_to_start_erase + k, cend (),
		  _cur_vector + pos_to_start_erase);
	_size -= k;
	check_if_still_dynamic ();
	return begin () + pos_to_start_erase;
  }

  /**
   * Delete all of the elements in the vector.
   */
  void clear ()
  {
	_size = INITIAL_SIZE;
	if (_cur_vector == _dynamic_vector)
	  {
		delete[] _dynamic_vector;
		_dynamic_vector = nullptr;
		_cur_vector = _static_vector;
		_capacity = StaticCapacity;
	  }
  }

  /**
   * @param value Value to check for.
   * @return True if the value is in the vector, false otherwise.
   */
  bool contains (const T &value) const
  {
	return std::find (cbegin (), cend (), value) != cend ();
  }

  T *data () const
  { return _cur_vector; }

  T *data ()
  { return _cur_vector; }

  iterator begin ()
  { return _cur_vector; }

  iterator end ()
  { return _cur_vector + _size; }

  const_iterator begin () const
  { return _cur_vector; }

  const_iterator end () const
  { return _cur_vector + _size; }

  const_iterator cbegin () const
  { return _cur_vector; }

  const_iterator cend () const
  { return _cur_vector + _size; }

  reverse_iterator rbegin ()
  { return reverse_iterator (end ()); }

  reverse_iterator rend ()
  { return reverse_iterator (begin ()); }

  const_reverse_iterator rbegin () const
  { return const_reverse_iterator (end ()); }

  const_reverse_iterator rend () const
  { return const_reverse_iterator (begin ()); }

  const_reverse_iterator crbegin () const
  { return const_reverse_iterator (end ()); }

  const_reverse_iterator crend () const
  { return const_reverse_iterator (begin ()); }

  //****************************************//
  //************** Operators ***************//
  //****************************************//
  /**
   * Assignment operator
   * @param other Reference to the other object.
   * @return Reference to this.
   */
  vl_vector &operator= (const vl_vector &other)
  {
	if (this != &other)
	  {
		delete[] _dynamic_vector;
		_dynamic_vector = nullptr;
		if (other._size > StaticCapacity)
		  {
			_dynamic_vector = new T[other._capacity];
			_cur_vector = _dynamic_vector;
		  }
		else
		  {
			_cur_vector = _static_vector;
		  }
		_size = other._size;
		_capacity = other._capacity;
	  }
	copy (other.cbegin (), other.cend (), begin ());
	return *this;
  }

  /**
   * Access operator. const version
   * @param index Index to access.
   * @return The element at the specified index.
   */
  T operator[] (const size_t index) const
  {
	return *(cbegin () + index);
  }

  /**
 * Access operator. non-const version.
 * @param index Index to access.
 * @return Reference to the element at the specified index.
 */
  T &operator[] (const size_t index)
  {
	return *(begin () + index);
  }

  /**
   * ' == ' operator
   * @param other Reference to the other vector.
   * @return True if the two vectors are equal, false otherwise.
   */
  bool operator== (const vl_vector &other) const
  {
	if (size () == other._size && capacity () == other._capacity)
	  {
		return std::equal (cbegin (), cend (), other.cbegin ());
	  }
	return false;
  }

  /**
 * ' != ' operator
 * @param other Reference to the other vector.
 * @return False if the two vectors are equal, true otherwise.
 */
  bool operator!= (const vl_vector &other) const
  {
	return !(*this == other);
  }

 private:
  size_t _size = 0;
  size_t _capacity;
  T *_dynamic_vector = nullptr;
  T _static_vector[StaticCapacity];
  T *_cur_vector = _static_vector;

  /**
   * Calculate the capacity of the vector.
   * @param k The number of the added element.
   * @return The updated capacity.
   */
  size_t calculate_capacity (size_t k)
  {
	if (_size + k > StaticCapacity)
	  {
		return floor (CAPACITY_GROWTH_FACTOR * (_size + k) / 2);
	  }
	return StaticCapacity;
  }

  /**
   * Checks if the constraints need to be initialize a dynamic vector or static
   * vector.
   */
  void current_vector_type ()
  {
	if (capacity () > StaticCapacity)
	  {
		_dynamic_vector = new T[capacity ()];
		_cur_vector = _dynamic_vector;
	  }
	else
	  {
		_cur_vector = _static_vector;
	  }
  }

  /**
   * Checks if the capacity needs to be increased.
   * @param k The number of the added element.
   */
  void check_capacity (size_t k)
  {
	if (size () + k > capacity ()) // Dynamic case
	  {
		size_t old_capacity = capacity ();
		_capacity = calculate_capacity (k);
		if (capacity () != old_capacity) // Increase _capacity
		  {
			T *tmp = new T[capacity ()];
			copy (cbegin (), cend (), tmp);
			delete[] _dynamic_vector;
			_dynamic_vector = tmp;
			_cur_vector = _dynamic_vector;
		  }
	  }
  }

  /**
   * Checks if the vector is still need to be on the Heap or it can be used in
   * the stack.
   */
  void check_if_still_dynamic ()
  {
	if (size () <= StaticCapacity)
	  {
		copy (cbegin (), cend (), _static_vector);
		_capacity = StaticCapacity;
		_cur_vector = _static_vector;
		delete[] _dynamic_vector;
		_dynamic_vector = nullptr;
	  }
  }

};

#endif //_VL_VECTOR_H_
