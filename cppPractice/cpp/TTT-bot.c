#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of children (possible moves from any given game state in tic-tac-toe)
#define MAX_CHILDREN 9

// Structure to represent each node in the search tree (each game state)
typedef struct Node {
    char board[3][3]; // Represents the tic-tac-toe board state
    int move; // Move that led to this board state, represented as an integer (0-8)
    struct Node* children[MAX_CHILDREN]; // Pointers to child nodes
    int childCount; // Number of children
} Node;

// Function to create a new node given a board state and a move
Node* createNode(char board[3][3], int move) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            newNode->board[i][j] = board[i][j];
        }
    }
    newNode->move = move;
    newNode->childCount = 0;
    for (int i = 0; i < MAX_CHILDREN; ++i) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Function to add a child to a node
void addChild(Node* parent, Node* child) {
    if (parent->childCount < MAX_CHILDREN) {
        parent->children[parent->childCount++] = child;
    } else {
        printf("Maximum children exceeded\n");
    }
}

// Function to free the search tree starting from a given node
void freeTree(Node* root) {
    if (root == NULL) return;
    for (int i = 0; i < root->childCount; ++i) {
        freeTree(root->children[i]);
    }
    free(root);
}

int main() {
    // Example usage
    // Initial empty board
    char initialBoard[3][3] = {{' ', ' ', ' '},
                               {' ', ' ', ' '},
                               {' ', ' ', ' '}};

    // Create the root node
    Node* root = createNode(initialBoard, -1); // -1 indicates no move (initial state)

    // Here you would build the tree with all possible moves and their outcomes
    // For simplicity, this example does not include the logic for generating all possible game states

    // Don't forget to free the tree to avoid memory leaks
    freeTree(root);

    return 0;
}
