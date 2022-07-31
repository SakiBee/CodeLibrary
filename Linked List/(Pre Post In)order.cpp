/*
Author: Md. Sakib Uddin.
Reg: 2018-15-32.
*/
#include<bits/stdc++.h>

struct node{
	char data;
	struct node* l;
	struct node* r;
};
void in_Travers(struct node* root){
	if(root == NULL) return;
	in_Travers(root -> l);
	printf("-> %c ", root -> data);
	in_Travers(root -> r);
}
void pre_Travers(struct node* root){
	if(root == NULL) return;
	printf("-> %c ", root->data);
	pre_Travers(root -> l);
	pre_Travers(root -> r);
}
void post_Travers(struct node* root){
	if(root == NULL) return;
	post_Travers(root -> l);
	post_Travers(root -> r);
	printf("-> %c ", root ->data);
}
struct node* cNode(char value){
	struct node* newNode = (struct node*)malloc(sizeof(struct node*));
	newNode->data = value;
	newNode->l = NULL;
	newNode->r = NULL;
	return newNode;
}
int main(){
	struct node* root =  cNode('C');
	root->l = cNode('A');
	root->r = cNode('E');
	root->l->r = cNode('B');
	root->l->r->l = cNode('D');
	root->l->r->l->l = cNode('I');
	root->l->r->r = cNode('H');
	root->l->r->r->l = cNode('K');
	root->l->r->r->r = cNode('M');
	root->r->l = cNode('F');
	root->r->r = cNode('G');
	root->r->r->l = cNode('J');
	root->r->r->l->r = cNode('L');
	root->r->r->l->r->l = cNode('N');
	root->r->r->l->r->r = cNode('O');

	printf("\nGiven Preorder Traversal:- \n");
	pre_Travers(root);

	printf("\n\nGiven Inorder Traversal:- \n");
	in_Travers(root);
	
	printf("\n\nExpected and Final Postorder Traversal:- \n");
	post_Travers(root);

	return 0;
}
