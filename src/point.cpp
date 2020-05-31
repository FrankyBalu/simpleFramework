#include "../include/point.h"

SF::Point<int>::Point()
{
	_x = 0;
	_y = 0;
}

SF::Point<int>::Point(int x, int y)
{
	_x = x;
	_y = y;
}

SF::Point<int>::~Point()
{
}

int SF::Point<int>::X()
{
	return _x;
}

int SF::Point<int>::Y()
{
	return _y;
}

void SF::Point<int>::X(int x)
{
	_x = x;
}

void SF::Point<int>::Y(int y)
{
	_y = y;
}

SF::Point<int>& SF::Point<int>::operator= ( const SF::Point<int> &rhs)
{
	_x = rhs._x;
	_y = rhs._y;  
	return *this;
}
bool SF::Point<int>::operator ==(const SF::Point<int>& rhs)
{
	if ( _x == rhs._x && _y == rhs._y )
    	return true;
    else
    	return false;
}


SF::Point<float>::Point()
{
	_x = 0;
	_y = 0;
}

SF::Point<float>::Point(float x, float y)
{
	_x = x;
	_y = y;
}

SF::Point<float>::~Point()
{
}

float SF::Point<float>::X()
{
	return _x;
}

float SF::Point<float>::Y()
{
	return _y;
}

void SF::Point<float>::X(float x)
{
	_x = x;
}

void SF::Point<float>::Y(float y)
{
	_y = y;
}

SF::Point<float>& SF::Point<float>::operator= ( const SF::Point<float> &rhs)
{
	_x = rhs._x;
	_y = rhs._y;  
	return *this;
}
bool SF::Point<float>::operator ==(const SF::Point<float>& rhs)
{
	if ( _x == rhs._x && _y == rhs._y )
    	return true;
    else
    	return false;
}
