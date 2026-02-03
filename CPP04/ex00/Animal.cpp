#include "Animal.hpp"

Animal::Animal() {
  _type = "Animal";
  std::cout << "Animal created!" << std::endl;
}

Animal::Animal(const Animal& other) {
  *this = other;
  std::cout << "Animal copied!" << std::endl;
}

Animal& Animal::operator=(const Animal& other){
  if (this != &other)
    this->_type = other._type;
  std::cout << "Animal assigned" << std::endl;
  return (*this);
}

Animal::~Animal() {
  std::cout << "Animal destroyed!" << std::endl;
}

std::string Animal::getType() const {
  return (_type);
}

void Animal::makeSound() const {
  std::cout << "Animal sound" << std::endl;
}
