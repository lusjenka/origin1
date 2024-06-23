#include "ClientsDB.h"

ClientsDB::ClientsDB(const std::string& connection) : connection_{ connection } { std::cout << "�������� ���������� � ��." << std::endl; };

void ClientsDB::dropTables()
{
    pqxx::transaction trn(connection_);
    trn.exec(R"(DROP TABLE IF EXISTS clients, phones;)");
    trn.commit();
}

void ClientsDB::createTables()
{
    pqxx::transaction trn(connection_);
    trn.exec(R"(CREATE TABLE IF NOT EXISTS clients(id SERIAL PRIMARY KEY, name TEXT, surname TEXT, email TEXT UNIQUE);  
        CREATE TABLE IF NOT EXISTS phones(id SERIAL PRIMARY KEY, client_id INT REFERENCES clients(id), phone TEXT UNIQUE);)");
    trn.commit();
    std::cout << "������� �������" << std::endl;
}

void ClientsDB::addClient(const std::string& name, const std::string& surname, const std::string& email, const std::string& phone)
{

    pqxx::transaction trn(connection_);
    connection_.set_client_encoding("UTF8");
    pqxx::result res = trn.exec_params("INSERT INTO clients(name, surname, email) VALUES ($1, $2, $3) RETURNING id;", name, surname, email);
    if (!res.empty())
    {
        int client_id = res[0][0].as<int>();
        trn.exec_params("INSERT INTO phones(client_id, phone) VALUES ($1, $2);", client_id, phone);
        trn.commit();
        std::cout << "�������� ������ � ID: " << client_id << std::endl;
    }
    else
    {
        trn.abort();
        std::cerr << "������ �� ��������." << std::endl;
    }
}

void ClientsDB::addPhone(const std::string& name, const std::string& phone)
{
    pqxx::transaction trn(connection_);
    pqxx::result res = trn.exec_params("SELECT id, surname FROM clients WHERE name = $1;", name);
    if (!res.empty())
    {
        int client_id = res[0][0].as<int>();
        trn.exec_params("INSERT INTO phones (client_id, phone) VALUES ($1, $2);", client_id, phone);

        std::string client_surname = res[0][1].as<std::string>();
        trn.commit();
        std::cout << "�������� ������� ��� �������: " << client_id << " " << name << " " << client_surname << std::endl;
    }
    else
    {
        trn.abort();
        std::cerr << "�� ������ ������ " << name << std::endl;
    }
}

void ClientsDB::updateClient(const std::string& email, const std::string& newName, const std::string& newSurname, const std::string& newEmail)
{
    pqxx::transaction trn(connection_);
    pqxx::result res = trn.exec_params("SELECT id FROM clients WHERE email = $1;", email);
    if (!res.empty())
    {
        int client_id = res[0][0].as<int>();
        trn.exec_params(R"(UPDATE clients SET name = $1, surname = $2, email = $3 WHERE id = $4;)", newName, newSurname, newEmail, client_id);
        trn.commit();
        std::cout << "�������� ���������� ������� " << client_id << " " << newName << " " << newSurname << " " << newEmail << std::endl;
    }
    else
    {
        trn.abort();
        std::cerr << "�� ������ ������ " << newName << std::endl;
    }
}

void ClientsDB::removePhone(const std::string& email, const std::string& phone)
{
    pqxx::transaction trn(connection_);
    pqxx::result res = trn.exec_params("SELECT id, name, surname FROM clients WHERE email = $1;", email);
    if (!res.empty())
    {
        int client_id = res[0][0].as<int>();
        trn.exec_params("DELETE FROM phones WHERE client_id = $1 AND phone = $2;", client_id, phone);
        trn.commit();
        std::string client_name = res[0][1].as<std::string>();
        std::string client_surname = res[0][2].as<std::string>();
        std::cout << "������� ������ ��� ������� " << client_id << " " << client_name << " " << client_surname << std::endl;
    }
    else
    {
        trn.abort();
        std::cerr << "�� ������ ������ " << email << std::endl;
    }
}

void ClientsDB::removeClient(const std::string& email)
{
    pqxx::transaction trn(connection_);
    pqxx::result res = trn.exec_params("SELECT id, name, surname FROM clients WHERE email = $1;", email);
    if (!res.empty()) {
        int client_id = res[0][0].as<int>();
        std::string client_name = res[0][1].as<std::string>();
        std::string client_surname = res[0][2].as<std::string>();
        trn.exec_params("DELETE FROM phones WHERE client_id = $1;", client_id);
        trn.exec_params("DELETE FROM clients WHERE id = $1;", client_id);
        trn.commit();
        std::cout << "������ ������ " << client_id << " " << client_name << " " << client_surname << std::endl;
    }
    else {
        trn.abort();
        std::cerr << "�� ������ ������ " << email << std::endl;
    }
}

std::vector<Client> ClientsDB::findClients(const std::string& query)
{
    std::vector<Client> result;
    pqxx::transaction trn(connection_);
    pqxx::result res = trn.exec_params(
        "SELECT * "
        "FROM clients "
        "LEFT JOIN public.phones on public.clients.id = public.phones.client_id "
        "WHERE clients.name = $1 OR clients.surname = $1 OR clients.email = $1 OR phones.phone = $1;", query);
    for (auto& row : res) {
        Client client;
        client.name_ = row["name"].as<std::string>();
        client.surname_ = row["surname"].as<std::string>();
        client.email_ = row["email"].as<std::string>();
        
        result.push_back(client);
    }
    return result;
}

void ClientsDB::show()
{
    pqxx::transaction trn(connection_);

    pqxx::result tables = trn.exec("SELECT table_name FROM information_schema.tables WHERE table_schema='public';");

    for (auto& row : tables)
    {
        std::string table_name = row[0].as<std::string>();

        std::string query = "SELECT * FROM " + table_name;
        pqxx::result data = trn.exec(query);

        std::cout << "�������: " << table_name << std::endl;
        for (auto& row : data) {
            for (auto& field : row) {
                std::cout << field.c_str() << "  ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
   // std::cout << "���������" << std::endl;
};