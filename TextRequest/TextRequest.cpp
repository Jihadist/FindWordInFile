// TextRequest.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include <filesystem>

void runQueries(std::ifstream &infile);

int main()
{
	auto error_code=0;
    std::cout << "Hello World!\n";
	std::ifstream in("C:/0101.txt");
	if (in.is_open())
	{
		runQueries(in);
		error_code = 0xBADC0FFE;
	}
	std::string path = "C:/";
	in.close();
	error_code ^= 1;
	return error_code;
}

std::string make_plural(const size_t ctr, const std::string & word, const std::string & ending)
{
	return (ctr > 1) ? word + ending : word;
}

std::ostream & print(std::ostream & os, const QueryResult &qr)
{
	os << qr.request_ << " occurs " << qr.lines_->size() << " "
		<< make_plural(qr.lines_->size(), "time", "s") << "\n";
	for (auto num : *qr.lines_)
		os << "\t(line " << num + 1 << ") " << *(qr.file_->begin() + num) << "\n";
	return os;
}

void runQueries(std::ifstream &infile)
{
	// infile - поток ifstream для входного файла
	TextQuery tq(infile);
	// цикл взаимодействия с пользователем: приглашение ввода искомого
	// слова и вывод результатов
	while (true)
	{
		std::cout << "enter word to look for, or q to quit:";
		std::string s;
		// остановиться по достижении конца файла или при встрече
		// стоп символа во вводе
		if (!(std::cin >> s) || s == "q")
			break;
		// выволнить запрос и вывести результат
		print(std::cout, tq.query(s)) << std::endl;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
