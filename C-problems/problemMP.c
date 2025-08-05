//
// Created by Lenovo on 04.08.2025.
//
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <malloc.h>
#include <stdint.h>
#include <stdlib.h>

struct poly
{
    unsigned n;
    int *p;
};

void multiply(struct poly *ans, struct poly *m1, struct poly *m2)
{
    for (int i = 0; i < m1->n; i++)
    {
        for (int j = 0; j < m2->n; j++)
        {
            unsigned number = m1->n - i - 1 + m2->n - j - 1;
            ans->p[ans->n - number - 1] += m1->p[i] * m2->p[j];
        }
    }
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    struct poly m1, m2, ans;
    m1.n = n;
    m2.n = k;
    m1.p = malloc(m1.n * sizeof(int));
    m2.p = malloc(m2.n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m1.p[i]);
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &m2.p[i]);
    }
    ans.n = m1.n + m2.n - 1;
    ans.p = calloc(ans.n, sizeof(int));
    multiply(&ans, &m1, &m2);
    int m = ans.n - 1;
    while (ans.p[m] == 0 && m >= 0)
    {
        if (ans.p[m] == 0) ans.p[m] = -1;
        m--;
    }
    for (int i = 0; i < ans.n; i++)
    {
        ans.p[i] != -1 ? printf("%d ", ans.p[i]) : 0;
    }
    free(m1.p);
    free(m2.p);
}