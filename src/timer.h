#ifndef TIMER_H
#define TIMER_H

#include <thread>

namespace platform
{
          /** Poll/select timing functions, accurate to milliseconds*/
          void SleepMillis(long millis);
          //calls function after given time(ms)
          void FutureCall(long millis, std::function<void(void*)>function, void* params);
}

#endif /*TIMER_H*/
