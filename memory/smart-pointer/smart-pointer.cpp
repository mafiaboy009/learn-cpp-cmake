#include "smart-pointer.hpp"

int main()
{
    cout << "* unique pointer *" << '\n';
    unique_ptr<Rectangle> uniP1 = make_unique<Rectangle>( 10, 5);
    cout << uniP1->area() << '\n'; // This'll print 50
 
    // unique_ptr<Rectangle> P2(P1);
    unique_ptr<Rectangle> uniP2;
    uniP2 = move( uniP1 );
 
    // This'll print 50
    cout << uniP2->area() << '\n';
 	unique_ptr<Rectangle> uniP3 = make_unique<Rectangle>( 10, 5);
	uniP3 = move( uniP2 );
	cout << uniP3->area() << '\n';

    //cout<< uniP1->area() <<endl; should throw an error

    cout << "* shared pointer *" << '\n';

	shared_ptr<Rectangle> shaP1 = make_shared<Rectangle>( 10, 5 );
	// This'll print 50
	cout << shaP1->area() << '\n';

	shared_ptr<Rectangle> shaP2;
	shaP2 = shaP1;

	// This'll print 50
	cout << shaP2->area() << '\n';
	// This'll now not give an error,
	cout << shaP1->area() << '\n';

	// This'll also print 50 now
	// This'll print 2 as Reference Counter is 2
	cout << shaP2.use_count() << '\n';
    cout << shaP1.use_count() << '\n';
    
	return 0;
}
