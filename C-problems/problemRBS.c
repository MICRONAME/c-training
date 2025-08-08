//
// Created by Lenovo on 07.08.2025.
//
#include <stdio.h>
#include <stdlib.h>

struct node_t
{
    struct node_t *next;
    int data;
};

void delete_node(struct node_t *top)
{
    while (top != NULL) top = top->next;
}

void add(struct node_t **list, int idx, int value)
{
    struct node_t *new = calloc(1, sizeof(struct node_t));
    new->data = value;
    if (list[idx] == NULL)
    {
        list[idx] = new;
        return;
    }
    if (value <= list[idx]->data)
    {
        new->next = list[idx];
        list[idx] = new;
        return;
    }
    struct node_t *i = list[idx];
    for (; i->next != NULL; i = i->next)
    {
        if (value <= i->next->data)
        {
            new->next = i->next;
            i->next = new;
            return;
        }
    }
    i->next = new;
}

struct node_t **divide(int *arr, int num, int n)
{
    struct node_t **list = calloc(n, sizeof(struct node_t *));
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= n * num) add(list, n - 1, arr[i]);
        else add(list, arr[i] / num, arr[i]);
    }
    return list;
}

void print(struct node_t **ans, int n)
{
    for (int j = 0; j < n; j++)
    {
        for (struct node_t *i = ans[j]; i != NULL; i = i->next)
        {
            printf("%d ", i->data);
        }
        printf("%d ", 0);
    }
}

void delete_list(struct node_t **list, int n){
    for (int i = 0; i < n; i++)
    {
        while (list[i] != NULL) list[i] = list[i]->next;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] > mx) mx = arr[i];
    }
    int num = mx / n;
    struct node_t **ans = divide(arr, num, n);
    print(ans, n);
    delete_list(ans, n);
    free(arr);
}