#include "logManager.h"

std::map<std::string, Logger*> logManager::m_loggers;
logManager::logManager(){}
logManager::~logManager(){}
bool logManager::Startup(){return true;}
void logManager::Shutdown()
{
     for(std::map<std::string, Logger*>::iterator iter = m_loggers.begin();iter != m_loggers.end();iter++)
     {
           Logger* logger = (Logger*)iter->second;
           delete logger;
     }
}

Logger& logManager::Get(std::string logName)
{
        if(m_loggers.find(logName) == m_loggers.end())
        {
                m_loggers[logName] = new Logger(logName);
        }
        return *m_loggers[logName];
}
