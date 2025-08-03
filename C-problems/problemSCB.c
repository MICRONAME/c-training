#include <stdio.h>
#include <stdlib.h>

typedef int (*cmp_t)(const void *lhs, const void *rhs);

int func_int(const void *lhs, const void *rhs)
{
    int *l = lhs;
    int *r = rhs;
    return l - r;
}

void *cbsearch(const void *key, const void *base, int num, int size, cmp_t cmp) {
    // TODO: ваш код здесь
    void *left = base;
    void *right = left + num * size;
    while (right - left > size)
    {
        void *mid = left + (((right - left) / (2 * size)) * size);
        if (cmp(key, mid) > 0)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    return right;
}

int main() {
    // your code goes here
    int *arr = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) arr[i] = i;
    int k = 1;
    printf("%p", cbsearch(&k, arr, 6, sizeof(int), func_int));
    free(arr);
}