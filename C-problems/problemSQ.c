//
// Created by Lenovo on 03.08.2025.
//
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <malloc.h>
#include <stdint.h>
#include <stdlib.h>

void swap(int *arr, unsigned lhs, unsigned rhs)
{
    const int temp = arr[lhs];
    arr[lhs] = arr[rhs];
    arr[rhs] = temp;
}
///НУИГОВНИЩЕ
unsigned partition(int *arr, unsigned low, unsigned high) {
    // TODO: ваш код здесь
    unsigned l = low + 1, r = high;
    while (r > l)
    {
        while (arr[l] <= arr[low] && l < r) l++;
        while (arr[r] > arr[low] && r > l) r--;
        if (arr[l] <= arr[low])
        {
            swap(arr, l, low);
            return l;
        }
        swap(arr, l, r);
    }
#if 0
    if (arr[low] >= arr[l])
    {
        swap(arr, low, l);
        printf("%d ", l);
        return l;
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
#endif
    if (arr[low] >= arr[l - 1]) swap(arr, l - 1, low);
    //printf("%d ", l - 1);
    return l - 1;
}

void qsort_impl(int *arr, unsigned low, unsigned high) {
    if (low >= high) return;
    unsigned pi = partition(arr, low, high);
    if (pi > low) qsort_impl(arr, low, pi - 1);
    qsort_impl(arr, pi + 1, high);
}

void Qsort(int *arr, unsigned len) {
    qsort_impl(arr, 0u, len - 1);
}

int main()
{
    int *arr = malloc((3) * sizeof(int));
    arr[0] = 2; arr[1] = 0, arr[2] = 8; arr[3] = 4; arr[4] = 3;
    Qsort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d", arr[i]);
    }
    free(arr);
}