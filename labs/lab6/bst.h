#ifndef BST_H
#define BST_H

#include "data.h"

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

