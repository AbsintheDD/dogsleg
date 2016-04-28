#ifndef _CORE_H
#define _CORE_H

#include "includes.h"

#define eps 0.000001

void wait();

class Point
{
	double x;
	double y;
	double z;
public:
	Point(double=0.0, double=0.0, double=0.0);
	Point(const Point &);
	double &_x();
	double &_y();
	double &_z();
};

double dist(Point, Point);

class Vector
{
	double x;
	double y;
	double z;
public:
	Vector(double=0.0, double=0.0, double=0.0);
	Vector(const Vector &);
	double &_x();
	double &_y();
	double &_z();
};

class Line
{
	Point P;
	Vector V;
public:
	Line(Point, Vector);
	Line(const Line &);
	Point _P();
	Vector _V();
	Point cut_x(double, double &);
	Point cut_y(double, double &);
	Point cut_z(double, double &);
};

class Polyhon
{
	double xs;	double xe;
	double ys;	double ye;
	double zs;	double ze;
public:
	Polyhon(double, double,
		double, double,
		double, double);
	bool cut(Line, double &, Point &, double &, Point &);
};

#endif