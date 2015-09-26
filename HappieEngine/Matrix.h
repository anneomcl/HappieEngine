
class Matrix{

public:
	size_t rows;
	size_t columns;

	Matrix();
	~Matrix();
	
	Matrix(const Matrix& m);
	Matrix& operator=(Matrix& rhs);

	float get(size_t row, size_t column);
	void set(size_t row, size_t column, float value);

private:

	float data[2][2];
};