#include "Counter.h"

    Counter::Counter(int count) {
    this->count = count;
}
    Counter::Counter() {
    count = 1;
}
    int Counter::get_priv_field() { return count; }

    void Counter::plus() {
        count += 1;
    }
    void Counter::minus() {
        count -= 1;
    }