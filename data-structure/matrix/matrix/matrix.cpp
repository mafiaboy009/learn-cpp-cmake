#include "matrix.hpp"

template <typename T>
matrix<T>::matrix( unsigned m, unsigned n )
{
    if( m==0 || n==0 )
    {
        _rows = 0;
        _columns = 0;
        _mat = nullptr;
    }
    else
    {
        _rows = m;
        _columns = n;
        _mat = new T*[m];
        for(unsigned i=0; i < m; ++i )
        {
            _mat[i] = new T[n];
        }
    }
}