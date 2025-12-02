#include <stdio.h>
#include <stdlib.h>

typedef struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
} node;

node *create()
{
    node *temp;
    printf("\nEnter data: ");
    temp = (node*)malloc(sizeof(node));
    scanf("%d",&temp->data);
    temp->left=temp->right=NULL;
    return temp;
}

void insert(node *root,node *temp)
{
    if(temp->data<root->data)
    {
        if(root->left!=NULL)
            insert(root->left,temp);
        else
            root->left=temp;
    }
    if(temp->data>root->data)
    {
        if(root->right!=NULL)
            insert(root->right,temp);
        else
            root->right=temp;
    }
}

void preorder(node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main()
{
    char ch;
    node *root=NULL,*temp;
    do
    {
        temp=create();
        if(root==NULL)
            root=temp;
        else
            insert(root,temp);
        printf("\nWant More? (y/n): ");
        scanf(" %c",&ch);
    }
    while(ch=='y'||ch=='Y');

    printf("Preorder Transversal\n");
    preorder(root);

    printf("\nInorder Transversal\n");
    inorder(root);
}
