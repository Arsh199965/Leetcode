#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} TreeNode;
typedef struct stack
{
    int top;
    int size;
    int arr[];
} stack;
void push(stack *s, int value)
{
    if (s->top < s->size - 1)
    {
        s->arr[++(s->top)] = value;
    }
    else
    {
        printf("Stack overflow\n");
    }
}

int pop(stack *s)
{
    if (s->top >= 0)
    {
        return s->arr[(s->top)--];
    }
    else
    {
        printf("Stack underflow\n");
        return -1;
    }
}
int indexOf(int *arr, int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}
void printInOrder(TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }
    printInOrder(node->left);
    printf("%d ", node->data);
    printInOrder(node->right);
}
TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize)
{
    stack *parent = malloc(sizeof(stack) + inorderSize * sizeof(int));
    parent->top = -1;
    parent->size = inorderSize;

    stack *root = malloc(sizeof(stack) + inorderSize * sizeof(int));
    root->top = -1;
    root->size = inorderSize;

    int current = 1;
    TreeNode *treehead = (TreeNode *)malloc(sizeof(TreeNode));
    treehead->data = preorder[0];
    treehead->left = treehead->right = NULL;
    TreeNode *temp = treehead;

    push(root, indexOf(inorder, inorderSize, preorder[0]));

    while (current < preorderSize)
    {
        int flag = 0;
        // Only run this loop if parent->top >= 0 to avoid negative loop bound.
        for (int i = 0; i < parent->top + 1; i++)
        {
            int currentIndex = indexOf(inorder, inorderSize, preorder[current]);
            int pVal = parent->arr[parent->top - i];
            int rVal = root->arr[root->top];
            if ((currentIndex < pVal && rVal > pVal) || (currentIndex > pVal && rVal < pVal))
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            pop(root);
            pop(parent);
        }

        int currentIndex = indexOf(inorder, inorderSize, preorder[current]);
        int topIndex = root->arr[root->top];
        // Decide whether to attach as left or right child based on inorder index
        if (currentIndex < topIndex)
        {
            temp->left = (TreeNode *)malloc(sizeof(TreeNode));
            temp->left->data = preorder[current];
            temp->left->left = temp->left->right = NULL;
            temp = temp->left;
            push(parent, topIndex);
            push(root, currentIndex);
        }
        else
        {
            temp->right = (TreeNode *)malloc(sizeof(TreeNode));
            temp->right->data = preorder[current];
            temp->right->left = temp->right->right = NULL;
            temp = temp->right;
            push(parent, topIndex);
            push(root, currentIndex);
        }
        current++;
    }
    free(parent);
    free(root);
    return treehead;
}

int main()
{
    int preOrder[] = {1, 2, 4, 5, 3, 6, 7};
    int inOrder[] = {4, 2, 5, 1, 6, 3, 7};
    int preSize = sizeof(preOrder) / sizeof(preOrder[0]);
    int inSize = sizeof(inOrder) / sizeof(inOrder[0]);
    TreeNode *root = buildTree(preOrder, preSize, inOrder, inSize);
    printInOrder(root);
}