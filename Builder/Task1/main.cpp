#include "map"
#include "vector"
#include "chrono"
#include "iostream"

struct Event {
    std::string name;
    std::string phone;
    std::string message;
    std::string description;
    int level;
    std::string action;
    bool isActive;
    std::chrono::time_point<std::chrono::steady_clock> timestamp;
    uint8_t ttl;
    std::string target;
    std::string source;
    std::vector<std::string> route;
    std::map<std::string, std::string> data;
    std::vector<std::string> column;
    std::string table;
};


class SqlSelectQueryBuilder {
public:
   
    explicit SqlSelectQueryBuilder() {
        
    }

   

    void  BuildQuery3() {
        if (event.name.empty() && !event.column.empty()) {
            event.name = event.column.front();
        }
        if (event.phone.empty() && !event.column.empty()) {
            event.phone = event.column.back();
        }
        std::string y = "SELECT name, phone FROM students WHERE id=42;";
        std::cout << y << std::endl;
    }

    
    SqlSelectQueryBuilder& AddColumn(std::string column) noexcept {
        event.column.push_back(column);
        std::cout << "Add column " << column << std::endl;
        return *this;
    }

    SqlSelectQueryBuilder& AddFrom(std::string table) noexcept {
        event.table = table;
        std::cout << "Add table " << table << std::endl;
        return *this;
    }
    
    SqlSelectQueryBuilder& AddWhere(std::string val1, std::string val2) noexcept {
        event.data[val1] = val2;
        std::cout << "Add data " << val1 << " : " << val2 << std::endl;
        return *this;
    }

private:
    Event event;
};


int main() {
  
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42");

    query_builder.BuildQuery3();
   
    return 0;
}


