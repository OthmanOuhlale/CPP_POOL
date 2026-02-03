#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
  _type = "WrongAnimal";
  std::cout << "Animal created!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
  *this = other;
  std::cout << "Animal copied!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
  if (this != &other)
    this->_type = other._type;
  std::cout << "Animal assigned" << std::endl;
  return (*this);
}

WrongAnimal::~WrongAnimal() {
  std::cout << "Animal destroyed!" << std::endl;
}

std::string WrongAnimal::getType() const {
  return (_type);
}

void WrongAnimal::makeSound() const {
  std::cout << "Animal sound" << std::endl;
}
