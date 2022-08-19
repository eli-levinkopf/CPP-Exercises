//
// Created by Eli Levinkopf on 20/12/2021.
//

#include "Apartment.h"
#include "Stack.h"
#include "AVL1.h"

//void print_stack (const Stack &stack)
//{
//  std::cout << "my stack:" << std::endl;
//  for (auto apartment: stack._apartments)
//	{
//	  std::cout << "\t" << apartment;
//	}
//}
typedef std::pair<double, double> double_pair;
AVL func ();
Apartment
create_apartment_and_insert (AVL &avl, const double_pair &coordinates)
{
  Apartment apt (coordinates);
  avl.insert (apt);
  return apt;
}

int main ()
{
//  std::pair<double, double> pair1;
//  std::pair<double, double> pair2;
//  pair1.first = 1.1, pair1.second = 2.2;
//  pair2.first = 1.1 + EPSILON, pair2.second = 2.2 - EPSILON;
//  Apartment apartment1 (pair1);
//  Apartment apartment2 (pair2);
////  std::cout << "x: " << apartment1.get_x () << " y: " << apartment1.get_y ()
////			<< std::endl;
////  std::cout << "> " << (apartment1 > apartment2) << std::endl;
////  std::cout << "== " << (apartment1 == apartment2) << std::endl;
////  std::cout << apartment1;
////  std::cout << apartment2;
////  =================================
//  std::vector<std::pair<double, double>> coordinates;
//  for (int i = 0; i < 10; ++i)
//	{
//	  std::pair<double, double> cur_pair;
//	  cur_pair.first = (double)i, cur_pair.second = (double)i;
//	  coordinates.push_back (cur_pair);
//	}
//  Stack my_stack (coordinates);
////  print_stack (my_stack);
//  const Stack my_const_stack (coordinates);
//  std::cout << "size: " << my_stack.size () << std::endl;
//
////  print_stack (my_stack);
//  for (int i = 0; i < 2; ++i)
//	{
//	  try
//		{
//		  my_stack.pop ();
//		}
//	  catch (const std::out_of_range &e)
//		{
//		  std::cerr<<e.what()<<std::endl;
////		  exit(EXIT_FAILURE);
//		}
//	}
//
//  std::cout << "=============" << std::endl;
//
//  print_stack (my_stack);
//  std::cout << "size: "<<my_stack.size () << std::endl;
////
//  std::cout << "empty: " << my_stack.empty () << std::endl;
//  try
//	{
//	  std::cout << "top element: " << my_const_stack.top ();
//	}
//  catch (const std::out_of_range &e)
//	{
//	  std::cerr << e.what () << std::endl;
//	}
//  print_stack (my_const_stack);

//for (auto it: my_stack){
//	std::cout << it.first<<","<<it.second << " ";
//}

//  for (auto it = l.begin (); it != l.end (); ++it)
//	{
//	  linked_list::iterator::value_type val = *it;
//	  std::cout << val << " ";
//	}


//  for (auto it: my_stack)
//	{ std::cout << it << std::endl; }

AVL avl = func();
std::cout<<avl.root_->data_;

  return 0;
}

AVL func ()
{
  AVL avl;

  Apartment apt1 ({0, 0});
  auto *node = new AVL::node(apt1);
  Apartment apt2 ({1, 1});
  avl.insert(apt1);
  avl.root_->left_ = node;
//  delete node;
  return  avl;
}


//// C++ program to illustrate the
//// capacity function in vector
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//  vector<int> g1;
//
//  for (int i = 1; i <= 23; i++)
//	g1.push_back(i);
//
//  cout << "Size : " << g1.size();
//  cout << "\nCapacity : " << g1.capacity();
//  cout << "\nMax_Size : " << g1.max_size();
//
//  // resizes the vector size to 4
//  g1.resize(4);
//
//  // prints the vector size after resize()
//  cout << "\nSize : " << g1.size();
//
//  // checks if the vector is empty or not
//  if (g1.empty() == false)
//	cout << "\nVector is not empty";
//  else
//	cout << "\nVector is empty";
//
//  // Shrinks the vector
//  g1.shrink_to_fit();
//  cout << "\nVector elements are: ";
//  for (auto it = g1.begin(); it != g1.end(); it++)
//	cout << *it << " ";

//  return 0;
//}
