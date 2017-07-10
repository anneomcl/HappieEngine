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

Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs) {
	Vector3D sum = Vector3D();

	sum.x = lhs.x + rhs.x;
	sum.y = lhs.y + rhs.y;
	sum.z = lhs.z + rhs.z;

	return sum;
}

Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs) {
	Vector3D diff = Vector3D();

	diff.x = lhs.x - rhs.x;
	diff.y = lhs.y - rhs.y;
	diff.z = lhs.z - rhs.z;

	return diff;
}

Vector3D operator*(const Vector3D& lhs, const float& rhs) {
	Vector3D mul = Vector3D();

	mul.x = lhs.x * rhs;
	mul.y = lhs.y * rhs;
	mul.z = lhs.z * rhs;

	return mul;	
}

Vector3D operator*(const float& lhs, const Vector3D& rhs) {
	return rhs * lhs;
}
