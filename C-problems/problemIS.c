//
// Created by Lenovo on 25.08.2025.
//
#include <stdio.h>
#include <stdlib.h>

struct tree_t {
    struct tree_t *left;
    struct tree_t *right;
    int data;
};

int max = -10;

int check(struct tree_t *top, int l, int r)
{
    if (top->data < l || top->data > r) return 0;
    if (top->left) if (!check(top->left, l, top->data)) return 0;
    if (top->right) if (!check(top->right, top->data, r)) return 0;
    return 1;
}

int check_is_bst(struct tree_t *top) {
    // TODO: ваш код здесь
    return check(top, INT_MIN, INT_MAX);
}

struct tree_t* generate()
{
    struct tree_t* top = calloc(1, sizeof(struct tree_t));
    top->left = calloc(1, sizeof(struct tree_t));
    top->right = calloc(1, sizeof(struct tree_t));
    top->left->left = calloc(1, sizeof(struct tree_t));
    top->right->left = calloc(1, sizeof(struct tree_t));
    top->right->left->left = calloc(1, sizeof(struct tree_t));
    top->right->left->right = calloc(1, sizeof(struct tree_t));
    top->right->right = calloc(1, sizeof(struct tree_t));

    top->data = 4;
    top->left->data = 2;
    top->left->left->data = 1;
    top->right->data = 8;
    top->right->left->data = 6;
    top->right->left->left->data = 5;
    top->right->left->right->data = 10;
    top->right->right->data = 9;

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
    struct tree_t *tree = generate();
    printf("%d", check_is_bst(tree));
    delete_tree(tree);
}