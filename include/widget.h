/*
 * widget.h
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


#ifndef _SIMPLEFRAMEWORK_WIDGET
#define _SIMPLEFRAMEWORK_WIDGET

#include <string>
#include "rect.h"
#include "renderer.h"
#include "event.h"

namespace SF {


class Widget {
protected:
	Widget(){}
	~Widget(){}
public:		
	
    virtual Rect<int>	Size			( void ) = 0;
	virtual void		Size            ( Rect<int> rect ) = 0;
	virtual Point<int>	Offset          ( void ) = 0;
	virtual void		Offset	        ( Point<int> offset ) = 0;
	
    virtual Renderer* 	GetRenderer 	( void ) = 0;
	
	virtual bool		AddChild		( Widget *child, std::string ID ) = 0;
	virtual bool		AddChild		( Widget *child, std::string ID, int width, int height ) = 0;
	virtual bool		ChangeChild 	( std::string ID ) = 0;
	virtual void 		ProcessEvent	( Event *event ) = 0;
	virtual void		Update			( void ) = 0;
	virtual bool		Draw			( void ) = 0;
	virtual std::string	ID				( void ) = 0;
	

	void ( *onClick )	( void *data );
	void ( *onPress )	( void *data );
	void ( *onSlideH )	( void *data );
	void ( *onSlideV )	( void *data );
	void ( *onRelease )	( void *data );
};


}//namespace SF

#endif //_SIMPLEFRAMEWORK_WIDGET
