#include "../include/video.h"
#include "../include/window.h"
#include "../include/event.h"
#include "../include/log.h"

bool isRunning = true;

int main ()
{
    SF::SetLogLevel(SF::TRACE_GRAPHIC);
	SF::VideoDriver::Inst()->Init ( SF::VideoDriver::Inst()->getVideoDriver(0).c_str());
	
	SF::Window win ( "test window", 0, 0, 600, 600, SF::WINDOW_SHOWN | SF::WINDOW_RESIZABLE, "MainWindow" );
	win.GetRenderer()->DrawColor ( 255, 0, 0, 0 );
	
	while ( win.IsOpen() )
	{
		win.ProcessEvent(nullptr);
		win.Update (  );
		win.Draw ();
	}
	return 0;
}
