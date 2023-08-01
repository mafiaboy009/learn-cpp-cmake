#include "linkedlist.cpp"
#include <iostream>
using namespace std;

template <typename T>
void checkAnagram(linkedList<T>& word1, linkedList<T>& word2)
{
    int ar1[123]{};
    int ar2[123]{};
    bool anagramBool = true;

    node<T> *tmp1 = word1.getHead();
    while (tmp1)
    {
        ++ar1[int(tmp1->getData())%26];
        tmp1 = tmp1->getNextNode();
    }

    tmp1 = word2.getHead();
    while (tmp1)
    {
        ++ar2[int(tmp1->getData())%26];
        tmp1 = tmp1->getNextNode();
    }

    for (int i = 0; i < 26; ++i)
    {
        //cout << "ar1[" << i << "] : " << ar1[i] << endl;
        //cout << "ar2[" << i << "] : " << ar2[i] << endl;
        if (ar1[i] != ar2[i])
        {
            anagramBool = false;
            break;
        }
    }

    if ( anagramBool )
    {
        cout << "linked lists are anagram\n";
    }
    else
    {
        cout << "linked lists are not anagram\n";
    }
}

int main()
{
    //cout << "Ref:: int('a') is " << int('a') << endl;
    //cout << "Ref:: int('z') is " << int('z') << endl;
    {
        linkedList<char> word1;
        word1.insert('e');
        word1.insert('a');
        word1.insert('r');
        word1.insert('t');
        word1.insert('h');
        word1.print();

        linkedList<char> word2;
        word2.insert('h');
        word2.insert('e');
        word2.insert('a');
        word2.insert('r');
        word2.insert('t');
        word2.print();

        checkAnagram(word1, word2);
    }
    cout << "\n\n";
    {
        linkedList<char> word1;
        word1.insert('s');
        word1.insert('h');
        word1.insert('a');
        word1.insert('r');
        word1.insert('e');
        word1.print();

        linkedList<char> word2;
        word2.insert('s');
        word2.insert('h');
        word2.insert('a');
        word2.insert('p');
        word2.insert('e');
        word2.print();

        checkAnagram(word1, word2);
    }

    return EXIT_SUCCESS;
}