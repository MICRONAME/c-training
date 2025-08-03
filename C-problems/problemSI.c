//
// Created by Lenovo on 30.07.2025.
//
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <malloc.h>
#include <stdint.h>
#include <stdlib.h>

int moveright(int *arr, int key, int last) {
    for (int i = last; i > 0; i--)
    {
        if (arr[i - 1] < key)
        {
            return i;
        }
        else
        {
            arr[i] = arr[i - 1];
            arr[i - 1] = key;
        }
    }
    return 0;
}

void inssort(int *arr, int len) {
    int i;
    for (i = 0; i < len; ++i) {
        int key, pos;
        key = arr[i];
        pos = moveright(arr, key, i);
        arr[pos] = key;
    }
}

int main()
{
    int n, sc;
    sc = scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        sc = scanf("%d", &arr[i]);
    }
    inssort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    free(arr);
}