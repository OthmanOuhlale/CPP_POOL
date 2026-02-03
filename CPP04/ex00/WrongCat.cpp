#include "WrongCat.hpp"

WrongCat::WrongCat() {
  _type = "WrongCat";
  std::cout << "Cat created!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
  std::cout << "Cat copied!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other){
  if (this != &other)
    WrongAnimal::operator=(other);
  std::cout << "Cat assigned" << std::endl;
  return (*this);
}

WrongCat::~WrongCat() {
  std::cout << "Cat destroyed!" << std::endl;
}

void WrongCat::makeSound() const {
  std::cout << "Meow Meow Meow..." << std::endl;
}
