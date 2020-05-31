/*
 * window.h
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


#ifndef __LIBGUI_WINDOW__
#define __LIBGUI_WINDOW__

#include "video.h"
#include "event.h"
#include "widget.h"
#include <map>
#include <vector>


namespace SF {

  
class Window : public Widget
{
private:
    rawWindow                       *_Window;
    std::map <std::string,Widget*>  _Child;
    std::vector <std::string>       _ChildOrder;
    Widget                          *_MainChild;
    bool                            _IsOpen;
    Event 		                    _Event;
    
    std::string	                    _ID;
	Widget 		                    *_Parent;
	Renderer 	                    *_Renderer;
	Rect<int> 		                _Rect;
	Point<int> 		                _Offset;
	

    
public:
	Window ( std::string title, int x, int y, int w, int h, unsigned int flags, std::string ID );
	virtual ~Window ( void );
	bool		IsOpen				( void );
		
	Rect<int>	Size			( void );
	void		Size            ( Rect<int> rect );
	Point<int>	Offset          ( void );
	void		Offset	        ( Point<int> offset );
	
    Renderer* 	GetRenderer 	( void );
	
	bool		AddChild		( Widget *child, std::string ID );
	bool		AddChild		( Widget *child, std::string ID, int width, int height );
	bool		ChangeChild 	( std::string ID );
	void 		ProcessEvent	( Event *event );
	void		Update			( void );
	bool		Draw			( void );
	std::string	ID				( void );
	
	void ( *onClick )	( void *data );
	void ( *onPress )	( void *data );
	void ( *onSlideH )	( void *data );
	void ( *onSlideV )	( void *data );
	void ( *onRelease )	( void *data );
  
  
    
  
};



}//namespace LIBGUI
#endif //__LIBGUI_WINDOW__
