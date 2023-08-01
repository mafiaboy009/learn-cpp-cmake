#include <iostream>
using namespace std;

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
    cA.print();
}

customArray createCustomArray(int num)
{
    cout << num << " :fn: create custom array\n";
    double data[] = {1.2,2.3,3.4,4.5,5.6};
    customArray anArray(data,5);
    return anArray;
}

int main()
{
    int num = 7;

    cout << "step 0\n";
    customArray a;
    a.print();

    cout << "step 1\n";
    customArray anArray(createCustomArray(num));
    anArray.print();

    cout << "step 2\n";
    customArray aanArray(move(anArray));

    cout << "step 3\n";
    num = 8;
    foo(createCustomArray(num));

    return EXIT_SUCCESS;
}