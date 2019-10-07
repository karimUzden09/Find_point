#include<iostream>
#include<math.h>
#include<string>
#include <fcntl.h>
#include<io.h>

using namespace std;

struct point
{
	point(int32_t X=0, int32_t Y=0):x(X),y(Y){}
	int32_t x, y;
};
struct Square
{
	
	 Square(point a, point b, point c,point d);
	point a, b, c,d ;
};
Square::Square(point a, point b, point c,point d)
{
	this->a.x = a.x;
	this->a.y = a.y;

	this->b.x = b.x;
	this->b.y = b.y;

	this->c.x = c.x;
	this->c.y = c.y;

	this->d.x = d.x;
	this->d.y = d.y;
}
bool IsInTriangle(point p, point a, point b, point c) {
	int aSide = (a.y - b.y) * p.x + (b.x - a.x) * p.y + (a.x * b.y - b.x * a.y);
	int bSide = (b.y - c.y) * p.x + (c.x - b.x) * p.y + (b.x * c.y - c.x * b.y);
	int cSide = (c.y - a.y) * p.x + (a.x - c.x) * p.y + (c.x * a.y - a.x * c.y);

	return (aSide >= 0 && bSide >= 0 && cSide >= 0) || (aSide < 0 && bSide < 0 && cSide < 0);
}
void FindTriangle(Square sq,point test_point) {
	point o(0, 0);
	if (IsInTriangle(test_point,sq.a,sq.d,o) || IsInTriangle(test_point,sq.b,sq.c,o))
	{
		wcout << L"True!!!" << endl;
	}
	else
	{
		wcout << L"False" << endl;
	}
	
}
void locale_to_russ() {// дл€ отоброжени€ русских символов
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);
}

int main() {

	locale_to_russ();
	point a(0, 5);
	point b(5, 0);
	point c(0, -5);
	point d(-5, 0);
	Square sq(a, b, c, d);
	wcout << L"¬ведите координаты точки x" << endl;
	int x = 0; int y = 0;
	wcin >> x;
	wcout << L"¬ведите координаты точки y" << endl;
	wcin >> y;
	point test(x, y);

	FindTriangle(sq,test);
	return 0;
}