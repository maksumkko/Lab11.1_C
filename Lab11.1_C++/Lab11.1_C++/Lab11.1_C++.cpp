#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void CreateTXT(const char* fname) // ��������� ����� � �������� �����
{
    ofstream fout(fname); // ������� ���� ��� ������
    string s; // �������� ������������ �����
    cout << "Enter lines (press Enter on an empty line to finish):" << endl;
    while (true) {
        getline(cin, s); // ����� �����
        if (s.empty()) // �������� �� ������� �����
            break;     // ��������� ��������
        fout << s << endl; // �������� ����� � ����
    }
    cout << "File created successfully." << endl;
}

void PrintTXT(const char* fname) // ��������� ����� �� �����
{
    ifstream fin(fname); // ������� ���� ��� ����������
    string s; // ���������� �����
    cout << "File contents:" << endl;
    while (getline(fin, s)) // ���� ����� ��������� �����
    {
        cout << s << endl; // �������� ���� �� �����
    }
    cout << endl;
}

void FindThirdComma(const char* fname, int& lineNumber, int& position) {
    ifstream fin(fname);
    string line;
    lineNumber = -1; // �����������
    position = -1;
    int currentLine = 0, commaCount = 0;

    while (getline(fin, line)) {
        currentLine++;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ',') {
                commaCount++;
                if (commaCount == 3) {
                    lineNumber = currentLine;
                    position = i + 1; // ������� �������
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
    cin.ignore(); // ������� ����� ���� ����� ���� �����

    CreateTXT(fname); // ��������� ���������� �����
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