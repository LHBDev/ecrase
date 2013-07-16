#ifndef LOGGER_H
#define LOGGER_H

#include <string> 
#include <stdarg.h>
#include <iostream>
#include <sstream>

namespace LogLevel{
                    enum level
                    {
                         DEBUG,
                         INFO,
                         WARNING,
                         ERROR,
                         CRASH
                    };
                   }
          
          class Logger;
          class LogBuffer : public std::stringbuf
          {
                private:
                        std::string m_logSys;
                        LogLevel::level m_logLevel;
                        
                        friend class Logger;
                public:
                       LogBuffer(std::string system);
                       ~LogBuffer();
                       int sync();
                       std::string GetLogLevelString(LogLevel::level lvl);
          };
          class Logger : public std::ostream
          {
                private:
                        std::string m_logSys;
                public:
                       Logger(std::string system = "core");
                       virtual ~Logger();
                       static std::ostream& endl(std::ostream& stream);
                       std::ostream&operator<<(LogLevel::level lvl);
          };


#endif /*LOGGER_H*/
          
