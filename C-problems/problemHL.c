#include <stdio.h>
#include <stdlib.h>

struct node_t
{
    int data;
    struct node_t *next;
};

int loop_len(struct node_t *top) {
    if (top == NULL)
        return 0;

    struct node_t *first = top;
    struct node_t *second = top->next;
    int p = 1;
    int len = 1;

    while (second != NULL && second != first) {
        if (len == p) {
            p *= 2;
            len = 0;
            first = second;
        }
        second = second->next;
        ++len;
    }
    if (second == NULL)
        return 0;
    return len;
}
#if 0
void print(struct node_t *top)
{
    for (struct node_t *p = top; p != NULL; p = p->next)
        printf("%d", p->data);
}

void delete_list(struct node_t *top)
{
    while (top != NULL) top = top->next;
}

struct node_t * initialize(int n)
{
    int data;
    struct node_t *top = NULL, *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        struct node_t *new = calloc(1, sizeof(struct node_t));
        scanf("%d", &data);
        if (top == NULL)
        {
            top = new;
            top->data = data;
        }
        else
        {
            if (tail == NULL)
            {
                tail = new;
                top->next = tail;
                tail->data = data;
            }
            else
            {
                tail->next = new;
                tail = tail->next;
                tail->data = data;
            }
        }
    }
    return top;
}

int main()
{
    int n, sc;
    sc = scanf("%d", &n);
    struct node_t *list = initialize(n);
    int len = loop_len(list);
    printf("%d\n", len);
    print(list);
    delete_list(list);
}
#endif