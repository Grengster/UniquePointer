// UniquePtr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "uniquePtr.h"
#include "uniquePtr.cpp"

int main()
{
    struct Entity {
        int id = -1;
    };

    UniquePtr<Entity> entityPointer(new Entity);
    UniquePtr<Entity> testPointer(new Entity);
    testPointer->id = 999;
    //std::cout << entityPointer.get();
    //UniquePtr<String> stringPointer(new String("Hello World"));

    std::cout << "testPointer points to " << testPointer->id << '\n';
    std::cout << "entityPointer points to " << entityPointer->id << '\n';
    entityPointer.swap(testPointer);//doesnt work, no idea why cant swap

    
    //stPointer = entityPointer.release();
    std::cout << "testPointer points to " << testPointer->id << '\n';
    std::cout << "entityPointer points to " << entityPointer->id << '\n';
    //std::cout << stringPointer->c_str();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
