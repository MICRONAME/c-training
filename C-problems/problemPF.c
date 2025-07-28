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

int check(__uint128_t n)
{
    int count = 0;
    for (int i = 0; i < 300; i++)
    {
        __uint128_t x = rand();
        if (powmod(x, n - 1, n) % n == 1 && gcd(x, n) == 1)
        {
            count++;
        }
    }
    if (count >= 100) return count;
    return 0;
}

unsigned long long solve(__uint128_t a, __uint128_t b)
{
    __uint128_t f1 = 0, f2 = 1;
    __uint128_t ans = 0;
    while (f2 * a + f1 * b <= UINT64_MAX / (2 * 2 * 2 * 2))
    {
        __uint128_t temp = f2 * a + f1 * b;
        int x = check(temp);
        if (x)
        {
            ans = temp;
            //printf("%llu%s", temp, "\n");
        }
        f1 = f2;
        f2 = temp;
    }
    return ans;
}

int main()
{
    unsigned long long a, b, sc;
    sc = scanf("%llu%llu", &a, &b);
    assert(sc == 2);
    assert(0ull < a && a < 256ull);
    assert(0ull < b && b < 256ull);
    printf("%llu", solve(a, b));
    //printf("%d", check(1000000007));
}