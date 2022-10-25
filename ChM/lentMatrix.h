#pragma once
#include "myVector.h"

class lentMatrix {
	myVector a;
	myVector b;
	myVector c;
	myVector p;
	myVector q;
	int k;
	int size;
	void normalizeABCtoPQ();
	void normalizePQtoABC();
public:
	lentMatrix();
	lentMatrix(int size_, int k_);
	void randomFilling(double x, double y);
	void HilbertFilling();
	lentMatrix operator+(lentMatrix matr);
	lentMatrix operator-(lentMatrix matr);
	myVector operator*(myVector vec);
	myVector solution(myVector f);
	void operator=(lentMatrix matr);
	friend std::ostream& operator<<(std::ostream& output, lentMatrix matr);
	friend std::istream& operator>>(std::istream& input, lentMatrix& matr);
};

