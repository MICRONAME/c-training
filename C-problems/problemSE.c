//
// Created by Lenovo on 05.08.2025.
//
#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, unsigned lhs, unsigned rhs)
{
    const int temp = arr[lhs];
    arr[lhs] = arr[rhs];
    arr[rhs] = temp;
}

void selection(int *arr, int pos, int size)
{
    int mn = 1e9, ind = -1;
    for (int i = pos; i < size; i++)
    {
        if (mn > arr[i])
        {
            mn = arr[i];
            ind = i;
        }
    }
    swap(arr, ind, pos);
}

int main()
{
    int n, k;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &k);
    selection(arr, k, n);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    free(arr);
}
