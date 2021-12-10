#include <>

using namespace std;

int main(){

    int i = 9;

    // convert object from one type to another
    float f = static_cast<float>( i ); 

    // type conversion needs to be defined
    dog d1 = static_cast<dog>(string("Bob")); 

    // convert pointer/reference from one type to a related type ( down/up cast )
    dog *pd = static_cast<dog*>(new yellowdog()); 

    return 0;
}
