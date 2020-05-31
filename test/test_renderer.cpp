#include "../include/renderer.h"
#include <iostream>
#include "../include/log.h"
#include "../include/event.h"


int main ()
{
    SF::SetLogLevel(SF::TRACE_GRAPHIC);
	SF::RendererInfo info;
	SF::rawWindow *win;
	SF::Renderer *renderer;
	
	
	int index = SF::GetNumRenderDrivers ();
	
	LOG(SF::DEBUG, "There are " << index << " renderer driver" );
	
	for (int i = 0; i<index; i++ )
	{
		SF::GetRenderDriverInfo ( i, &info );
		SF::PrintDriverInfo ( &info );
	}
	
	SF::VideoDriver::Inst()->Init ( SF::VideoDriver::Inst()->getVideoDriver(0).c_str());
	 win = SF::VideoDriver::Inst()->CreateWindow ( "test", 100, 100, 400, 400, SF::WINDOW_SHOWN );

	 renderer = new SF::Renderer ( win );
	 renderer->DrawColor (255,255,255,0);
	 renderer->Clear();
	 renderer->DrawColor (255,0,0,0);
	 renderer->DrawPoint ( 50, 50 );
	 renderer->DrawColor (0,255,0,0);
	 renderer->DrawLine ( 55, 55, 100, 100 );
	 SF::Rect<int> rect(300, 300, 50, 50 );
	 renderer->DrawColor (0,0,255,0);
	 renderer->DrawColor (255,255,0,0);
	 renderer->DrawRect ( &rect );
	 SF::Rect<int> rectfill(350, 350, 50, 50 );
	 renderer->DrawColor (0,255,255,0);
	 renderer->DrawFillRect ( &rectfill );
	 renderer->Present();
	 bool run = true;
	 while ( run)
	 {
	 	SF::cEvent::Inst()->Update();
	 	SF::Event ev = SF::cEvent::Inst()->Get();
	 	//std::cout << "Event.type: " << ev.type << std::endl;
	 	if ( ev.Type == SF::QUIT)
	 		run = false;
	 		
	 }
	 
	// SDL_Delay (2000);
}
