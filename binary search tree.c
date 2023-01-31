#include <stdio.h>
#include <stdlib.h>
struct node
{
    int element;
    struct node *left;
    struct node *right;
};
struct node *root= NULL;
struct node *insert(struct node *root,struct node *newnode)
{
 if(root==NULL)
 {
     root=newnode;
 }
 else
 {
     if(newnode->element<root->element)
     {
         if(root->left==NULL)
            root->left=newnode;
         else
            insert(root->left,newnode);
     }
     else if (newnode->element>root->element)
     {
         if(root->right==NULL)
            root->right=newnode;
         else
            insert(root->right,newnode);
     }
     else
        printf("\n\t Element already exists\n\n");
 }
 return root;
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d-->",root->element);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d-->",root->element);
        inorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d-->",root->element);
    }
}
int main()
{
    int ch,val,i,n;
    struct node newnode;
    do
    {
        printf("\n\t\t Binary Search Tree\n");
        printf("\n\t<1>Creation of BST");
        printf("\n\t<2>Inorder Traversal");
        printf("\n\t<3>Preorder Traversal");
        printf("\n\t<4>Postorder Traversal");
        printf("\n\t<5>Exit");
        printf("\n\tEnter Your Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\n\t\t Creation of BST");
            printf("enter no.of elements to create");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
                printf("\n\t Inserting Elements %d",i);
                scanf("%d",&val);
                newnode=(struct node *)malloc(sizeof(struct node));
                newnode->element=val;
                newnode->left=NULL;
                newnode->right=NULL;
                root=insert(root,newnode);
            }
            break;
        case 2:
            if(root==NULL)
                printf("\n\t Empty tree");
            else
                {
                    printf("\n\n\tInorderTraversal:");
            inorder(root);
            }
            break;
        case 3:
            if(root==NULL)
                printf("\n\t Empty Tree");
                  else
                {
                    printf("\n\n\tPreorder Traversal:");
            preorder(root);
            }
            break;
            case 4:
            if(root==NULL)
                printf("\n\t Empty Tree");
                  else
                {
                    printf("\n\n\tPostorder Traversal:");
            postorder(root);
            }
            break;
            case 5:exit(0);
            default:printf(\n\t Invalid choice\n");
            break;
        }
    }while(ch!=5);
    return 0;
}
