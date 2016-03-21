 ///
 /// @file    test_timer.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-21 07:03:24
 ///

#include "thread.h"
#include "timer.h"
#include "timerthread.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <iostream>

using std::cout;
using std::endl;

	struct Product{
		void produce(){
			srand(time(NULL));
			int num = rand() % 100;
			cout<<"produce a num -->"<<num<<endl;
		}
	};

	int main(void){
		Product product;
		yy::TimerThread timer(std::bind(&Product::produce,&product),2,3);
		timer.start();
		sleep(20);
		timer.stop();
		return 0;
	}

