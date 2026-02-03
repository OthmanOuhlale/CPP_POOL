#include "Brain.hpp"

Brain::Brain() {
  int i = 0;
  while (i < 100)
  {
    ideas[i] = "";
    i++;
  }
  std::cout << "Brain created!" << std::endl;
}

Brain::Brain(const Brain& other) {
  for (int i = 0; i< 10; i++)
    ideas[i] = other.ideas[i];
  std::cout << "Brain copied!" << std::endl;
}

Brain& Brain::operator=(const Brain& other){
  if (this != &other)
  {
    int i = 0;
    while (i < 100)
    {
        ideas[i] = other.ideas[i];
        i++;
    }
  }
  std::cout << "Brain assigned" << std::endl;
  return (*this);
}

Brain::~Brain() {
  std::cout << "Brain destroyed!" << std::endl;
}
