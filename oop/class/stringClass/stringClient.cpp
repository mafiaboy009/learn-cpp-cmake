#include "stringClass.hpp"

using namespace std;

int main(){
    {
        cout << "\ns1\n";
        stringClass s1((char *)"The Boy");
        s1.print();

        cout << "\ns2\n";
        stringClass s2(s1);
        s2[0] = 'P';
        s1.print();
        s2.print();

        cout << "\ns3\n";
        char *str1 = s1;
        cout << str1 << '\n';
        s1.print();

        cout << "\ns4\n";
        s2 = s1;
        s1.print();
        s2.print();

        cout << "\ns5\n";
        stringClass s3 = s1;
        s3.print();

        cout << "\ns6\n";
        stringClass s4;
        s4.print();

        cout << "\ns7\n";
        stringClass s5 = s4 = s1;
        s1.print();
        s4.print();
        s5.print();
        cout << s4[3] << '\n';

        cout << "\ns8\n";
        s1[2]='P';
        s1.print();
        stringClass s6(move(s1));
        s6.print();
        s1.print();
    }
    return EXIT_SUCCESS;
}
