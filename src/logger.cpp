
#include "logger.h"


          LogBuffer::LogBuffer(std::string system) : m_logSys(system),
                                           m_logLevel(LogLevel::INFO)
          {
          }
          LogBuffer::~LogBuffer()
          {
                               pubsync();
          }
          std::string LogBuffer::GetLogLevelString(LogLevel::level lvl)
          {
                      switch(lvl)
                      {
                                 case LogLevel::DEBUG:
                                      return "DEBUG";
                                 case LogLevel::INFO:
                                      return "INFO";
                                 case LogLevel::ERROR:
                                      return "ERROR";
                                 case LogLevel::WARNING:
                                      return "WARNING";
                                 case LogLevel::CRASH:
                                      return "CRASH";
                                 default:
                                         return "UNKNOWN";
                      }
          }
          int LogBuffer::sync()
          {
              if (str().length() != 0)
              {
                               std::cout<<"["<<m_logSys<<"] ["
                                 << GetLogLevelString(m_logLevel)<<"] "<< str();
                               str("");//Reset Buffer
              }
              return 0;
          }
          
          Logger::Logger(std::string system) 
            : std::ostream(new LogBuffer(system)),
            m_logSys(system)
            {
            
            }
          Logger::~Logger()
          {
                           delete rdbuf();
          }
          
          std::ostream& Logger::endl(std::ostream& stream)
          {
                        stream.put('\n');
                        stream.flush();
                        LogBuffer* buff = (LogBuffer*)stream.rdbuf();
                        buff->m_logLevel = LogLevel::INFO;//Reset to default level
                        return stream;
          }
          
          std::ostream& Logger::operator<<(LogLevel::level lvl)
          {
                        LogBuffer* buff = (LogBuffer*)rdbuf();
                        buff->m_logLevel = lvl;
                        return *this;
          }
