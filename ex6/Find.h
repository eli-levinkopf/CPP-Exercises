//
// Created by rotem on 21/09/2021.
//

#ifndef _FIND_H_
#define _FIND_H_
#include <vector>
#include <cstddef>
#include <unordered_set>
#include <string>
#include <chrono>
#include <iostream>
#include <ostream>
#include <fstream>
#include "Apartment.h"
#include "AVL.h"
#include "Stack.h"
#include <sstream>
#include "Find.h"
#include <iostream>
#include <unordered_set>
/**
 *  The function returns an Iterator to the item that corresponds to the item
 * we were looking for. If there is no such member, returns end ().
 * @tparam InputIt template
 * @param first Pointer to the beginning of the iterator
 * @param last Pointer to the end of the iterator
 * @param value value to find
 * @return Pointer to an iterator to the item that corresponds to the item
 * we were looking for. If there is no such member, returns end ()
 */
template<class InputIt>
InputIt find (InputIt first, InputIt last, const Apartment &value)
{
  for (auto &it = first; it != last; ++it)
	{
	  if (*it == value)
		{
		  return it;
		}
	  if (it == last)
		{
		  return last;
		}
	}
  return last;
}
#endif //_FIND_H_
