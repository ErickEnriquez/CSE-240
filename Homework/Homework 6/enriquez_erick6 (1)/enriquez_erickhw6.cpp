#include<iostream>
#include "enriquez_Vector3D.h"
using namespace std;
int main() {
	double x1, y1, z1, x2, y2, z2, scalar;//variables to be used
	cout<<"Enter coordinates for Pt1 (x,y,z)\n";
	cin >> x1 >> y1 >> z1;//get the x,y,z coordinated for the first point

	Point3D p1(x1, y1, z1);//creata a point object

	cout << "enter coorinates for Pt2 (x,y,z)\n";
	cin >> x2 >> y2 >> z2;//get the x,y,z coordinates for the 2nd point
	
	Point3D p2(x2, y2, z2); //create another point object
	Point3D* p2Ptr = &p2;	//create a pointer to the p2  object

	//output the points and the distance between them
	cout << "\npoint 1\n" << p1 << "\npoint 2\n" << p2 << "\ndistance between 2 pts:\t" << p1.getDistance(p2Ptr);

	Vector3D* v1 = new Vector3D(p1, p2);//create a vector from the 2 points
	 //output the vector information
	cout << "\n\nVector made from the 2\n" << v1 << "\n\nmagnitude = " << v1->getSize() << "\n\nAngle of vector " 
		<< v1->CalculateAngle() << " Rads\n\nunit vectors\n";
	
	Vector3D* Unit = new Vector3D(p1,p2);//create a unit vector
	Unit->getUnitVector();//calculate its unit vector and them print it
	cout <<"<"<< Unit->getux()<<","<<Unit->getuy()<<","<<Unit->getuz()<<">";

	cout<<	"\n\nEnter coordinates for 2nd Vector<X,Y,Z>\n";
	cin >> x1 >> y1 >> z1;// get coordinates for 2nd Vector
	Vector3D* v2 = new Vector3D(x1,y1,z1);	//create a new vector
	cout<< v2 <<"\neuclidian distance is "<<v1->getDistance(v2);
	cout << "\n\ndot product = "<<v1->dotProduct(v2); //get the dot product between the 2 
	cout << "\ncross product " << v1->crossProduct(v2); //get the cross product
	cout << "\n\n" << v1 << " + " << v2 << " = " << v1->add(v2); //adding the 2 vectors
	cout << "\n\n" << v1 << " - " << v2 << " = " << v1->subtract(v2)<<"\n\nEnter a Scalar\n"; //subtracting the 2 vectors
	cin >> scalar;
	Vector3D* scale = new Vector3D(p1, p2);//create a new vector and multiply it by scalar
	scale->scale(scalar);
	cout << scalar << "*" << v1 << " = " << scale<< "\n\nmagnitude = " << scale->getSize() << "\n\nAngle of vector " << scale->CalculateAngle() 
		<< " Rads\n\nunit vectors\n<"<<Unit->getux()<<","<<Unit->getuy()<<","<<Unit->getuz()<<">";
	//output the scaled vector and print its information
	






	








	return 0;
}