#include "linkedlist.hpp"

int main()
{
    linkedList<int> intLL;
    intLL.print();
    intLL.insert(5);
    intLL.insert(1);
    intLL.insert(5);
    intLL.insert(3);
    intLL.insert(5);
    intLL.insert(7);
    intLL.insert(7);
    intLL.insert(7);
    intLL.insert(7);
    intLL.insert(7);
    intLL.insert(7);
    intLL.insert(7);
    intLL.insert(7);
    intLL.insert(7);
    intLL.insert(5);
    intLL.insert(9);
    intLL.insert(5);
    intLL.print();
    intLL.reverse();
    intLL.print();
    intLL.reverse();
    intLL.removeDuplicates(5);
    intLL.print();
    intLL.remove(10);
    intLL.reverse();
    intLL.print();
    intLL.remove(1);
    intLL.remove(6);
    intLL.print();
    intLL.removeData(5);
    intLL.print();

    linkedList<char> charLL;
    charLL.print();
    charLL.insert('a');
    charLL.insert('z');
    charLL.insert('b');
    charLL.insert('y');
    charLL.insert('a');
    charLL.insert('z');
    charLL.insert('b');
    charLL.insert('y');
    charLL.print();
    charLL.removeDuplicates('a');
    charLL.print();
    charLL.clear();
    charLL.insert('y');
    charLL.insert('y');
    charLL.insert('y');
    charLL.insert('y');
    charLL.insert('y');
    charLL.print();

    return EXIT_SUCCESS;
}