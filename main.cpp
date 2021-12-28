// UniquePtr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "uniquePtr.h"
#include <cassert>


struct Entity {
    int id = -1;
};

template <class T>
void assert_string_test(UniquePtr<T> test);
template <class T>
void assert_test_value(UniquePtr<T> test);
template <class T>
void assert_swap_test(UniquePtr<T> entity, UniquePtr<T> test);
template <class T>
void assert_reset_test(UniquePtr<T>* entity);
void assert_check_entity_value(const Entity* entity);
template <class T>
void assert_release_test(Entity* entity, UniquePtr<T>* test);



int main()
{
    

    UniquePtr<Entity> entityPointer(new Entity);
    UniquePtr<Entity> testPointer(new Entity);
    const UniquePtr<std::string> test(new std::string("Hello World"));

    assert_string_test(test);

    testPointer->id = 999;
    assert_test_value(entityPointer);
    

    std::cout << "testPointer points to " << testPointer->id << '\n';
    std::cout << "entityPointer points to " << entityPointer->id << '\n';


    entityPointer.swap(testPointer);
    assert_swap_test(entityPointer, testPointer);



    std::cout << (*test).c_str() << std::endl;
    std::cout << test->c_str() << std::endl;

    testPointer.reset();
    assert_reset_test(&testPointer);
    
    Entity* entity_ptr = new Entity();
    entity_ptr->id = 10;
    assert_check_entity_value(entity_ptr);
    entity_ptr = entityPointer.release();
    assert_release_test(entity_ptr, &entityPointer);
}


template <class T>
void assert_string_test(UniquePtr<T> test)
{

    assert(strcmp(test->c_str(), "Hello World") == 0);

}

template <class T>
void assert_test_value(UniquePtr<T> test)
{
    assert(test->id == -1);

}
template <class T>
void assert_swap_test(UniquePtr<T> entity, UniquePtr<T> test)
{
    assert(entity->id == 999);
    assert(test->id == -1);
}

template <class T>
void assert_reset_test(UniquePtr<T>* entity)
{
    assert(entity->ptr == nullptr);
}

void assert_check_entity_value(const Entity* entity)
{
    assert(entity->id == 10);
}

template <class T>
void assert_release_test(Entity* entity, UniquePtr<T>* test)
{
    assert(entity->id == 999);
    assert(test->ptr == nullptr);
}
