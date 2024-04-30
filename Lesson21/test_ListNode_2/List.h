#pragma once
#include <cstdint>
#include <iostream>

struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {       
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }
    /*void print()

    {

        ListNode* print_ptr = m_head->next; //создаем указатель равный указателю на первый элемент
        while (print_ptr->next != nullptr) //пока этот указатель не будет равен нулю...

        {

            std::cout << print_ptr->value << " "; // выводим данные этого объекта
            print_ptr = print_ptr->next; // переходим к след.объекту списка, то есть присваиваем указателю значение указателя на следующий объект

        }

        std::cout << std::endl;

    }
    void printLast()

    {
        if (Empty()) throw std::runtime_error("list is empty");
        ListNode* print_ptr = m_tail->prev; //создаем указатель равный указателю на последний элемент

        std::cout << print_ptr->value << " "; // выводим данные этого объекта
     
    }
    void printFirst()

    {
        if (Empty()) throw std::runtime_error("list is empty");
        ListNode* print_ptr = m_head->next; //создаем указатель равный указателю на последний элемент

        std::cout << print_ptr->value << " "; // выводим данные этого объекта

    }
    */

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};