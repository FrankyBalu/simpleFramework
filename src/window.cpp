/*
 * window.cpp
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
 
#include "../include/window.h"
#include "../include/log.h"
#include <iostream> 
#include <algorithm>
#include <SDL.h>





SF::Window::Window ( std::string title, int x, int y, int w, int h, unsigned int flags, std::string ID )
{
		_Window = SF::VideoDriver::Inst()->CreateWindow ( title.c_str(), x, y, w, h, flags );
		if (_Window == nullptr)
		{
            _IsOpen = false;
			return;
		}
		_Renderer = new SF::Renderer ( _Window );
		if (_Renderer == nullptr)
		{
			_IsOpen = false;
			return;
		}
		if (ID != "")
            _ID = ID;
        else
            _ID = "UNKNOWN WINDOW ID";
		_Parent = nullptr;
		_MainChild = nullptr;
 		int tmpW, tmpH;
		SDL_GetWindowSize((SDL_Window*)_Window, &tmpW, &tmpH);
        _Rect.X (0);
		_Rect.Y (0);
		_Rect.W (tmpW);
        _Rect.H (tmpH);
		_Offset.X(0);
		_Offset.Y(0);
		_IsOpen = true;	
}

SF::Window::~Window ( void )
{
}

bool SF::Window::IsOpen ( void )
{
	return _IsOpen;
}

SF::Renderer* SF::Window::GetRenderer ( void )
{
	return _Renderer;
}

SF::Rect<int> SF::Window::Size ( void )
{
	return (const SF::Rect<int>) _Rect;
}


bool SF::Window::AddChild ( SF::Widget *child, std::string ID)
{
	auto it = _Child.find(ID);	
    if ( it != _Child.end())
	{
		LOG(SF::ERR_GRAPHIC, "Widget with ID: " << ID << " allready exists in window: " << _ID );
		return false;
	}
	_Child[ID] = child;
	_Child[ID]->Size ( _Rect );
	_Child[ID]->Offset ( _Offset );
	if (_MainChild == nullptr )
	{
            _MainChild = child;
			LOG(SF::NORMAL_GRAPHIC, "Change MainWidget to: "  << _ID );
    }
    _ChildOrder.push_back(ID);
	LOG(SF::NORMAL_GRAPHIC, "Add widget " << ID << " to Window " << _ID );
	return true;
}

bool SF::Window::AddChild ( SF::Widget *child, std::string ID, int width, int height )
{
	auto it = _Child.find(ID);	
    if ( it != _Child.end())
	{
		LOG(SF::ERR_GRAPHIC, "Widget with ID: " << ID << " allready exists in window: " << _ID );
		return false;
	}
	_Child[ID] = child;
	SF::Rect<int> rect;
	rect.W(width);
    rect.H( height );
	_Child[ID]->Size ( rect );
	_Child[ID]->Offset ( _Offset );
	if (_MainChild == nullptr )
	{
            _MainChild = child;
            LOG(SF::NORMAL_GRAPHIC, "Change MainWidget to: "  << _ID );
    }
    _ChildOrder.push_back(ID);
	LOG(SF::NORMAL_GRAPHIC, "Add widget " << ID << " to Window " << _ID );
	return true;
}

bool SF::Window::ChangeChild ( std::string ID)
{
	auto it = _Child.find(ID);	
    if ( it == _Child.end())
	{
		LOG(ERR_GRAPHIC, "No widget with ID (" << ID << ") in window " << _ID );
		return false;
	}
	else
	{
	   LOG(NORMAL_GRAPHIC, "Change mainwidget to "<< ID );
		_MainChild = _Child[ID];
		return true;
	}
}


void SF::Window::Size ( SF::Rect<int> rect )
{
	_Rect = rect;
	for (long unsigned int v = 0; v < _ChildOrder.size(); v++)
	{
		_Child[_ChildOrder[v]]->Size (_Rect);
	}
}

void SF::Window::ProcessEvent ( SF::Event *event )
{
	if ( event != nullptr )
		return;
	SF::cEvent::Inst()->Update();
	_Event = SF::cEvent::Inst()->Get();
	if ( _Event.Type == SF::WINDOWRESIZE )
	{
		//TODO resize
	}
	else if ( _Event.Type != SF::NOEVENT )
	{
		if ( _MainChild != nullptr )
		{
			_MainChild->ProcessEvent ( &_Event );
		}
		if ( _Event.Type == SF::QUIT )
		{
			_IsOpen = false;
		}
	}
}

void SF::Window::Update ( void )
{
	for (unsigned long v = 0; v < _ChildOrder.size(); v++)
	{
		_Child[_ChildOrder[v]]->Update ();
	}
	
}

bool SF::Window::Draw ( void )
{
	if ( _Renderer->Clear() != 0 )
	{
// 		LOG->ERROR (LOG_CATEGORY_LIBGUI,"Fenster %s: Renderer konnte nicht resetet werden", _ID.c_str());
		return false;
	}
	if ( _MainChild != nullptr )
	{
		if ( !_MainChild->Draw() )
		{
			//LOG->ERROR (LOG_CATEGORY_LIBGUI,"Fenster %s: Konnte %s nicht Rendern: %s", _ID.c_str(), _MainChildID.c_str());
			return false;
		}
		
	}
	_Renderer->Present();
	return true;
}

void SF::Window::Offset ( SF::Point<int> offset )
{
	//TODO blödsinn... die Compilerwarnung muss auch anders weg gehen, denk ich mal
	offset.X();
}
SF::Point<int>	SF::Window::Offset	( void )
{
	return _Offset;
}

std::string SF::Window::ID ( void )
{
	return _ID;
}

