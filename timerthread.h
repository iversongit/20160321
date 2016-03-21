 ///
 /// @file    timerthread.h
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-21 06:21:12
 ///

 
#ifndef __TIMERTHREAD_H__
#define __TIMERTHREAD_H__

#include "thread.h"
#include "timer.h"
#include <functional>
#include <iostream>

namespace yy{
	class TimerThread{
		public:
			typedef std::function<void()> TimerThreadCallback;
			TimerThread(TimerThreadCallback cb,int init_sec,int interval_sec);

			void start();
			void stop();
		private:  //组合的方式
			Thread _thread;
			Timer _timer;
	};
}
#endif
