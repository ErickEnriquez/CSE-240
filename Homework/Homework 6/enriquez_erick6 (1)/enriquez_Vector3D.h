#pragma once
#include<iostream>// to overwrite the << operator
#include "enriquez_Point3D.h"
class Vector3D :public Point3D {//Vector 3D inherits from Point3D
protected:
	double size, ux, uy, uz, angle; // variables

private:
	double CalculateSize(); //calculate the magnitude of a vector
	void CalculateUnitVector(); // calculae a vecotors unit vectors

public:
	Vector3D(double, double, double);//create a vector 

	Vector3D(Point3D, Point3D);//create a vector with 2 pts

	Vector3D* getUnitVector();// -create and return the unit vector

	double dotProduct(Vector3D* other);// – returns dot product

	Vector3D* crossProduct(Vector3D* other);// – returns cross product vector

	Vector3D* add(Vector3D* other);// – add two vectors together get a third

	Vector3D* subtract(Vector3D* other);// – subtract two vectors together get a third

	void scale(double value);// – multiply the vector by the value, don’t forget you might need to recalculate angle, size and unit vector components

	double getDistance(Vector3D* other);// get the euclidian distance between 2 vectors

	double CalculateAngle();	//get the angle between 2 vectors

	friend std::ostream& operator<<(std::ostream& out, const Vector3D* pt); //will overwrite the << operator 

	//getters
	double getSize();
	double getux();
	double getuy();
	double getuz();
	double getAngle();

};