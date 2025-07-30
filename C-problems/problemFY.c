//
// Created by Lenovo on 30.07.2025.
//
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <malloc.h>
#include <stdint.h>
#include <stdlib.h>

int myrand() {
    static unsigned long int seed = 1;
    seed = seed * 1103515245 + 12345;
    return (unsigned int)(seed / 65536) % 32768;
}

int main()
{
    int n, sc, val;
    sc = scanf("%d", &n);
    assert(sc == 1);
    if (n == 0)
    {
        printf("%d", 0);
        return 0;
    }
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        sc = scanf("%d", &val);
        assert(sc == 1);
        arr[i] = val;
    }
    for (int i = n - 1; i > 0; i--)
    {
        int x = myrand(), temp = arr[i];
        arr[i] = arr[x % (i + 1)];
        arr[x % (i + 1)] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
}