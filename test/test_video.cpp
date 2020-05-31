#include "../include/video.h"
#include "../include/log.h"
#include <iostream>
#include <SDL2/SDL.h>

int main ()
{
	SF::rawWindow *win;
	
	int dr = SF::VideoDriver::Inst()->getNumVideoDrivers();
	
	for ( int i = 0; i < dr; i++ )
	{
		LOG(SF::TRACE, "Videotreiber " << i << ": " << SF::VideoDriver::Inst()->getVideoDriver(i) );
	}
	SF::VideoDriver::Inst()->Init ( SF::VideoDriver::Inst()->getVideoDriver(0).c_str());
    SF::VideoDriver::Inst()->Init ( SF::VideoDriver::Inst()->getVideoDriver(0).c_str());

    win = SF::VideoDriver::Inst()->CreateWindow ( "test", 100, 100, 300, 300, SF::WINDOW_SHOWN );
	 
	 if ( win != nullptr )
	 	SDL_Delay (2000);
	return 0;
}
