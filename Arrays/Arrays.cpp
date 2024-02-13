#include <iostream>
#include <random>

using namespace std;

int main() {

	random_device rd;    // Создание объекта для генерации случайных чисел
	mt19937 gen(rd());   // Инициализация генератора случайных чисел с использованием случайного устройства

	// Создание распределения случайных чисел в диапазоне от 1 до 5
	uniform_int_distribution<> distribution(1, 5);
	
	// todo diagonal

	int nums[6][8];

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			nums[i][j] = distribution(gen);
			cout << nums[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (nums[i][j] == nums[i][j + 1] && nums[i][j] == nums[i][j + 2]) {
				cout << "row " << i + 1 << ": " << nums[i][j] << endl;
			}
		}
	}
	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 4; i++) {
			if (nums[i][j] == nums[i + 1][j] && nums[i][j] == nums[i + 2][j]) {
				cout << "column " << j + 1 << ": " << nums[i][j] << endl;
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++) {
			if (nums[i][j] == nums[i + 1][j+ 1] && nums[i][j] == nums[i + 2][j + 2]) {

				cout << "diagonal " << "[" << i + 1 << "][" << j + 1 << "], " << "[" << i + 2 << "][" << j + 2 << "], " << "[" << i + 3 << "][" << j + 3 << "]" << endl;
			}
		}
	}

	return 0;
}