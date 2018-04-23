#pragma once

class Point {
private:
	double x;
	double y;
public:
	Point() = default;  // позволяет создавать пустые
						/*Point() :x(0), y(0);*/
	Point(double x, double y) : x(x), y(y) {}
	double getX() { return x; }
	double getY() { return y; }

	void setXY(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
};