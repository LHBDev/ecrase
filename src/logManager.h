#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <map>

#include "logger.h"

class logManager
{
      private:
              static std::map<std::string, Logger*> m_loggers;
      public:
             logManager();
             virtual ~logManager();
             static bool Startup();
             static void Shutdown();
             static Logger& Get(std::string logNamge = "Ecrase");
};

#endif /*LOGMANAGER_H*/
