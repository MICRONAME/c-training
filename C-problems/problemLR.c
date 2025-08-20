#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node_t
{
    int data;
    struct node_t *next;
};

struct node_t *reverse(struct node_t *top) {
    if (top == NULL) return NULL;
    if (top->next == NULL) return top;
    struct node_t *tail = top, *mid = top->next, *head = top->next->next;
    if (head == NULL){
        top->next->next = top;
        top->next = NULL;
        return mid;
    }
    while (head != NULL){
        if (tail == top){
            top->next = NULL;
        }
        mid->next = tail;
        tail = mid; mid = head; head = head->next;
    }
    mid->next = tail;
    return mid;
}

void delete_list(struct node_t *top)
{
    while (top != NULL) top = top->next;
}

void print(struct node_t *top)
{
    for (struct node_t *p = top; p != NULL; p = p->next)
        printf("%d", p->data);
    printf("\n");
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
    assert(sc == 1);
    struct node_t *list = initialize(n);
    print(list);
    struct node_t *reversed = reverse(list);
    print(reversed);
    delete_list(list);
}