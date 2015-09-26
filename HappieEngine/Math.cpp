#include "Vector3D.h"
#include "Matrix.h"

#define PI = 3.1415;

namespace Math{

	Vector3D add(Vector3D a, Vector3D b){

		Vector3D sum = Vector3D();
		sum.x = a.x + b.x;
		sum.y = a.y + b.y;
		sum.z = a.z + b.z;

		return sum;
	}

	Vector3D subtract(Vector3D b, Vector3D a){

		Vector3D diff = Vector3D();
		diff.x = b.x - a.x;
		diff.y = b.y - a.y;
		diff.z = b.z - a.z;

		return diff;
	}

	Vector3D multiply(Vector3D a, float c){

		Vector3D mul = Vector3D();
		mul.x = a.x * c;
		mul.y = a.y * c;
		mul.z = a.z * c;

		return mul;
	}

	/*
	Project A onto B.
	A dot B = |A| |B| cos(theta)
	Can find angle between A and B
	*/
	float dot(Vector3D a, Vector3D b){

		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	//Find the determinant.
	float det(float a, float b, float c, float d){

		return a*d - b*c;
	}

	/*
		i   j   k
		ax  ay  az
		bx  by  bz

		    | ay  az |            | ax  az |            | ax  ay |
	   det  | by  bz | * i -  det | bx  bz |  * j + det | bx  by | * k

			| a  b |
		det	| c  d | = ad - bc

		Returns a vector that is perpendicular to A and B.
		Used to find normal vectors on mesh faces in graphics, for example.

		| A cross B | = |A| |B| sin(theta)
	*/
	Vector3D cross(Vector3D a, Vector3D b){

		Vector3D crossProduct = Vector3D();
		crossProduct.x = det(a.y, a.z, b.y, b.z);
		crossProduct.y = -1 * det(a.x, a.z, b.x, b.z);
		crossProduct.z = det(a.x, a.y, b.x, b.y);

		return crossProduct;
	}

	//Absolute value of A.
	float abs(float a){
		if (a < 0){
			return (-1 * a);
		}
		else{
			return a;
		}
	}

	//Newton's Method: Xn+1 = Xn - f(Xn) / f'(Xn), where f(x) = x^2 - val and f'(x) = 2x. 
	//TO-DO: Alternate overloaded function with margin of error as parameter
	float sqrtNewton(float val, float estimate){
		
		float error = abs(estimate*estimate - val);

		if (error <= 0.0001){
			return estimate;
		}
		else{

			float newEstimate = (((val / estimate) + estimate) / 2);
			return sqrtNewton(val, newEstimate);
		}
	}

	//Finds square root using Newton's Method. 
	float sqrt(float x){

		if (x < 0){
			return -1.0;
		}
		else{
			return sqrtNewton(x, 1.0);
		}
	}

	//Finds |v| = sqrt(v.x^2 + v.y^2 + v.z^2).
	float magnitude(Vector3D v){

		return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
	}

}