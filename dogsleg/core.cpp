#include "core.h"

// side

void wait()
{
	char temp;
	cout << endl << "type any symbol..." << endl;
	cin >> temp;
}

// Point

Point::Point(double arg1, double arg2, double arg3)
{
	x = arg1;
	y = arg2;
	z = arg3;
}

Point::Point(const Point &arg)
{
	x = arg.x;
	y = arg.y;
	z = arg.z;
}

double &Point::_x()
{
	return x;
}

double &Point::_y()
{
	return y;
}

double &Point::_z()
{
	return z;
}

// side

double dist(Point arg1, Point arg2)
{
	return sqrt((arg1._x() - arg2._x())*(arg1._x() - arg2._x()) + (arg1._y() - arg2._y())*(arg1._y() - arg2._y()) + (arg1._z() - arg2._z())*(arg1._z() - arg2._z()));
}

// Vector

Vector::Vector(double arg1, double arg2, double arg3)
{
	x = arg1;
	y = arg2;
	z = arg3;
}

Vector::Vector(const Vector &arg)
{
	x = arg.x;
	y = arg.y;
	z = arg.z;
}

double &Vector::_x()
{
	return x;
}

double &Vector::_y()
{
	return y;
}

double &Vector::_z()
{
	return z;
}

// Line

Line::Line(Point arg1, Vector arg2)
{
	P._x() = arg1._x();
	P._y() = arg1._y();
	P._z() = arg1._z();
	V._x() = arg2._x();
	V._y() = arg2._y();
	V._z() = arg2._z();
}

Line::Line(const Line &arg)
{
	P = arg.P;
	V = arg.V;
}

Point Line::_P()
{
	return P;
}

Vector Line::_V()
{
	return V;
}

Point Line::cut_x(double arg, double &t)
{
	t = (arg - P._x()) / V._x();
	Point temp(arg, P._y() + t*V._y(), P._z() + t*V._z());
	return temp;
}

Point Line::cut_y(double arg, double &t)
{
	t = (arg - P._y()) / V._y();
	Point temp(P._x() + t*V._x(), arg, P._z() + t*V._z());
	return temp;
}

Point Line::cut_z(double arg, double &t)
{
	t = (arg - P._z()) / V._z();
	Point temp(P._x() + t*V._x(), P._y() + t*V._y(), arg);
	return temp;
}

// Polyhon

Polyhon::Polyhon(double arg1, double arg2,
	double arg3, double arg4,
	double arg5, double arg6)
{
	xs = arg1; xe = arg2;
	ys = arg3; ye = arg4;
	zs = arg5; ze = arg6;
}

bool Polyhon::cut(Line arg1, double &t1, Point &P1, double &t2, Point &P2)
{
	double txs, txe, tys, tye, tzs, tze;
	Point Pxs = arg1.cut_x(xs, txs),
		Pxe = arg1.cut_x(xe, txe),
		Pys = arg1.cut_y(ys, tys),
		Pye = arg1.cut_y(ye, tye),
		Pzs = arg1.cut_z(zs, tzs),
		Pze = arg1.cut_z(ze, tze);
	int i = 0;
	if ((Pxs._y() >= ys) && (Pxs._y() <= ye) && (Pxs._z() >= zs) && (Pxs._z() <= ze))
	{
		i++;
		if (i == 1)
		{
			t1 = txs;
			P1 = Pxs;
		}
		if ((i == 2) && fabs(txs - t1)>eps)
		{
			t2 = txs;
			P2 = Pxs;
		}
	}
	if ((Pxe._y() >= ys) && (Pxe._y() <= ye) && (Pxe._z() >= zs) && (Pxe._z() <= ze))
	{
		i++;
		if (i == 1)
		{
			t1 = txe;
			P1 = Pxe;
		}
		if ((i == 2) && fabs(txe - t1)>eps)
		{
			t2 = txe;
			P2 = Pxe;
		}
	}
	if ((Pys._x() >= xs) && (Pys._x() <= xe) && (Pys._z() >= zs) && (Pys._z() <= ze))
	{
		i++;
		if (i == 1)
		{
			t1 = tys;
			P1 = Pys;
		}
		if ((i == 2) && fabs(tys-t1)>eps)
		{
			t2 = tys;
			P2 = Pys;
		}
	}
	if ((Pye._x() >= xs) && (Pye._x() <= xe) && (Pye._z() >= zs) && (Pye._z() <= ze))
	{
		i++;
		if (i == 1)
		{
			t1 = tye;
			P1 = Pye;
		}
		if ((i == 2) && fabs(tye - t1)>eps)
		{
			t2 = tye;
			P2 = Pye;
		}
	}
	if ((Pzs._x() >= xs) && (Pzs._x() <= xe) && (Pzs._y() >= ys) && (Pzs._y() <= ye))
	{
		i++;
		if (i == 1)
		{
			t1 = tzs;
			P1 = Pzs;
		}
		if ((i == 2) && fabs(tzs - t1)>eps)
		{
			t2 = tzs;
			P2 = Pzs;
		}
	}
	if ((Pze._x() >= xs) && (Pze._x() <= xe) && (Pze._y() >= ys) && (Pze._y() <= ye))
	{
		i++;
		if (i == 1)
		{
			t1 = tze;
			P1 = Pze;
		}
		if ((i == 2) && fabs(tze - t1)>eps)
		{
			t2 = tze;
			P2 = Pze;
		}
	}
	if (i == 0)
		return false;
	else if (i == 1)
	{
		t2 = t1;
		P2 = P1;
		return true;
	}
	else
		return true;
}