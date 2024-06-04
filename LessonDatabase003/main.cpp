#include <iostream>
#include <pqxx/pqxx>
#include <string>
#include <map>
#include  <Windows.h>
#pragma execution_character_set("utf-8")


int main()
{
	//setlocale(LC_ALL, "Russian");
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	setvbuf(stdout, nullptr, _IOFBF, 1000);
	try
	{
		pqxx::connection c(
			"host=localhost "
			"port=5432 "
			"dbname=postgres "
			"user=postgres "
			"password=479Hgf43#_pgS");

		std::cout << "Hello" << std::endl;

		pqxx::transaction t{ c };

		auto values = t.query<int, std::string>("SELECT * FROM Исполнители");
		for (std::tuple<int, std::string> value : values)
		{
			std::cout << "id: " << std::get<0>(value) << " ";
			std::cout << "Имя: " << std::get<1>(value) << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Error happened:" << e.what() << std::endl;
	}
	return 0;
	
}