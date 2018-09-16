#pragma once

#ifndef Stack_
#define Stack_
#include <string>
template<class T>
class Stack {
private:
	T * Pbuff;//ͷ�ڵ�ָ��
	size_t capapity;//����
	size_t length;//ջ����
public:
	Stack();//���캯��
	Stack(Stack &  data);//���ƹ��캯������ʱΪ�գ�
	~Stack();//��������
	void Push(const T& data);//ѹ��ջ
	const  T &Get();//���ջ��Ԫ��
	void Put();//����
	bool is_null();//ջ�Ƿ�Ϊ�գ�trueΪ�գ�falseΪ�ǿ�
};

template<class T>
Stack<T>::Stack() {
	capapity = length = 0;
	Pbuff = NULL;
}

template<class T>
Stack<T>::Stack(Stack &data) {//��ʱΪ��


}

template<class T>
Stack<T>::~Stack() {
	delete Pbuff;
}

template<class T>
void Stack<T>::Push(const T & data) {
	if (capapity == length) {//�����Ѿ����꣬����
		capapity = capapity / 2 == 0 ? capapity + 1 : capapity + capapity / 2;
		T * Pbuff_ = new T[capapity];
		memcpy(Pbuff_, pbuff, capapity * sizeof(T));
		delete Pbuff;
		Pbuff = Pbuff_;
	}
	memcpy(Pbuff_ + length, &data, sizeof(T));//д������
	length++;
}

template<class T>
const T & Stack<T>::Get() {
	return 	Pbuff[length - 1];
}

template<class T>
void Stack<T>::Put() {
	if (length > 0)	 length--;
	else {//ջΪ�գ����������Ϣ
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

