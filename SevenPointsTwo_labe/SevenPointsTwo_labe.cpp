#include <iostream>
#include <stdarg.h>
#include <cmath>
using namespace std;

int sideLength(int x1, int y1, int x2, int y2) {
	return sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2));
}

int square(int x1, int y1, int x2, int y2, int x3, int y3) {
	double AB = sideLength(x1, y1, x2, y2);
	double BC = sideLength(x2, y2, x3, y3);
	double CD = sideLength(x3, y3, x1, y1);
	double per = (AB + BC + CD) / 2;
	return sqrt(per * (per - AB) * (per - BC) * (per - CD));
}

double square1(int pointNum, ...) {
	va_list values;
	va_start(values, pointNum);

	double allCount = 0;
	int x1, x2, y1, y2, x3, y3;
	x1 = va_arg(values, int);
	y1 = va_arg(values, int);
	x2 = va_arg(values, int);
	y2 = va_arg(values, int);
	x3 = va_arg(values, int);
	y3 = va_arg(values, int);
	allCount += square(x1, y1, x2, y2, x3, y3);
	for (int i = 0; i < pointNum / 2 - 3; i++)
	{
		x2 = x3;
		y2 = y3;
		x3 = va_arg(values, int);
		y3 = va_arg(values, int);
		allCount += square(x1, y1, x2, y2, x3, y3);
	}
	va_end(values);
	return allCount;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int x1, y1, x2, y2, x3, y3;

	cout << "Введите координаты x и y точки начала отрезка: ";
	cin >> x1 >> y1;
	cout << "Введите координаты x и y точки конца отрезка: ";
	cin >> x2 >> y2;

	cout << "Длинна отрезка равна: " <<  sideLength(x1, y1, x2, y2) << endl;

	/*__________________________________________________________________________*/

	cout << "Площадь треугольника равна: " << square(0, 0, 7, 1, 1, 7) << endl;

	/*__________________________________________________________________________*/

	cout <<"Площадь треугольника, содержащего диагональ наиболь-шей длины выпуклого" <<
		" многоугольника, заданного коорди - натами своих вершин : " << square1(8, 0, 0, 1, 0, 3, 8, 1, 4, 0, 2, -4, 3) << endl;
	return 0;
}