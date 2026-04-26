#include "Element.hpp"

bool Element::operator<(const Element& other) const {
    return this->value < other.value;
}