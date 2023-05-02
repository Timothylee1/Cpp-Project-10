/******************************************************************************
\File point.hpp
\Author Timothy Lee Ke xin
\Par DP email: timothykexin.lee@digipen.edu.sg
\Par Course: RSE 1202
\Par Section: Constructors and Operator Overloading
\Par Programming Lab #5
\Date 10-02-2022

  \Brief
   The aim of this lab is to gain experience in class design and implementaion
   of complete class, constrcutors, and overloading constructors. This program
   has 2 constructors, 8 member operators, and 15 non-member non-friend 
   functions. There will be no use of destructors or new and delete operators 
   or their counterparts. The user/client can use these minimal yet versatile 
   interface to create new operations that involve the class in use, Point that
   has the cartesian coordinates system. From there the points can be 
   incremented, decremented, rotated, negated, added, subtracted, and 
   multiplied. It can also be used to find distance between, mid point, and dot
   product. The file additionally contains iostream overloads.

-Constructors
  - Point()
      One of the two constructors of Point with 0 initialized the
      cartesian coordinates; A default constructor. Returns Point.
   
  - Point(double, double)
      One of the two constructors of Point with corresponding input
      parameter values initializing the corresponding coordinates. Returns 
      Point.

-Member functions   
  - operator[]
      Takes in an intergal to be assessed against to determine which coordinate
      to return; x or y. If the parameter is eqaul to 0, it returns x, else y.
   
  - const operator[]
      An overload of the subscript operator, much like the previous function.
      However, it acts like p1[0][1]. If the parameter is equal to 0, it 
      returns x, else y;
   
  - operator+=
      Returns a reference to Point. This function adds a double to the Point
      coordinates.
   
  - operator+=
      Returns a reference to Point. This function adds the coordinates of the
      two Point.
   
  - operator++
      Returns a reference to Point. Performs pre-increment of the coordinates
      in the Point object.
   
  - operator++
      Returns a pointer to Point. Performs post-increment of the coordinates
      in the Point object. int in the function parameter is used to identify
        post prefix.
   
  - operator--
      Returns a reference to Point. Performs pre-decrement of the coordinates
      in the Point object.
   
  - operator--
      Returns a pointer to Point. Performs post-decrement of the coordinates
      in the Point object. int in the function parameter is used to identify
        post prefix.

-Non-member non-friend functions
  - operator%
      Returns a pointer to a Point. It takes in a read only Point and double
      and rotates the Point coordinates about double degrees.

  - operator/
      Returns a double containing the distance between two Points.
      
  - operator+
      Returns a pointer to the sum of the two corresponding Point 
      coordinates.

  - operator+
      Returns a pointer to the sum of a corresponding Point coordinates and 
      an type double value.

  - operator+
      Returns a pointer to the sum of an type double value and a 
      corresponding Point coordinates.
      
  - operator-
      Returns a pointer to the subtraction of the two corresponding Point 
      coordinates.

  - operator-
      Returns a pointer to the subtraction of a corresponding Point coordinates
      and an type double value.

  - operator-
      Returns a pointer to the subtraction of an type double value and a 
      corresponding Point coordinates.
 
  - operator-
      Takes in the reference to Point and negates the objects inside and 
      returns a pointer to Point.
 
  - operator^
      Returns a pointer after averaging out the corresponding points in the 
      Point object in the function parameter.
 
  - operator*
      Returns a double of a sum of the product of the corresponding points.

  - operator*
      Returns a pointer of Point after multiplying the Point objects with the
      double in the parameter.   

  - operator*
      Returns a pointer of Point after multiplying the double in the parameter 
      with the Point objects.

  - operator<<
      Returns a refernce to the ostream at the end of execution. Prints out the
      Point coordinates like "(x, y)".
 
  - operator>>
      Returns a reference to the istream at the end of execution. Receives 
      input from istream and assigns the Point corresponding object.
******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
#ifndef POINT_HPP
#define POINT_HPP
////////////////////////////////////////////////////////////////////////////////
#include <iostream> // istream, ostream
//#include <cstddef>

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
	Point operator%(Point const&, double const);
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
	
	