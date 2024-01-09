#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

};

struct Node* createBST(struct Node* root, int num)
{
    if(root == NULL)
    {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data=num;
        temp->left=temp->right=NULL;
        return temp;
    }

    if(num<root->data)
    {
        root->left=createBST(root->left,num);
    }
    else if (num>root->data)
    {
        root->right=createBST(root->right, num);
    }
    else{
        printf("Duplicates not allowed!");
    }
    
}

void preOrder(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    else{
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }

}

void main()
{
    struct Node* root;
    root=(struct Node*)malloc(sizeof(struct Node));
    root=NULL;

    root=createBST(root,5);
    root=createBST(root,3);
    root=createBST(root,7);
    root=createBST(root,4);
    root=createBST(root,2);
    preOrder(root);




}