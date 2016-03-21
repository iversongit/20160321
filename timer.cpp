 ///
 /// @file    timer.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-21 04:10:28
 ///

#include "timer.h"
#include <stdio.h>
#include <unistd.h>
#include <poll.h>
#include <sys/timerfd.h>
#include <iostream>

namespace yy{
	int createTimerFd(){
		int fd = timerfd_create(CLOCK_REALTIME,0);
		if(-1 == fd){
			perror("timeerfd_create error!");
			return 0;
		}
		return fd;
	}
	
	void setTimerFd(int fd,int init_sec,int interval_sec){
		struct itimerspec it;
		it.it_value.tv_sec = init_sec;
		it.it_value.tv_nsec = 0;
		it.it_interval.tv_sec = interval_sec;
		it.it_interval.tv_nsec = 0;
		int ret = timerfd_settime(fd,0,&it,NULL);
		if(-1 == ret){
			perror("timerfd_settime error!");
			return;
		}
	}

	void stopTimerFd(int fd){
		setTimerFd(fd,0,0);
	}

	int readTimerFd(int fd){
		uint64_t howmany;
		ssize_t ret = read(fd,&howmany,sizeof(howmany));
		if(ret != sizeof(howmany)){
			perror("readtimefd error!");
			return 0;
		}
		return howmany;
	}

	Timer::Timer(TimerCallback tb,int init_sec,int interval_sec)
	:_fd(createTimerFd())
	,_tb(tb)
	,_isStart(false)
	{
		setTimerFd(_fd,init_sec,interval_sec);
	}

	Timer::~Timer(){
		if(_isStart)
			stop();
	}

	void Timer::start(){
		_isStart = true;
		struct pollfd pfd;
		pfd.fd = _fd;        //监听定时器文件描述符
		pfd.events = POLLIN; //监听读事件
		while(_isStart){
			int ret = poll(&pfd,1,5000); //poll函数是一个阻塞式的函数
			if(-1 == ret){
				if(errno == EINTR) continue;
				else{
					perror("poll error!");
					exit(0);
				}
			}else if(0 == ret){
				perror("no fd,time out!");
			}else{
				if(pfd.revents == POLLIN){
					readTimerFd(_fd);
					if(_tb) _tb();
				}
			}
		}
	}

	void Timer::stop(){
		if(_isStart){
			stopTimerFd(_fd);
			_isStart = false;
		}
	}

	

}

