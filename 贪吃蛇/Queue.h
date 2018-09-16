#ifndef Queue_
#define Queue_
#include<string>
#include"chain_.h"

void memcpy(const char * read, char * write, size_t size) {
	for (int i = 0; i < size; i++) {
		write[i] = read[i];
	}
}

template<class T>
class Queue {//���������²���
private:
	T * Head;//ͷָ��
	T * Tail;//�ӵ�
	T * Pbuff;
	chain<T> chain;
	size_t length;
	size_t capapity;

public:
	Queue();//���캯��
	Queue(Queue & data);//���ƹ��캯��
	~Queue();//��������

	void Push(const T & data);//ѹ��ջ����
	void Put();//��������
	const T & Get();//���ջ��Ԫ��
};

template <class T>
Queue<T>::Queue() {
	
}

template<class T>
Queue<T>::Queue(Queue & data) {
	data.
}

template <class T>
Queue<T>::~Queue() {
	delete Pbuff;
	Head = Tail = NULL;
	capapity = length = 0;
}

template <class T>
void Queue<T>::Push(const T& data) {
	//�ڴ����
	if (Tail - Pbuff == capapity - 1) {
		if (length <= capapity / 2) {
			memcpy(Pbuff, Head, length * sizeof(T));
			Head = Pbuff;
			Tail = Head + length-1;
		}
		else {
			capapity += capapity / 2 ? 1 : capapity / 2;
			T *Pbuff_ = new T[capapity];
			memcpy(Pbuff_, Head, length * sizeof(T));
			delete Pbuff;
			Pbuff = Pbuff_;
			Head = Pbuff;
			Tail = Head + length-1;
		}
	}
	//д������
	length++;
	Tail = Head + (!length?0:length-1);
	memcpy(Tail, &data, sizeof(T));
}

template <class T>
void Queue<T>::Put() {
	if (length > 0) {
		Head++;
		length--;
	}
}

template<class T>
const T & Queue<T>::Get() {
	return Head[0];
}

#endif // !Queue_
