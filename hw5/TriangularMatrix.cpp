#include "TriangularMatrix.h"
#include <bits/stdc++.h>
using namespace std;

// #Constructor && Destructor
// ## Constructor
Matrix::Matrix() {
	rows = totalElement = -1;
	arr = NULL;
	tmpMatrix = NULL;
}

// ## Destructor
Matrix::~Matrix() {
	delete arr;
	delete tmpMatrix;
	arr = NULL;
	tmpMatrix = NULL;
}

// ## Copy Constructor
Matrix::Matrix (const Matrix& old) {
	rows = totalElement = -1;
	arr = NULL;
	tmpMatrix = NULL;
	*this = old;
}

// #Operator overloading
// ## <<
ostream& operator<< (ostream& os, const Matrix& x) {
	int tmp = (x.UORL == 1) ? x.rows : 1;
	double *it = x.arr;

	os << endl;
	for (int i=0; i<x.rows; i++) {
		if (i == 0) os << "/ ";
		else if (i == x.rows-1) os << "\\ ";
		else os << "| ";

		if (x.UORL == true) {
			for (int j=0; j<x.rows-tmp; j++) {
				os << fixed << setprecision(2) << setw(10) << 0 << " ";
			}
			for (int j=x.rows-tmp; j<x.rows; j++) {
				os << fixed << setprecision(2) << setw(10) << *it << " ";
				it ++;
			}
		} else {
			for (int j=x.rows-tmp; j<x.rows; j++) {
				os << fixed << setprecision(2) << setw(10) << *it << " ";
				it ++;
			}
			for (int j=0; j<x.rows-tmp; j++) {
				os << fixed << setprecision(2) << setw(10) << 0 << " ";
			}
		}
		(x.UORL == 1) ? tmp -- : tmp ++;

		if (i == 0) os << "\\ ";
		else if (i == x.rows-1) os << "/ ";
		else os << "| ";
		os << endl;
	}
	return os;
}

// ## =
Matrix& Matrix::operator= (const Matrix& old) {
	delete arr;
	totalElement = old.totalElement;
	rows = old.rows;
	UORL = old.UORL;
	arr = new double[totalElement];
	for (int i=0; i<totalElement; i++) {
		arr[i] = old.arr[i];
	}
}

// ## +
Matrix& Matrix::operator+ (const Matrix& old) {
	if (!isValid (*this, old)) return *this;
	delete tmpMatrix;
	tmpMatrix = new Matrix;
	*tmpMatrix = *this;
	for (int i=0; i<old.totalElement; i++) {
		tmpMatrix -> arr[i] += old.arr[i];
	}
	return *tmpMatrix;
}

// ## -
Matrix& Matrix::operator- (const Matrix& old) {
	if (!isValid (*this, old)) return *this;
	delete tmpMatrix;
	tmpMatrix = new Matrix;
	*tmpMatrix = *this;
	for (int i=0; i<old.totalElement; i++) {
		tmpMatrix -> arr[i] -= old.arr[i];
	}
	return *tmpMatrix;
}

// ## Matrix * Matrix
// ### check valid && initial
Matrix& Matrix::operator* (const Matrix& old) {
	if (!isValid (*this, old)) return *this;
	delete tmpMatrix;
	tmpMatrix = new Matrix;
	*tmpMatrix = *this;

	double tmp1[rows][rows];
	double tmp2[rows][rows];
	double *it1 = arr;
	double *it2 = old.arr;
	int tt = (UORL == 1) ? rows : 1;

// ### turn into 2-D array
	for (int i=0; i<rows; i++) {
		if (UORL == true) {
			for (int j=0; j<rows-tt; j++) {
				tmp1[i][j] = tmp2[i][j] = 0;
			}
			for (int j=rows-tt; j<rows; j++) {
				tmp1[i][j] = *it1;
				tmp2[i][j] = *it2;
				it1 ++;
				it2 ++;
			}
		} else {
			for (int j=0; j<tt; j++) {
				tmp1[i][j] = *it1;
				tmp2[i][j] = *it2;
				it1 ++;
				it2 ++;
			}
			for (int j=tt; j<rows; j++) {
				tmp1[i][j] = tmp2[i][j] = 0;
			}
		}
		(UORL == 1) ? tt-- : tt++;
	}

// ### multiplication
	double ans[rows][rows] = {0};
	for (int i=0; i<rows; i++) {
		for (int j=0; j<rows; j++) {
			for (int k=0; k<rows; k++) {
				ans[i][j] += tmp1[i][k] * tmp2[k][j];
			}
		}
	}

//	for (int i=0; i<rows; i++) {
//		for (int j=0; j<rows; j++) {
//			printf("%f ", ans[i][j]);
//		}
//		printf("\n");
//	}

// ### store into 1-D array
	double *it = tmpMatrix -> arr;
	tt = (UORL == 1) ? rows : 1;
	for (int i=0; i<rows; i++) {
		if (UORL == true) {
			for (int j=rows-tt; j<rows; j++) {
				*it = ans[i][j];
				it ++;
			}
		} else {
			for (int j=0; j<tt; j++) {
				*it = ans[i][j];
				it ++;
			}
		}
		(UORL == 1) ? tt-- : tt++;
	}
	return *tmpMatrix;
}

// ## Matrix * double
Matrix& Matrix::operator* (double x) {
	delete tmpMatrix;
	tmpMatrix = new Matrix;
	*tmpMatrix = *this;
	for (int i=0; i<totalElement; i++) {
		tmpMatrix -> arr[i] *= x;
	}
	return *tmpMatrix;
}

// ## double * Matrix
Matrix& operator* (double x, Matrix& m) {
	return (m * x);
}

// ## +=
Matrix& Matrix::operator+= (const Matrix& old) {
	if (!isValid (*this, old)) return *this;
	return operator= (*this + old);
}

// ## -=
Matrix& Matrix::operator-= (const Matrix& old) {
	if (!isValid (*this, old)) return *this;
	return operator= (*this - old);
}

// ## Matrix *= Matrix
Matrix& Matrix::operator*= (const Matrix& old) {
	if (!isValid (*this, old)) return *this;
	return operator= (*this * old);
}

// ## Matrix *= double
Matrix& Matrix::operator*= (double x) {
	return operator= (*this * x);
}

// ## ()
double Matrix::operator() (int x, int y) const {
	double tmp[rows][rows];
	double *it = arr;
	int tt = (UORL == 1) ? rows : 1;

	for (int i=0; i<rows; i++) {
		if (UORL == true) {
			for (int j=0; j<rows-tt; j++) {
				tmp[i][j] = 0;
			}
			for (int j=rows-tt; j<rows; j++) {
				tmp[i][j] = *it;
				it ++;
			}
		} else {
			for (int j=0; j<tt; j++) {
				tmp[i][j] = *it;
				it ++;
			}
			for (int j=tt; j<rows; j++) {
				tmp[i][j] = 0;
			}
		}
		(UORL == 1) ? tt-- : tt++;
	}

	return tmp[x-1][y-1];
}

// #Function
// ## Check if the operation isValid
bool Matrix::isValid (Matrix &x, const Matrix &y) {
	if (x.UORL != y.UORL || x.rows != y.rows) {
		cout << "You cannot operate an upper triangular matrix with a lower triangular matrix" << endl;
		return false;
	}
	return true;
}
// ## readMatrix
void Matrix::readMatrix() {
	cout << "specify numbers of rows:\n> ";
	cin >> rows;
	if (rows < 1) {
		cout << "invalid !\n";
		return;
	}
	cout << "upper or lower triangular: (upper: 1, lower:0, defalut set to upper)\n> ";
	cin >> UORL;
	cout << "input elements of the matrix:\n> ";

	totalElement = 0;
	for (int i=1; i<=rows; i++) totalElement += i;
	arr = new double[totalElement];

	for (int i=0; i<totalElement; i++) {
		cin >> arr[i];
	}
	return;
}

// ## size
int Matrix::size() const{
	return rows;
}
