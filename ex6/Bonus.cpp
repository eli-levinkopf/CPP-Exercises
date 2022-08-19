//
// Created by Eli Levinkopf on 28/12/2021.
//

#include <utility>

#include "MesureTimeHelper.h"
#include <chrono>
#include "Apartment.h"
#include "AVL.h"
#include "Stack.h"
#include "Find.h"

#define APARTMENT_X_X = 31.81428051893798
#define APARTMENT_X_Y = 35.18577781093502

/**
 *  Insert the apartments form the vector to the stack and search the apartment
 *  in the stack
 * @param apartment reference to an apartment
 * @param pairs_vector reference to vector of coordinates
 */
void
insert_and_search_stack (const Apartment &apartment, std::vector<std::pair<
	double, double>> &pairs_vector);
/**
 *  Insert the apartments form the vector to the AVL and search the apartment
 *  in the AVL
 * @param apartment reference to an apartment
 * @param pairs_vector reference to vector of coordinates
 */
void insert_and_search_avl (const Apartment &apartment, std::vector<std::pair<
	double, double>> &pairs_vector);
/**
 *  Insert the apartments form the vector to the set and search the apartment
 *  in the set
 * @param apartment reference to an apartment
 * @param pairs_vector reference to vector of coordinates
 */
void
insert_and_search_set (const Apartment &apartment, const std::vector<std::pair<
	double, double>>& pairs_vector);

void search_apartment (std::string &file_path)
{
  std::vector<std::pair<double,
  double>> pairs_vector = xy_from_file (file_path);
  std::pair<double, double> pair_x{31.81428051893798,
								   35.18577781093502};
  const Apartment apartment_x (pair_x);

  insert_and_search_stack (apartment_x, pairs_vector);
  insert_and_search_avl (apartment_x, pairs_vector);
  insert_and_search_set (apartment_x, pairs_vector);

}

void
insert_and_search_set (const Apartment &apartment, const std::vector<std::pair<
	double, double>>& pairs_vector)
{

  std::unordered_set<Apartment, MyHashFunction> my_set;
  //  Insert the apartments
  auto t1_insert_to_set = std::chrono::high_resolution_clock::now ();
  for (auto &pair: pairs_vector)
	{
	  Apartment cur_apartment (pair);
	  my_set.insert (cur_apartment);
	}
  auto t2_insert_to_set = std::chrono::high_resolution_clock::now ();

  //  search with general find
  auto first_set = my_set.begin (), end_set = my_set.end ();
  auto t1_find_in_set = std::chrono::high_resolution_clock::now ();
  find (first_set, end_set, apartment);
  auto t2_find_in_set = std::chrono::high_resolution_clock::now ();

  //  search with set find
  auto t1_set_find = std::chrono::high_resolution_clock::now ();
  my_set.find (apartment);
  auto t2_set_find = std::chrono::high_resolution_clock::now ();

  auto t_insert_to_set = std::chrono::duration_cast<std::chrono::nanoseconds> (
	  t2_insert_to_set - t1_insert_to_set).count ();
  auto t_general_find_in_set = std::chrono::duration_cast<std::chrono::
	  nanoseconds> (t2_find_in_set - t1_find_in_set).count ();
  auto t_set_find = std::chrono::duration_cast<std::chrono::nanoseconds> (
	  t2_set_find - t1_set_find).count ();

  std::cout << "t_insert_to_set: " << t_insert_to_set << std::endl;
  std::cout << "t_general_find_in_set: " << t_general_find_in_set << std::endl;
  std::cout << "t_set_find: " << t_set_find << std::endl;

}

void insert_and_search_avl (const Apartment &apartment, std::vector<std::pair<
	double,
	double>> &pairs_vector)
{
  //  Insert the apartments
  auto t1_insert_to_avl = std::chrono::high_resolution_clock::now ();
  AVL my_avl (pairs_vector);
  auto t2_insert_to_avl = std::chrono::high_resolution_clock::now ();

//  search with general find
  auto first_avl = my_avl.begin (), end_avl = my_avl.end ();
  auto t1_find_in_avl = std::chrono::high_resolution_clock::now ();
  find (first_avl, end_avl, apartment);
  auto t2_find_in_avl = std::chrono::high_resolution_clock::now ();

//  search with avl find
  auto t1_avl_find = std::chrono::high_resolution_clock::now ();
  my_avl.find (apartment);
  auto t2_avl_find = std::chrono::high_resolution_clock::now ();

  auto t_insert_to_avl = std::chrono::duration_cast<std::chrono::nanoseconds> (
	  t2_insert_to_avl - t1_insert_to_avl).count ();
  auto t_general_find_in_avl = std::chrono::duration_cast<std::chrono::
	  nanoseconds> (t2_find_in_avl - t1_find_in_avl).count ();
  auto t_avl_find = std::chrono::duration_cast<std::chrono::nanoseconds> (
	  t2_avl_find - t1_avl_find).count ();

  std::cout << "t_insert_to_avl: " << t_insert_to_avl << std::endl;
  std::cout << "t_general_find_in_avl: " << t_general_find_in_avl << std::endl;
  std::cout << "t_avl_find: " << t_avl_find << std::endl;
}

void
insert_and_search_stack (const Apartment &apartment, std::vector<std::pair<
	double,
	double>> &pairs_vector)
{
  //  Insert the apartments
  auto t1_insert_to_stack = std::chrono::high_resolution_clock::now ();
  Stack my_stack (pairs_vector);
  auto t2_insert_to_stack = std::chrono::high_resolution_clock::now ();

  //  search with general find
  auto first_stack = my_stack.begin (), end_stack = my_stack.end ();
  auto t1_find_in_stack = std::chrono::high_resolution_clock::now ();
  find (first_stack, end_stack, apartment);
  auto t2_find_in_stack = std::chrono::high_resolution_clock::now ();

  auto t_insert_to_stack = std::chrono::duration_cast<std::chrono::
	  nanoseconds> (t2_insert_to_stack - t1_insert_to_stack).count ();
  auto t_general_find_in_stack = std::chrono::duration_cast<std::chrono::
	  nanoseconds> (t2_find_in_stack - t1_find_in_stack).count ();

  std::cout << "t_insert_to_stack: " << t_insert_to_stack << std::endl;
  std::cout << "t_general_find_in_stack: " << t_general_find_in_stack <<
  std::endl;

}
