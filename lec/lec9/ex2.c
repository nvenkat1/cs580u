#include<stdio.h>

struct Node{
	Data d;
	Node *left;
	Node *right;
	Node *parent;
}

struct tree{
	Node *root;
};


Node * createNode(Data d, Node * parent){ //how would we know what to set to parent, hence add parameter to know when to set aprart.
	Node * n = malloc(sizeof(Node));
	n->data = d;
	n->parent = parent; 		//for root, pass parent as NULL
	n->left = n->right = NULL;
	return n;
}

void insertNode(Tree *t, Data d){
	if(t.root == NULL){
		t->root = createNode(d,NULL);
	}else{
		insert(d, t->root);
	}
}
Data * findNode(Tree *t, Data d){
        if(t.root == NULL){
                //t->root = createNode(d,NULL);
		return NULL;
        }else{
		Node *n = search(d, t->root)->data;
		if(n!=NULL)
			return n->d;
		else
			return NULL;
                //search(d, t->root);
        }
}

void insert(Data d, Node *root){
	/*
	//Whole thing is added to insertNode function
	//When root is null we dont have access to Tree
	//Solution add 3rd param, Tree *t
	//but we cant make and pass that parameter all the time. break it into auxalary function
	if(root==NULL)
		root = createNode(d, NULL);
	//- If value is less then -go>left
	*/
	if(d.data < root->d.data){
		// If less is null
		if(root->left == NULL){
	 		root->left = createNode();            //Base case
		}else{
		//already node there, make current node as root for next node)
			insert(data, root->left);
		}
	}else if(d.data > root->d.data){
	//value is greater - than go right
		// If right is null
		if(root->right == NULL){
			root->right = createNode();            //Base case
		}else{
		//already node there, make current node as root for next node)
			insert( data, root->right);
		}
	}
	//if value is equal.. we are not handling that.
}

//changed return type from data to ndoe//

Node * search(Data d, Node *root){
        if(d.data < root->d.data){
                // If less is null
                if(root->left == NULL){
                        //root->left = createNode();            //Base case
			return NULL;
                }else{
                //already node there, make current node as root for next node)
                        return search(data, root->left);		//Added return
		//We will have to returb geer b/c of recursion
                }
        }else if(d.data > root->d.data){
        //value is greater - than go right
                // If right is null
                if(root->right == NULL){
                        //root->right = createNode();            //Base case
			return NULL;
                }else{
                //already node there, make current node as root for next node)
                        return search( data, root->right);
                }
        }else{
		//return &(root.data);
		return  root;
	}
}

void deleteLeaf(Node *n){
	// address of this node  == parent of left child htne its left node
	// address of this node  == parent of right child htne its right node
	if(n->parent->left == n)
		n->parent->left = NULL;
	else
		n->parent->right = NULL;
	free(n);
	n= NULL;
}

Node * findMaxinMinSubTree(Node * p){
	p = p->left;

	while(p->right!=NULL)
		p = p->right;

	return p;
}
void shortCircuit(Node *n){
	//first check whther its left or right child
	if(n->parent->left == n){
		//nwo we  dont know node we are trying to delete has left subtree or riht sub tree to update new pointers
		if(n->left ==NULL){
			n->parent->left = n->right;
			n->right->parent  = n->parent;
		}else{
			n->parent->left = n->left;
			n->left->parent  = n->parent;

        }else{	///this is reamingn update it.
		if(n->right == NULL){
			n->parent->right = n->right;
			n->right->parent  = n->parent;
		}else{
			n->parent->right = n->left;
			n->left->parent  = n->parent;
		}
	}
}
Node * promotion(Node *n){
	Node * promot = findMaxInMinSubtree(n);
	//copy and promote
	n->data = promot->data;

	//now copited node, has child or doesnt have child
	if(promote->left == NULL && promote->right==NULL);
		deleteleaf(prmote);
	else	//as we already found max or min, it will have only 1 child
		shortCircuit(promote);
}

void deleteNode(struct tree * t, struct Data d){
	Node * to_delete = searchNode(t,d);

	if(to_delete !=NULL){
		//how to know which node to delete
		//chcekc left and right pointers
		//then to check these are not equal to null
		if(to_delete->left !=NULL && to_delete->right != NULL){
			//it has 2 childers
			promotion(to_delete);
		}else if(to_delete->left !=NULL || to_delete->right != NULL){
			//has only one child
			shortCircuit(to_delete);
		}else{
			//means its leaf.
			deleteLeaf(to_delete);
		}

	}else{
		printf("Not Found\n");
	}
}

int main(){


	return 0;
}
