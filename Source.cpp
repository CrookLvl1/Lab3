#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	std::fstream first, second, temp;
	std::string line;

	//Запись из первого файла в вспомогательный
	first.open("file1.txt", ios::in);
	temp.open("temp.txt", ios::out);
	
	while (!first.eof()) {
		getline(first, line);
		//Если файл не закончился после прочтения строки, значит добавляем "\n" в конце строки,
		//Иначе добавляем строку без знака "\n" в конце.
		!first.eof() ? temp << line << std::endl : temp << line;
	}

	first.close();
	temp.close();

	//Запись из второго файла в первый
	second.open("file2.txt", ios::in);
	first.open("file1.txt", ios::out);

	while (!second.eof()) {
		getline(second, line);
		!second.eof() ? first << line << std::endl : first << line;
	}

	first.close();
	second.close();

	//Запись из вспомогательного файла во второй
	second.open("file2.txt", ios::out);
	temp.open("temp.txt", ios::in);
	while (!temp.eof()) {
		getline(temp, line);
		!temp.eof() ? second << line << std::endl : second << line;
	
	}
	second.close();
	temp.close();
	//Удаление вспомогательного файла
	std::remove("temp.txt");

	return 0;
}