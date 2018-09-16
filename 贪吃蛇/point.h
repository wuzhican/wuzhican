#pragma once
struct Point
{
	int x;
	int y;
	Point();
	Point(Point & data);
	~Point();
	void print();
};

Point::Point() {

}

Point::Point(Point & data) {
	x = data.x;
	y = data.y;
}

Point::~Point() {

}

void Point::print() {
	using std::cout;
	cout << '(' << x << ',' << y << ')';
}
