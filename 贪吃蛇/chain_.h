#ifndef CHAIN_
#define CHAIN_
#include<iostream>

void memcpy(const char * read, char * write, size_t size) {
	for (int i = 0; i < size; i++) {
		write[i] = read[i];
	}
}

	template<class T>
	struct Data {//链表节点数据结构
		T data;
		Data<T> * next;
		Data();//空构造函数
		Data(Data<T> & data_r);//复制构造函数
		~Data();//析构函数
	};

	template <class T>
	Data<T>::Data() {

	}

	template <class T>
	Data<T>::Data(Data<T> & data_r) {
		memcpy(&data, &data_r, sizeof(Data<T>));
	}

	template <class T>
	Data<T>::~Data() {

	}

template <class T>
class chain {
private:
	Data<T> * head;//指向头节点的指针
	size_t length;//记录链表的长度
	Data<T> &get_p(size_t place) {//用于内部访问指定节点的函数，返回的是直接应用
		Data<T> * point;
		point = head;
		for (int i = 0; i < place; i++) {
			point = (*point).next;
		}
		return *point;
	}
public:
	chain();//构造函数
	chain(chain & data);//复制构造函数
	~chain();//析构函数
	void add(const T & data);//在链表为增加节点
	void del(size_t place);//删除节点
	void swap(size_t place1, size_t place2);//交换place1和place2节点
	void inse(size_t place,bool side,const T & data);//再place前或后插入节点 side=1时再前插入，=0时再后插入 data为插入的数据
	size_t leng();//得到链表的长度
	T & get(size_t place);//获得指定位置的节点数据
};

template <class T>
chain<T>::chain() {
	head = new Data<T>;//创建头节点,length归0
	length = 0;
}

template <class T>
chain<T>::chain(chain & data) {
	for(int i = length-1; i >0 ; i--) {//清空节点数据
		del(i);
	}
	length = 0;
	for (int i = 0; i < data.length() - 1; i++) {//写入数据
		add(data.get(i));
	}
}

template <class T>
chain<T>::~chain() {
	for (int i = length-1; i >=0; i--) {//依次清除节点
		del(i);
	}
}

template <class T>
void chain<T>::add(const T &data) {
	if (length == 0) {//还未写入数据
		get_p(0).data = data;
		get_p(0).next = NULL;
		length++;
	}
	else {//第一节点已经写入，创建新节点，链接并写入数据
		get_p(length - 1).next = new Data<T>;
		length++;
		get_p(length - 1).data = data;
		get_p(length - 1).next = NULL;
	}
}

template<class T>
void chain<T>::del(size_t place) {
	if (place < length) {//检测删除节点是否超出链表长度
		if (place == 0) {//删除头节点并将head指针置为原头节点的next指针
			Data<T> * point;
			point = head;
			head = (*head).next;
			delete point;
			length--;
		}
		else if (place == length - 1) {//删除尾节点，并将新的尾节点next指针置空
			delete &get_p(place);
			length--;
			get_p(length - 1).next = NULL;
		}
		else {//删除中间节点，并链接两边的节点
			Data<T>* point;
			point = &get_p(place);
			get_p(place - 1).next = &get_p(place + 1);
			length--;
			delete point;
		}
	}
	else { std::cout << "there is no data to delete!\a"; }
}

template<class T>
void chain<T>::swap(size_t place1, size_t place2) {//将两节点数据对调
	Data<T> data;
	data = get_p(place1);
	get_p(place1) = get_p(place2);
	get_p(place2) = data;
}

template<class T>
void chain<T>::inse(size_t place, bool side, const T&data) {//side 一为前，0为后
	if (place == 0 && side) {
		Data<T> *point;
		point = new Data<T>;
		*point.next = head;
		*point.data = data;
		head = point;
		length++;
	}
	else if (place == length - 1 && !side) {
		Data<T> *point;
		point = new Data<T>;
		get_p(length - 1).next = point;
		*point.data = data;
		*point.next = NULL;
	}
	else {
		Data<T>* point1;
		Data<T>* point2;
		point1 = new Data<T>;
		*point1.data = data;
		point2=get_p(place + side).next;
		get_p(place + side).next = point1;
		*point1.next = point2;
	}
}

template<class T>
size_t chain<T>::leng() {
	return length;
}

template <class T>
 T &chain<T>::get(size_t place) {
	return get_p(place).data;
}

#endif