/*
 * rect.cpp
 * Copyright (C) 2020 Frank Kartheuser <frank.kurbatsch@gmail.com>
 *
 * libGUI is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * libGUI is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#include "../include/rect.h"
#include <SDL.h>

SF::Rect<int>::Rect ( void )
{
	_x = 0;
	_y = 0;
	_w = 1;
	_h = 1;
}

SF::Rect<int>::Rect ( Point p, int w, int h )
{
	_x = p.X();
	_y = p.Y();
	_w = w;
	_h = h;
}

SF::Rect<int>::Rect ( int x, int y, int w, int h )
: Point ( x, y )
{
	_w = w;
	_h = h;
}

SF::Rect<int>::~Rect()
{

}


int SF::Rect<int>::W ( void )
{
	return _w;
}

int SF::Rect<int>::H ( void )
{
	return _h;
}


void SF::Rect<int>::W ( int w )
{
	_w = w;
}

void SF::Rect<int>::H ( int h )
{
	_h = h;
}
	
bool SF::Rect<int>::PointIsIn ( SF::Point<int> p )
{
	if ( (p.X() > _x && p.X() < (_x + _w )) &&
		 (p.Y() > _y && p.Y() < (_y + _h )))
	{
		 return true;
	}
	else
	{
		return false;
	}
}

bool SF::Rect<int>::HasIntersection ( SF::Rect<int>& r )
{
	SDL_Rect a,b;
	a.x = _x;
	a.y = _y;
	a.h = _h;
	a.w = _w;
	a.x = r.X();
	a.y = r.Y();
	a.h = r.H();
	a.w = r.W();
	
	return SDL_HasIntersection ( &a, &b );
}

SF::Rect<int>& SF::Rect<int>::operator= ( const SF::Rect<int> &rhs)
{
	_x = rhs._x;
	_y = rhs._y;
	_w = rhs._w;
	_h = rhs._h;
	return *this;
}

bool SF::Rect<int>::operator==(const SF::Rect<int>& rhs)
{
	if ( ( _x == rhs._x) &&
			( _y == rhs._y ) &&
		 ( _w == rhs._w ) &&
		 ( _h == rhs._h ))
		 return true;
	else
		return false; 
}

SF::Rect<float>::Rect ( void )
{
	_x = 0;
	_y = 0;
	_w = 1;
	_h = 1;
}

SF::Rect<float>::Rect ( Point<float> p, float w, float h )
{
	_x = p.X();
	_y = p.Y();
	_w = w;
	_h = h;
}

SF::Rect<float>::Rect ( float x, float y, float w, float h )
: Point ( x, y )
{
	_w = w;
	_h = h;
}

SF::Rect<float>::~Rect()
{

}


float SF::Rect<float>::W ( void )
{
	return _w;
}

float SF::Rect<float>::H ( void )
{
	return _h;
}


void SF::Rect<float>::W ( float w )
{
	_w = w;
}

void SF::Rect<float>::H ( float h )
{
	_h = h;
}
	
bool SF::Rect<float>::PointIsIn ( SF::Point<float> p )
{
	if ( (p.X() > _x && p.X() < (_x + _w )) &&
		 (p.Y() > _y && p.Y() < (_y + _h )))
	{
		 return true;
	}
	else
	{
		return false;
	}
}

bool SF::Rect<float>::HasIntersection ( SF::Rect<float>& r )
{
	SDL_Rect a,b;
	a.x = _x+0.5;
	a.y = _y+0.5;
	a.h = _h+0.5;
	a.w = _w+0.5;
	b.x = r.X()+0.5;
	b.y = r.Y()+0.5;
	b.h = r.H()+0.5;
	b.w = r.W()+0.5;
	
	return SDL_HasIntersection ( &a, &b );
}

SF::Rect<float>& SF::Rect<float>::operator= ( const SF::Rect<float> &rhs)
{
	_x = rhs._x;
	_y = rhs._y;
	_w = rhs._w;
	_h = rhs._h;
	return *this;
}

bool SF::Rect<float>::operator==(const SF::Rect<float>& rhs)
{
	if ( ( _x == rhs._x) &&
			( _y == rhs._y ) &&
		 ( _w == rhs._w ) &&
		 ( _h == rhs._h ))
		 return true;
	else
		return false; 
}
