#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	std::fstream first, second, temp;
	std::string line;

	//������ �� ������� ����� � ���������������
	first.open("file1.txt", ios::in);
	temp.open("temp.txt", ios::out);
	
	while (!first.eof()) {
		getline(first, line);
		//���� ���� �� ���������� ����� ��������� ������, ������ ��������� "\n" � ����� ������,
		//����� ��������� ������ ��� ����� "\n" � �����.
		!first.eof() ? temp << line << std::endl : temp << line;
	}

	first.close();
	temp.close();

	//������ �� ������� ����� � ������
	second.open("file2.txt", ios::in);
	first.open("file1.txt", ios::out);

	while (!second.eof()) {
		getline(second, line);
		!second.eof() ? first << line << std::endl : first << line;
	}

	first.close();
	second.close();

	//������ �� ���������������� ����� �� ������
	second.open("file2.txt", ios::out);
	temp.open("temp.txt", ios::in);
	while (!temp.eof()) {
		getline(temp, line);
		!temp.eof() ? second << line << std::endl : second << line;
	
	}
	second.close();
	temp.close();
	//�������� ���������������� �����
	std::remove("temp.txt");

	return 0;
}