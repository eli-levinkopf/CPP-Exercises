//
// Created by rotem on 07/10/2021.
//

#ifndef _STACK_H_
#define _STACK_H_

#include "Apartment.h"
#include <utility>
#include <vector>
#include <list>

class Stack {
  std::list<Apartment> _apartments;
  class const_iterator;

  struct node {
	node *_next;
	Apartment _data_pair;
	node (node *next, Apartment pair)
		: _next (next), _data_pair (pair)
	{}
	~node ()
	{
	  delete _next;
	}
  };

  node *_head;

  //****************************************//
  //*************** Iterator ***************//
  //****************************************//
  class Iterator {
	node *_cur_apartment;
	friend class const_iterator;
   public:
	//****************************************//
	//*************** typedefs ***************//
	//****************************************//
	typedef Apartment value_type;
	typedef Apartment *pointer;
	typedef Apartment &reference;
	typedef std::forward_iterator_tag iterator_category;
	typedef std::ptrdiff_t difference_type;

	Iterator (node *cur_apartment);

	//****************************************//
	//*************** operators **************//
	//****************************************//
	pointer operator-> ();
	reference operator* ();
//  pre (++x)
	Iterator &operator++ ();
//  post (x++)
	Iterator operator++ (int);
	bool operator== (const Iterator &rhs) const;
	bool operator!= (const Iterator &rhs) const;

  };
  //****************************************//
  //*************** Const Iterator *********//
  //****************************************//
  class const_iterator {
	node *_cur_apartment;
   public:
	//****************************************//
	//*************** typedefs ***************//
	//****************************************//
	typedef Apartment value_type;
	typedef const Apartment *pointer;
	typedef const Apartment &reference;
	typedef std::forward_iterator_tag iterator_category;
	typedef std::ptrdiff_t difference_type;

	const_iterator (node *cur_apartment);
	const_iterator (const Iterator &it);

	//****************************************//
	//*************** operators **************//
	//****************************************//
	pointer operator-> ();
	reference operator* ();
//  pre (++x)
	const_iterator &operator++ ();
//  post (x++)
	const_iterator operator++ (int);
	bool operator== (const const_iterator &rhs) const;
	bool operator!= (const const_iterator &rhs) const;
  };

 public:
  /**
   * Default constructor, constructs an empty stack
   */
  Stack ();
  /**
   * Constructor that gets vector of pairs, and pushes them as apartments
   * to the stack, when the first pair is pushed first.
   * @param coordinates vector of pairs
   */
  Stack (std::vector<std::pair<double, double>> coordinates);
  /**
   * Copy Constructor
   * @param other reference to a stack
   */
  Stack (const Stack& other);
  /**
   * assignment operator
   * @param rhs reference to a stack
   * @return reference to this
   */
  Stack &operator= (const Stack& rhs);
  /**
   * Destructor
   */
  ~Stack ();
  /**
   * Pushes an apartment to the top of the stack
   * @param apartment reference to an apartment
   */
  void push (const Apartment &apartment);
  /**
   * A method that deletes the item from the top of the stack.
   * Calling this method with an empty stack will throw an out of range
   * exception with an informative message of your choice.
   */
  void pop ();
  /**
  *A method that returns true if the stack is empty and otherwise false.
  */
  bool empty () const;
  /**
  *A method that returns how many items are inside the stack.
  */
  size_t size () const;
  /**
   * Method that return the item from the top of the stack, but do not remove
   * it from it.
   * Calling this method with an empty stack will throw an out of range
   * exception with an informative message of your choice.
   * @return refernce to the top most item
   */
  Apartment &top ();
  /**
   * Method that return the item from the top of the stack, but do not
   * remove it from it.
   * Calling this method with an empty stack will throw an out of range
   * exception with an informative message of your choice.
   * @return copy to the top most item
   */
  Apartment top () const;
  /**
   * The stack should support the Iterator (at least a forward Iterator) so
   * that the item at the top of the stack is the first item.
   */
  typedef Iterator iterator;
  typedef const_iterator const_iterator;
  Iterator begin ();
  Iterator end ();
  const_iterator begin () const;
  const_iterator end () const;
  const_iterator cbegin () const;
  const_iterator cend () const;
  /**
   * check if the vector is empty. throw an exception if yes.
   */
  void check_empty_vector () const;
  /**
   * print all apartments in the stack
   * @param os reference to os
   * @param stack reference stack
   */
  friend std::ostream &operator<< (std::ostream &os, Stack &stack);
};

#endif //_STACK_H_
