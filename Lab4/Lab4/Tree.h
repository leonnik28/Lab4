#ifndef LAB4_TREE
#define LAB4_TREE
typedef struct Node {
    char* question;         // «начение узла
    struct Node* left;  // ”казатель на левого потомка
    struct Node* right; // ”казатель на правого потомка
} Node;

#endif