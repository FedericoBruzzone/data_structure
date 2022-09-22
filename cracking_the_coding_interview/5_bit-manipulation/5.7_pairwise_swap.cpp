#include "../../ALL_H_FILES.h"
#include "bitutils.cpp"

// =============================================================

int swapOddEvenBits(int x)
{
    int n1 = (x & 0xaaaaaaaa) >> 1; // (01100100 & 10101010) >> 1 = 00010000
    int n2 = (x & 0x55555555) << 1; // (01100100 & 01010101) << 1 = 10001000
    return (n1 | n2);
}

// =============================================================

int main()
{
    // (10_d)1010_b => (5_d)0101_b
    LOG(bits(100))
    LOG(bits(swapOddEvenBits(100)))
}