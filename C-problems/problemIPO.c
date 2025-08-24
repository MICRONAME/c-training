//
// Created by Lenovo on 22.08.2025.
//
#include <stdio.h>
#include <stdlib.h>

struct tree_t
{
    struct tree_t *left;
    struct tree_t *right;
    int data;
};

//via recursive call
void print_pre(struct tree_t *top) {
    // TODO: ваш код здесь
    if (top == NULL) return;
    printf("%d", top->data);
    print_pre(top->left);
    print_pre(top->right);
}

struct tree_t* generate()
{
    struct tree_t* top = calloc(1, sizeof(struct tree_t));
    top->left = calloc(1, sizeof(struct tree_t));
    top->right = calloc(1, sizeof(struct tree_t));
    //top->left->left = calloc(1, sizeof(struct tree_t));
    //top->left->right = calloc(1, sizeof(struct tree_t));
    //top->left->right->left = calloc(1, sizeof(struct tree_t));
    //top->left->right->right = calloc(1, sizeof(struct tree_t));
    top->data = 0;
    top->left->data = 1;
    top->right->data = 2;
    //top->left->left->data = 3;
    //top->left->right->data = 4;
    //top->left->right->left->data = 5;
    //top->left->right->right->data = 6;
    return top;
}

void delete_tree(struct tree_t *top)
{
    if (top == NULL) return;
    delete_tree(top->left);
    delete_tree(top->right);
    free(top);
}

int main()
{
    struct tree_t* tree = generate();
    print_pre(tree);
    delete_tree(tree);
}