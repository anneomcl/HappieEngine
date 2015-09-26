#include "Vector3D.h"

Vector3D::Vector3D() : 
x(0), 
y(0),
z(0)
{

}

Vector3D::~Vector3D(){

}

Vector3D::Vector3D(float xCoord, float yCoord, float zCoord) : 
x(xCoord),
y(yCoord),
z(zCoord)
{

}

Vector3D::Vector3D(const Vector3D& v) : 
x(v.x),
y(v.y),
z(v.z)
{

}

Vector3D& Vector3D::operator=(const Vector3D& rhs){
	
	if (this != &rhs){
		this->x = rhs.x;
		this->y = rhs.y;
		this->z = rhs.z;
	}

	return *this;
}