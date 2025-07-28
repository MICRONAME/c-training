#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <malloc.h>
#include <stdint.h>
#include <stdlib.h>

__uint128_t gcd(__uint128_t a, __uint128_t b) {
    return b == 0 ? a : gcd(b, a % b);
}

__uint128_t powmod(__uint128_t n, __uint128_t p, __uint128_t mod)
{
    __uint128_t mult = n % mod;
    __uint128_t prod = 1;
    while (p > 0)
    {
        if (p % 2 == 1)
        {
            prod = (prod * mult) % mod;
        }
        mult = (mult * mult) % mod;
        p = p >> 1;
    }
    return prod;
}

int main()
{
    unsigned long long n, sc;
    int count = 0;
    sc = scanf("%llu", &n);
    assert(sc == 1);
    for (int i = 0; i < 100; i++)
    {
        __uint128_t x = rand();
        if (powmod(x, n - 1, n) % n == 1 && gcd(x, n) == 1)
        {
            count++;
        }
    }
    if (count >= 10) printf("%c", '1');
    else printf("%c", '0');
}