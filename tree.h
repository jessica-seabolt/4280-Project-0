// Jessica Seabolt 4280 Project 0

#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <stdio.h>

// Build the tree from the given file stream.
Node *buildTree(FILE *file);

// Tree traversals
void printPreorder(Node *root, int level, FILE *file);
void printInorder(Node *root, int level, FILE *file);
void printPostorder(Node *root, int level, FILE *file);

// Utility function for freeing memory
void freeTree(Node *root);

#endif // TREE_H