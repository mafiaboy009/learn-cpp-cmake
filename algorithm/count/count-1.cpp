#include <iostream>
#include <algorithm>
#include <string_view>

using namespace std;

int count_dots(std::string_view str) {
  return std::count(std::begin(str), std::end(str), '.');
}

int main(){
    string dotString{".dkk3k.3.3.e.d.d..s.g.tg.hn...z..w"};
    cout << "Number of dots: " << count_dots(dotString);
    return EXIT_SUCCESS;
}