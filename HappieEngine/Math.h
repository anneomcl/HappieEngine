namespace Math{

	Vector3D add(Vector3D a, Vector3D b);
	Vector3D subtract(Vector3D b, Vector3D a);
	Vector3D multiply(Vector3D a, float c);

	float dot(Vector3D a, Vector3D b);
	float det(float a, float b, float c, float d);
	Vector3D cross(Vector3D a, Vector3D b);

	float sqrtNewton(float val, float estimate);
	float sqrt(float x);

	float abs(float a);
	float magnitude(Vector3D v);
};