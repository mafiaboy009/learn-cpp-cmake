#include <iostream>
using namespace std;

/* 
    std::move() vs std::forward()
std::move<T>(arg); // turn arg into an rvalue type
std::forward<T>(arg); // turn arg to type of T&&
*/

class customArray{
    double* _arr{};
    unsigned _size{};
    public:

    customArray():_arr{nullptr},_size{0}{ cout << "default ctor \n"; }
    //customArray() = delete;

    customArray(double* inData, unsigned inSize):_size{inSize}
    {
        cout << "non-default ctor \n";
        _arr = new double[_size];
        for(unsigned i = 0; i<_size;++i)
        {
            _arr[i] = inData[i];
        }
    }

    /* this copy constructor is costly */
    customArray(const customArray& cpData)
    {
        cout << "copy ctor \n";
        _size = cpData._size;
        _arr = new double[_size];
        for(unsigned i = 0; i < _size; ++i)
        {
            _arr[i] = cpData._arr[i];
        }
    }

    /* inexpensive shallow copying */
    customArray(customArray&& cpData)
    {
        cout << "move ctor \n";
        _size = cpData._size;
        _arr = cpData._arr;
        cpData._size = 0;
        cpData._arr = nullptr;
    }

    void setCustomArray(double* inData, unsigned inSize)
    {
        _size = inSize;
        _arr = new double[_size];
        for(unsigned i = 0; i<_size;++i)
        {
            _arr[i] = inData[i];
        }
    }

    void print()
    {
        for(unsigned i = 0; i < _size; ++i)
        {
            cout<< _arr[i] << " ";
        }
        cout << "\n";
    }

    customArray operator=(const customArray& cpData)
    {
        cout << "assignment operator \n";
        _size = cpData._size;
        _arr = new double[_size];
        for(unsigned i = 0; i < _size; ++i)
        {
            _arr[i] = cpData._arr[i];
        }
        return *this;
    }

    ~customArray()
    {
        cout << "dtor\n";
        delete _arr;
    }
};

void foo(customArray cA) // expensive copy constructor is called
{
    cout << ":fn: foo\n";
    cA.print();
}

customArray createCustomArray(int num)
{
    cout << num << ":fn: create custom array\n";
    double data[] = {1.2,2.3,3.4,4.5,5.6};
    customArray anArray(data,5);
    return anArray;
}

template <typename T>
void replay(T&& arg)
{
    cout << ":fn: replay\n";
    foo( forward<T>(arg) );
    // Perfect forwarding means
    // If arg is an lvalue then call copy constructor
    // If arg is an rvalue then call move constructor
}

int main()
{
    int num = 7;
    cout << "step 1\n";
    customArray anArray(createCustomArray(num));
    cout << "step 1a\n";
    replay(anArray);

    cout << "step 2\n";
    num = 8;
    replay(createCustomArray(num));

    return EXIT_SUCCESS;
}