/******************************************************************************
\File point.cpp
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
#include "point.hpp"  // Point members
#include <cmath>      // sin, cos, sqrt
#include <iostream>

namespace hlp2 {

// define 2 constructors
    
    /*************************************************************************/
    /*! 
    \brief
        One of the two constructors of Point with 0 initializing the
        cartesian coordinates; A default constructor. Returns Point.

    \param x
        Initialized Point object with 0.

    \param y
        Initialized Point object with 0.
    */    
    /*************************************************************************/
    Point::Point() : x{}, y{} {}

    /*************************************************************************/
    /*! 
    \brief
        One of the two constructors of Point with corresponding input
        parameter values initializing the corresponding coordinates. Returns
        Point.

    \param x
        Cartesian point x; Initialized Point object with x.

    \param y
        Cartesian point y; Initialized Point object with y.
    */    
    /*************************************************************************/
    Point::Point(double x, double y) : x(x), y(y) {}

// define 8 member functions

    /*************************************************************************/
    /*! 
    \brief
        Takes in an intergal to be assessed against to determine which 
        coordinate to return; x or y. If the parameter is eqaul to 0, it 
        returns x, else y.

    \param i
        An intergral value used to check for the corresponding coordinate.
    */    
    /*************************************************************************/
	double& Point::operator[](int i) {
        return i == 0 ? this->x : this->y;
    }

    /*************************************************************************/
    /*! 
    \brief
        Takes in an intergal to be assessed against to determine which 
        coordinate to return; x or y. If the parameter is eqaul to 0, it 
        returns x, else y.

    \param x
        An intergral value used to check for the corresponding coordinate.
    */    
    /*************************************************************************/
	double const& Point::operator[](int i) const {
        return i == 0 ? this->x : this->y;
	}

    /*************************************************************************/
    /*! 
    \brief
        Returns a reference to Point. This function adds a double to the Point
        coordinates.

    \param rhs
        The double parameter to be added unto the Point object coordinates.
    */    
    /*************************************************************************/
	Point& Point::operator+=(double const rhs) {
        this->x += rhs;
        this->y += rhs;
        return *this;
    }

    /*************************************************************************/
    /*! 
    \brief
        Returns a reference to Point. This function adds the coordinates of the
        two Point.

    \param rhs
        The Point parameter to be added unto the Point object corresponding
        coordinates.
    */    
    /*************************************************************************/
	Point& Point::operator+=(Point const& rhs) {
        this->x += rhs[0];
        this->y += rhs[1];
        return *this; 
    }

    /*************************************************************************/
    /*! 
    \brief
        Returns a reference to Point. Performs pre-increment of the coordinates
        in the Point object.
    */    
    /*************************************************************************/
	Point& Point::operator++( ) {
        ++(this->x); ++(this->y);
        return *this;
    }

    /*************************************************************************/
    /*! 
    \brief
        Returns a pointer to Point. Performs post-increment of the coordinates
        in the Point object. int in the function parameter is used to identify
        post prefix.

    \param old
        Initialized with the reference to the Point. To contain and return the
        pointer to the Point.
    */    
    /*************************************************************************/
	Point const Point::operator++(int) {
        Point const old {*this};
        ++(this->x); ++(this->y);
        return old;
    }

    /*************************************************************************/
    /*! 
    \brief
        Returns a reference to Point. Performs pre-decrement of the coordinates
        in the Point object.
    */    
    /*************************************************************************/
	Point& Point::operator--( ) {
        --(this->x); --(this->y);
        return *this;
    }

    /*************************************************************************/
    /*! 
    \brief
        Returns a pointer to Point. Performs post-decrement of the coordinates
        in the Point object. int in the function parameter is used to identify
        post prefix.
        
    \param old
        Initialized with the reference to the Point. To contain and return the
        pointer to the Point.
    */    
    /*************************************************************************/
	Point const Point::operator--(int){
        Point const old {*this};
        --(this->x); --(this->y);
        return old;
    }

// define 15 non-member, non-friend functions

    /*************************************************************************/
    /*! 
    \brief
        Returns a pointer a Point. It takes in a read only Point and 
        double and rotates the Point coordinates about double degrees.

    \param lhs
        A reference to a read only Point containing the object coordinates.

    \param rhs
        The angle to be used for rotation of Point coordinates; in degrees.

    \param tmp
        To be returned. Contains the coordinates after rotation.

    \param angle
        The angle converted to radians for use in the cmath header functions.
    */    
    /*************************************************************************/
	Point operator%(Point const& lhs, double const rhs) {
        Point tmp;
        double angle = rhs * 3.14159 / 180;
        tmp[0] = lhs[1] * cos(angle) - lhs[0] * sin(angle);
        tmp[1] = lhs[0] * cos(angle) + lhs[1] * sin(angle);
        tmp[0] = (tmp[0] <= 0 && tmp[0] > -0.0009) ? 0 : tmp[0];
        tmp[1] = (tmp[1] <= 0 && tmp[1] > -0.0009) ? 0 : tmp[1];
        return tmp;
    }

    /*************************************************************************/
    /*! 
    \brief
        Returns a double containing the distance between two Points.

    \param lhs
        A reference to the first read only Point containing the object 
        coordinates.

    \param rhs
        A reference to the second read only Point containing the object 
        coordinates.

    \param distance
        To be returned. Contains the distance of the two Points.

    \param hori
        The distance between the two horizontal-axis coordinates.

    \param verti
        The distance between the two vertical-axis coordinates.
    */    
    /*************************************************************************/
	double operator/(Point const& lhs, Point const& rhs) {
        double distance, hori, verti;
        hori = abs(lhs[0] - rhs[0]);
        verti = abs(lhs[1] - rhs[1]);
        return distance = sqrt( pow(hori, 2.0) + pow(verti, 2.0));
    }

    /*************************************************************************/
    /*! 
    \brief
        Returns a pointer to the sum of the two corresponding Point 
        coordinates.

    \param lhs
        A reference to the first read only Point containing the object 
        coordinates.

    \param rhs
        A reference to the second read only Point containing the object 
        coordinates.
    */    
    /*************************************************************************/
	Point operator+(Point const& lhs, Point const& rhs) {
        return Point(lhs[0] + rhs[0], lhs[1] + rhs[1]);
    }

    /*************************************************************************/
    /*! 
    \brief
        Returns a pointer to the sum of a corresponding Point coordinates and 
        a type double value.

    \param lhs
        A reference to the read only Point containing the object coordinates.

    \param rhs
        A reference to theread only double to increment the Point object.
    */    
    /*************************************************************************/
	Point operator+(Point const& lhs, double const& rhs) {
        return Point(lhs[0] + rhs, lhs[1] + rhs);
    }

    /*************************************************************************/
    /*! 
    \brief
        Returns a pointer to the sum of a type double value and a 
        corresponding Point coordinates.

    \param lhs
        A reference to the second read only double to increment the Point 
        object.

    \param rhs
        A reference to the read only Point containing the object coordinates.
    */    
    /*************************************************************************/
	Point operator+(double const& lhs, Point const& rhs) {
        return Point(rhs[0] + lhs, rhs[1] + lhs);
    }

    /*************************************************************************/
    /*! 
    \brief
        Returns a pointer to the subtraction of the two corresponding Point 
        coordinates.

    \param lhs
        A reference to the first read only Point containing the object 
        coordinates.

    \param rhs
        A reference to the second read only Point containing the object 
        coordinates.
    */    
    /*************************************************************************/
	Point operator-(Point const& lhs, Point const& rhs) {
        return Point(lhs[0] - rhs[0], lhs[1] - rhs[1]);
    }

	/*************************************************************************/
    /*! 
    \brief
        Returns a pointer to the subtraction of a corresponding Point 
        coordinates and a type double value.

    \param lhs
        A reference to the read only Point containing the object coordinates.

    \param rhs
        A reference to the read only double to increment the Point object.
    */    
    /*************************************************************************/
	Point operator-(Point const& lhs, double const& rhs) {
        return Point(lhs[0] - rhs, lhs[1] - rhs);
    }

	/*************************************************************************/
    /*! 
    \brief
        Returns a pointer to the subtraction of a type double value and a 
        corresponding Point coordinates.

    \param lhs
        A reference to the read only double to increment the Point object.

    \param rhs
        A reference to the read only Point containing the object coordinates.
    */    
    /*************************************************************************/
	Point operator-(double const& lhs, Point const& rhs) {
        return Point(lhs - rhs[0], lhs - rhs[1]);
    }

	/*************************************************************************/
    /*! 
    \brief
        Takes in the reference to Point and negates the objects inside and 
        returns a pointer to Point.

    \param rhs
        A reference to the read only Point containing the object coordinates.
    */    
    /*************************************************************************/
	Point operator-(Point const& rhs) {
        return Point(-rhs[0], -rhs[1]);
    }

	/*************************************************************************/
    /*! 
    \brief
        Returns a pointer after averaging out the corresponding points in the 
        Point object in the function parameter.

    \param lhs
        A reference to the first read only Point containing the object 
        coordinates.

    \param rhs
        A reference to the second read only Point containing the object 
        coordinates.
    */    
    /*************************************************************************/
	Point operator^(Point const& lhs, Point const& rhs) {
        return Point((lhs[0] + rhs[0]) / 2, (lhs[1] + rhs[1]) / 2);
    }

	/*************************************************************************/
    /*! 
    \brief
        Returns a double of a sum of the product of the corresponding points.

    \param lhs
        A reference to the first read only Point containing the object 
        coordinates.

    \param rhs
        A reference to the second read only Point containing the object 
        coordinates.
    */    
    /*************************************************************************/
	double operator*(Point const& lhs, Point const& rhs) {
        double sum {lhs[0] * rhs[0]};
        return sum += lhs[1] * rhs[1];
    }

	/*************************************************************************/
    /*! 
    \brief
        Returns a pointer of Point after multiplying the Point objects with the
        double in the parameter.

    \param lhs
        A reference to the read only double to increment the Point object.

    \param rhs
        Contains a double that the object coordinates will be multiplied with.
    */    
    /*************************************************************************/
	Point operator*(Point const& lhs, double rhs) {
        return Point(lhs[0]*rhs, lhs[1]*rhs);
    }

	/*************************************************************************/
    /*! 
    \brief
        Returns a pointer of Point after multiplying the Point objects with the
        double in the parameter.

    \param lhs
        Contains a double that the object coordinates will be multiplied with.

    \param rhs
        A reference to the read only double to increment the Point object.
    */    
    /*************************************************************************/
	Point operator*(double lhs, Point const& rhs) {
        return Point(rhs[0]*lhs, rhs[1]*lhs);
    }

	/*************************************************************************/
    /*! 
    \brief
        Returns a refernce to the ostream at the end of execution. Prints out 
        the Point coordinates like "(x, y)".

    \param os
        Contains the reference to the ouput stream.

    \param rhs
        A reference to the Point object to be printed.
    */    
    /*************************************************************************/
	std::ostream& operator<<(std::ostream& os, Point const& rhs) {
        os << "(" << rhs[0] << ", " << rhs[1] << ")";
        return os;
    }

	/*************************************************************************/
    /*! 
    \brief
        Returns a reference to the istream at the end of execution. Receives 
        input from istream and assigns the Point corresponding object.

    \param is
        Contains the reference to the input stream.

    \param rhs
        A reference to the Point object that is to be assigned to.
    */    
    /*************************************************************************/
	std::istream& operator>>(std::istream& is, Point& rhs) {
        is >> rhs[0] >> rhs[1];
        return is;
    } 

} // end hlp2 namespace
