#include "multiset.h"
#include <iostream>
using namespace std;

multiset::multiset(universum* pUniversum) {
	this->pUniversum = pUniversum;
	bool flag;
	flag = intInput("\n\nВыберите, как заполнить множество: [0] - Вручную, [1] - Автоматически\n", 1);
	cardinality.resize(pUniversum->getCardinality().size());

	if (flag) {
		cout << "\nКакая будет мощность множества? (Максимум " << pUniversum->getSize()<<")\n";
		int card;
		card = intInput("", pUniversum->getSize());
		for (int i = 0; i < card; i++) {
			int ind;
			do {
				ind = rand() % pUniversum->getSize();
			} while (cardinality[ind] != 0);
			cardinality[ind] = (rand() % (pUniversum->getCardinality()[ind] )) + 1;
		}
	}
	else {
		int multiplicity;
		for (int i = 0; i < pUniversum->getSize(); i++) {
			cout << "Введите кратность элемента №" << i << " - ";
			for (bool j : pUniversum->getUni()[i])
				std::cout << j;
			cout  << ", она не должна превышать " << pUniversum->getCardinality()[i] << "\n";
			cardinality[i] = intInput("", pUniversum->getCardinality()[i]);
		}
	}
}

multiset::multiset(universum* pUniversum, int ptr) {
	this->pUniversum = pUniversum;
	cardinality.resize(pUniversum->getCardinality().size());
}
	
void multiset::Out() {
	cout << "\nmultiset:" << '\n';
	for (int i = 0; i < pUniversum->getSize(); i++) {
		cout << i << ") code:\t";
		for (bool j : pUniversum->getUni()[i])
			std::cout << j;
		cout << "\tcardinality: " << cardinality[i] << '\n';
	}
}

void multiset::addition(multiset A) {
	for (int i = 0; i < pUniversum->getSize(); i++) {
		cardinality[i] = pUniversum->getCardinality()[i] - A.cardinality[i];
	}
}

void multiset::unionS(multiset A, multiset B) {
	for (int i = 0; i < pUniversum->getSize(); i++) {
		cardinality[i] = max(A.cardinality[i], B.cardinality[i]);
	}
}

void multiset::intersection(multiset A, multiset B) {
	for (int i = 0; i < pUniversum->getSize(); i++) {
		cardinality[i] = min(A.cardinality[i], B.cardinality[i]);
	}
}

void multiset::difference(multiset A, multiset B) {
	multiset notB(pUniversum, 1);
	notB.addition(B);
	intersection(A, notB);
}


void multiset::simDifference(multiset A, multiset B) {
	for (int i = 0; i < pUniversum->getSize(); i++) {
		cardinality[i] = abs(A.cardinality[i] - B.cardinality[i]);
	}
}

void multiset::arifDifference(multiset A, multiset B) {
	for (int i = 0; i < pUniversum->getSize(); i++) {
		cardinality[i] = A.cardinality[i] - B.cardinality[i];
		if (cardinality[i] < 0) cardinality[i] = 0;
	}
}

void multiset::arifMultiplication(multiset A, multiset B) {
	for (int i = 0; i < pUniversum->getSize(); i++) {
		cardinality[i] = A.cardinality[i] * B.cardinality[i];
		if (cardinality[i] > pUniversum->getCardinality()[i]) 
			cardinality[i] = pUniversum->getCardinality()[i];
	}
}