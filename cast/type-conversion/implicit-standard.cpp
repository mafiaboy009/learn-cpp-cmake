/*
 *  Category A: Implicit Standard Type Conversion
 *
 */

void f(int i){
    ++i;
}

int main(){
    char c = 'A';
    int i = c; // Integral promotion
    char *pc = 0; // int -> nullptr
    pc = &c;
    f(i);
    f(c);// char c is implicitly converted to int
    f(*pc);
 //   dog *pd = new yellowdog(); // pointer type conversion; note this is not user defined type conversion

    return 0;
}
