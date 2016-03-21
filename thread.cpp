 ///
 /// @file    thread.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-19 00:30:18
 ///

#include "thread.h"
#include <iostream>

namespace yy{
	Thread::Thread(ThreadCallback cb)
	:_phid(0)
	,_isRunning(false)
	,_cb(cb)
	{
	}

	Thread::~Thread(){
		if(_isRunning)
			pthread_detach(_phid);
	}

	void Thread::start(){
		pthread_create(&_phid,NULL,&Thread::threadFunc,this);
		_isRunning = true;
	}

	void Thread::join(){
		if(_isRunning)
			pthread_join(_phid,NULL);
	}

	void * Thread::threadFunc(void * arg){
		Thread * thread = static_cast<Thread *>(arg);
		if(thread)	thread->_cb();
	}
}
