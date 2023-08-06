// helloworld.cpp
export module helloworld;  // module declaration
import <iostream>;         // import declaration
 
export void hello() {      // export declaration
    std::cout << "Hello world!\n";
}

/*
    To compile: 
    a. ONE Step approach
    g++ -std=c++20 -fmodules-ts helloworld.cpp main.cpp -o hello -xc++-system-header iostream
    ( OR )
    b. TWO Step approach
        i. g++ -std=c++20 -fmodules-ts -xc++-system-header iostream
        ii. g++ -std=c++20 -fmodules-ts helloworld.cpp main.cpp

*/