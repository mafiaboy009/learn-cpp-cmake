#include <iostream>

#include <random>

/*
 * https://zhang-xiao-mu.blog/2019/11/02/random-engine-in-modern-c/
 */

int main(){

	std::random_device seed{};
	std::mt19937 engine{seed()};
	std::uniform_int_distribution<> dis{1, 10};

    std::default_random_engine defaultRandomEngine;

	int i{0};
	while( i < 6 ){
		int a{ dis(engine) };
		std::cout << "default : " << defaultRandomEngine()%10 << '\n';
		std::cout << "mt19937 : " << a << '\n';
		++i;
	}

    return 0;
}
