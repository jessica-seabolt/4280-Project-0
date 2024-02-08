// Jessica Seabolt 4280 Project 0

#include "node.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 1013 // 1024 for max name length, - 11 to account for the longest suffix ".postorder" (maybe there was a better way but I wanted to be done lol)

int main(int argc, char *argv[])
{
    FILE *inputFile, *outputFile;
    char baseFilename[MAX_FILENAME_LEN] = "output"; // Default base filename
    char filenameBuffer[MAX_FILENAME_LEN + 11];     // Extra space for suffixes

    // Process command line arguments
    if (argc > 2)
    {
        fprintf(stderr, "Usage: %s [file]\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (argc == 2)
    {
        if (strlen(argv[1]) >= MAX_FILENAME_LEN)
        {
            fprintf(stderr, "Error: Filename too long.\n");
            return EXIT_FAILURE;
        }
        strncpy(baseFilename, argv[1], sizeof(baseFilename) - 1);
        baseFilename[sizeof(baseFilename) - 1] = '\0'; // Ensure null termination
        inputFile = fopen(argv[1], "r");
        if (inputFile == NULL)
        {
            perror("Error opening input file");
            return EXIT_FAILURE;
        }
    }
    else
    {
        inputFile = stdin;
        printf("Enter words to build the tree. Press Ctrl+D (Unix) or Ctrl+Z (Windows) to finish.\n");
    }

    // Build the tree
    Node *root = buildTree(inputFile);
    if (inputFile != stdin)
    {
        fclose(inputFile);
    }

    // Output in preorder
    snprintf(filenameBuffer, sizeof(filenameBuffer), "%s.preorder", baseFilename);
    outputFile = fopen(filenameBuffer, "w");
    if (outputFile == NULL)
    {
        perror("Error opening output file for preorder");
        freeTree(root);
        return EXIT_FAILURE;
    }
    printPreorder(root, 0, outputFile);
    fclose(outputFile);

    // Output in inorder
    snprintf(filenameBuffer, sizeof(filenameBuffer), "%s.inorder", baseFilename);
    outputFile = fopen(filenameBuffer, "w");
    if (outputFile == NULL)
    {
        perror("Error opening output file for inorder");
        freeTree(root);
        return EXIT_FAILURE;
    }
    printInorder(root, 0, outputFile);
    fclose(outputFile);

    // Output in postorder
    snprintf(filenameBuffer, sizeof(filenameBuffer), "%s.postorder", baseFilename);
    outputFile = fopen(filenameBuffer, "w");
    if (outputFile == NULL)
    {
        perror("Error opening output file for postorder");
        freeTree(root);
        return EXIT_FAILURE;
    }
    printPostorder(root, 0, outputFile);
    fclose(outputFile);

    // Free the tree
    freeTree(root);

    return EXIT_SUCCESS;
}