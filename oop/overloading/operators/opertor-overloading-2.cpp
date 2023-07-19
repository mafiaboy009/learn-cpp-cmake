/*
Note: The argument of type int that denotes the postfix form of the increment or decrement operator isn't commonly used to pass arguments.
*/

// increment_and_decrement2.cpp
class Int
{
public:
    Int operator++( int n ); // Postfix increment operator
private:
    int _i;
};

Int Int::operator++( int n )
{
    Int result = *this;
    if( n != 0 )    // Handle case where an argument is passed.
        _i += n;
    else
        _i++;       // Handle case where no argument is passed.
    return result;
}

int main()
{
   Int i;
   i.operator++( 25 ); // Increment by 25.
}