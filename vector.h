#include <stdexcept>
#include <initializer_list>
#include <iostream>

using namespace std;

template<typename T>
class Vector 
{
private:

    T* arrayofelements;
    size_t _size;
    size_t _capacity;

    void reallocate(size_t newCapacity);

public:

    Vector(); 
    explicit Vector(size_t count);
    Vector(size_t count, const T& value);
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;

    ~Vector();

    T& operator[](size_t pos);
    T& at(size_t pos);
    T& front();
    T& back();

    bool empty() const noexcept;
    size_t size() const noexcept;
    size_t capacity() const noexcept;
    void reserve(size_t new_cap);
    void resize(size_t count);

    void pushback(const T& value);
    void pushback(T&& value);
    void popback();
    void clear() noexcept;

    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other) noexcept;

    Vector& operator+=(const T& value);
    Vector& operator+=(const Vector& other);
    Vector& operator--();
    Vector& operator++();
    Vector operator--(int);
    Vector operator++(int);

    class concatenate_error : public invalid_argument 
    {
    public:
        explicit concatenate_error(const string& msg) : invalid_argument(msg) 
        {

        }
    };
};
