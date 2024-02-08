// Jessica Seabolt 4280 Project 0

#include "tree.h"
#include <stdlib.h>
#include <string.h>

// Create a new node
static Node *createNode(const char *data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode)
    {
        newNode->data = strdup(data);
        newNode->left = newNode->middle = newNode->right = NULL;
    }
    return newNode;
}

// Insert a node
static Node *insertNode(Node *root, const char *data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data[0] < root->data[0])
    {
        root->left = insertNode(root->left, data);
    }
    else if (data[0] > root->data[0])
    {
        root->right = insertNode(root->right, data);
    }
    else
    {
        Node *dup = createNode(data);
        dup->middle = root->middle;
        root->middle = dup;
    }

    return root;
}

Node *buildTree(FILE *file)
{
    Node *root = NULL;
    char buffer[1024]; // Assuming a max word length of 1024 characters so I don't get a buffer overflow and cry

    while (fscanf(file, "%1023s", buffer) != EOF)
    {
        root = insertNode(root, buffer);
    }

    return root;
}

void printPreorder(Node *root, int level, FILE *file)
{
    if (root == NULL)
        return;

    fprintf(file, "%*s%c:%s\n", level * 2, "", root->data[0], root->data);
    printPreorder(root->left, level + 1, file);
    printPreorder(root->middle, level + 1, file);
    printPreorder(root->right, level + 1, file);
}

void printInorder(Node *root, int level, FILE *file)
{
    if (root == NULL)
        return;

    printInorder(root->left, level + 1, file);
    fprintf(file, "%*s%c:%s\n", level * 2, "", root->data[0], root->data);
    printInorder(root->middle, level + 1, file);
    printInorder(root->right, level + 1, file);
}

void printPostorder(Node *root, int level, FILE *file)
{
    if (root == NULL)
        return;

    printPostorder(root->left, level + 1, file);
    printPostorder(root->middle, level + 1, file);
    printPostorder(root->right, level + 1, file);
    fprintf(file, "%*s%c:%s\n", level * 2, "", root->data[0], root->data);
}

void freeTree(Node *root)
{
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->middle);
    freeTree(root->right);
    free(root->data);
    free(root);
}