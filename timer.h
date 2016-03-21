 ///
 /// @file    timer.h
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-21 04:01:59
 ///

#ifndef __TIMER_H__
#define __TIMER_H__


#include "nocopyable.h"
#include <functional>
#include <iostream>

namespace yy{
	class Timer : Nocopyable{
		public:
			typedef std::function<void()> TimerCallback;
			Timer(TimerCallback tb,int init_sec,int interval_sec);
			~Timer();

			void start();
			void stop();

		private:
			TimerCallback _tb;
			int _fd;
			bool _isStart;
	};

}

#endif
