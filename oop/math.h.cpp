#include <iostream>
// # ��������������� �����������, ���� ����������� � ���, ��� ������������ ���� �� cpp ����� � ��������� ��� ��� �����-�� �����������
#define AAA 0 //���������� ���-��, �� �������� ������������ � ������, ���������� ������ �� ������ ����������
#define sub(a,b) ((a)-(b)) //������� ����� ������������� ��� �������� ����������, �� ��� ���� �++, � ��� �����������
//#error "hello loser"
//�������� - �++ - ������������
#pragma once //��� ���� ����� ��� ������� � ������ ������ �� �������� ��������� ��� ��������� �������
int mult(int a, int b) {
	return a * b;
}
int add(int a, int b) {
	return a + b;
}
//global variable but it must be initialized in one cpp
extern int x;
//classes can be realized fully here
class Em {};