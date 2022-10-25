#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <Windows.h>


class myVector {
	double* mas;
	int size;
public:
	myVector();
	myVector(int size_);
	myVector(int size_, double mas_);
	/*~myVector();*/
	void setOnes();
	void operator=(myVector vec);
	myVector operator+(myVector vec);
	myVector operator-(myVector vec);
	double operator*(myVector vec);
	myVector operator*(double number);
	friend myVector operator*(myVector vec, double number);
	double norm();
	friend std::ostream& operator<<(std::ostream& output, myVector vec);
	friend std::istream& operator>>(std::istream& input, myVector& vec);
	void randomFilling(double min, double max);
	double& operator[](int number);
};