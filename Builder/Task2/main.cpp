#include<iostream>
#include <vector>
#include <map>

struct Table_fields {
	std::string select_colum;
	std::string select_from;
	std::string select_where;
	std::string select_query;
	std::vector<std::string> name_of_colums;//название столбца
	std::string name_of_table;//название таблицы
	std::vector<std::string> date;//данные таблицы
	std::vector<std::string> search_name_of_colums;//искомая инфа

};

std::string count_cols(std::vector<std::string>& name_of_colums) {
	std::string result = "";
	for (int i = 0; i < name_of_colums.size(); i++) {
		if (i == name_of_colums.size() - 1) {
			result = result + name_of_colums[i];
		}
		else result = result + name_of_colums[i] + ", ";
	}
	return result;
}

std::string search_name_of_cols(std::vector<std::string>& search_name_of_colums, std::vector<std::string>& date) {
	std::string result = "";
	for (int i = 0; i < search_name_of_colums.size(); i++) {
		if (i == search_name_of_colums.size() - 1) {
			result = result + search_name_of_colums[i] + "=" + date[i];
		}
		else result = result + search_name_of_colums[i] + "=" + date[i] + " AND ";
	}
	return result;

}

std::string search_name_of_cols_and_sign(std::vector<std::string>& search_name_of_colums, std::vector<std::string>& date, char sign) {
	std::string result = "";
	for (int i = 0; i < search_name_of_colums.size(); i++) {
		if (i == search_name_of_colums.size() - 1) {
			result = result + search_name_of_colums[i] + sign + date[i];
		}
		else result = result + search_name_of_colums[i] + sign + date[i] + " AND ";
	}
	return result;
}

class SqlSelectQueryBuilder {
protected:
	Table_fields fields;
	int count_col = 0;
public:
	explicit SqlSelectQueryBuilder() {
		fields.name_of_colums.push_back("*");
	}

	SqlSelectQueryBuilder& AddColum(std::string name_of_colums) {
		if (count_col == 0) {
			fields.name_of_colums.pop_back();
		}
		fields.name_of_colums.push_back(name_of_colums);
		count_col++;
		return *this;
	}

	SqlSelectQueryBuilder& AddFrom(std::string name_of_table) {
		fields.name_of_table = name_of_table;
		return *this;
	}

	SqlSelectQueryBuilder& AddWhere(std::string search_name_of_colums, std::string date) {
		fields.search_name_of_colums.push_back(search_name_of_colums);
		fields.date.push_back(date);
		return *this;
	}

	virtual std::string BuildQuery() {

		fields.select_query = "SELECT " + count_cols(fields.name_of_colums) + 
			" FROM " + fields.name_of_table + 
			" WHERE " + search_name_of_cols(fields.search_name_of_colums, fields.date) + "; ";
		return fields.select_query;
	}

	SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept {
		for (const auto& element : kv) {
			fields.search_name_of_colums.push_back(element.first);
			fields.date.push_back(element.second);
		}
		return *this;

	}

	SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept {
		if (count_col == 0) {
			fields.name_of_colums.pop_back();
		}
		for (const auto& element : columns) {
			fields.name_of_colums.push_back(element);
			count_col++;
		}
		return *this;
	}

};

class AdvancedSqlSelectQueryBuilder : public SqlSelectQueryBuilder {
private:
	char sign;

public:
	AdvancedSqlSelectQueryBuilder MoreLess(std::string search_name_of_colums, std::string date, char sign) {
		this->sign = sign;
		fields.search_name_of_colums.push_back(search_name_of_colums);
		fields.date.push_back(date);

		return *this;
	}

	std::string BuildQuery() override {


		fields.select_query = "SELECT " + count_cols(fields.name_of_colums) + " FROM " + fields.name_of_table + " WHERE " + search_name_of_cols_and_sign(fields.search_name_of_colums, fields.date, sign) + "; ";
		return fields.select_query;
	}

	
};


int main() {

    SqlSelectQueryBuilder query_builder;
    query_builder.AddColum("name").AddColum("phone");
   
    AdvancedSqlSelectQueryBuilder query_builders;
    query_builders.AddColumns({ "name", "phone" });
    query_builders.AddFrom("students");
    query_builders.MoreLess("id", "42", '>');

    std::cout << query_builders.BuildQuery();

}

