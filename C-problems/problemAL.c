//
// Created by Lenovo on 06.08.2025.
//
#include <stdio.h>
#include <stdlib.h>

struct node_t {
    struct node_t *next;
    int data;
};

//некрасивый код, но зашел в тестовую систему даже без free, видимо из-за того что нет необходимости доступа к той памяти,
//которую я использовал, и дальше уже не важно что в ней лежит. лучше бы посмотреть в интернете

struct node_t *read_list(FILE *inp) {
    // TODO: ваш код здесь
    struct node_t *start1 = calloc(1, sizeof(struct node_t)), *end1 = calloc(1, sizeof(struct node_t)),
    *start2 = calloc(1, sizeof(struct node_t)), *end2 = calloc(1, sizeof(struct node_t));
    for (;;){
        int sc, n;
        sc = fscanf(inp, "%d", &n);
        if (sc != -1){
            if (n % 2 == 0){
                if (start1->next == NULL)
                {
                    start1->data = n;
                    start1->next = end1;
                }
                else
                {
                    end1->data = n;
                    struct node_t *temp = calloc(1, sizeof(struct node_t));
                    end1->next = temp;
                    end1 = end1->next;
                }
            }
            else{
                if (start2->next == NULL)
                {
                    start2->data = n;
                    start2->next = end2;
                }
                else
                {
                    end2->data = n;
                    struct node_t *temp = calloc(1, sizeof(struct node_t));
                    end2->next = temp;
                    end2 = end2->next;
                }
            }
        }
        else break;
    }
    *end1 = *start2;
    if (start1->next == NULL)
    {
        *start1 = *end1;
    }
    return start1;
}

void delete_list(struct node_t *top) {
    // TODO: ваш код здесь
    while (top != NULL){
        struct node_t *tmp = top;
        top = top->next;

        free(tmp);
    }
}

int main()
{
    FILE* file = fopen("C:/Users/Lenovo/CLionProjects/c-training/C-problems/input.txt", "r");
    struct node_t *value =  read_list(file);
    while (value != NULL)
    {
        printf("%d ", value->data);
        value = value->next;
    }
    //delete_list(value);
}