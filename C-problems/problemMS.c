//
// Created by Lenovo on 04.08.2025.
//
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <malloc.h>
#include <stdint.h>
#include <stdlib.h>

int comp(const void *lhs, const void *rhs){
    return (*(int *)lhs - *(int *)rhs);
}

void merge(int *arr, int l, int m, int r)
{
    qsort(arr + l, r + 1 - l, sizeof(int), comp);
};

void merge_sort_imp(int *arr, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort_imp(arr, l, m);
    merge_sort_imp(arr, m + 1, r);
    merge(arr, l, m, r);
}

void merge_sort(int *arr, int n) {
    merge_sort_imp(arr, 0, n - 1);
}

int main()
{
    int n = 5;
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i;
    }
    merge_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
}