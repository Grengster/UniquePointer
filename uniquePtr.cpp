#include "uniquePtr.h"


template <class T>
UniquePtr<T>::UniquePtr() : ptr(nullptr) 
{
}

template <class T>
UniquePtr<T>::UniquePtr(T* obj) : ptr(obj) //copy variable obj to ptr
{
}

template <class T>
UniquePtr<T>::~UniquePtr() {
    this->release();
}

template <class T>
typename UniquePtr<T>::pointer UniquePtr<T>::get() const
{
    return *(this->ptr);
}

template <class T>
typename UniquePtr<T>::class_type& UniquePtr<T>::operator*() const
{
    return *(this->ptr);
}

template <class T>
typename UniquePtr<T>::pointer UniquePtr<T>::operator->() const
{
    return this->ptr;
}

template <class T>
UniquePtr<T>::operator bool() const
{
    return this == nullptr;
}




template <class T>
void UniquePtr<T>::reset()
{
    this->ptr = nullptr; //set current ptr to null Memory testing!!!!
}

template <class T>
UniquePtr<T>& UniquePtr<T>::operator=(const T& number)
{
    ptr = number.ptr; //not sure if right
    return *this;
}

template <class T>
void UniquePtr<T>::swap(UniquePtr<T>& other) noexcept
{
    UniquePtr temp = *this; 
    *this = other;
    other = temp;
}

template <class T>
typename UniquePtr<T>::pointer UniquePtr<T>::release()
{
    T* tempPtr = this->ptr; //set current pointer to null and pass it to new object
	this->ptr = nullptr;
    return tempPtr;
}


template <class T>
int UniquePtr<T>::getNumber() const
{
    return reinterpret_cast<int>(*this->ptr);
}


// constructor
//template <class T>
//UniquePtr<T>::UniquePtr() :
//    _refCount(nullptr),
//    _ptr(nullptr)
//{
//}
//
//template <class T>
//UniquePtr<T>::UniquePtr(T* iObject) :
//    _refCount(new RefCount()),
//    _ptr(iObject)
//{
//    this->_refCount->AddRef();
//}
//
//// copy constructor
//template <class T>
//UniquePtr<T>::UniquePtr(const UniquePtr<T>& iSPtr)
//{
//    this->_copyUniquePtr(iSPtr);
//}
//
//// destructor
//template <class T>
//UniquePtr<T>::~UniquePtr() {
//    this->_release();
//}
//
//// operators
//template <class T>
//UniquePtr<T>& UniquePtr<T>::operator=(const UniquePtr<T>& iSPtr) {
//    if (iSPtr._ptr && (this != &iSPtr)) {
//        this->_release();
//        this->_copyUniquePtr(iSPtr);
//    }
//    return *this;
//}
//
//template <class T>
//T& UniquePtr<T>::operator*() {
//    return *(this->_ptr);
//}
//
//template <class T>
//T* UniquePtr<T>::operator->() {
//    return this->_ptr;
//}
//
//template <class T>
//void UniquePtr<T>::_release() {
//    if (this->_refCount && this->_refCount->Release() == 0) {
//        delete this->_ptr;
//        delete this->_refCount;
//    }
//}
//
//template <class T>
//void UniquePtr<T>::_copyUniquePtr(const UniquePtr<T>& iSPtr) {
//    this->_ptr = iSPtr._ptr;
//    this->_refCount = iSPtr._refCount;
//    this->_refCount->AddRef();
//}