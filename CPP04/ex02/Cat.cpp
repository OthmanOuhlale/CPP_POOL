#include "Cat.hpp"

Cat::Cat() {
  _type = "Cat";
  brain = new Brain();
  std::cout << "Cat created!" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
  brain = new Brain(*other.brain);
  std::cout << "Cat copied!" << std::endl;
}

Cat& Cat::operator=(const Cat& other){
  if (this != &other)
  {
    Animal::operator=(other);
    *brain = *other.brain;
  }
  std::cout << "Cat assigned" << std::endl;
  return (*this);
}

Cat::~Cat() {
  delete brain;
  std::cout << "Cat destroyed!" << std::endl;
}

void Cat::makeSound() const {
  std::cout << "Meow Meow Meow..." << std::endl;
}
