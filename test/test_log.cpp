#include "../include/log.h"
#include <iostream>
#include <SDL2/SDL.h>

int main ()
{
    SF::SetLogLevel(SF::TRACE_CORE);
    LOG(SF::TRACE_CORE,      "Test");
	LOG(SF::TRACE_GRAPHIC, "Test");
	LOG(SF::TRACE_SOUND, "Test");
	LOG(SF::NORMAL_CORE, "Test");
    LOG(SF::NORMAL_GRAPHIC, "Test");
    LOG(SF::NORMAL_SOUND, "Test");
    LOG(SF::WARN_CORE, "Test");
    LOG(SF::WARN_GRAPHIC, "Test");
    LOG(SF::WARN_SOUND, "Test");
    LOG(SF::ERR_CORE, "Test");
    LOG(SF::ERR_GRAPHIC, "Test");
    LOG(SF::ERR_SOUND, "Test");
    LOG(SF::TRACE, "Test");
    LOG(SF::DEBUG, "Test");
    LOG(SF::INFO, "Test");
    LOG(SF::WARN, "Test");
    LOG(SF::ERR, "Test");
}
