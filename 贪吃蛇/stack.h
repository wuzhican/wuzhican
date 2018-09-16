#pragma once

#ifndef Stack_
#define Stack_
#include <string>
template<class T>
class Stack {
private:
	T * Pbuff;//头节点指针
	size_t capapity;//容量
	size_t length;//栈长度
public:
	Stack();//构造函数
	Stack(Stack &  data);//复制构造函数（暂时为空）
	~Stack();//析构函数
	void Push(const T& data);//压入栈
	const  T &Get();//获得栈顶元素
	void Put();//弹出
	bool is_null();//栈是否为空，true为空，false为非空
};

template<class T>
Stack<T>::Stack() {
	capapity = length = 0;
	Pbuff = NULL;
}

template<class T>
Stack<T>::Stack(Stack &data) {//暂时为空


}

template<class T>
Stack<T>::~Stack() {
	delete Pbuff;
}

template<class T>
void Stack<T>::Push(const T & data) {
	if (capapity == length) {//容量已经用完，扩容
		capapity = capapity / 2 == 0 ? capapity + 1 : capapity + capapity / 2;
		T * Pbuff_ = new T[capapity];
		memcpy(Pbuff_, pbuff, capapity * sizeof(T));
		delete Pbuff;
		Pbuff = Pbuff_;
	}
	memcpy(Pbuff_ + length, &data, sizeof(T));//写入数据
	length++;
}

template<class T>
const T & Stack<T>::Get() {
	return 	Pbuff[length - 1];
}

template<class T>
void Stack<T>::Put() {
	if (length > 0)	 length--;
	else {//栈为空，输出错误信息
		using std::cout;
		cout << "the Stack is null!\a";
	}
}

template<class T>
bool Stack<T>::is_null() {
	if (length == 0)return true;
	else return false;
}

#endif // !Stack

