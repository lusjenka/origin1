#pragma once

class Counter
{
private:
    int count;
public:

    Counter(int count);
    Counter();
    
    int get_priv_field();

    void plus();
    void minus();

};