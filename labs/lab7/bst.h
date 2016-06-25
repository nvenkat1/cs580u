#ifndef BST_H
#define BST_H

#include "data.h"

#define PART1 1

typedef struct node {
	Data *data;
	struct node *left;
	struct node *right;
	struct node *parent;
}Node;

typedef struct tree{
	struct node *root;
}Tree;

Tree * createTree();
Node * createNode(Data d, Node *parent);
void insert(Tree * tree, Data value);
void insertNode(Node * root, Data value);
void search(Tree * tree, Data data);
Node * searchNode(Node * node, Data value);
#endif
