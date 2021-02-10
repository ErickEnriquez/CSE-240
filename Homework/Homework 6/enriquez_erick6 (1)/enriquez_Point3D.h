#pragma once
#include<iostream>//to overwrite the stream insertion operator
class Point3D {
protected:
	//variables
	double x, y, z;

public:
	Point3D();//default constructor
	Point3D(double, double, double);//constructor with parameters

	//setters
	void setX(double);
	void setY(double);
	void setZ(double);

	//getters

	double getX();
	double getY();
	double getZ();

	//get distance
	double getDistance(Point3D*);

	//override the stream insertion operator to print the object
	friend std::ostream& operator<<(std::ostream&,  const Point3D&);
};