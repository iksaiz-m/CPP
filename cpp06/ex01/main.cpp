#include "Serializer.hpp"


int main(void)
{
    Data x;
    // x = NULL;
    x.content = "Hola soy Iker";
    x.i = 10;
    uintptr_t serialized;
    Data *nonserialized;

    std::cout << "pointer x: " << &x << std::endl;
    // std::cout << "pointerx.content: " << &x.content << std::endl;
    // std::cout << "pointerx.i: " << &x.i << std::endl;
    serialized = Serializer::serialize(&x);
    std::cout << "uintptr_t: " << serialized << std::endl;
    nonserialized = Serializer::deserialize(serialized);
    std::cout << "deserialized x: "<< nonserialized << std::endl;
    return (0);
}