//
// Created by Lenovo on 27.07.2025.
//
//
// Created by Lenovo on 16.07.2025.
//
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <malloc.h>

#if 0
long long func(long long n, long long m)
{
    long long f1 = 0, f2 = 1;
    if (n == 0) return 0;
    for (long long i = 1; i < n; i++)
    {
        long long temp = f2;
        f2 = (f2 + f1) % m;
        f1 = temp;
    }
    return f1;
}
#endif

#if 0
// бинарное возведение в степень по модулю. запомнить!!!!!
unsigned long long powmod(unsigned long long n, unsigned long long p, unsigned long long mod)
{
    unsigned long long mult = n % mod;
    unsigned long long prod = 1;
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
#endif


int main()
{
#if 0
    //задача нахождения первого и последнего бита числа
    int n, i = 0;
    int sc = scanf("%d", &n);
    assert(sc == 1);
    while (!(n & (1 << i)))
    {
        i++;
    }
    printf("%d%c", i, ' ');
    i = 0;
    while (!(n & (1 << (31 - i))))
    {
        i++;
    }
    printf("%d%c", 32 - i - 1, ' ');
#endif
#if 0
    // invert k-th bit of sequence
    int n, k, sc, m;
    sc = scanf("%d", &n);
    assert(sc == 1);
    int *v = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        sc = scanf("%d", &m);
        assert(sc == 1);
        v[i] = m;
    }
    sc = scanf("%d", &k);
    assert(sc == 1);
    v[k / 8] = v[k / 8] ^ (1 << (k % 8));
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", v[i], ' ');
    }
#endif

#if 0
    // алгоритм проверки числа на простоту с помощью малой теоремы ферма и бинарного возведения в степень
    unsigned long long n, sc;
    int count = 0;
    sc = scanf("%llu", &n);
    assert(sc == 1);
    for (unsigned long long i = 2; i < 202; i++)
    {
        if (powmod(i, n - 1, n) % n == 1ull && i % n != 0)
        {
            count++;
        }
    }
    if (count >= 100) printf("%c", '1');
    else printf("%c", '0');
#endif

}