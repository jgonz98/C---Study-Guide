#include <cstdlib>
#include <stdexcept>

template <typename T>
class Array
{
public:
    Array(int siz = 0); // Constructor
    ~Array();           // Deconstructor
    T &operator[](int i)
    {
        if (i >= s || i < 0)
        {
            throw std::invalid_argument("Index of array is out of bounds!");
        }
        return *(a + i);
    }
    int size();

private:
    T *a;
    int s;
};

template <typename T>
Array<T>::Array(int siz) // Constructor
{
    a = (T *)malloc(sizeof(T) * siz);
    s = siz;
}

template <typename T>
Array<T>::~Array() // Destructor
{
    delete (a);
}

template <typename T>
int Array<T>::size()
{
    return s;
}