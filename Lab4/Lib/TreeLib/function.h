#ifndef LIB_TREE
#define LIB_TREE
#include <stdio.h>

typedef struct Node {
    char* question; 
    struct Node* left; 
    struct Node* right;
} Node;

void file_open(errno_t err);
Node* create_node(const char* word);
void new_node_l(Node** node);
void save_tree(Node* root, FILE* fp);
void free_tree(Node* root);
Node* load_tree(FILE* fp);
int check_r(Node** node);
int check_l(Node** node);
void traverse(Node* node);

#endif