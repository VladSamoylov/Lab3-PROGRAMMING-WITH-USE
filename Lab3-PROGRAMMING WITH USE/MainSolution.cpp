#include "iostream"
#include "windows.h"
#include "conio.h"

using namespace std;

/**
 * @brief �������� �������� �������� ���� int, ��� ��� ���������� �� �������
 * @param i �������� ���� int ������� � ���������
 * @return ������� �������� �������� ��� �������� ������ �������
*/
int CheckIntValue(int* i) {

	cin.ignore(666, '\n');
	while (true) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(666, '\n');
			cout << "You enter wrong data! Please enter correct data: \n";
			cin >> *i;
		}
		else {
			return *i;
		}
	}
}

/**
 * @brief �������� �������� �������� ���� float, ��� ��� ���������� �� �������
 * @param i �������� ���� float ������� � ���������
 * @return ������� �������� �������� ��� �������� ������ �������
*/
float CheckFloatValue(float* i) {

	cin.ignore(666, '\n');
	while (true) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(666, '\n');
			cout << "You enter wrong data! Please enter correct data: \n";
			cin >> *i;
		}
		else {
			return *i;
		}
	}
}

/**
 * @brief �������� �������� ������� ��������, ���� ������� ���� �����
 * @param n ʳ������ �������� ������ �������� ������������ � ���������
 * @return ������� �������� �������� ������� �������� ������
*/
int CheckMinMembersOfMassive(int* n) {

	if (*n < 0) {
		cout << "You enter wrong data! Please enter correct data (min members - 0): \n";
		cin >> *n;
		*n = CheckIntValue(&*n);
	}
	return *n;
}

void FillTheMassiveAandB(int* n) {
	float* masA = new float[*n];
	int j = 0, zero = 0;

	for (int i = 0; i < *n; i++) {
		masA[i] = 0.7 * cos(pow(i, 2)) - 3 * i;
		if (masA[i] == 0) {
			zero++;
		}
	}
	float* masB = new float[*n - zero];
	for (int i = 0; i < *n; i++) {
		if (masA[i] < 0) {
			masB[j] = masA[i];
			j++;
		}
	}
	for (int i = 0; i < *n; i++) {
		if (masA[i] > 0) {
			masB[j] = masA[i];
			j++;
		}
	}
	cout << "masA have " << *n << " elements: \n";
	for (float* ptr = masA; ptr < &masA[*n]; ptr++) {
		cout << *ptr;
		cout <<" (" << ptr << ") /";
	}
	cout << endl;
	cout << "masB have " << *n - zero << " elements: \n";
	for (int i = 0; i < *n - zero; i++) {
		cout << masB[i] << '/';
	}
	cout << endl;
	
	delete[] masA;
	delete[] masB;
}

/**
 * @brief ��������� ���� �� ����� ����������� ��������� � ��������
 * @param q ���� ������������ ��������, ��� �������� ������������ � ���������
 * @return ������� ���� ���� ��� ����������� ������ ����������� � ��������
*/
int MenuOfSolution(int* q) {
	int n;

	switch (*q) {
	case 1:
		cout << "\n__Task A__\n";
		cout << "Enter amount members of masive A: ";
		cin >> n;
		n = CheckIntValue(&n);
		n = CheckMinMembersOfMassive(&n);
		FillTheMassiveAandB(&n);
		break;
	case 2:

		cout << "\n__Task B__\n";
		cout << "Enter symbol to get the code of character: ";
		
		break;
	case 3:
		

		cout << "\n__Task C__\n";
		cout << "Enter number N: ";
		
		break;
	case 4:
		

		cout << "\n__Task D__\n";
		cout << "Enter amount sequence members: ";
		
		break;
	default:
		cout << "\n__You don't enter any task for execution__\n";
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
	q = CheckIntValue(&q);
	MenuOfSolution(&q);

	return main();
}