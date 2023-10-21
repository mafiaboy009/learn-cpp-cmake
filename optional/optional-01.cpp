#include <iostream>
#include <optional>

using namespace std;

optional<bool> returnNull(bool cond)
{
    if(cond)
    {
        return true;
    }
    else
    {
        return nullopt;
    }

}

void print(optional<bool> check )
{
    if( check.has_value() )
    {
        if( check )
        {
            cout << "has_value::True\n";
        }
        else
        {
            cout << "has_value::False\n";
        }
    }
    else
    {
        cout << "Null value\n";
    }
}
    

int main()
{
    optional check = true; // optional<bool>
    check = returnNull(true);
    print(check);
    check = returnNull(false);
    print(check);
    return EXIT_SUCCESS;
}