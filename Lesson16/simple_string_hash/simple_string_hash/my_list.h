#pragma once
#include <iostream>

struct Node {

    int date;

    Node* next_ptr;//указатель на след.элемент
    Node(int _date)
    {
        date = _date; //данные
        next_ptr = nullptr;
    }
};

class List

{

private:

    Node* first_ptr;

    Node* last_ptr;

public:

    List();

    ~List();

    bool is_empty()

    {

        return first_ptr == nullptr;

    }

    void insert_back(int _value)

    {

        Node* new_node = new Node(_value); //создаем новый объект

        if (is_empty()) // если объектов нет в списке, то
        {
            first_ptr = last_ptr = new_node; // и первый и последний указатель будут указывать на только что созданный объект
        }

        else
        {
            last_ptr->next_ptr = new_node;
            last_ptr = new_node;
        }
    }



    void remove_front()

    {

        if (is_empty())//если список пустой, то выходим?
        {
            return;
        }
        Node* delete_ptr = nullptr; //создаем указатель, равный нулю
        if (first_ptr == last_ptr) // если указатели равны(то есть один объект в списке), то
        {
            delete_ptr = first_ptr;//созданному ук.присвают знач.ук.на первый элемент
            first_ptr = last_ptr = nullptr; // указатели на первый и посл.обнул€ют.
        }
        else
        {
            first_ptr = first_ptr->next_ptr;//переставл€ем указатель первого элемента на следующий, то есть след.элемент стал первым
        }
        delete delete_ptr; // удал€ем указатель
    }
    void print()
    {
        Node* print_ptr = first_ptr; //создаем указатель равный указателю на первый элемент

        while (print_ptr != nullptr) //пока этот указатель не будет равен нулю...
        {
            std::cout << print_ptr->date << " "; // выводим данные этого объекта
            print_ptr = print_ptr->next_ptr; // переходим к след.объекту списка, то есть присваиваем указателю значение указател€ на следующий объект
        }

    }
    bool find(int value)
    {
        if (is_empty())
        {
            return false;
        }
        Node* find_ptr = first_ptr; //создаем указатель равный указателю на первый элемент
        while (find_ptr != nullptr) //пока этот указатель не будет равен нулю...
        {
            if (find_ptr->date == value)
            {
                return true;
            }
            find_ptr = find_ptr->next_ptr; // переходим к след.объекту списка, то есть присваиваем указателю значение указател€ на следующий объект
        }
        return false;
    }

};


List::List() //вызов конструктора
{
    first_ptr = last_ptr = nullptr;//типа пустой (начальное состо€ние, по умолчанию)
}

List::~List()//вызов деструктора
{
    Node* current_ptr = first_ptr;//создание указател€ current-текущий, присваиваем ему указатель на первый элемент
    Node* delete_ptr; // создаем указатель дл€ удалени€
    while (current_ptr != nullptr) //пока текущий указатель не будет равен 0
    {
        delete_ptr = current_ptr; //указатель дл€ удалени€ приравниваем к текущему указателю
        current_ptr = current_ptr->next_ptr; //текущий приравнием к указателю на след.объект, то есть переходим на след.эл.
        delete delete_ptr;// указатель дл€ удалени€ удал€ем
    }
}