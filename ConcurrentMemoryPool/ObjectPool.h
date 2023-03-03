//
// Created by 旭哥 on 2023-02-19.
//

#ifndef CONCURRENTMEMORYPOOL__OBJECTPOOL_H
#define CONCURRENTMEMORYPOOL__OBJECTPOOL_H

#include <iostream>
using std::endl;
using std::cout;

// 定长内存池

//// 方式一
//template<size_t N>
//class ObjectPool
//{};

// 方式二
template<class T>
class ObjectPool
{
public:
	T* New()
	{
		if (_memory == nullptr)
		{
			_memory = (char*)malloc(128 * 1024);
			if (_memory == nullptr)
			{
				throw std::bad_alloc();
			}
		}

		T* obj = (T*)_memory; // 给T对象分配内存空间
		_memory += sizeof(T);

		return obj;
	}
private:
	char* _memory = nullptr; // 一次向系统申请一大块内存
	void* _freeList = nullptr; // 链表，维护释放的内存
};


#endif//CONCURRENTMEMORYPOOL__OBJECTPOOL_H
