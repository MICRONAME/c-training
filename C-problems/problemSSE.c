//
// Created by Lenovo on 05.08.2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef int (*cmp_t)(void const * lhs, void const * rhs);

int comp(const void *lhs, const void *rhs){
    char *l = lhs, *r = rhs;
    if (*l < *r) return 1;
    return 0;
}

void pr(const int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (arr[i] & (1 << j)) printf("%d", 1);
            else printf("%d", 0);
        }
        printf("\n");
    }
}

void swap(void *v, int i, int j, int size)
{
    char *temp = v;
    for (int bit = 0; bit < 8 * size; bit++) {
        if ((*(temp + i * size) & (1 << bit)) != (*(temp + j * size) & (1 << bit))) {
            *(temp + i * size) ^= (1 << bit);
            *(temp + j * size) ^= (1 << bit);
        }
    }
}

int selstep(void * parr, int eltsize, int numelts, int nsorted, cmp_t cmp) {
    // TODO: реализуйте эту функцию
    void *mn = parr + nsorted * eltsize; int c = nsorted;
    for (void *i = parr + nsorted * eltsize; i < parr + eltsize * numelts; i += eltsize){
        if (cmp(i, mn))
        {
            mn = i;
            c = (i - parr) / eltsize;
        }
    }
    swap(parr, nsorted, c, eltsize);
    return 0;
}

int main()
{
    int n, k;
    scanf("%d", &n);
    char *arr = malloc(n * sizeof(char));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &k);
    pr(arr, n);
    selstep(arr, sizeof(char), n, k, comp);
    printf("\n");
    pr(arr, n);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    free(arr);
}