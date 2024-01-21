#include "hCounter.h"


    int Counter::get_priv_field() { return count; }

    void Counter::plus() {
        count += 1;
    }
    void Counter::minus() {
        count -= 1;
    }
