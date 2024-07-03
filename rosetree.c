#include <stdio.h>
#include <stdlib.h>

// Main rosetree nodes
typedef struct rosenode {
    // Value of rosenode
    int value;
    // Pointer to a node
    struct node* ptrs;
    // Parent node, left null if root
    struct rosenode* parent;
} rosenode;

// Linked list implementation to hold pointers to lower rosenodes
typedef struct node
{
    // Pointer to an branch of the rosenode that points to it
    struct rosenode* offspring;
    // Pointer to another node which can point to another branch of the rosenode
    struct node* next;
    // Pointer to parent rosenode
    struct rosenode* parent;
} node;

int main (void)
{
    // Creates tree with structure                         11
    //                                                    /  \
    //                                                   7   14
    //                                                  /   / | \
    //                                                 13  5  9 12
    rosenode *root = malloc(sizeof(rosenode));
    node *node01 = malloc(sizeof(node));
    node *node02 = malloc(sizeof(node));
    root->value = 11; root->parent = NULL; root->ptrs = node01;
    rosenode *rose11 = malloc(sizeof(rosenode));
    rosenode *rose12 = malloc(sizeof(rosenode));
    node01->offspring = rose11; node01->next = node02; node01->parent = root;
    node02->offspring = rose12; node02->next = NULL; node02->parent = root;
    node *node111 = malloc(sizeof(node));
    node *node121 = malloc(sizeof(node));
    node *node122 = malloc(sizeof(node));
    node *node123 = malloc(sizeof(node));    
    rose11->value = 7; rose11->parent = node01->parent; rose11->ptrs = node111;
    rose12->value = 14; rose12->parent = node02->parent; rose12->ptrs = node121;
    rosenode *rose211 = malloc(sizeof(rosenode));
    rosenode *rose221 = malloc(sizeof(rosenode));
    rosenode *rose222 = malloc(sizeof(rosenode));
    rosenode *rose223 = malloc(sizeof(rosenode));
    node111->offspring = rose211; node111->next = NULL; node111->parent = rose11;
    node121->offspring = rose221; node121->next = node122; node121->parent = rose12;
    node122->offspring = rose222; node122->next = node123; node122->parent = node121->parent;
    node123->offspring = rose223; node123->next = NULL; node123->parent = node122->parent;
    rose211->value = 13; rose211->parent = node111->parent; rose211->ptrs = NULL;
    rose221->value = 5; rose221->parent = node121->parent; rose221->ptrs = NULL;
    rose222->value = 9; rose222->parent = node122->parent; rose222->ptrs = NULL;
    rose223->value = 12; rose223->parent = node123->parent; rose223->ptrs = NULL;

    // Traversing the tree to print a specific value
    int *x = malloc(sizeof(int));
    *x = root->ptrs->next->offspring->value;
    printf("%i\n", *x);

    // Traversing back up the tree
    int *y = malloc(sizeof(int));
    *y = rose211->parent->parent->value;
    printf("%i\n", *y);

    // Free memory
    free(root); free(node01); free(node02); free(rose11); free(rose12); free(node111); free(node121); free(node122); free(node123); free(rose211); free(rose221); free(rose222); free(rose223); free(x); free(y);
}