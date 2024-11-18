#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void CreateTXT(const char* fname) // створення файлу з введених рядків
{
    ofstream fout(fname); // відкрили файл для запису
    string s; // введений користувачем рядок
    cout << "Enter lines (press Enter on an empty line to finish):" << endl;
    while (true) {
        getline(cin, s); // ввели рядок
        if (s.empty()) // перевірка на порожній рядок
            break;     // завершуємо введення
        fout << s << endl; // записали рядок у файл
    }
    cout << "File created successfully." << endl;
}

void PrintTXT(const char* fname) // виведення файлу на екран
{
    ifstream fin(fname); // відкрили файл для зчитування
    string s; // прочитаний рядок
    cout << "File contents:" << endl;
    while (getline(fin, s)) // поки можна прочитати рядок
    {
        cout << s << endl; // виводимо його на екран
    }
    cout << endl;
}

void FindThirdComma(const char* fname, int& lineNumber, int& position) {
    ifstream fin(fname);
    string line;
    lineNumber = -1; // Ініціалізація
    position = -1;
    int currentLine = 0, commaCount = 0;

    while (getline(fin, line)) {
        currentLine++;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ',') {
                commaCount++;
                if (commaCount == 3) {
                    lineNumber = currentLine;
                    position = i + 1; // Позиція символу
                    return;
                }
            }
        }
    }
}

int main() {
    char fname[100];
    cout << "Enter file name: ";
    cin >> fname;
    cin.ignore(); // Очищуємо буфер після вводу імені файлу

    CreateTXT(fname); // створення текстового файлу
    PrintTXT(fname);

    int lineNumber, position;
    FindThirdComma(fname, lineNumber, position);

    if (lineNumber != -1) {
        cout << "Third comma found at line " << lineNumber << ", position " << position << "." << endl;
    }
    else {
        cout << "Third comma not found in the file." << endl;
    }

    return 0;
}