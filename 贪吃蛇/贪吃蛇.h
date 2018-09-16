
#ifndef SNACK_
#define SNACK_
#include "Stack.h"
#include"point.h"
#include<string>
using std::string;




class Snack {
private:
	enum side {
		up,down,left,right
	}ahead_side ;//前进方向
	Queue<Point> snack;
	Point * Head;

public:
	Snack();
	~Snack();
	bool is_beat();
	void go();
	void grow(size_t length);
};

Snack::Snack() {
	ahead_side = right;
	Point begin;
	snack.Push(begin);
}

Snack::~Snack() {

}

bool Snack::is_beat() {

}

void Snack::go() {

}

void Snack::grow(size_t length) {

}


class Map {
private:
	string * map;
	size_t LONG;
	size_t WIDE;
public:
	Map(size_t size);
	~Map();
	const string & read(const Point & place);
	void write(const Point & place, string & data);
};

Map::Map(size_t size) {

}

Map::~Map() {

}

const string & Map::read(const Point &place) {

}

void Map::write(const Point & place, string & data) {

}


#endif // !SNACK_

