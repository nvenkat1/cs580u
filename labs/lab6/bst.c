#include "data.h"
#include "bst.h"

#include<stdio.h>
#include<stdlib.h>


Tree * createTree(){
	Tree *tree = malloc(sizeof(Tree));
	(*tree).root = NULL;
	return tree;
}
Node * createNode(Data dataIn, Node *parent){
	Node *node = malloc(sizeof(Node));
	(*node).data = initData(dataIn.num);
	(*node).parent = parent;
	(*node).left = (*node).right = NULL;
	return node;
}
