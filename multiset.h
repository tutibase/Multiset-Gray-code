#pragma once
#include "universum.h"

class multiset
{
private:
	universum* pUniversum; // ��������� �� ��������� - ������ ���������

	std::vector<short> cardinality; // �������� ��������� ���������

public:
	multiset(universum* pUniversum);
	multiset(universum* pUniversum, int ptr);
	void Out();

	void addition(multiset A);
	void unionS(multiset A, multiset B);
	void intersection(multiset A, multiset B);
	void difference(multiset A, multiset B);
	void simDifference(multiset A, multiset B);
	void arifDifference(multiset A, multiset B);
	void arifMultiplication(multiset A, multiset B);
};

