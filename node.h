// Jessica Seabolt 4280 Project 0

#ifndef NODE_H
#define NODE_H

// I feel like it's pretty obvious what this is lol
typedef struct Node
{
    char *data;
    struct Node *left;
    struct Node *middle;
    struct Node *right;
} Node;

#endif // NODE_H