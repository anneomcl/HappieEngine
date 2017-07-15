
class Vector3D{

public:
	float x;
	float y;
	float z;

	Vector3D();
	~Vector3D();

	Vector3D(float xCoord, float yCoord, float zCoord);
	Vector3D(const Vector3D& v);
	Vector3D& operator= (const Vector3D& rhs);

	friend Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs);
	friend Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs);
	friend Vector3D operator*(const Vector3D& lhs, const float& rhs);
	friend Vector3D operator*(const float& lhs, const Vector3D& rhs);
		
private:

};
