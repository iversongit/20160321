 ///
 /// @file    nocopyable.h
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-20 23:27:55
 ///

#ifndef __NOCOPYABLE_H__
#define __NOCOPYABLE_H__

namespace yy{
	class Nocopyable{
		public:
			Nocopyable(){}
		private:
			Nocopyable(const Nocopyable & rhs);
			Nocopyable & operator =(const Nocopyable & rhs);
	};
}
#endif
