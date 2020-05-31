#include "../include/log.h"

SF::LogLevel SF::GlobalLevel = SF::TRACE;

void SF::SetLogLevel ( SF::LogLevel lev )
{
	SF::GlobalLevel = lev;
}

std::string SF::LogTime ( void )
{
    time_t ttime = time(0);
    tm *ltime = localtime(&ttime);
    std::stringstream TimeStr;
/*    if ( toFile )
    {
        TimeStr << "[" << 1900 + ltime->tm_year << "." << ltime->tm_mon << "." << ltime->tm_mday << "] ";
    }*/
    TimeStr.fill('0');
    TimeStr << "[" << std::setw(2) << ltime->tm_hour << ":" << std::setw(2) << ltime->tm_min << ":" << std::setw(2) << ltime->tm_sec << "] ";
    return TimeStr.str();
}

std::string SF::LogLevelName ( SF::LogLevel level )
{
    switch (level)
    {
        case SF::TRACE_CORE:
            return " \033[1;37mCORE TRACE\033[0m  ";
        case SF::TRACE_GRAPHIC:
            return "\033[1;37mGRAPHIC TRACE\033[0m";
        case SF::TRACE_SOUND:
            return " \033[1;37mSOUND TRACE\033[0m ";
        case SF::NORMAL_CORE:
            return "    \033[1;34mCORE\033[0m     ";
        case SF::NORMAL_GRAPHIC:
            return "   \033[1;34mGRAPHIC\033[0m   ";
        case SF::NORMAL_SOUND:
            return "    \033[1;34mSOUND\033[0m    ";
        case SF::WARN_CORE:
            return " \033[1;33mSOUND WARN\033[0m  ";
        case SF::WARN_GRAPHIC:
            return "\033[1;33mGRAPHIC WARN\033[0m ";
        case SF::WARN_SOUND:
            return " \033[1;33mSOUND WARN\033[0m  ";
        case SF::ERR_CORE:
            return " \033[1;31mSOUND ERROR\033[0m ";
        case SF::ERR_GRAPHIC:
            return "\033[1;31mGRAPHIC ERROR\033[0m";
        case SF::ERR_SOUND:
            return " \033[1;31mSOUND ERROR\033[0m ";
        case SF::TRACE:
            return "    \033[1;37mTRACE\033[0m    ";
        case SF::DEBUG:
            return "    \033[1;34mDEBUG\033[0m    ";
        case SF::INFO:
            return "    \033[1;32mINFO\033[0m     ";
        case SF::WARN:
            return "   \033[1;33mWARNING\033[0m   ";
        case SF::ERR:
            return "    \033[1;31mERROR\033[0m    ";
        default:
            return "            UNKNOWN           ";
    }
}

/*void SF::LOGLEVEL ( SF::LogLevel level )
{
    //SF::_GlobalLevel = level;
}*/

/*void LOGINIT ( std::string file, LogLevel level )
{
    SF::_GlobalLevel = new SF::LogLevel;
    *SF::_GlobalLevel = level;
}*/
