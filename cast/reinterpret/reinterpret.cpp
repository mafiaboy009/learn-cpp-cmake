/*
 * re-interpret the bits of the object pointed to
 * the ultimate cast that can cast one pointer to any other type of pointer
 *
 * can introduce bug
 * this casting is used in low level coding
 */


int main(){
    long p = 3345566;
    dog *dd = reinterpret_cast<dog*>( p ); 
}
