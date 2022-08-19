////
//// Created by Eli Levinkopf on 20/12/2021.
////
//
////
//// Created by Eli Levinkopf on 20/12/2021.
////
//
//#include "Stack_1.h"
//
////Stack::Stack () : _apartments ()
////{}
//
//Stack::Stack ()
//{}
//
//Stack::Stack (std::vector<std::pair<double, double>> coordinates)
//{
//  for (auto pair: coordinates)
//	{
//	  Apartment cur_apartment (pair);
//	  push (cur_apartment);
//	}
//}
//
//void Stack::push (const Apartment &apartment)
//{ _apartments.insert (_apartments.begin (), apartment); }
//
//void Stack::pop ()
//{
//  check_empty_vector ();
//  _apartments.erase (_apartments.begin ());
//}
//
//void Stack::check_empty_vector () const
//{
//  if (_apartments.empty ())
//	{
//	  throw std::out_of_range ("Error: the stack is empty. An empty Stack is an invalid input for top() and pop() functions\n");
//	}
//}
//
//bool Stack::empty () const
//{ return _apartments.empty (); }
//
//size_t Stack::size () const
//{ return _apartments.size (); }
//
//Apartment &Stack::top ()
//{
//  check_empty_vector ();
//  return _apartments.front ();
//}
//
//Apartment Stack::top () const
//{
//  check_empty_vector ();
//  std::pair<double, double> pair;
//  pair.first = _apartments.front ().get_x ();
//  pair.second = _apartments.front ().get_y ();
//  return pair;
//}
//
//Apartment &Stack::get_next ()
//{
//  return _apartments[index++];
//}
//
//
////============================= iterator
////Stack::iterator::iterator (Stack& stack) : _it(stack._apartments.begin ())
////{}
//Stack::iterator::iterator (Apartment &apartment)
//	: _apartment (apartment), _idx (0), _next(apartment)
//{}
//
//
//Stack::iterator::pointer Stack::iterator::operator-> ()
//{ return &_apartment; }
//
//Apartment &Stack::iterator::operator* ()
//{ return _apartment; }
//
//
//Stack::iterator &Stack::iterator::operator++ ()
//{
//  _apartment = _apartments[++_idx];
//  return *this;
//}
//
//
////Stack::iterator Stack::iterator::operator++ (int)
////{
////  iterator it = *this;
////  _apartment = _apartments[++_idx];
////  return it;
////}
//
//bool Stack::iterator::operator== (const Stack::iterator &rhs) const
//{ return _apartment == rhs._apartment; }
//
//bool Stack::iterator::operator!= (const Stack::iterator &rhs) const
//{ return !(*this == rhs); }
//
//Stack::iterator Stack::begin ()
//{ return _apartments[0]; }
//
//Stack::iterator Stack::end ()
//{ return _apartments[size ()]; }
//
//


////==================================
//AVL::node *AVL::node::insert (AVL::node *new_node)
//{
//  if ((this) == nullptr)
//	{
//	  return new_node;
//	}
//  else if (data_ > new_node->get_data ())
//	{
////	  if (left_)
////		{
//	  left_ = left_->insert (new_node);
////		}
////	  else
////	  {
////	  left_ = new_node;
////	  }
//	}
//  else if (data_ < new_node->get_data ())
//	{
////	  if (right_)
////		{
//	  right_ = right_->insert (new_node);
////		}
////	  else
////	  {
////		right_ = new_node;
////	  }
//	}
//  else
//	{
//	  return this;
//	}
////	2
//  set_height ();
//// 3
//  return avl_balance (new_node);
//}
////========================
