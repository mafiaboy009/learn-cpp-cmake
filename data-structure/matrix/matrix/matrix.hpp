#pragma once

template <typename T>
class matrix final
{
    unsigned _rows{};
    unsigned _columns{};
    T** _mat{};
    public:
    matrix():_rows{0},_columns{0},_mat{nullptr}{}
    matrix( unsigned m, unsigned n );
};