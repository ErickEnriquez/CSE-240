#include "enriquez_Point3D.h"
#include <math.h>// for the sqrt function
#include <iostream>// to overwrite the << operator


//default constructor
Point3D::Point3D() {

}

/*constructor with parameters*/
Point3D::Point3D(double xIn, double yIn, double zIn) {
	this->x = xIn;
	this->y = yIn;
	this->z = zIn;
}

/*setters*/
void Point3D::setX(double xIn) {
	this->x = xIn;
}
void Point3D::setY(double yIn) {
	this->y = yIn;
}
void Point3D::setZ(double zIn) {
	this->z = zIn;
}
/*getters*/
double Point3D::getX() {
	return this->x;
}
double Point3D::getY() {
	return this->y;
}
double Point3D::getZ() {
	return this->z;
}

/*this method will give you back the distance between a point3D object and a point3D object pointer and will give you the distance between the 2*/
double Point3D::getDistance(Point3D* myPoint) {
	double xDist = this->x - myPoint->getX();//(x2-x1)
	double yDist = this->y - myPoint->getY();//(y2-y1)
	double zDist = this->z - myPoint->getZ();//(z2-z1)
	double distance = sqrt((xDist*xDist) + (yDist*yDist) + (zDist*zDist));//sqrt((x2-x1)^2+(y2-y1)^2+(z2-z1)^2
	return distance;//returns distance
}

/*overload the << operator to output the object*/
std::ostream& operator<<(std::ostream &string, const Point3D &pt) {
	return string << pt.x<<"\t"<<pt.y<<"\t"<<pt.z;
}