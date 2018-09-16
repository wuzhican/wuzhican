#ifndef CHAIN_
#define CHAIN_
#include<iostream>

void memcpy(const char * read, char * write, size_t size) {
	for (int i = 0; i < size; i++) {
		write[i] = read[i];
	}
}

	template<class T>
	struct Data {//����ڵ����ݽṹ
		T data;
		Data<T> * next;
		Data();//�չ��캯��
		Data(Data<T> & data_r);//���ƹ��캯��
		~Data();//��������
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
	Data<T> * head;//ָ��ͷ�ڵ��ָ��
	size_t length;//��¼����ĳ���
	Data<T> &get_p(size_t place) {//�����ڲ�����ָ���ڵ�ĺ��������ص���ֱ��Ӧ��
		Data<T> * point;
		point = head;
		for (int i = 0; i < place; i++) {
			point = (*point).next;
		}
		return *point;
	}
public:
	chain();//���캯��
	chain(chain & data);//���ƹ��캯��
	~chain();//��������
	void add(const T & data);//������Ϊ���ӽڵ�
	void del(size_t place);//ɾ���ڵ�
	void swap(size_t place1, size_t place2);//����place1��place2�ڵ�
	void inse(size_t place,bool side,const T & data);//��placeǰ������ڵ� side=1ʱ��ǰ���룬=0ʱ�ٺ���� dataΪ���������
	size_t leng();//�õ�����ĳ���
	T & get(size_t place);//���ָ��λ�õĽڵ�����
};

template <class T>
chain<T>::chain() {
	head = new Data<T>;//����ͷ�ڵ�,length��0
	length = 0;
}

template <class T>
chain<T>::chain(chain & data) {
	for(int i = length-1; i >0 ; i--) {//��սڵ�����
		del(i);
	}
	length = 0;
	for (int i = 0; i < data.length() - 1; i++) {//д������
		add(data.get(i));
	}
}

template <class T>
chain<T>::~chain() {
	for (int i = length-1; i >=0; i--) {//��������ڵ�
		del(i);
	}
}

template <class T>
void chain<T>::add(const T &data) {
	if (length == 0) {//��δд������
		get_p(0).data = data;
		get_p(0).next = NULL;
		length++;
	}
	else {//��һ�ڵ��Ѿ�д�룬�����½ڵ㣬���Ӳ�д������
		get_p(length - 1).next = new Data<T>;
		length++;
		get_p(length - 1).data = data;
		get_p(length - 1).next = NULL;
	}
}

template<class T>
void chain<T>::del(size_t place) {
	if (place < length) {//���ɾ���ڵ��Ƿ񳬳�������
		if (place == 0) {//ɾ��ͷ�ڵ㲢��headָ����Ϊԭͷ�ڵ��nextָ��
			Data<T> * point;
			point = head;
			head = (*head).next;
			delete point;
			length--;
		}
		else if (place == length - 1) {//ɾ��β�ڵ㣬�����µ�β�ڵ�nextָ���ÿ�
			delete &get_p(place);
			length--;
			get_p(length - 1).next = NULL;
		}
		else {//ɾ���м�ڵ㣬���������ߵĽڵ�
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
void chain<T>::swap(size_t place1, size_t place2) {//�����ڵ����ݶԵ�
	Data<T> data;
	data = get_p(place1);
	get_p(place1) = get_p(place2);
	get_p(place2) = data;
}

template<class T>
void chain<T>::inse(size_t place, bool side, const T&data) {//side һΪǰ��0Ϊ��
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