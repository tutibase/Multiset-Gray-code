#include "universum.h"
#include <iostream>
#include <cmath>
using namespace std;

universum::universum() {
	this->bitDepth = intInput("Введите разрядность кодов Грея [1; 20]: ", 20, 1);
	size = pow(2, bitDepth);

	gray_code_generator();

	for (int i = 0; i < size; i++) {
		cardinality.push_back(rand() % 9 + 1);
	}
}

void universum::gray_code_generator() {
	vector<bool> B(bitDepth, 0);
	uni.push_back(B);

	for (int i = 1; i < size; i++) {
		int ind = Q(i);
		ind = bitDepth - ind;
		B[ind] = 1 - B[ind];
		uni.push_back(B);
	}
}

int universum::Q(int i) {
	int q = 1;
	int j = i;
	while (j % 2 == 0) {
		j /= 2;
		q++;
	}
	return q;
}

void universum::Out() {
	cout << "\nUniversum:" << '\n';
	for (int i = 0; i < size; i++) {
		cout << i << ") code:\t";
		for (bool j : uni[i])
			std::cout << j;
		cout << "\tcardinality: " << cardinality[i] << '\n';
	}
}

vector<unsigned short> &universum::getCardinality() {
	return cardinality;
}

int universum::getBitDepth() {
	return bitDepth;
}

int universum::getSize() {
	return size;
}

std::vector<std::vector<bool>> &universum::getUni() {
	return uni;
}

int intInput(const char* msg, int maxi, int mini) {
	cout << msg;
	int val;
	while (true) {
		cin >> val;
		if (cin.peek() != '\n' or val > maxi or val < mini) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			printf("\nНекоректное значение, повторите ввод\n");
		} else break;
	}
	return val;
}

void help() {
	cout << "\n\n[0] - выход" << '\n';
	cout << "[1] - help" << '\n';
	cout << "[2] - вывести универсум" << '\n';
	cout << "[3] - вывести A" << '\n';
	cout << "[4] - вывести B" << '\n';
	cout << "[5] - ¬A" << '\n';
	cout << "[6] - ¬B" << '\n';
	cout << "[7] - объединение A и B" << '\n';
	cout << "[8] - пересечение A и B" << '\n';
	cout << "[9] - A\\B" << '\n';
	cout << "[10] - B\\A" << '\n';
	cout << "[11] - симметрическая разность A и B" << '\n';
	cout << "[12] - симметрическая разность B и A" << '\n';
	cout << "[13] - A-B" << '\n';
	cout << "[14] - B-A" << '\n';
	cout << "[15] - A*B" << '\n';
	/*cout << "[1] - " << '\n';
	cout << "[1] - " << '\n';
	cout << "[1] - " << '\n';*/

}