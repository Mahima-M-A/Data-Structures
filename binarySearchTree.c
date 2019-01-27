#include<stdio.h>
#include<stdlib.h>


/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
     int key;
     struct node* left;
     struct node* right;
};


// function to search a given key in a given BST
struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;

    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

struct node* insert(struct node*r, int x)
{
	if (r == NULL)
	{
            r = (struct node*)malloc(sizeof(struct node));
            r->key = x;
            r->left = r->right = NULL;
            return r;
	}
	else if (x < r->key)
            r->left = insert(r->left, x);
	else if (x > r->key)
            r->right = insert(r->right, x);
	return r;
}

struct node* findmin(struct node*r)
{
	if (r == NULL)
		return NULL;
	else if (r->left!=NULL)
		return findmin(r->left);
	else if (r->left == NULL)
		return r;
}

struct node* del(struct node*r, int x)
{
	struct node *t;
	if(r == NULL)
		printf("\nElement not found");
	else if (x < r->key)
            r->left = del(r->left, x);
	else if (x > r->key)
            r->right = del(r->right, x);
	else if ((r->left != NULL) && (r->right != NULL))
	{
            t = findmin(r->right);
            r->key = t->key;
            r->right = del(r->right, r->key);
	}
	else
	{
            t = r;
            if (r->left == NULL)
                r = r->right;
            else if (r->right == NULL)
                r = r->left;
            free(t);
	}
	return r;
}

//function to display the tree itself

void display(struct node * root,int i)
{
    int j;

    if(root!=NULL)
    {
        display(root->right,i+1);
        for(j=1;j<=i;j++) printf("\t");
        printf("%d\n",root->key);
        display(root->left,i+1);
    }
}

//function to display the tree elements in postorder

void printPostorder(struct node* node)
{
     if (node == NULL)
        return;

     // first recur on left subtree
     printPostorder(node->left);

     // then recur on right subtree
     printPostorder(node->right);

     // now deal with the node
     printf("%d ", node->key);
}

//function to display the tree elements in inorder

void printInorder(struct node* node)
{
     if (node == NULL)
          return;

     /* first recur on left child */
     printInorder(node->left);

     /* then print the data of node */
     printf("%d ", node->key);

     /* now recur on right child */
     printInorder(node->right);
}

//function to display the tree elements in preorder

void printPreorder(struct node* node)
{
     if (node == NULL)
          return;

     /* first print data of node */
     printf("%d ", node->key);

     /* then recur on left sutree */
     printPreorder(node->left);

     /* now recur on right subtree */
     printPreorder(node->right);
}

/* Driver program to test above functions*/
int main()
{
    struct node* root = NULL;
    struct node* LOC=NULL;
    int x, c = 1, z;
    int element;
  
    while(1)
    {
        printf("\n1 Insert an element ");
        printf("\n2 Delete an element");
        printf("\n3 Search for an element ");
        printf("\n4 Display");
        printf("\n5 To print the preorder");
        printf("\n6 To print the inorder");
        printf("\n7 To print the postorder");
        printf("\n-1 Exit ");
        printf("\nEnter your choice: ");
        scanf("%d", &c);
        switch(c)
        {
            case 1:
                printf("\nEnter the item:");
                scanf("%d", &z);
                root = insert(root,z);
                break;
            case 2:
                printf("\nEnter the info to be deleted:");
                scanf("%d", &z);
                root = del(root, z);
                break;
            case 3:
                printf("\nEnter element to be searched:  ");
                scanf("%d", &element);
                LOC=search(root, element);
                if(LOC != NULL)
                    printf("\n%d found in Binary Search Tree !!\n",element);
                else
                    printf("\nIt is not present in Binary Search Tree\n");
                break;
            case 4 : 
                if(root == NULL)
                    printf("\nTree empty");
                else
                {
                    printf("\n Display Root is %d",root->key);
                    printf("\n");
                    display(root,1);
                }
                break;
            case 5:
                printf("\nPreorder traversal of binary tree is \n");
                printPreorder(root);
                break;
            case 6:
                printf("\nInorder traversal of binary tree is \n");
                printInorder(root);
                break;
            case 7:
                printf("\nPostorder traversal of binary tree is \n");
                printPostorder(root);
                break;
            case -1:
                exit(0);
            default:
                printf("Invalid choice!");
        }
    }
    return 0;
}
