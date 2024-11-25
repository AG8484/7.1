#include "vector.h"
#include <utility>
#include <cstring>

using namespace std;

template<typename T>
void Vector<T>::reallocate(size_t newcapacity) 
{
    T* newArray = new T[newcapacity];
    for (size_t i = 0; i < _size; ++i) 
    {
        newArray[i] = move(arrayofelements[i]);
    }
    delete[] arrayofelements;
    arrayofelements = newArray;
    _capacity = newcapacity;
}

template<typename T>
Vector<T>::Vector() : arrayofelements(nullptr), _size(0), _capacity(0)
{

}

template<typename T>
Vector<T>::Vector(size_t count) : arrayofelements(new T[count]{}), _size(count), _capacity(count)
{

}

template<typename T>
Vector<T>::Vector(size_t count, const T& value) : arrayofelements(new T[count]), _size(count), _capacity(count) 
{
    for (size_t i = 0; i < count; ++i) 
    {
        arrayofelements[i] = value;
    }
}

template<typename T>
Vector<T>::Vector(const Vector& other) : arrayofelements(new T[other._capacity]), _size(other._size), _capacity(other._capacity) 
{
    for (size_t i = 0; i < _size; ++i) 
    {
        arrayofelements[i] = other.arrayofelements[i];
    }
}

template<typename T>
Vector<T>::Vector(Vector&& other) noexcept : arrayofelements(other.arrayofelements), _size(other._size), _capacity(other._capacity) 
{
    other.arrayofelements = nullptr;
    other._size = 0;
    other._capacity = 0;
}

template<typename T>
Vector<T>::~Vector() 
{
    delete[] arrayofelements;
}

template<typename T>
T& Vector<T>::operator[](size_t pos) 
{
    return arrayofelements[pos];
}

template<typename T>
T& Vector<T>::at(size_t pos) 
{
    if (pos >= _size)
    {
        throw out_of_range("index out of bound");
    }
    return arrayofelements[pos];
}

template<typename T>
T& Vector<T>::front() 
{
    if (empty())
    {
        throw out_of_range("empty vector");
    } 
    return arrayofelements[0];
}

template<typename T>
T& Vector<T>::back() 
{
    if (empty())
    {
        throw out_of_range("empty vector");
    }
    return arrayofelements[_size - 1];
}

template<typename T>
bool Vector<T>::empty() const noexcept 
{
    return _size == 0;
}

template<typename T>
size_t Vector<T>::size() const noexcept 
{
    return _size;
}

template<typename T>
size_t Vector<T>::capacity() const noexcept 
{
    return _capacity;
}

template<typename T>
void Vector<T>::reserve(size_t new_cap) 
{
    if (new_cap > _capacity) 
    {
        reallocate(new_cap);
    }
}

template<typename T>
void Vector<T>::resize(size_t count) 
{
    if (count < _size) 
    {
        _size = count;
    } 
    else if (count > _capacity) 
    {
        reserve(count);
        for (size_t i = _size; i < count; ++i) 
        {
            arrayofelements[i] = T{};
        }
        _size = count;
    }
}

template<typename T>
void Vector<T>::pushback(const T& value) 
{
    if (_size == _capacity)
    {
        reserve((_capacity == 0) ? 1 : 2 * _capacity);
    } 
    arrayofelements[_size++] = value;
}

template<typename T>
void Vector<T>::pushback(T&& value) 
{
    if (_size == _capacity)
    {
        reserve((_capacity == 0) ? 1 : 2 * _capacity);
    } 
    arrayofelements[_size++] = move(value);
}

template<typename T>
void Vector<T>::popback() 
{
    if (empty())
    {
        throw out_of_range("empty vector");
    } 
    --_size;
}

template<typename T>
void Vector<T>::clear() noexcept 
{
    _size = 0;
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) 
{
    if (this != &other) 
    {
        T* newArray = new T[other._capacity];
        for (size_t i = 0; i < other._size; ++i) 
        {
            newArray[i] = other.arrayofelements[i];
        }
        delete[] arrayofelements;
        arrayofelements = newArray;
        _size = other._size;
        _capacity = other._capacity;
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector&& other) noexcept 
{
    if (this != &other) 
    {
        delete[] arrayofelements;
        arrayofelements = other.arrayofelements;
        _size = other._size;
        _capacity = other._capacity;
        other.arrayofelements = nullptr;
        other._size = 0;
        other._capacity = 0;
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator+=(const T& value) 
{
    pushback(value);
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator+=(const Vector& other) 
{
    if (other.empty()) 
    {
        throw concatenate_error("can't concatenate with empty vector");
    }
    for (size_t i = 0; i < other._size; ++i) 
    {
        pushback(other.arrayofelements[i]);
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator--() 
{
    if (empty())
    {
        throw out_of_range("empty vector");
    } 
    for (size_t i = 1; i < _size; ++i) 
    {
        arrayofelements[i - 1] = move(arrayofelements[i]);
    }
    --_size;
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator++() 
{
    reserve(_size + 1);
    for (size_t i = _size; i > 0; --i) 
    {
        arrayofelements[i] = move(arrayofelements[i - 1]);
    }
    arrayofelements[0] = 1;
    ++_size;
    return *this;
}

template<typename T>
Vector<T> Vector<T>::operator--(int) {
    Vector tmp = *this;
    popback();
    return tmp;
}

template<typename T>
Vector<T> Vector<T>::operator++(int) 
{
    Vector tmp = *this;
    pushback(1);
    return tmp;
}
