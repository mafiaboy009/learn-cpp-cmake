#include <cstdio>

int main()
{
    int x = 0xFFFFFFFF; // 32 bits
    x = x >> 4; // right shift by 4; 2's compliment; Sign Extension
    printf("0x%x\n", x); // 0xFFFFFFFF

    unsigned int y = 0xFFFFFFFF; // 32 bits
    y = y >> 4; // right shift by 4; Zero Extension
    printf("0x%x\n", y); // 0xFFFFFFF

    return 0;
}
