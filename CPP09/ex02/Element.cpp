#include "Element.hpp"

int Element::comparisons = 0;

void Element::addItem(int idx) {
    pair_ids.push_back(idx);
}

int Element::getItem() {
    int idx = pair_ids.back();
    pair_ids.pop_back();
    return idx;
}

bool Element::operator<(const Element& other) const {
    comparisons++;
    return this->value < other.value;
}