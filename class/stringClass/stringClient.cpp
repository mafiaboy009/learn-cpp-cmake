#include "stringClass.hpp"

using namespace std;

/*
class MystringClass{
    friend ostream& operator<<(ostream& os, const MystringClass& str);

    friend istream& operator>>(istream& is, MystringClass& str);

    friend MystringClass opertor+(const MystringClass& lhs, const MystringClass& rhs);

    char *str;

    public:
    MystringClass();
    MystringClass(char *strPtr);
    MystringClass(const MystringClass& source);
    MystringClass(MystringClass&& source);
    MystringClass& operator=(const MystringClass& rhs);
    void pop_back();
    void push_back();
    int getLength();
    void copy(char s[], int length, int pos);
    void swap(MystringClass& rhs);
    ~MystringClass(){ delete [] str; }
}

class stringClass{
    private:

    protected:

    public:
        char *array;

        stringClass(char* chArr){
            if( chArr == nullptr){
                array = new char[1];
                array[0] = '\0';
            }
            else{
                int length = strlen( chArr );
                array = new char[length+1];
                for(int i = 0; i < length; i++ ){
                    array[i] = chArr[i];
                }
                array[length] = '\0';
            }
        }

        stringClass(){
            array = new char[1];
            array[0] = '\0';
        }

        stringClass(const stringClass& str){
            int length = strlen( str.array )+1;
            array = new char[length];
            for(int i = 0; i < length; i++ ){
                array[i] = str[i];
            }
        }

        stringClass(stringClass&& str){
            array = str.array;
            str.array = nullptr;
        }

        void print(){
            cout << array << '\n';
        }

        stringClass& operator=(stringClass&& rhs){
            delete[] array;
            array=rhs.array;
            rhs.array = nullptr;
            return *this;
        }

        stringClass& operator=(const stringClass& rhs){
            if( this == &rhs){
                return *this;
            }
            stringClass str(rhs);
            *this = move(str);
            return *this;
        }

        char operator[](int i) const {
            return array[i];
        }

        char& operator[](int i){
            return array[i];
        }

        operator char*() { return array;}

        ~stringClass(){
            delete[] array;
        }

};
*/

int main(){
    {
        cout << "\ns1\n";
        stringClass s1((char *)"Ajay");
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
