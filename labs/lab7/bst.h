#ifndef BST_H
#define BST_H

#include "data.h"

#define PART1 1
#define DEBUG1 0
#define PART2 1
#define PART2_1 1 
#define PART2_2 1

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

Data* findNode(Tree * tree, Data data);
Node * searchNode(Node * node, Data value);

Node * findMaxMinSubTree(Node * node);
void removeLead(Tree *, Node *);
void shortCircuit(Tree *, Node *);
void promotion(Tree *, Node *);
void removeNode(Tree *, Data );

void * freeNode(Node * node);
void printSearchResult(Node *node);

void inOrder(Tree *tree, Node *node);
void preOrder(Tree *tree, Node *node);
void postOrder(Tree *tree, Node *node);

void* postOrderDelete(Node *node);
void* deleteTree(Tree *tree);

#endif
