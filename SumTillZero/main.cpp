#include <iostream>
#include <locale>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int num = 1, sum = 0;

	while (num != 0) {
		cout << "������� ����� ����� ��� ����� '0', ����� ���������: ";
		cin >> num;
		sum += num;
	}

	cout << num;

	return 0;
}