//
// Created by Eli Levinkopf on 20/12/2021.
//

#include "Apartment.h"

Apartment::Apartment (const std::pair<double, double> &Coordinates)
	: _x (Coordinates.first), _y (Coordinates.second)
{
}

double Apartment::get_x () const
{
  return _x;
}

double Apartment::get_y () const
{
  return _y;
}

bool Apartment::operator< (const Apartment &other) const
{
  return !((*this) == other) && (get_dist (*this) < get_dist (other));
}

bool Apartment::operator> (const Apartment &other) const
{
  return !((*this) == other) && (get_dist (*this) > get_dist (other));
}

double Apartment::get_dist (const Apartment &apartment) const
{
  return sqrt (pow (apartment.get_x () - X_FEEL_BOX, 2)
			   + pow (apartment.get_y () - Y_FEEL_BOX, 2));
}

bool Apartment::operator== (const Apartment &other) const
{
  return ((other.get_x () - EPSILON <= _x) && (_x <= other.get_x () + EPSILON)
		  && (other.get_y () - EPSILON <= _y)
		  && (_y <= other.get_y () + EPSILON));
}

std::ostream &operator<< (std::ostream &os, const Apartment &apartment)
{
  std::cout << "(" << apartment.get_x () << "," << apartment.get_y () << ")"
			<< std::endl;
  return os;
}
