#pragma once

class Counter
{
private:
    int count;
public:

    Counter(int count) {
        this->count = count;
    }
    Counter() {
        count = 1;
    }
    int get_priv_field();

    void plus();
    void minus();

};