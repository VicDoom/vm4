#include<iostream>
#include<fstream>

using namespace std;

bool checkInput(ifstream& fin) {

	if (fin.is_open()) {
		return true;
	}
	else {
		return false;
	}
}

bool readInput(ifstream& fin, ofstream& fout, int& N, double*& yArray) {

	int count = 0;

	fin >> N;

	yArray = new double[N];
	bool isRightInput = true;

	double num;

	for (int i = 0; i < N; i++) {

		fin >> num;
		yArray[i] = num;
		count++;

	}

	if (count != N) {

		isRightInput = false;

	}

	(isRightInput)
		? fout << "Данные введены верно" << '\n'
		: fout << "Некорректно введённые данные";

	return (isRightInput);
}

void findQ(int N, double* y, double *&Q) {

	Q[0] = y[0];
	Q[N - 1] = y[N - 1];

	Q[1] = (10 * y[0] + 8 * y[1] + 6 * y[2] + 4 * y[3] + 2 * y[4] - 2 * y[6]) / 28;
	Q[2] = (7 * y[0] + 6 * y[1] + 5 * y[2] + 4 * y[3] + 3 * y[4] + 2 * y[5] + y[6]) / 28;

	for (int i = 3; i < N - 3; i++) {
		Q[i] = (y[i - 3] + y[i - 2] + y[i - 1] + y[i] + y[i + 1] + y[i + 2] + y[i + 3]) / 7;
	}

	Q[N - 3] = (y[N - 7] + 2 * y[N - 6] + 3 * y[N - 5] + 4 * y[N - 4] 
				+ 5 * y[N - 3] + 6 * y[N - 2] + 7 * y[N - 1]) / 28;

	Q[N - 2] = ((-2)*y[N - 7] + 2 * y[N - 5] + 4 * y[N - 4]
		+ 6 * y[N - 3] + 8 * y[N - 2] + 10 * y[N - 1]) / 28;

}

void print(int N, double* A) {
	cout << '\n';
	for (int i = 0; i < N; i++)
		cout << A[i] << ' ';
}

int main() {

	setlocale(LC_ALL, "rus");
	int N;
	double* yArray;

	ifstream fin;
	ofstream fout;

	fin.open("input.txt");
	fout.open("output.txt");

	if (checkInput(fin)) {

		if (readInput(fin, fout, N, yArray)) {
			cout << "Success";
		}

	}
	else {

		fout << "Файл не найден";
		return 0;

	}

	double* Q = new double[N];

	findQ(N, yArray, Q);
	print(N, yArray);
	print(N, Q);

	return 0;
}