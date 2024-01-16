#pragma once
#include <vector>

class universum {
private:
	int bitDepth; // разрядность кодов Грея
	int size; // количество кодов Грея
	std::vector<unsigned short> cardinality; // мощность (максимальная) элементов универсума 
	std::vector<std::vector<bool>> uni; // коды Грея

public:
	universum();
	void gray_code_generator();
	int Q(int i);

	void Out();
	std::vector<unsigned short> &getCardinality();
	int getBitDepth();
	int getSize();
	std::vector<std::vector<bool>> &getUni();
};

int intInput(const char* msg, int maxi, int mini = 0);
void help();
