#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.value = 42;

    Data* original = &data;

    uintptr_t raw = Serializer::serialize(original);
    Data* restored = Serializer::deserialize(raw);

    std::cout << "Original pointer:  " << original << std::endl;
    std::cout << "Restored pointer:  " << restored << std::endl;
    
    return 0;
}

