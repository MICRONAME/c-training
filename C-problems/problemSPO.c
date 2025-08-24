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

struct stack_node
{
    struct stack_node *next;
    struct tree_t *data;
};
#if 0
struct stack_node* pop(struct stack_node *top)
{
    if (top == NULL) return top;
    top = top->next;
    return top;
}
#endif
//via iterative tools
void print_pre(struct tree_t *top) {
    // TODO: ваш код здесь
    if (top == NULL) return;

    struct stack_node *stack = calloc(1, sizeof(struct stack_node));
    stack->data = top;
    stack->next = NULL;

    while (stack != NULL) {
        struct tree_t *current = stack->data;
        printf("%d ", current->data);

        struct stack_node *next_node = stack->next;

        free(stack);
        stack = next_node;

        if (current->right != NULL) {
            struct stack_node *right_node = calloc(1, sizeof(struct stack_node));
            right_node->data = current->right;
            right_node->next = stack;
            stack = right_node;
        }

        if (current->left != NULL) {
            struct stack_node *left_node = calloc(1, sizeof(struct stack_node));
            left_node->data = current->left;
            left_node->next = stack;
            stack = left_node;
        }
    }
}

struct tree_t* generate()
{
    struct tree_t* top = calloc(1, sizeof(struct tree_t));
    top->left = calloc(1, sizeof(struct tree_t));
    top->right = calloc(1, sizeof(struct tree_t));
    top->right->left = calloc(1, sizeof(struct tree_t));
    top->right->right = calloc(1, sizeof(struct tree_t));
    top->right->right->left = calloc(1, sizeof(struct tree_t));
    top->right->right->right = calloc(1, sizeof(struct tree_t));
    top->data = 0;
    top->left->data = 1;
    top->right->data = 2;
    top->right->left->data = 3;
    top->right->right->data = 4;
    top->right->right->left->data = 5;
    top->right->right->right->data = 6;
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