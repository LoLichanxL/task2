// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
int charToInt(char c) {
	return (int)c - 48;
}
void sum(std::string max, std::string min, int diff) {
	char result[1001] = {};
	int current_remainder = 0;
	for (int i = max.size() - 1; i >= 0; i--) {
		if (i - diff >= 0) {
			int res = (charToInt(max[i]) + charToInt(min[i - diff]) + current_remainder) % 10;
			current_remainder = ((int)max[i] - 48 + (int)min[i - diff] - 48 + current_remainder) / 10;
			result[i + 1] = (char)(res + 48);
		}
		else
		{
			int res = ((int)max[i] - 48 + current_remainder) % 10;
			current_remainder = ((int)max[i] - 48 + current_remainder) / 10;
			result[i + 1] = (char)(res + 48);
		}
		result[0] = char(current_remainder + 48);
	}
	for (int i = 0; i < max.size() + 1; i++) {
		if (i == 0 && result[0] == '0') {

		}
		else {
			std::cout << result[i];
		}
	}
}


void multiply(int max[], int min[], int max_len, int min_len) {
	int res[2000] = {};
	int carry = 0;
	for (int i = max_len - 1; i >= 0; i--) {
		for (int j = min_len - 1; j >= 0; j--) {
			int k = (res[i + j] + max[i] * min[j] + carry);
			res[i + j] = k % 10;
			carry = k / 10;
		}
		res[max_len + min_len - 1 - i] += carry;
	}
	if (carry != 0) {
		std::cout << carry;
	}
	for (int i = 0; i < max_len + min_len - 1; i++) {
		std::cout << res[i];
	}
}
int main()
{
	std::ifstream in("input.txt", std::ios::in);
	std::string a;
	std::string b;
	in >> a;
	in >> b;
	std::string sum_result;
	if (a.size() <= b.size()) {
		sum(b, a, b.size() - a.size());
	}
	else {
		sum(a, b, a.size() - b.size());
	}
	int aa[1000];
	int bb[1000];
	std::cout << std::endl;
	for (int i = 0; i < a.size(); i++) {
		aa[i] = charToInt(a[i]);
		std::cout << aa[i];
	}

	std::cout << std::endl;
	for (int i = 0; i < b.size(); i++) {
		bb[i] = charToInt(b[i]);
		std::cout << bb[i];
	}

	std::cout << std::endl;
	multiply(aa, bb, a.size(), b.size());

	std::cout << std::endl;
}





