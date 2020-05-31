/*
 * event.cpp
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
 
 #include "../include/log.h"
#include "../include/event.h"
#include <SDL.h>

namespace SF {

cEvent *cEvent::_Instance = 0;

cEvent::cEvent ( void )
{
    _MouseButtonDown = false;
	_FingerDown = false;
    _Event.Type		= NOEVENT;
	_Event.WindowID = 0;
	_Event.NewW		= 0;
	_Event.NewH		= 0;
	_Event.X		= 0;
	_Event.Y		= 0;
	_Event.XRel		= 0;
	_Event.YRel		= 0;
	_Event.x		= 0;
	_Event.y		= 0;
	_Event.xRel		= 0;
	_Event.yRel		= 0;
}

cEvent::~cEvent ( void )
{
}

cEvent* cEvent::Inst ( void )
{
	if (_Instance == 0)
	{
		_Instance = new cEvent();
    }
    return _Instance;
}


bool cEvent::Update ( void )
{
	SDL_Event _SDLevent;
    if ( SDL_PollEvent( &_SDLevent ) > 0 )
    {
    	//Benutzer möchte das Program beenden
    	if ( _SDLevent.type == SDL_QUIT )
        {
        	_Event.Type = QUIT;
        	LOG(TRACE_CORE, "QUIT Event ausgelöst" );
        	return true;
        }
        //Mausknopf wurde gedrückt
        if ( _SDLevent.type == SDL_MOUSEBUTTONDOWN )
        {
        	_Event.Type 		= MOUSEBUTTONDOWN;
        	_MouseButtonDown 	= true;
        	_Event.WindowID 	= _SDLevent.button.windowID;
        	_Event.NewW 		= 0;
        	_Event.NewH 		= 0;
        	_Event.X 			= _SDLevent.button.x;
        	_Event.Y 			= _SDLevent.button.y;
        	_Event.XRel 		= 0;
        	_Event.YRel 		= 0;
        	_Event.Clicks		= 0;
        	_Event.x 			= 0;
        	_Event.y			= 0;
        	_Event.xRel			= 0;
        	_Event.yRel			= 0;
        	LOG(TRACE_CORE, "MOUSEBUTTONDOWN: x: " << _Event.X << "y: " << _Event.Y << "WindowID: " << _Event.WindowID );
        	return true;
		}
        if ( _SDLevent.type == SDL_MOUSEBUTTONUP )
        {
        	_Event.Type 		= MOUSEBUTTONUP;
        	_MouseButtonDown 	= false;
        	_Event.WindowID 	= _SDLevent.button.windowID;
        	_Event.NewW 		= 0;
        	_Event.NewH 		= 0;
        	_Event.X 			= _SDLevent.button.x;
        	_Event.Y 			= _SDLevent.button.y;
        	_Event.XRel 		= 0;
        	_Event.YRel 		= 0;
        	_Event.Clicks		= _SDLevent.button.clicks;
        	_Event.x 			= 0;
        	_Event.y			= 0;
        	_Event.xRel			= 0;
        	_Event.yRel			= 0;
        	LOG(TRACE_CORE, "MOUSEBUTTONUP: x: " << _Event.X << " y: " << _Event.Y << " clicks: " << _Event.Clicks << " WindowID: %" <<_Event.WindowID );
        	return true;
		}
        if ( _SDLevent.type == SDL_MOUSEMOTION && _MouseButtonDown )
        {
        	_Event.Type 		= MOUSEMOTION;
        	_Event.WindowID 	= _SDLevent.motion.windowID;
        	_Event.NewW 		= 0;
        	_Event.NewH 		= 0;
        	_Event.X 			= _SDLevent.motion.x;
        	_Event.Y 			= _SDLevent.motion.y;
        	_Event.XRel 		= _SDLevent.motion.xrel;
        	_Event.YRel 		= _SDLevent.motion.yrel;
        	_Event.Clicks		= 0;
        	_Event.x 			= 0;
        	_Event.y			= 0;
        	_Event.xRel			= 0;
        	_Event.yRel			= 0;
        	LOG(TRACE_CORE, "MOUSEMOTION: x: " << _Event.X << " y: " << _Event.Y << " relx: " << _Event.XRel << " rely: " << _Event.YRel << " WindowID: " <<_Event.WindowID );
        	return true;
		}
        
        if ( _SDLevent.type == SDL_FINGERDOWN )
        {
        	_Event.Type 		= FINGERDOWN;
        	_FingerDown		 	= true;
        	_Event.WindowID 	= _SDLevent.tfinger.windowID;
        	_Event.NewW 		= 0;
        	_Event.NewH 		= 0;
        	_Event.X 			= 0;
        	_Event.Y 			= 0;
        	_Event.XRel 		= 0;
        	_Event.YRel 		= 0;
        	_Event.Clicks		= 0;
        	_Event.x 			= _SDLevent.tfinger.x;
        	_Event.y			= _SDLevent.tfinger.y;
        	_Event.xRel			= 0;
        	_Event.yRel			= 0;
        	LOG(TRACE_CORE, "FINGERDOWN: x: " << _Event.x << " y: " << _Event.y << " WindowID: " <<_Event.WindowID );
        	return true;
		}
        if ( _SDLevent.type == SDL_FINGERUP )
        {
        	_Event.Type 		= FINGERUP;
        	_FingerDown 		= false;
        	_Event.WindowID 	= _SDLevent.tfinger.windowID;
        	_Event.NewW 		= 0;
        	_Event.NewH 		= 0;
        	_Event.X 			= 0;
        	_Event.Y 			= 0;
        	_Event.XRel 		= 0;
        	_Event.YRel 		= 0;
        	_Event.Clicks		= 0;
        	_Event.x 			= _SDLevent.tfinger.x;
        	_Event.y			= _SDLevent.tfinger.y;
        	_Event.xRel			= 0;
        	_Event.yRel			= 0;
        	LOG(TRACE_CORE, "FINGERUP: x: " << _Event.x << " y: " << _Event.y << " WindowID: " <<_Event.WindowID );
        	return true;
		}
        if ( _SDLevent.type == SDL_FINGERMOTION && _FingerDown)
        {
        	_Event.Type 		= FINGERMOTION;
        	_Event.WindowID 	= _SDLevent.tfinger.windowID;
        	_Event.NewW 		= 0;
        	_Event.NewH 		= 0;
        	_Event.X 			= 0;
        	_Event.Y 			= 0;
        	_Event.XRel 		= 0;
        	_Event.YRel 		= 0;
        	_Event.Clicks		= 0;
        	_Event.x 			= _SDLevent.tfinger.x;
        	_Event.y			= _SDLevent.tfinger.y;
        	_Event.xRel			= _SDLevent.tfinger.dx;
        	_Event.yRel			= _SDLevent.tfinger.dy;
        	LOG(TRACE_CORE, "FINGERMOTION: x: " << _Event.x << " y: " << _Event.y << " relx: " << _Event.xRel << " rely: " << _Event.yRel << " WindowID: " << _Event.WindowID );
        	return true;
		}
		if ( (_SDLevent.type == SDL_WINDOWEVENT) && (_SDLevent.window.event == SDL_WINDOWEVENT_RESIZED) )
        {
        	_Event.Type 		= WINDOWRESIZE;
        	_Event.WindowID 	= _SDLevent.window.windowID;
        	_Event.NewW 		= _SDLevent.window.data1;
        	_Event.NewH 		= _SDLevent.window.data2;
        	_Event.X 			= 0;
        	_Event.Y 			= 0;
        	_Event.XRel 		= 0;
        	_Event.YRel 		= 0;
        	_Event.Clicks		= 0;
        	_Event.x 			= 0;
        	_Event.y			= 0;
        	_Event.xRel			= 0;
        	_Event.yRel			= 0;
        	LOG(TRACE_CORE, "WINDOWRESIZE: NewW: " << _Event.NewW << " NewH: " << _Event.NewH << " WindowID: " <<_Event.WindowID );
        	return true;
		}
	}
//	LOG(TRACE_CORE) << "Kein Benutzbares Event vorhanden" << std::endl;
	return false;
}

Event cEvent::Get ( void )
{	
	//LOG->INFO (LOG_CATEGORY_LIBGUI,"GetEvent Type: %d Window: %d NewX: %d NewY: %d X: %d Y: %d\n", _Event.Type, _Event.WindowID, _Event.NewW, _Event.NewH, _Event.X, _Event.Y );
	//LOG->INFO (LOG_CATEGORY_LIBGUI,"         XRel: %d YRel: %d x: %f y: %f xRel: %f, yRel: %f", _Event.XRel, _Event.YRel, _Event.x, _Event.y, _Event.xRel, _Event.yRel);
	Event retEvent 	= _Event;
	_Event.Type		= NOEVENT;
	_Event.WindowID = 0;
	_Event.NewW		= 0;
	_Event.NewH		= 0;
	_Event.X		= 0;
	_Event.Y		= 0;
	_Event.XRel		= 0;
	_Event.YRel		= 0;
	_Event.x		= 0;
	_Event.y		= 0;
	_Event.xRel		= 0;
	_Event.yRel		= 0;
	if ( retEvent.Type > NOEVENT && retEvent.Type < LASTEVENT )
		return retEvent;
	else
		return _Event;
}
        
        
}//namespace SF
