#ifndef _SIMPLEFRAME_WORK_LOG
#define _SIMPLEFRAME_WORK_LOG


#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream
#include <ostream>
#include <iomanip>


namespace SF {
    

    /**
     * @brief LogLevel to use for Logging
     * Note: 0-9 are for library use only
     */
typedef enum LogLevel {
    TRACE_CORE,
    TRACE_GRAPHIC,
    TRACE_SOUND,
    NORMAL_CORE,
    NORMAL_GRAPHIC,
    NORMAL_SOUND,
    WARN_CORE,
    WARN_GRAPHIC,
    WARN_SOUND,
    ERR_CORE,
    ERR_GRAPHIC,
    ERR_SOUND,
    TRACE,
    DEBUG,
    INFO,
    WARN,
    ERR,
}LogLevel;

extern LogLevel GlobalLevel;

void SetLogLevel ( LogLevel lev );

std::string LogTime ( void );

std::string LogLevelName ( LogLevel level );

struct None { };



template <typename First,typename Second>
struct Pair {
  First first;
  Second second;
};

template <typename List>
struct LogData {
  List list;
};

template <typename Begin,typename Value>
LogData<Pair<Begin,const Value &>>
  operator<<(LogData<Begin> begin,const Value &value)
{
  return {{begin.list,value}};
}

template <typename Begin,size_t n>
LogData<Pair<Begin,const char *>>
  operator<<(LogData<Begin> begin,const char (&value)[n])
{
  return {{begin.list,value}};
}

inline void printList(std::ostream &os,None)
{
    os <<"";
}


template <typename Begin,typename Last>
void printList(std::ostream &os,const Pair<Begin,Last> &data)
{
  printList(os,data.first);
  os << data.second;
}

template <typename List>
void log(LogLevel level, const LogData<List> &data)
{
	if ( level >= SF::GlobalLevel )
  	{
		std::cout << SF::LogTime() << "{" << SF::LogLevelName(level) << "}: ";
  		printList(std::cout,data.list);
  		std::cout << std::endl;
	}
}


#define LOG(a,x) (SF::log(a,SF::LogData<SF::None>() << x))
                

} //namespace SF

#endif //_SIMPLEFRAME_WORK_LOG
