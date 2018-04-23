/*Разработать класс Rectangle (прямоугольник) со сторонами параллельными осям координат. Поля класса должны быть
объектами класса Point (точка). Класс должен содержать: конструктор по умолчанию, конструктор с параметрами,
при необходимости реализовать деструктор и конструктор копирования.
Добавить методы для:
□	перемещения прямоугольника вдоль осей+
□	изменения размера прямоугольника+
□	определения площади,+
периметра прямоугольника-
□	метод для проверки на равенство  двух прямоугольников+
□	вывод на экран информации об объекте
□	для копирования объектов
□	остальные методы на усмотрение разработчика(методы set и get)
Написать интерфейс для работы с классом. Реализовать динамический массив объектов класса с возможностью добавления,
удаления объектов из массива. Реализовать возможность записи информации об объектах массива в текстовый файл, бинарный файл.
*/

#include <iostream>
#include<string>
#include<ctime>
#include<fstream> // библиотека работы с файлами

#include "Point.h"
#include"Rectangle.h"

using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int k;
	cout << "Enter tasks number:";
	cin >> k;

	switch (k) {

	case 1: {

	} break;

		//point
	case 2: {
		ifstream in;
		ofstream out;
		out.open("write.txt", ios::out); // для вывода, файл если создан, то перезаписывается
										 /*out.open("write.txt", ios::app); //если файл существет, пишется дальше*/

		in.open("read.txt");
		Point p[5];
		double x, y;
		int i = 0;
		if (!in) {
			cerr << "file open erros" << endl;
		}
		else
		{
			while (!in.eof()) {
				in >> x >> y;
				p[i++].setXY(x, y);
			}
		}
		for (int k = 0; k < i; k++) {
			cout << p[k].getX() << "\t" << p[k].getY() << endl;
			out << p[k].getX() << "\t" << p[k].getY() << endl;
		}
		out.close();
		system("pause");
	} break;

	case 3: {
		ifstream in;
		ofstream out;
		out.open("write.txt", ios::out); // для вывода, файл если создан, то перезаписывается
										 /*out.open("write.txt", ios::app); //если файл существет, пишется дальше*/
		in.open("read.txt");
		Rectangle p[8];
		double xa, ya, xb, yb, xc, yc, xd, yd;
		int i = 0;
		if (!in) {
			cerr << "file open errors" << endl;
		}
		else
		{
			while (!in.eof()) {
				in >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
				Rectangle R(xa, ya, xb, yb, xc, yc, xd, yd);
				p[i++] = R;
			}
		}
		for (int k = 0; k < i; k++) {
			out << p[k].getXA() << "\t" << p[k].getYA() << "\t" << p[k].getXB() << "\t" << p[k].getYB() << "\t" <<
				p[k].getXC() << "\t" << p[k].getYC() << "\t" << p[k].getXD() << "\t" << p[k].getYD() << endl;
		}
		out.close();
		system("pause");
	}break;
		//сдвиг по оси
	case 4: {
		ifstream in;
		ofstream out;
		out.open("write.txt", ios::out); // для вывода, файл если создан, то перезаписывается
										 /*out.open("write.txt", ios::app); //если файл существет, пишется дальше*/
		in.open("read.txt");
		Rectangle *p;
		p = new Rectangle[5];
		double xa, ya, xb, yb, xc, yc, xd, yd;
		int i = 0;

		if (!in) {
			cerr << "file open erros" << endl;
		}
		else
		{
			while (!in.eof()) {
				in >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
				Rectangle R(xa, ya, xb, yb, xc, yc, xd, yd);
				p[i++] = R;
				cout << p->getXA() << "\n" << p->getYA() << "\n" << p->getXB() << "\n" << p->getYB() << "\n" <<
					p->getXC() << "\n" << p->getYC() << "\n" << p->getXD() << "\n" << p->getYD() << endl;
			}
		}
		for (int k = 0; k < i; k++) {
			p[k].move('x', 5);
			/*cout<< p[k].getXA() << "\n" << p[k].getYA() << "\n" << p[k].getXB() << "\n" << p[k].getYB() << "\n" <<
				p[k].getXC() << "\n" << p[k].getYC() << "\n" << p[k].getXD() << "\n" << p[k].getYD() << endl;*/
			out << p[k].getXA() << "\n" << p[k].getYA() << "\n" << p[k].getXB() << "\n" << p[k].getYB() << "\n" <<
				p[k].getXC() << "\n" << p[k].getYC() << "\n" << p[k].getXD() << "\n" << p[k].getYD() << endl;
		}
		out.close();
		system("pause");
	}break;

		//resize
	case 5: {
		ifstream in;
		ofstream out;
		out.open("write.txt", ios::out); // для вывода, файл если создан, то перезаписывается
										 /*out.open("write.txt", ios::app); //если файл существет, пишется дальше*/
		in.open("Read1.txt");
		double xCenter, yCenter, sideA, sideB;
		Rectangle *p;
		p = new Rectangle[4];
			
		int i = 0;
		if (!in) {
			cerr << "file open erros" << endl;
		}
		else
		{
			while (!in.eof()) {
				in >> xCenter >> yCenter >> sideA >> sideB;
				Rectangle R(xCenter, yCenter, sideA, sideB);
				p[i++] = R;

			}}
		for (int k = 0; k < i; k++) {
			p[0].resize(2, 5);
			out << p[k].getXA() << "\t" << p[k].getYA() << "\t" <<
				p[k].getXB() << "\t" << p[k].getYB() << "\t" <<
				p[k].getXC() << "\t" << p[k].getYC() << "\t" <<
				p[k].getXD() << "\t" << p[k].getYD() << endl;
		}
		out.close();
		system("pause");
	}break;

		//Площадь
	case 6: {
		ifstream in;
		ofstream out;
		out.open("write.txt");
		in.open("Read1.txt");
		double xCenter, yCenter, sideA, sideB;
		Rectangle *p;
		p = new Rectangle[2];

		int i = 0;
		if (!in) {
			cerr << "file open error" << endl;}
		else
		{
			while (!in.eof()) {
				in >> xCenter >> yCenter >> sideA >> sideB;
				Rectangle R(xCenter, yCenter, sideA, sideB);
				p[i] = R;
				cout << "area:" << p[i].area() << endl;
				i++;
			}}

		out.close();
		system("pause");
	}break;

		//Perimetr
	case 7: {
		ifstream in;
		ofstream out;
		out.open("write.txt");
		in.open("Read1.txt");
		double xCenter, yCenter, sideA, sideB;
		Rectangle *p;
		p = new Rectangle[2];

		int i = 0;
		if (!in) {
			cerr << "file open error" << endl;
		}
		else
		{
			while (!in.eof()) {
				in >> xCenter >> yCenter >> sideA >> sideB;
				Rectangle R(xCenter, yCenter, sideA, sideB);
				p[i] = R;
				cout << "Perimetr:" << p[i].Perimetr() << endl;
				i++;
			}
		}

		out.close();
		system("pause");
	}break;
		//compare
	case 8: {
		ifstream in;
		ofstream out;
		out.open("write.txt");
		in.open("Read2.txt");
		double xCenter, yCenter, sideA, sideB;
		Rectangle *p;
		p = new Rectangle[2];

		int i = 0;
		if (!in) {
			cerr << "file open error" << endl;
		}
		else
		{
			while (!in.eof()) {
					in >> xCenter >> yCenter >> sideA >> sideB;
					Rectangle R(xCenter, yCenter, sideA, sideB);
					p[i] = R;
					cout << i << "\t" << p[i].getSideA() << "\t" << p[i].getSideB() << endl;
					i++;
			}
			cout << "Compare:" << p[0].compare(p[1]) << endl;
		}
		
			
		

		out.close();
		system("pause");
	}break;
		system("pause");
		return 0;
	}
}