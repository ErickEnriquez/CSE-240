#include "enriquez_Vector3D.h"
#include <math.h>// for sqrt function
/* constructor given 2 3d points create a vector with 3 points , a magnitude, and an angle*/
Vector3D::Vector3D(Point3D p1, Point3D p2) {
	this->x = p1.getX() - p2.getX();
	this->y = p1.getY() - p2.getY();
	this->z = p1.getZ() - p2.getZ();
	this->size = CalculateSize();//get the magnitude of the vector
	CalculateAngle();
}
/*given X,Y,Z create a vector*/
Vector3D::Vector3D(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->size = CalculateSize();
	CalculateAngle();
}

double Vector3D::CalculateSize() {
	double temp = sqrt((this->x*this->x) + (this->y*this->y) + (this->z*this->z));//( x^2 + y^2 + z^2 )^(1/2)
	return temp;//return the magnitude of the vector
}
//calculate the unit vecotor of the vector
void Vector3D::CalculateUnitVector() {
	this->ux = this->x / this->size; // divide x by magnitude to get unit vector in x direction
	this->uy = this->y / this->size; // divide y by magnitude to get unit vector in y direction
	this->uz = this->z / this->size; // divide z by magnitude to get unit vector in z direction
}
//get a unit vector
Vector3D* Vector3D::getUnitVector() {
	CalculateUnitVector();//calculate the unit vectors 
	Vector3D* pointer = new Vector3D(this->ux,this->uy,this->uz);//create a pointer dynamically and set up the vector components
	return pointer;	//return the pointer
}

//calculate the dot product of 2 vectors
double Vector3D::dotProduct(Vector3D* other) {
	double dotProduct = ((this->x * other->getX()) + (this->y * other->getY()) + (this->z*other->getZ()));//<(ax*bx)+(ay*by)+(az*bz)>
	return dotProduct;
}
/*the method will take 2 vectors and give you the cross product between the 2*/
Vector3D* Vector3D::crossProduct(Vector3D* other) {
	double i = (this->y * other->getZ()) - (this->z * other->getY()) ; // (ay*bz-az*uy) component in x direction
	double j = -((this->x * other->getZ()) - (this->z * other->getX())); // (ax*bz-az*bx) component in y direction
	double k = (this->x * other->getY()) - (this->y * other->getX());//	 (ax*by-bx*ay) component in z direction
	Vector3D* crossProduct = new Vector3D(i,j,k);	//create a vector and give it the components
	return crossProduct;	//return the pointer
}
/*add 2 vectors together*/
Vector3D* Vector3D::add(Vector3D* other) {
	double i = this->x + other->getX(); //add x components
	double j = this->y + other->getY();	//add y components
	double k = this->z + other->getZ();	//add z components
	Vector3D* add = new Vector3D(i,j,k);//create a vecotr and give it components
	return add;//return the vector pointer
}
/*subtract 2 vectors together*/
Vector3D* Vector3D::subtract(Vector3D* other) {
	double i = this->x + -(other->getX());//subtract x components
	double j = this->y + -(other->getY());//subtract y components
	double k = this->z + -(other->getZ());//subtract y components
	Vector3D* sub = new Vector3D(i, j, k);//create a vector and give it components
	return sub;//return the vector pointer
}
/*scale the vector by a scalar */
void Vector3D::scale(double scalar) {
	this->x *= scalar; //multiply the x component by scalar
	this->y *= scalar; //multiply the y component by scalar
	this->z *= scalar; ////multiply the z component by scalar
	this->size = CalculateSize(); //calculate the new magnitude
	CalculateUnitVector();//calculate the unit vectors
	CalculateAngle();//recalculate the angle
}
 /*return the angle of a vector in xy plane in radians*/
double Vector3D::CalculateAngle(){
	return this->angle = atan2(this->y, this->x); //arcTan(y/x)
}

/*getters*/
double Vector3D::getSize() {
	return this->size;
}
double Vector3D::getAngle() {
	return this->angle;
}
double Vector3D::getux() {
	return this->ux;
}
double Vector3D::getuy() {
	return this->uy;
}
double Vector3D::getuz() {
	return this->uz;
}

/*this method gives you the euclidian distance between 2 vectors*/
double Vector3D::getDistance(Vector3D* other) {
	double d;
	double i = (this->getX() - other->getX()) * (this->getX() - other->getX());
	double j = (this->getY() - other->getY()) * (this->getY() - other->getY());
	double k = (this->getZ() - other->getZ()) * (this->getZ() - other->getZ());
	d = sqrt(i+j+k);
	return d;
}
/* this function overloads the << operator to print the vector as <X,Y,Z>*/
std::ostream & operator<<(std::ostream & out, const Vector3D * pt){
	out << "<" << pt->x << "," << pt->y << "," << pt->z << ">";
	return out;
}
