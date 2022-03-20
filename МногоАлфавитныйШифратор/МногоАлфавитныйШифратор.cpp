#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

void encrypt(string main, string cyphr[]);
void decrypt(string main, string cyphr[]);

void main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream fin;
	fin.open("Alphabet.txt");
	int option;
	bool stop = false;
	string main_alph, cyphr_alph[5];
	getline(fin, main_alph);
	cout << "Исходный алфавит:" << endl;
	cout << main_alph << endl;
	for (int i = 0; i < 5; i++) { getline(fin, cyphr_alph[i]); }
	cout << endl << "Алфавит шифрования:" << endl;
	for (int i = 0; i < 5; i++) { cout << cyphr_alph[i] << endl; }
	do {
		cout << endl << "Выберите режим работы: " << endl << "[1] Шифровка текста" << endl << "[2] Дешифровка текста" << endl << "[3] Выход" << endl << "Выбор: ";
		cin >> option;
		switch (option) {
		case 1: {encrypt(main_alph, cyphr_alph); break; }
		case 2: {decrypt(main_alph, cyphr_alph); break; }
		case 3: stop = true;
		}
	} while (stop != true);
}

void encrypt(string main, string cyphr[]) {
	string input;
	cout << "Введите текст: ";
	cin.ignore();
	getline(cin, input);
	for (int i = 0; i < size(input); i++) {
		for (int j = 0; j < size(main); j++) {
			if (input[i] == main[j]) { input[i] = cyphr[i % 5][j]; break; }
		}
	}
	cout << "Зашифрованный текст: " << input << endl;
}

void decrypt(string main, string cyphr[]) {
	string input;
	cout << "Введите текст: ";
	cin.ignore();
	getline(cin, input);
	for (int i = 0; i < size(input); i++) {
		for (int j = 0; j < size(main); j++) {
			if (input[i] == cyphr[i % 5][j]) { input[i] = main[j]; break; }
		}
	}
	cout << "Расшифрованный текст: " << input << endl;
}