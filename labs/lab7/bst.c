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
void insert(Tree * tree, Data data){
	if((*tree).root == NULL){
		(*tree).root = createNode(data, NULL);
	}else{
		insertNode((*tree).root, data);
	}
}
void search(Tree * tree, Data data){
        if((*tree).root == NULL){
		return NULL;
        }else{
                search((*tree).root, data);
        }
}

/**
**If the value is already in the tree,
just print a message that
you cannot insert duplicate values
*/
void insertNode(Node * root, Data data){
	/*Make sure you check for the special case 
	of an empty tree [if(bst->root == NULL)],
	*/ 
	if((data).num < (*(*root).data).num){
		if( (*root).left == NULL){
			(*root).left = createNode(data, root);
		}else{
			insertNode((*root).left, data);
		}
	}else if((data).num > (*(*root).data).num){
		if((*root).right == NULL){
			(*root).right = createNode(data, root);
		}else{
			insertNode((*root).right, data);
		}
	}
}

Node* searchNode(Node * root, Data data){
	/*Make sure you check for the special case 
	of an empty tree [if(bst->root == NULL)],
	*/ 
       if((data).num < (*(*root).data).num){
                if( (*root).left == NULL){
			return NULL;
                }else{
                        return (Node *) searchNode((*root).left, data);
                }
        }else if((data).num > (*(*root).data).num){
                if((*root).right == NULL){
			return NULL;
                }else{
                        return (Node *) searchNode((*root).right, data);
                }
        }else{
		return &((*root).data);
	}
}
