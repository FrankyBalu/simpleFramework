/*
 * video.cpp
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

#include "../include/video.h"
#include "../include/log.h"
#include <SDL2/SDL.h>


SF::VideoDriver* SF::VideoDriver::_Instance = 0;

SF::VideoDriver* SF::VideoDriver::Inst()
{
	if ( _Instance == 0 )
	{
		_Instance = new SF::VideoDriver();
	}
	return _Instance;
}


SF::VideoDriver::VideoDriver ( void )
{
	_Init = false;
}


SF::VideoDriver::~VideoDriver ( void )
{
	SDL_VideoQuit();
	_Init = false;
}

int SF::VideoDriver::getNumVideoDrivers ( void )
{
	return SDL_GetNumVideoDrivers ( );
}

std::string SF::VideoDriver::getVideoDriver ( int index )
{
	return SDL_GetVideoDriver ( index );
}

bool SF::VideoDriver::Init ( const char *driver_name )
{
    LOG(NORMAL_GRAPHIC, "Init VideoDriver " << driver_name );
	if (_Init)
	{
		LOG(WARN_GRAPHIC, " Videodriver allready initialised!" );
		return false;
	}
	if ( SDL_VideoInit ( driver_name ) < 0 )
	{
		LOG(ERR_GRAPHIC, SDL_GetError() );
		return false;
	}
	_Init = true;
	return true;	
}

SF::rawWindow* SF::VideoDriver::CreateWindow ( std::string title, int x, int y, int w, int h, uint32_t flags )
{
	LOG(NORMAL_GRAPHIC, "Create window: " << title );
	SDL_Window* win = SDL_CreateWindow ( title.c_str(), x, y, w, h, flags );
	if ( win == nullptr )
	{
		LOG(ERR_GRAPHIC, SDL_GetError() );
		return nullptr;
	}
	LOG(NORMAL_GRAPHIC, "successfull" );
	return (rawWindow*)win;
}

