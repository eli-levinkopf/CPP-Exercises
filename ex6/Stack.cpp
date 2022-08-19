//
// Created by Eli Levinkopf on 20/12/2021.
//

#include "Stack.h"

#define ERROR_MESSAGE "Error: the stack is empty. An empty Stack "\
                               "is an invalid input for top() and pop()"\
                               " functions\n"

Stack::Stack () : _head (nullptr)
{}

Stack::Stack (std::vector<std::pair<double, double>> coordinates)
	: _head (nullptr)
{
  for (auto pair: coordinates)
	{
	  push (pair);
	}
}

Stack::Stack (const Stack &other) : _head (nullptr)
{
  std::list<Apartment> reverse_apartments_list = other._apartments;
  reverse_apartments_list.reverse();
  for (Apartment apt: reverse_apartments_list)
	{
	  push (apt);
	}
}

Stack &Stack::operator= (const Stack &rhs)
{
  std::list<Apartment> reverse_apartments_list = rhs._apartments;
  reverse_apartments_list.reverse();
  for (Apartment apartment: reverse_apartments_list)
	{
	  std::pair<double, double> new_pair;
	  new_pair.first = apartment.get_x ();
	  new_pair.second = apartment.get_y ();
	  new_pair = {apartment.get_x (), apartment.get_y ()};
	  push (new_pair);
	}
  return *this;
}

Stack::~Stack ()
{
  while (!_apartments.empty ())
	{
	  _apartments.pop_front ();
	}
  delete _head;
}

void Stack::push (const Apartment &apartment)
{
  std::pair<double, double> pair;
  pair.first = apartment.get_x ();
  pair.second = apartment.get_y ();
  _head = new node (_head, pair);
  _apartments.insert (_apartments.begin (), pair);
}

void Stack::pop ()
{
  check_empty_vector ();
  _apartments.pop_front ();
}

void Stack::check_empty_vector () const
{
  if (_apartments.empty ())
	{
	  throw std::out_of_range (ERROR_MESSAGE);
	}
}
bool Stack::empty () const
{ return _apartments.empty (); }

size_t Stack::size () const
{ return _apartments.size (); }

Apartment &Stack::top ()
{
  check_empty_vector ();
  return _apartments.front ();
}
Apartment Stack::top () const
{
  check_empty_vector ();
  std::pair<double, double> pair;
  pair.first = _apartments.front ().get_x ();
  pair.second = _apartments.front ().get_y ();
  return pair;
}

std::ostream &operator<< (std::ostream &os, Stack &stack)
{
  for (auto it = stack.begin (); it != stack.end (); ++it)
	{
	  Stack::Iterator::value_type val = *it;
	  std::cout << val << std::endl;
	}
  return os;
}

Stack::Iterator Stack::begin ()
{ return _head; }

Stack::Iterator Stack::end ()
{ return {nullptr}; }

Stack::const_iterator Stack::begin () const
{ return _head; }

Stack::const_iterator Stack::end () const
{ return {nullptr}; }

Stack::const_iterator Stack::cbegin () const
{ return _head; }

Stack::const_iterator Stack::cend () const
{ return {nullptr}; }

//****************************************//
//*************** Iterator ***************//
//****************************************//

Stack::Iterator::Iterator (Stack::node *cur_apartment)
	: _cur_apartment (cur_apartment)
{}

Stack::Iterator::pointer Stack::Iterator::operator-> ()
{ return &_cur_apartment->_data_pair; }

Apartment &Stack::Iterator::operator* ()
{ return _cur_apartment->_data_pair; }

Stack::Iterator &Stack::Iterator::operator++ ()
{
  _cur_apartment = _cur_apartment->_next;
  return *this;
}

Stack::Iterator Stack::Iterator::operator++ (int)
{
  Iterator it = *this;
  _cur_apartment = _cur_apartment->_next;
  return it;
}

bool Stack::Iterator::operator== (const Stack::Iterator &rhs) const
{ return _cur_apartment == rhs._cur_apartment; }

bool Stack::Iterator::operator!= (const Stack::Iterator &rhs) const
{ return !(*this == rhs); }


//****************************************//
//*************** Const Iterator *********//
//****************************************//

Stack::const_iterator::const_iterator (Stack::node *cur_apartment)
	: _cur_apartment (cur_apartment)
{}

Stack::const_iterator::const_iterator (const Stack::Iterator &it)
	: _cur_apartment (it._cur_apartment)
{}

Stack::const_iterator::pointer Stack::const_iterator::operator-> ()
{ return &_cur_apartment->_data_pair; }

const Apartment &Stack::const_iterator::operator* ()
{ return _cur_apartment->_data_pair; }

Stack::const_iterator &Stack::const_iterator::operator++ ()
{
  _cur_apartment = _cur_apartment->_next;
  return *this;
}

Stack::const_iterator Stack::const_iterator::operator++ (int)
{
  const_iterator it = *this;
  _cur_apartment = _cur_apartment->_next;
  return it;
}

bool Stack::const_iterator::operator== (const Stack::const_iterator &rhs) const
{ return _cur_apartment == rhs._cur_apartment; }

bool Stack::const_iterator::operator!= (const Stack::const_iterator &rhs) const
{ return !(*this == rhs); }


