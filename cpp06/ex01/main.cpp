#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.value = 42;

    Data* originalPtr = &data;

    std::cout << "Original pointer: " << originalPtr << std::endl;
    std::cout << "Original value: " << originalPtr->value << std::endl;

    uintptr_t raw = Serializer::serialize(originalPtr);
    std::cout << "Serialized value (uintptr_t): " << raw << std::endl;

    Data* deserializedPtr = Serializer::deserialize(raw);

    std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;
    std::cout << "Deserialized value: " << deserializedPtr->value << std::endl;

    if (originalPtr == deserializedPtr)
        std::cout << "SUCCESS: pointers are identical" << std::endl;
    else
        std::cout << "ERROR: pointers differ" << std::endl;

    return 0;
}
