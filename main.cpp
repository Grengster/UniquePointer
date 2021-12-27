// UniquePtr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "uniquePtr.h"
#include <cassert>

template <class T>
void test_cases_1(UniquePtr<T> test);
template <class T>
void test_cases_2(UniquePtr<T> entity, UniquePtr<T> test);
template <class T>
void test_cases_3(UniquePtr<T> test);

int main()
{
    struct Entity {
        int id = -1;
    };

    UniquePtr<Entity> entityPointer(new Entity);
    UniquePtr<Entity> testPointer(new Entity);
    const UniquePtr<std::string> test(new std::string("Hello World"));

    testPointer->id = 999;
    //std::cout << "HERE" << entityPointer.getNumber() << "HERE";
    //UniquePtr<String> stringPointer(new String("Hello World"));
    test_cases_1(entityPointer);
    

    std::cout << "testPointer points to " << testPointer->id << '\n';
    std::cout << "entityPointer points to " << entityPointer->id << '\n';


	entityPointer.swap(testPointer);//doesnt work, no idea why cant swap
    test_cases_2(entityPointer, testPointer);


    std::cout << (*test).c_str() << std::endl;
    std::cout << test->c_str() << std::endl;



    const Entity* temp_entity = entityPointer.release();

    
    std::cout << "entityPointer points to " << temp_entity->id << '\n';
}

template <class T>
void test_cases_1(UniquePtr<T> test)
{
    assert(test->id == -1);

}
template <class T>
void test_cases_2(UniquePtr<T> entity, UniquePtr<T> test)
{
    assert(entity->id == 999);
    assert(test->id == -1);
}
template <class T>
void test_cases_3(UniquePtr<T> test)
{
    assert(test.ptr == nullptr);
}