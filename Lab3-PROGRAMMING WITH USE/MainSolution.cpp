#include "iostream"
#include "math.h"

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

	if (*n <= 0) {
		cout << "You enter wrong data! Please enter correct data (min members - 0): \n";
		cin >> *n;
		*n = CheckIntValue(&*n);
	}
	return *n;
}

/**
 * @brief �������� ��������� � ������������ ����� �������
 * @param n ʳ������ �����
 * @param m ʳ������ ��������
 * @param max ����������� ������� ����� � �������� � �������
 * @return 
*/
pair<int,int> CheckMinMaxMembersOfMatrix(int* n, int* m, int max) {

	if (*n <= 0) {
		cout << "You enter wrong data! Please enter rows (min members - 2): \n";
		cin >> *n;
		*n = CheckIntValue(&*n);
	}
	if (*m <= 0) {
		cout << "You enter wrong data! Please enter colums (min members - 2): \n";
		cin >> *m;
		*m = CheckIntValue(&*m);
	}
	if (*n > max) {
		cout << "You enter wrong data! Please enter rows (max members - "<<max<<"): \n";
		cin >> *n;
		*n = CheckIntValue(&*n);
	}
	if (*m > max) {
		cout << "You enter wrong data! Please enter colums (max members - "<<max<<"): \n";
		cin >> *m;
		*m = CheckIntValue(&*m);
	}
	return make_pair(*n, *m);
}

/**
 * @brief �������� ����� � ���������� � �� ����� ���� ������������ �, � ����� �������� ���������� ��'��� ��������, ���� ������, � ��� ��������
 * @param n ʳ������ �������� ������ �������� ������������ � ��������� 
*/
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
 * @brief ����� ��� ������ � ���������� ������� �������� ������ �������� -1
 * @param mas �����, ���� ������� ��������
 * @param n ����� ������	
 * @param d ˳�������
*/
void ClearMassive(int *mas, int n, int* d) {
	
	*d = 0;
	for (int i = 0; i < n; i++) {
		mas[i] = -1;
	}
}

/**
 * @brief ���� �������� �� ������, ��� ���������� ���������� �������� �
 * @param mas �����, ����� ������� �������� ��������
 * @param target �������, ����� ������������ ��������
 * @param value �������� ��� ��������� �������� ������
 * @param n_team ����� �������
*/
void AddElementMassiveForTaskB(int* mas, int* target, int* value, int n_team) {

	mas[*target] = *value;
	*target += 1;
	mas[*target] = 65 + n_team;
	*target += 1;
}

/**
 * @brief ���� �������, ��� ������� ����� ���� �� ������� ������� �������
 * @param n ʳ������ ����� �������-�������
 * @param m ʳ������ �������� ������� -�������
*/
void FindTeamGetSecondPlace(int* n, int* m) {
	int** matrix_table = new int*[*n];
	int rnd_number, k = 1, team_number = 65, buffer = 0;
	int* record = new int[*n];
	int winner_save[26], second_place_save[26], i_save = 0, j_save = 0;

	for (int i = 0; i < *n; i++) {
		matrix_table[i] = new int[*m];
	}
	for (int i = 0; i < *n; i++) {
		for (int j = 0; j < *m; j++) {
			rnd_number = rand() % 3;
			if (rnd_number == 2) {
				rnd_number = 3;
			}
			if (i == j) {
				rnd_number = 0;
			}
			matrix_table[i][j] = rnd_number;
		}
	}
	for (int i = 0; i < *n; i++) {
		for (int j = 0 + i; j < *m; j++) {
			if (i != j) {				
				if (matrix_table[i][j] == 0) {
					matrix_table[i+k][j-k] = 3;
					k++;
				}
				else if (matrix_table[i][j] == 1) {
					matrix_table[i+k][j-k] = 1;
					k++;
				}
				else if (matrix_table[i][j] == 3) {
					matrix_table[i+k][j-k] = 0;
					k++;
				}
			}
		}
		k = 1;
	}
	cout << "------- ";
	for (int i = 0; i < *n; i++) {
		cout << char(team_number) << " | ";
		team_number++;
	}
	cout << endl;
	team_number = 65;
	for (int i = 0; i < *n; i++) {
		cout << "Team "<<char(team_number)<<": ";
		team_number++;
		buffer = 0;
		for (int j = 0; j < *m; j++) {
			cout << matrix_table[i][j] << " | ";
			buffer += matrix_table[i][j];
		}
		record[i] = buffer;
		cout << endl;
	}
	buffer = 0;
	for (int* ptr = record; ptr < &record[*n]; ptr++) {
		//cout << *ptr << endl;
		if (*ptr > buffer) {
			buffer = *ptr;			
			ClearMassive(second_place_save, 26, &j_save);
			for (int j = 0; j < i_save; j++) {
				second_place_save[j] = winner_save[j];
				j_save++;
			}
			ClearMassive(winner_save, 26, &i_save);
			AddElementMassiveForTaskB(winner_save, &i_save, &buffer, ptr - record);
			
		}
		else if (*ptr == buffer) {
			AddElementMassiveForTaskB(winner_save, &i_save, &buffer, ptr - record);
		}
		if (*ptr < buffer && *ptr > second_place_save[0]) {
			ClearMassive(second_place_save, 26, &j_save);
			AddElementMassiveForTaskB(second_place_save, &j_save, &*ptr, ptr - record);
		}
		else if (second_place_save[0] == *ptr) {
			AddElementMassiveForTaskB(second_place_save, &j_save, &second_place_save[0], ptr - record);
		}
	}
	if (winner_save[2] >= 0) {
		cout << "The second place goes to the teams ";
		for (int i = 1; i < 26; i +=2) {
			if (winner_save[i] >= 0) {
				cout << " or " << char(winner_save[i]);
			}
		}
		cout << " with: " << winner_save[0] << " points \n";
		cout << endl;
	}
	else if (second_place_save[2] >= 0) {
		cout << "The second place goes to the teams ";
		for (int* ptr = second_place_save + 1; ptr < &second_place_save[26]; ptr += 2) {
			if (*ptr >= 0) {
				cout << " or " << char(*ptr);
			}
		}
		cout << " with: " << second_place_save[0] << " points \n";
		cout << endl;
	}
	else {
		cout << "The second place goes to the team " << char(second_place_save[1]) << " with: " << second_place_save[0] << " points \n";
	}
	for (int i = 0; i < *n; i++) {
		delete[] matrix_table[i];
	}
	delete[] matrix_table;
}

/**
 * @brief ��������� ���� �� ����� ����������� ��������� � ��������
 * @param q ���� ������������ ��������, ��� �������� ������������ � ���������
 * @return ������� ���� ���� ��� ����������� ������ ����������� � ��������
*/
int MenuOfSolution(int* q) {
	int n, m;
	pair<int, int> matrix_size;

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
		cout << "Enter amount of Teams: ";
		cin >> n;
		n = CheckIntValue(&n);
		m = n;
		matrix_size = CheckMinMaxMembersOfMatrix(&n, &m, 26);
		n = matrix_size.first;
		m = n;
		FindTeamGetSecondPlace(&n, &m);		
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