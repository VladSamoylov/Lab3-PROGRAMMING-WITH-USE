#include "iostream"
#include "math.h"

using namespace std;

/**
 * @brief Перевіряє коректне значення типу int, яке ввів користувач до системи
 * @param i Значення типу int введене з клавіатури
 * @return Повертає коректне значення для подальшої роботи системи
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
 * @brief Перевіряє коректне значення типу float, яке ввів користувач до системи
 * @param i Значення типу float введене з клавіатури
 * @return Повертає коректне значення для подальшої роботи системи
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
 * @brief Перевіряє мінімальну кількість елементів, який повинен мати масив
 * @param n Кількість елементів масиву введенна користувачем з клавіатури
 * @return Повертає коректне значення кількості елементів масиву
*/
int CheckMinMembersOfMassive(int* n) {

	if (*n <= 0) {
		cout << "You enter wrong data! Please enter correct data (min members - 0): \n";
		cin >> *n;
		*n = CheckIntValue(&*n);
	}
	return *n;
}

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
 * @brief Заповнює масив А значеннями і на основі него створюємасив В, у якому спочатку розташовані від'ємні елементи, потім додатні, а нулі вилучено
 * @param n Кількість елементів масиву введенна користувачем з клавіатури 
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

void ClearMassive(int *mas, int n, int* d) {
	
	*d = 0;
	for (int i = 0; i < n; i++) {
		mas[i] = -1;
	}
}

void AddElementMassiveForTaskB(int* mas, int* target, int* value, int n_team) {

	mas[*target] = *value;
	*target += 1;
	mas[*target] = 65 + n_team;
	*target += 1;
}

void FindTeamGetSecondPlace(int* n, int* m) {
	int** matrix_table = new int*[*n];
	int rnd_number, k = 1, team_number = 65, buffer = 0, second_place = 0;
	int* record = new int[*n];

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
	int winner_save[26], second_place_save[26], i_save = 0, j_save = 0;
	for (int* ptr = record; ptr < &record[*n]; ptr++) {
		cout << *ptr << endl;
		if (*ptr > buffer) {
			buffer = *ptr;			
			ClearMassive(second_place_save, 26, &j_save);
			for (int j = 0; j < i_save; j++) {
				second_place_save[j] = winner_save[j];
				j_save++;
			}
			ClearMassive(winner_save, 26, &i_save);
			AddElementMassiveForTaskB(winner_save, &i_save, &buffer, ptr - record);
			//winner_save[i_save] = buffer;
			//i_save++;
			//winner_save[i_save] = 65 + (ptr - record);
			//i_save++;
			
		}
		else if (*ptr == buffer) {
			AddElementMassiveForTaskB(winner_save, &i_save, &buffer, ptr - record);
			//winner_save[i_save] = buffer;
			//i_save++;
			//winner_save[i_save] = 65 + (ptr - record);
			//i_save++;
		}
		if (*ptr < buffer && *ptr > second_place_save[0]) {
			ClearMassive(second_place_save, 26, &j_save);
			AddElementMassiveForTaskB(second_place_save, &j_save, &*ptr, ptr - record);
			//second_place_save[j_save] = *ptr;
			//j_save++;
			//second_place_save[j_save] = 65 + (ptr - record);
			//j_save++;
			//second_place = *ptr;
		}
		else if (second_place_save[0] == *ptr) {
			AddElementMassiveForTaskB(second_place_save, &j_save, &second_place_save[0], ptr - record);
			//second_place_save[j_save] = second_place_save[0];
			//j_save++;
			//second_place_save[j_save] = 65 + (ptr - record);
			//j_save++;
		}
	}
	if (winner_save[2] >= 0) {
		cout << "first place: \n";
		for (int i = 0; i < 26; i++) {			
			cout << winner_save[i] << '/';
		}
		cout << endl;
	}
	else if (second_place_save[2] >= 0) {
		cout << "second place: \n";
		for (int* ptr = second_place_save; ptr < &second_place_save[26]; ptr++) {
			cout << *ptr << '/';
		}
		cout << endl;
	}
	else {
		cout << "The second place goes to the team " << char(second_place_save[1]) << " with: " << second_place_save[0] << " points \n";
	}
	
}

/**
 * @brief Інтерфейс який дає змогу користувачу працювати з додатком
 * @param q Вибір виконуваного завдання, яке задається користувачем з клавіатури
 * @return Повертає саме себе для продовження роботи користувача з додатком
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