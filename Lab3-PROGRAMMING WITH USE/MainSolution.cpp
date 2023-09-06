#include "iostream"
#include "windows.h"
#include "conio.h"

using namespace std;

/**
 * @brief �������� �������� �������� ���� int, ��� ��� ���������� �� �������
 * @param i �������� ���� int ������� � ���������
 * @return ������� �������� �������� ��� �������� ������ �������
*/
int CheckIntValue(int i) {

	cin.ignore(666, '\n');
	while (true) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(666, '\n');
			cout << "You enter wrong data! Please enter correct data: \n";
			cin >> i;
		}
		else {
			return i;
		}
	}
}

/**
 * @brief �������� �������� �������� ���� float, ��� ��� ���������� �� �������
 * @param i �������� ���� float ������� � ���������
 * @return ������� �������� �������� ��� �������� ������ �������
*/
float CheckFloatValue(float i) {

	cin.ignore(666, '\n');
	while (true) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(666, '\n');
			cout << "You enter wrong data! Please enter correct data: \n";
			cin >> i;
		}
		else {
			return i;
		}
	}
}

/**
 * @brief ��������� ���� �� ����� ����������� ��������� � ��������
 * @param q ���� ������������ ��������, ��� �������� ������������ � ���������
 * @return ������� ���� ���� ��� ����������� ������ ����������� � ��������
*/
int MenuOfSolution(int q) {
	int n1 = 0, n4 = 2;

	switch (q) {
	case 1:
		int k;

		cout << "\nTask A\n";
		cout << "Enter amount sequence members: ";
		
	case 2:
		char symbol;

		cout << "\nTask B\n";
		cout << "Enter symbol to get the code of character: ";
		
		break;
	case 3:
		int n;

		cout << "\nTask C\n";
		cout << "Enter number N: ";
		
		break;
	case 4:
		int m;

		cout << "\nTask D\n";
		cout << "Enter amount sequence members: ";
		
		break;
	default:
		cout << "\nYou don't enter any task for execution\n";
		return 0;
	}
	return MenuOfSolution(q);
}

int main() {

	int q;
	cout << "\nCreated by Vladislav Samoilov / KNT - 223\n";

	cout << "--------Select task:--------\n";
	cout << "Task A) Calculate Min Of Odd Ones and Max of Pairs - Enter 1\n";
	cout << "Task B) Output response cod of symbol - Enter 2\n";
	cout << "Task C) Output 5 simple numbers bigger then user enter - Enter 3\n";
	cout << "Task G) Amount Sequence Members - Enter 4\n";
	cout << "------------------------------------------------------------\n";
	cin >> q;
	q = CheckIntValue(q);
	MenuOfSolution(q);

	return main();
}