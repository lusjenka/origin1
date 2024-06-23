#include <iostream>
#include <Wt/Dbo/dbo.h>
#include <Wt/dbo/backend/Postgres.h>
#include <Windows.h>
#include <set>
#include <string>

#pragma execution_character_set("utf-8")

using namespace std;

class Book;

class Publisher
{
public:
	string name;
	Wt::Dbo::collection<Wt::Dbo::ptr<Book>> books;

	template<typename Action>
	void persist(Action& a)
	{
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "publisher");
	}
};

class Stock;

class Book
{
public:
	string title;
	Wt::Dbo::ptr<Publisher> publisher;
	Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

	template<typename Action>
	void persist(Action& a)
	{
		Wt::Dbo::field(a, title, "title");
		Wt::Dbo::belongsTo(a, publisher, "publisher");
		Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "book");
	}
};

class Shop
{
public:
	string name;

	Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

	template<typename Action>
	void persist(Action& a)
	{
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "shop");
	}
};

class Sale;

class Stock
{
public:
	int count;
	Wt::Dbo::ptr<Book> book;
	Wt::Dbo::ptr<Shop> shop;
	Wt::Dbo::collection<Wt::Dbo::ptr<Sale>> sales;

	template<typename Action>
	void persist(Action& a)
	{
		Wt::Dbo::field(a, count, "count");
		Wt::Dbo::belongsTo(a, book, "book");
		Wt::Dbo::belongsTo(a, shop, "shop");
		Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "stock");
	}
};

class Sale
{
public:
	int price;
	string data_sale;
	int count;
	Wt::Dbo::ptr<Stock> stock;

	template<typename Action>
	void persist(Action& a)
	{
		Wt::Dbo::field(a, price, "price");
		Wt::Dbo::field(a, data_sale, "data_sale");
		Wt::Dbo::field(a, count, "count");
		Wt::Dbo::field(a, stock, "stock");
	}
};

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	try
	{
		string conStr = "host=localhost port=5432 dbname=clients user=postgres password=479Hgf43";

		unique_ptr<Wt::Dbo::backend::Postgres> conn = make_unique<Wt::Dbo::backend::Postgres>(conStr);

		Wt::Dbo::Session s;
		s.setConnection(move(conn));

		s.mapClass<Publisher>("publisher");
		s.mapClass<Book>("book");
		s.mapClass<Shop>("shop");
		s.mapClass<Stock>("stock");
		s.mapClass<Sale>("sales");

		s.createTables();

		Wt::Dbo::Transaction t{ s };

		unique_ptr <Publisher> publisher1{ new Publisher {"Eksmo"} };
		unique_ptr <Publisher> publisher2{ new Publisher {"AIST"} };
		unique_ptr <Publisher> publisher3{ new Publisher {"Machaon"} };

		auto publisherdb1 = s.add<Publisher>(move(publisher1));
		auto publisherdb2 = s.add<Publisher>(move(publisher2));
		auto publisherdb3 = s.add<Publisher>(move(publisher3));

		unique_ptr <Book> book1{ new Book {"Tom Soyer", publisherdb1} };
		unique_ptr <Book> book2{ new Book {"Atlant struggled", publisherdb1} };
		unique_ptr <Book> book3{ new Book {"Harry Potter"} };

		auto bookdb1 = s.add<Book>(move(book1));
		auto bookdb2 = s.add<Book>(move(book2));
		auto bookdb3 = s.add<Book>(move(book3));

		publisherdb3.modify()->books.insert(bookdb3);

		unique_ptr <Shop> shop1{ new Shop {"Ligovsky"} };
		unique_ptr <Shop> shop2{ new Shop {"Nevsky"} };
		unique_ptr <Shop> shop3{ new Shop {"Leninsky"} };

		auto shopdb1 = s.add<Shop>(move(shop1));
		auto shopdb2 = s.add<Shop>(move(shop2));
		auto shopdb3 = s.add<Shop>(move(shop3));

		unique_ptr <Stock> stock1{ new Stock {100, bookdb1, shopdb3} };
		unique_ptr <Stock> stock2{ new Stock {50, bookdb2, shopdb3} };

		auto stockdb1 = s.add<Stock>(move(stock1));
		auto stockdb2 = s.add<Stock>(move(stock2));
		auto stockdb3 = s.add<Stock>(move(unique_ptr <Stock> { new Stock {20, bookdb3, shopdb2} }));

		unique_ptr <Sale> sale1{ new Sale {199, "2024-06-03", 40, stockdb1} };
		unique_ptr <Sale> sale2{ new Sale {350, "2024-06-02", 30, stockdb2} };
		unique_ptr <Sale> sale3{ new Sale {150, "2024-06-01", 20, stockdb3} };

		s.add<Sale>(move(sale1));
		s.add<Sale>(move(sale2));
		s.add<Sale>(move(sale3));

		string name;
		cout << "Введите имя или id издателя: ";
		cin >> name;

		Wt::Dbo::ptr<Publisher> p;

		try
		{
			int id = stoi(name);
			p = s.find<Publisher>().where("id = ?").bind(id);
		}
		catch (const exception& e)
		{
			p = s.find<Publisher>().where("name = ?").bind(name);
		}

		set<string> shopNames;

		if (p)
		{
			cout << "Издательство найдено.Это: " << p->name << endl;

			for (const auto& book : p->books)
			{
				for (const auto& stock : book->stocks)
				{
					shopNames.insert(stock->shop->name);
				}
			}
			for (auto& shopName : shopNames)
			{
				cout << "Shop is: " << shopName << endl;
			}
		}
		else
		{
			cout << "Publisher not found." << endl;
		}
		t.commit();
	}
	catch (const exception& e)
	{
		cout << "Error: " << e.what() << endl;
	}
}