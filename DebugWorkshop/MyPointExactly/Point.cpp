#include "Point.h"
#include <iostream>

Point::Point()
{
	_coord = new int[2];
	_coord[0] = _coord[1] = 0;
}

Point::Point(int x, int y)
{
	_coord = new int[2];
	_coord[0] = x;
	_coord[1] = y;
}

Point::Point(const Point& other)
{
	*this = other;
}

Point::~Point()
{
	if (_coord == nullptr) return;
	delete _coord;
	_coord = nullptr;
}

Point& Point::operator=(const Point& other)
{
	if (this == &other) return *this;
	if (_coord != nullptr) {
		delete _coord;
		_coord = nullptr;
	}
	_coord = new int[2];
	for (int i = 0; i < 2; i++) {
		_coord[i] = other._coord[i];
	}
	return *this;
}

int Point::getX() const 
{ 
	return _coord[0]; 
}

int Point::getY() const
{ 
	return _coord[1]; 
}


std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << "(" << p._coord[0] << "," << p._coord[1] << ")";
	return os;
}
