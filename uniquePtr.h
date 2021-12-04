#pragma once

#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H
#include <memory>
//Literature: https://www.informit.com/articles/article.aspx?p=25264

template <class T>
class UniquePtr  
{
public:
	using class_type = T;
	using pointer = T*;
	pointer ptr;  //pointer to any data type we want

	UniquePtr();
	explicit UniquePtr(T* obj);
	~UniquePtr();

	pointer get();

	class_type& operator *() const;
	pointer operator->() const;
	explicit operator bool() const;

	static void swap(T* other);
	pointer release();
	static void reset();
};



#endif



//class RefCount {
//public:
//    void AddRef() {
//        ++(this->_count);
//    }
//    int Release() {
//        return --(this->_count);
//    }
//private:
//    int _count;
//};

//public:
//    int element_type;
//    UniquePtr();
//    UniquePtr(T* iObject);
//
//    // copy constructor
//    UniquePtr(const UniquePtr<T>& iSPtr);
//
//    // destructor
//    ~UniquePtr();
//
//    // operators
//    UniquePtr<T>& operator=(const UniquePtr<T>& iSPtr);
//    T& operator*();
//    T* operator->();
//
//private:
//    T* _ptr;
//    RefCount* _refCount;
//
//    void _release();
//    void _copyUniquePtr(const UniquePtr<T>& iSPtr);