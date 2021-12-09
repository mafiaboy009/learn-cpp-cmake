#include <iostream>

#include <random>

int main(){

	std::random_device seed{};
	std::mt19937 engine{seed()};
	std::uniform_int_distribution<> dis{1, 10};

	int i{0};
	while( i < 6 ){
		int a{ dis(engine) };
		std::cout << a << '\n';
		++i;
	}

    return 0;
}
