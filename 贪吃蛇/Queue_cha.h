#pragma once
#include"chain_.h"

template<class T>
class Queue {
private:
	chain<T> chain;

public:
	Queue();
	Queue(Queue & data);
	~Queue();
	void push();
	const T &get();
	void put();
	chain<T> & get_cha();
};
