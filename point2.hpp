// make sure to provide file-level documentation and function-level
// documentation for each function that you'll implement to avoid
// unnecessary grade deductions.

////////////////////////////////////////////////////////////////////////////////
#ifndef POINT_HPP
#define POINT_HPP
////////////////////////////////////////////////////////////////////////////////

#include <iostream> // istream, ostream
#include <cstddef>

namespace hlp2 {
	
class Point {
public:
	// declare constructors (2)
	Point(); //default ctor
	Point(double, double); //dbl-arg ctor

	// declare overloaded operators (8 member functions)
	double& operator[](int i);
	double const& operator[](int i) const ;
	Point& operator+=(double const);
	Point& operator+=(Point const&);
	Point& operator++(); //pre
	Point const operator++(int); //post
	Point& operator--(); //pre
	Point const operator--(int); //post

private:
	double x; // The x-coordinate of a Point
	double y; // The y-coordinate of a Point
};
  
	// declare 15 non-member, non-friend functions 
	Point operator%(Point const&, double const&);
	double operator/(Point const&, Point const&);
	Point operator+(Point const&, Point const&);
	Point operator+(Point const&, double const&);
	Point operator+(double const&, Point const&);
	Point operator-(Point const&, Point const&);	
	Point operator-(Point const&, double const&);
	Point operator-(double const&, Point const&);
	Point operator-(Point const&);
	Point operator^(Point const&, Point const&);
	double operator*(Point const&, Point const&);
	Point operator*(Point const&, double);
	Point operator*(double, Point const&);
	std::ostream& operator<<(std::ostream&, Point const&);
	std::istream& operator>>(std::istream&, Point&);





} // end namespace hlp2

#endif // end POINT_HPP
////////////////////////////////////////////////////////////////////////////////
	
	