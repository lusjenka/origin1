#pragma once
#include <iostream>

struct Node {

    int date;

    Node* next_ptr;//��������� �� ����.�������
    Node(int _date)
    {
        date = _date; //������
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

        Node* new_node = new Node(_value); //������� ����� ������

        if (is_empty()) // ���� �������� ��� � ������, ��
        {
            first_ptr = last_ptr = new_node; // � ������ � ��������� ��������� ����� ��������� �� ������ ��� ��������� ������
        }

        else
        {
            last_ptr->next_ptr = new_node;
            last_ptr = new_node;
        }
    }



    void remove_front()

    {

        if (is_empty())//���� ������ ������, �� �������?
        {
            return;
        }
        Node* delete_ptr = nullptr; //������� ���������, ������ ����
        if (first_ptr == last_ptr) // ���� ��������� �����(�� ���� ���� ������ � ������), ��
        {
            delete_ptr = first_ptr;//���������� ��.�������� ����.��.�� ������ �������
            first_ptr = last_ptr = nullptr; // ��������� �� ������ � ����.��������.
        }
        else
        {
            first_ptr = first_ptr->next_ptr;//������������ ��������� ������� �������� �� ���������, �� ���� ����.������� ���� ������
        }
        delete delete_ptr; // ������� ���������
    }
    void print()
    {
        Node* print_ptr = first_ptr; //������� ��������� ������ ��������� �� ������ �������

        while (print_ptr != nullptr) //���� ���� ��������� �� ����� ����� ����...
        {
            std::cout << print_ptr->date << " "; // ������� ������ ����� �������
            print_ptr = print_ptr->next_ptr; // ��������� � ����.������� ������, �� ���� ����������� ��������� �������� ��������� �� ��������� ������
        }

    }
    bool find(int value)
    {
        if (is_empty())
        {
            return false;
        }
        Node* find_ptr = first_ptr; //������� ��������� ������ ��������� �� ������ �������
        while (find_ptr != nullptr) //���� ���� ��������� �� ����� ����� ����...
        {
            if (find_ptr->date == value)
            {
                return true;
            }
            find_ptr = find_ptr->next_ptr; // ��������� � ����.������� ������, �� ���� ����������� ��������� �������� ��������� �� ��������� ������
        }
        return false;
    }

};


List::List() //����� ������������
{
    first_ptr = last_ptr = nullptr;//���� ������ (��������� ���������, �� ���������)
}

List::~List()//����� �����������
{
    Node* current_ptr = first_ptr;//�������� ��������� current-�������, ����������� ��� ��������� �� ������ �������
    Node* delete_ptr; // ������� ��������� ��� ��������
    while (current_ptr != nullptr) //���� ������� ��������� �� ����� ����� 0
    {
        delete_ptr = current_ptr; //��������� ��� �������� ������������ � �������� ���������
        current_ptr = current_ptr->next_ptr; //������� ���������� � ��������� �� ����.������, �� ���� ��������� �� ����.��.
        delete delete_ptr;// ��������� ��� �������� �������
    }
}