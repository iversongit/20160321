 ///
 /// @file    timerthread.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-21 06:51:22
 ///

#include "timerthread.h"
#include <iostream>

namespace yy{
	TimerThread::TimerThread(TimerThreadCallback cb,int init_sec,int interval_sec)
	:_timer(cb,init_sec,interval_sec)
	,_thread(std::bind(&Timer::start,&_timer))
	{
	
	}

	void TimerThread::start(){
		_thread.start();
	}

	void TimerThread::stop(){
		_timer.stop();
	}
	
	
}


