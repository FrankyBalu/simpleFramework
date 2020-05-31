/*
 * renderer.cpp
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
 
#include "../include/renderer.h"
#include "../include/log.h"
#include <SDL2/SDL.h>
#include <string>
#include <iostream>


int SF::GetNumRenderDrivers ( void )
{
	return SDL_GetNumRenderDrivers ( );
}

int SF::GetRenderDriverInfo ( int index, SF::RendererInfo *info )
{
	int ret = SDL_GetRenderDriverInfo ( index, (SDL_RendererInfo*)info );
	if ( ret != 0 )
	{
		LOG(SF::WARN_GRAPHIC, "No Info for driver " << index << ": " << SDL_GetError() );
	}
	return ret;
}

void SF::PrintDriverInfo ( RendererInfo *info )
{
	LOG(SF::TRACE_GRAPHIC, "RenderInfo:" );
	LOG(SF::TRACE_GRAPHIC, "Name: " << info->name );
	LOG(SF::TRACE_GRAPHIC, "Flags: " << info->flags );
	LOG(SF::TRACE_GRAPHIC, "max tex width: " << info->max_texture_width );
	LOG(SF::TRACE_GRAPHIC, "max tex height: " << info->max_texture_height );
}

SF::Renderer::Renderer ( SF::rawWindow *win )
{
	SDL_Renderer *ren = SDL_CreateRenderer ( (SDL_Window*)win, 0,  RENDERER_ACCELERATED | RENDERER_TARGETTEXTURE );
	if ( ren == nullptr )
	{
		LOG(SF::ERR_GRAPHIC, "Can't create Renderer: " << SDL_GetError() );
		_renderer = nullptr;
	}
	else
	{
		_renderer = (SF::rawRenderer*)ren;
		_info = new SF::RendererInfo;
		Info ();
		LOG(SF::NORMAL_GRAPHIC, "Create renderer" );
		SF::PrintDriverInfo ( _info );
		_window = win;
	}
}

SF::Renderer::Renderer ( SF::rawWindow *win, int index, Uint32 flags )
{
	SDL_Renderer *ren = SDL_CreateRenderer ( (SDL_Window*)win, index,  flags );
	if ( ren == nullptr )
	{
		LOG(SF::ERR_GRAPHIC, "Can't create Renderer: " << SDL_GetError() );
		_renderer = nullptr;
	}
	else
	{
		_renderer = (SF::rawRenderer*)ren;
		_info = new SF::RendererInfo;
		Info ();
		LOG(SF::NORMAL_GRAPHIC, "Renderer successfull created" );
		SF::PrintDriverInfo ( _info );
		_renderer = (rawRenderer*)ren;
		_window = win;
	}
}

void SF::Renderer::Info ( void )
{
	SDL_GetRendererInfo((SDL_Renderer*) _renderer,(SDL_RendererInfo*) _info);
}

SF::Renderer::~Renderer ( void )
{
	SDL_DestroyRenderer ( (SDL_Renderer*)_renderer);
}

SF::rawRenderer* SF::Renderer::Get ( void )
{
	return (SF::rawRenderer*)SDL_GetRenderer ( (SDL_Window*)_window);
}

int SF::Renderer::DrawColor( uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	int ret = SDL_SetRenderDrawColor ( (SDL_Renderer*)_renderer, r, g, b, a );
	if ( ret != 0 )
	{
		LOG(SF::WARN_GRAPHIC, "Can't set color: " << SDL_GetError() );
		return ret;
	}
	else
	{
		LOG(SF::TRACE_GRAPHIC, "Set color to:" );
        LOG(SF::TRACE_GRAPHIC, "RED  : " << std::to_string(r) );
        LOG(SF::TRACE_GRAPHIC, "GREEN: " << std::to_string(g) );
        LOG(SF::TRACE_GRAPHIC, "BLUE : " << std::to_string(b) );
        LOG(SF::TRACE_GRAPHIC, "ALPHA: " << std::to_string(a) );
		return ret;
	}
}

int SF::Renderer::DrawColor( uint8_t * r, uint8_t * g, uint8_t * b, uint8_t * a )
{
	int ret = SDL_GetRenderDrawColor ( (SDL_Renderer*)_renderer, r, g, b, a );
	if ( ret != 0 )
	{
		LOG(SF::WARN_GRAPHIC, "Can't get color: " << SDL_GetError() );
		return ret;
	}
	else
	{
		LOG(SF::TRACE_GRAPHIC, "Set color to:" );
        LOG(SF::TRACE_GRAPHIC, "RED  : " << std::to_string(*(r)) );
        LOG(SF::TRACE_GRAPHIC, "GREEN: " << std::to_string(*(g)) );
        LOG(SF::TRACE_GRAPHIC, "BLUE : " << std::to_string(*(b)) );
        LOG(SF::TRACE_GRAPHIC, "ALPHA: " << std::to_string(*(a)) );
		return ret;
	}
}

int SF::Renderer::Clear ( void )
{
	int ret = SDL_RenderClear ((SDL_Renderer*)_renderer);
	if ( ret != 0 )
	{
		LOG(SF::WARN_GRAPHIC, "Can't clear renderer: " << SDL_GetError() );
		return ret;
	}
	else
	{
		return ret;
	}
}

void SF::Renderer::Present( void )
{
	SDL_RenderPresent((SDL_Renderer*)_renderer);
}

int SF::Renderer::DrawPoint( int x, int y)
{
	int ret = SDL_RenderDrawPoint((SDL_Renderer*)_renderer, x, y);
	if ( ret != 0 )
	{
		LOG(SF::WARN_GRAPHIC, "Can't draw point: " << SDL_GetError() );
        return ret;
	}
	else
	{
		return ret;
	}
}

int SF::Renderer::DrawPoint( SF::Point<int> &point )
{
	int ret = SDL_RenderDrawPoint((SDL_Renderer*)_renderer, point.X(), point.Y());
	if ( ret != 0 )
	{
		LOG(SF::WARN_GRAPHIC, "Can't draw point: " << SDL_GetError() );
        return ret;
	}
	else
	{
		return ret;
	}
}

int SF::Renderer::DrawLine( int x1, int y1, int x2, int y2)
{
	int ret = SDL_RenderDrawLine((SDL_Renderer*)_renderer, x1, y1, x2, y2 );
	if ( ret != 0 )
	{
		LOG(SF::WARN_GRAPHIC, "Can't draw line: " << SDL_GetError() );
        return ret;
	}
	else
	{
		return ret;
	}
}

int SF::Renderer::DrawLine( SF::Point<int> &point1, SF::Point<int> &point2)
{
	int ret = SDL_RenderDrawLine((SDL_Renderer*)_renderer, point1.X(), point1.Y(), point2.X(), point2.Y() );
	if ( ret != 0 )
	{
		LOG(SF::WARN_GRAPHIC, "Can't draw line: " << SDL_GetError() );
        return ret;
	}
	else
	{
		return ret;
	}
}

int SF::Renderer::DrawRect( SF::Rect<int> *rect )
{
	SDL_Rect r;
	r.x = rect->X();
	r.y = rect->Y();
	r.w = rect->W();
	r.h = rect->H();
	int ret = SDL_RenderDrawRect((SDL_Renderer*)_renderer, &r );
	if ( ret != 0 )
	{
		LOG(SF::WARN_GRAPHIC, "Can't draw rect: " << SDL_GetError() );
        return ret;
	}
	else
	{
		return ret;
	}
}

int SF::Renderer::DrawFillRect( SF::Rect<int> * rect)
{
	SDL_Rect r;
	r.x = rect->X();
	r.y = rect->Y();
	r.w = rect->W();
	r.h = rect->H();
	int ret = SDL_RenderFillRect((SDL_Renderer*)_renderer, &r );
	if ( ret != 0 )
	{
		LOG(SF::WARN_GRAPHIC, "Can't draw fillrect: " << SDL_GetError() );
        return ret;
	}
	else
	{
		return ret;
	}
}







