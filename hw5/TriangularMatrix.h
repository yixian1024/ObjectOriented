#pragma once
#include <iostream>

// #Class
class Matrix {
	private:
		bool UORL; //U:1, L:0
		int rows;
		int totalElement;
		double *arr;
		bool isValid (Matrix&, const Matrix&);
		Matrix *tmpMatrix;

	public:
// ## Constructor && Destructor
		Matrix();
		~Matrix();
		Matrix (const Matrix&);

// ## Operator overloading
		friend std::ostream& operator<<(std::ostream&, const Matrix&);

		Matrix& operator= (const Matrix&);
		Matrix& operator+ (const Matrix&);
		Matrix& operator- (const Matrix&);

		Matrix& operator* (const Matrix&);
		Matrix& operator* (double);
		friend Matrix& operator* (double, Matrix&);

		Matrix& operator+= (const Matrix&);
		Matrix& operator-= (const Matrix&);
		Matrix& operator*= (const Matrix&);
		Matrix& operator*= (double);

		double operator() (int, int) const;

// ## Function
		void readMatrix();
		int size() const;
};
