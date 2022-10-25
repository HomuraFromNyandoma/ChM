#pragma once
#include "myVector.h"

myVector::myVector() {
	size = 3;
	mas = new double[3];
	for (int i = 0; i < 3; i++)
		mas[i] = 0;
}

myVector::myVector(int size_) {
	size = size_;
	mas = new double[size_];
	for (int i = 0; i < size; i++)
		mas[i] = 0;
}

myVector::myVector(int size_, double mas_) {
	size = size_;
	mas = new double[size_];
	for (int i = 0; i < size; i++)
		mas[i] = mas_;
}

//myVector::~myVector() {
//	delete[] mas;
//}

void myVector::setOnes()
{
	for (int i = 0; i < size; i++)
		mas[i] = 1;
}

void myVector::operator=(myVector vec) {
	delete[] mas;
	mas = new double[vec.size];
	size = vec.size;
	for (int i = 0; i < size; i++)
		mas[i] = vec.mas[i];
}

myVector myVector::operator+(myVector vec) {
	myVector temp(size);
	for (int i = 0; i < size; i++)
		temp.mas[i] = mas[i] + vec.mas[i];
	return temp;
}

myVector myVector::operator-(myVector vec) {
	myVector temp(size);
	for (int i = 0; i < size; i++)
		temp.mas[i] = mas[i] - vec.mas[i];
	return temp;
}

double myVector::operator*(myVector vec) {
	double temp = 0;
	for (int i = 0; i < size; i++)
		temp += mas[i] * vec.mas[i];
	return temp;
}

myVector myVector::operator*(double number) {
	myVector temp(size);
	for (int i = 0; i < size; i++)
		temp.mas[i] = mas[i] * number;
	return temp;
}

double myVector::norm() {
	double temp1 = abs(mas[0]);
	for (int i = 1; i < size; i++) {
		double temp2 = abs(mas[i]);
		if (temp2 > temp1)
			temp1 = temp2;
	}
	return temp1;
}

void myVector::randomFilling(double min, double max) {
	int temp = max / min;
	for (int i = 0; i < size; i++)
		mas[i] = min + rand() % temp * min;
}

double& myVector::operator[](int number) {
	return (mas[number - 1]);
}

myVector operator*(myVector vec, double number) {
	myVector temp(vec.size);
	for (int i = 0; i < vec.size; i++)
		temp.mas[i] = vec.mas[i] * number;
	return temp;
}

std::ostream& operator<<(std::ostream& output, myVector vec) {
	for (int i = 0; i < vec.size; i++)
		output << vec.mas[i] << ' ';
	output << '\n';
	return output;
}

std::istream& operator>>(std::istream& input, myVector& vec) {
	for (int i = 0; i < vec.size; i++)
		input >> vec.mas[i];
	return input;
}
