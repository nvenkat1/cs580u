#include "data.h"
#include "bst.h"

#include<stdio.h>
#include<stdlib.h>

//Constructor
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

//Operations
void insert(Tree * tree, Data data){
	if((*tree).root == NULL){
		(*tree).root = createNode(data, NULL);
	}else{
		insertNode((*tree).root, data);
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
	if(data.num < (*(*root).data).num){
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
	}else if(data.num == root->data->num){
		printf("\tYou can not insert Duplicate values in Binary Search Tree\n");
	}
}
Data* findNode(Tree * tree, Data data){
        if((*tree).root == NULL){
		return NULL;
        }else{
                Node *node = searchNode((*tree).root, data);
		if(node != NULL){
			printSearchResult(node);
			return node->data;
		}else{
			printf("\tCould not find Given Data in Tree\n");
			return NULL;
		}
        }
}

Node* searchNode(Node * root, Data data){
	/*Make sure you check for the special case
	of an empty tree [if(bst->root == NULL)],
	*/
       if(data.num < (*(*root).data).num){
                if( (*root).left == NULL){
			return NULL;
                }else{
                        return (Node *) searchNode((*root).left, data);
                }
        }else if(data.num > (*(*root).data).num){
                if((*root).right == NULL){
			return NULL;
                }else{
                        return (Node *) searchNode((*root).right, data);
                }
        }else{//Which means its equal to node itself.
		//return &((*root));
		return root;
	}
}
void printSearchResult(Node *node){
	printf("\tGiven value was found ");
	if(node->parent == NULL){
		printf("\n\tAt Root, With Node value = %d",node->data->num);
	}else{
		printf("\n\tWith Node value = %d \n\tWith Parent Node Value = %d",node->data->num, node->parent->data->num);
	}
	if(node->right!= NULL || node->left!= NULL){
		if(node->right!= NULL){
			printf("\n\tWith Right Child Node Value = %d",node->right->data->num);
		}
		if(node->left!= NULL){
			printf("\n\tWith Left Child Node Value = %d",node->left->data->num);
		}
	}else{
			printf("\n\tIts a leaf Node");
	}
	printf("\n");
}
void * freeNode(Node * node){
	node->data = deleteData(node->data);
	node->left = node->right = node->parent = NULL;
	free(node);
	return NULL;
}
void removeLeaf(Tree * tree, Node * node){
	if(node->parent->left == node){
		//means its a left leaf
		node->parent->left = NULL;
	}else{
		//its a right leaf
		node->parent->right = NULL;
	}
	node = freeNode(node);
}
void shortCircuit(Tree * tree, Node * node){
	//first check its right or left child
	if(node->parent->left == node){
		if(node->left == NULL){
			node->parent->right = node->right;
			node->right->parent = node->parent;
			node = freeNode(node);
		}else{
			node->parent->left = node->left;
			node->left->parent = node->parent;
			node = freeNode(node);
		}
	}else{	//it is right node
		if(node->right==NULL){
			node->parent->left = node->left;
			node->left->parent = node->parent;
			node = freeNode(node);
		}else{
			node->parent->right = node->right;
			node->right->parent = node->parent;
			node = freeNode(node);
		}
	}
}

Node * findMaxMinSubTree(Node * node){
	//This will always return maximum node among subtree
	//But which is less thatn current node.
	node = node->left;
	while(node->right != NULL){
		node = node->right;
	}
	return node;
}

void promotion(Tree * tree, Node * node){
	Node *promot = findMaxMinSubTree(node);
	//first copy data and then promot
	node->data = promot->data;

	//Check if Node to be Promoted has Child or not
	if(promot->left == NULL && promot->right == NULL){
		//Means its a leaf node.
		removeLeaf(tree, promot);
	}else{
		//It has only One child
		//Since when we found max and min. 
		//Max and min are one of the node with one child.
		shortCircuit(tree, promot);
	}
	
}
/**To Delete Any Node We Have 3 Cases
** Any Node Can Have 1. No Child  2. One Child    3. 2 Childs
			x		x		x
		       / \	       / \             / \
		      N   N           y   N           y   z
*/
void removeNode(Tree * tree, Data data){
        if((*tree).root == NULL){
		printf("\tEmpty Tree\n");
                return;
        }else{
                Node * toDelete = searchNode((*tree).root, data);

		if(toDelete!=NULL){
			//node with both left and right child
			if(toDelete->left !=NULL && toDelete->right != NULL){
				promotion(tree, toDelete);
				printf("\n\t");
				inOrder(tree->root);
				printf("\n\t");
				preOrder(tree->root);
				printf("\n\t");
				postOrder(tree->root);
			}else if(toDelete->left != NULL || toDelete->right != NULL){
				//It has at least one child left or right
				shortCircuit(tree, toDelete);
				printf("\n\t");
				inOrder(tree->root);
				printf("\n\t");
				preOrder(tree->root);
				printf("\n\t");
				postOrder(tree->root);
			}else{
				//its a leaf node
				removeLeaf(tree, toDelete);
				printf("\n\t");
				inOrder(tree->root);
				printf("\n\t");
				preOrder(tree->root);
				printf("\n\t");
				postOrder(tree->root);
			}
		}else{
			printf("\tNode to be deleted not Found\n\n");
		}
	}
}
void inOrder(Node *node){
	if(node != NULL){
		inOrder(node->left);	
		printf("%d ",node->data->num);
		inOrder(node->right);
	}
}
void preOrder(Node *node){
	if(node!=NULL){
		printf("%d ",node->data->num);
		preOrder(node->left);
		preOrder(node->right);
	}
}
void postOrder(Node *node){
   	if(node != NULL){
		postOrder(node->left);
		postOrder(node->right);
	   	printf("%d ", node->data->num);
   }
}
