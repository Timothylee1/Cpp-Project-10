// since clients won't have access to this file, you don't have
// to provide comments ...

#include "point.hpp"  // Point members
#include <cmath>      // sin, cos, sqrt

///////////////////////////////////////////////////////////////////////////////
// declare private stuff here [if any] in this anonymous namespace ...
namespace {

}

///////////////////////////////////////////////////////////////////////////////

namespace hlp2 {

// define 2 constructors
    Point::Point() : x{}, y{} {}
    Point::Point(double x, double y) : x(x), y(y) {}

// define 8 member functions
	double& Point::operator[](int i) {
        return i == 0 ? this->x : this->y;
    }

	double const& Point::operator[](int i) const {
        return i == 0 ? this->x : this->y;
	}

	Point& Point::operator+=(double const rhs) {
        this->x += rhs;
        this->y += rhs;
        return *this;
    }

	Point& Point::operator+=(Point const& rhs) {
        this->x += rhs[0];
        this->y += rhs[1];
        return *this; 
    }

	Point& Point::operator++( ) {
        ++(this->x); ++(this->y);
        return *this;
    }

	Point const Point::operator++(int) {
        Point const old {*this};
        ++(this->x); ++(this->y);
        return old;
    }

	Point& Point::operator--( ) {
        --(this->x); --(this->y);
        return *this;
    }

	Point const Point::operator--(int){
        Point const old {*this};
        --(this->x); --(this->y);
        return old;
    }

// define 15 non-member, non-friend functions
	Point operator%(Point const& lhs, double const& rhs) {
        Point tmp{lhs};
        tmp[0] = lhs[0] * cos(rhs) - lhs[1] * sin(rhs);
        tmp[1] = lhs[0] * sin(rhs) + lhs[1] * cos(rhs);
        return tmp;
    }

	double operator/(Point const& lhs, Point const& rhs) {
        double sum, hori, verti;
        hori = abs(lhs[0] - rhs[0]);
        verti = abs(lhs[1] - rhs[1]);
        return sum = sqrt( pow(hori, 2.0) + pow(verti, 2.0));
    }

	Point operator+(Point const& lhs, Point const& rhs) {
        Point tmp{lhs};
        tmp[0] = lhs[0] + rhs[0];
        tmp[1] = lhs[1] + rhs[1];
        return tmp; 
    }

	Point operator+(Point const& lhs, double const& rhs) {
        Point tmp{lhs};
        tmp[0] = lhs[0] + rhs;
        tmp[1] = lhs[1] + rhs;
        return tmp; 
    }

	Point operator+(double const& lhs, Point const& rhs) {
        Point tmp{rhs};
        tmp[0] = lhs + rhs[0];
        tmp[1] = lhs + rhs[1];
        return tmp; 
    }

	Point operator-(Point const& lhs, Point const& rhs) {
        Point tmp{lhs};
        tmp[0] = lhs[0] - rhs[0];
        tmp[1] = lhs[1] - rhs[1];
        return tmp; 
    }

	Point operator-(Point const& lhs, double const& rhs) {
        Point tmp{lhs};
        tmp[0] = lhs[0] - rhs;
        tmp[1] = lhs[1] - rhs;
        return tmp; 
    }

	Point operator-(double const& lhs, Point const& rhs) {
        Point tmp{rhs};
        tmp[0] = lhs - rhs[0];
        tmp[1] = lhs - rhs[1];
        return tmp;
    }

	Point operator-(Point const& rhs) {
        Point tmp{rhs};
        tmp[0] = -rhs[0];
        tmp[1] = -rhs[1];
        return tmp; 
    }

	Point operator^(Point const& lhs, Point const& rhs) {
        Point tmp{lhs};
        tmp[0]= (lhs[0] + rhs[0]) / 2;
        tmp[1] = (lhs[1] + rhs[1]) / 2;
        return tmp;
    }

	double operator*(Point const& lhs, Point const& rhs) {
        double sum {lhs[0] * rhs[0]};
        return sum += rhs[1] * rhs[1];
    }

	Point operator*(Point const& lhs, double rhs) {
        Point tmp{lhs};
        tmp[0] = lhs[0] * rhs;
        tmp[1] = lhs[1] * rhs;
        return tmp;
    }

	Point operator*(double lhs, Point const& rhs) {
        Point tmp(rhs[0]*lhs, rhs[1]*lhs);
        return tmp;
    }

	std::ostream& operator<<(std::ostream& os, Point const& rhs) {
        os << "(" << rhs[0] << "," << rhs[1] << ")";
        return os;
    }

	std::istream& operator>>(std::istream& is, Point& rhs) {
        is >> rhs[0];
        is >> rhs[1];
        return is;
    } 

} // end hlp2 namespace

///////////////////////////////////////////////////////////////////////////////
// define private stuff here [if any] in this anonymous namespace ...
namespace {
}
