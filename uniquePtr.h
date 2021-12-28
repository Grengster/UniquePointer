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

	UniquePtr() : ptr(nullptr){}
	explicit UniquePtr(T* obj) : ptr(obj){}
	~UniquePtr()
	{
		this->release();
	}
	UniquePtr(const UniquePtr& other) : UniquePtr(other.ptr){}		//copy constructor
		
	UniquePtr(UniquePtr&& other) noexcept : ptr(std::exchange(other.ptr, nullptr))	//move constructor
	{}

	UniquePtr& operator=(const T& number)							// copy assignment
	{
		return *this = UniquePtr(number);
	}
	
	UniquePtr& operator=(UniquePtr<T>&& other) noexcept				// move assignment
	{
		std::swap(ptr, other.ptr);
		return *this;
	}

	pointer get() const
	{
		return *(this->ptr);
	}

	class_type& operator *() const
	{
		return *(this->ptr);
	}

	pointer operator->() const
	{
		return this->ptr;
	}

	explicit operator bool() const
	{
		return this == nullptr;
	}

	int getNumber() const
	{
		return reinterpret_cast<int>(*this->ptr);
	}

	void swap(UniquePtr<T>& other) noexcept
	{
		std::swap(*this, other);
	}
	pointer release()
	{
		T* temp_ptr = this->ptr; //set current pointer to null and pass it to new object
		this->ptr = nullptr;
		return temp_ptr;
	}

	void reset()
	{
		delete this->ptr;
		this->ptr = nullptr;
	}
};



#endif