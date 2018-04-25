#include<iostream>
#include"Rectangle.h"


Rectangle::Rectangle(double xa, double ya, double xb, double yb, double xc, double yc, double xd, double yd) {
	a.setXY(xa, ya);
	b.setXY(xb, yb);
	c.setXY(xc, yc);
	c.setXY(xd, yd);
}

Rectangle::Rectangle(double xCenter, double yCenter, double sideA, double sideB)
{
	this->sideA = sideA;
	this->sideB = sideB;
	center.setXY(xCenter, yCenter);
	a.getX() = xCenter - sideA / 2;
	a.getY() = yCenter - sideB / 2;

	b.getX() = xCenter - sideA / 2;
	b.getY() = yCenter + sideB / 2;

	c.getX() = xCenter + sideA / 2;
	c.getY() = yCenter + sideB / 2;

	d.getX() = xCenter + sideA / 2;
	d.getY() = yCenter - sideB / 2;

}
Rectangle::Rectangle(double xCenter, double yCenter, double sideA, double sideB, int size)
{
	this->cur_size = size;
	this->buf_size = size;
	this->sideA = sideA;
	this->sideB = sideB;
	center.setXY(xCenter, yCenter);
	a.getX() = xCenter - sideA / 2;
	a.getY() = yCenter - sideB / 2;

	b.getX() = xCenter - sideA / 2;
	b.getY() = yCenter + sideB / 2;

	c.getX() = xCenter + sideA / 2;
	c.getY() = yCenter + sideB / 2;

	d.getX() = xCenter + sideA / 2;
	d.getY() = yCenter - sideB / 2;

}
void Rectangle::move(char direction, double value) {
	if (direction == 'x' || direction == 'X')
	{
		a.getX() += value;
		b.getX() += value;
		c.getX() += value;
		d.getX() += value;
	}
	else if (direction == 'y' || direction == 'Y')
	{
		a.getY() += value;
		b.getY() += value;
		c.getY() += value;
		d.getY() += value;
	}
	else {
		std::cerr << "wrong direction" << std::endl;
	}
}

void Rectangle::coordinates(double xCenter, double yCenter, double &sideA, double& sideB)
{
	
	this->sideA = sideA;
	this->sideB = sideB;
	center.setXY(xCenter, yCenter);
	a.getX() = xCenter - sideA / 2;
	a.getY() = yCenter - sideB / 2;

	b.getX() = xCenter - sideA / 2;
	b.getY() = yCenter + sideB / 2;

	c.getX() = xCenter + sideA / 2;
	c.getY() = yCenter + sideB / 2;

	d.getX() = xCenter + sideA / 2;
	d.getY() = yCenter - sideB / 2;

}

void Rectangle::resize(double X, double Y) {
	sideA += X;
	sideB += Y;
	std::cout << center.getX() << "\t" << center.getY() << std::endl;
	coordinates(center.getX(), center.getY(), sideA, sideB);
}

const double Rectangle::area() {
	return (this->sideA*this->sideB);
}

bool Rectangle::compare(Rectangle obj) {
	if ((this->area() == obj.area()) && (this->sideA == obj.sideA || this->sideA == obj.sideB))
		return 1;
	else return 0;
}

const double Rectangle::Perimetr() {
	return (this->sideA*2+this->sideB*2);
}

//Rectangle& Rectangle::push_back(const Rectangle &rec) {
//	if (cur_size >= buf_size)
//	{
//		Rectangle *temp;// сразу удаляется по завершению условия
//		buf_size *= 2;
//		temp = new Rectangle[buf_size];
//		for (int i = 0; i < cur_size; i++)
//		{
//			temp[i] = p[i];
//		}
//		delete[]&p;
//		p = temp;
//	}
//	p[cur_size++] = rec;
//}

void Rectangle::print() {
	for (int i = 0; i < cur_size; i++)
		std::cout << this->getSideA() << "\t" << this->getSideB() << std::endl; // поле размером 5
	
}