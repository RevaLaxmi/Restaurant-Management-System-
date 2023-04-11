#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char itemname[50];
    int amount;
    float costprice;
    int entry;
    struct node *left;
    struct node *right;
};

struct node *head_3 = NULL,*n_node,*tail_3 = NULL;
//struct node *head_3 = NULL;
//struct node *n_node = NULL;
//struct node *tail_3 = NULL;
struct node *head_1 = NULL, *tail_1 = NULL;
//struct node *head_1 = NULL;
//struct node *tail_1 = NULL;
struct node *head_s;

//the int values for everything and the char values and so on can stay the same - char of [50] for a limit
/*
// Tree Node
struct node
{
    int key;
    struct node *left, *right;
};
*/
// Allocates a new node with the given key and NULL left and right pointers.
/*
struct node *TreeNode(int key)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}
*/