#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void file_open(errno_t err) {
    if (err != 0) {
        printf("ERROR input");
        exit(1);
    }
}

Node* create_node(const char* word) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->question = (char*)malloc(strlen(word) + 1);
    strncpy_s(new_node->question, strlen(word) + 2, word, strlen(word) + 1);
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void new_node_l(Node** node) {
    printf("I do not know the answer. What was it? \n");
    char new_word[100];
    scanf_s("%s", new_word, _countof(new_word));
    getchar();
    (*node)->right = create_node(new_word);
    printf("How is %s different from %s?\n", (*node)->right->question, (*node)->question);
    char question[100];
    (*node)->left = create_node((*node)->question);
    fgets(question, 100, stdin);
    question[strlen(question) - 1] = '\0';
    (*node)->question = NULL;
    (*node)->question = (char*)malloc(sizeof(question));
    strcpy((*node)->question, question);
}

void save_tree(Node* root, FILE* fp) {
    if (root == NULL) {
        fprintf(fp, "$\n");
        return;
    }
    fprintf(fp, "%s\n", root->question);
    save_tree(root->right, fp);
    save_tree(root->left, fp);
}

void free_tree(Node* root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->right);
    free_tree(root->left);
    free(root);
}

Node* load_tree(FILE* fp) {
    char question[100];
    if (fgets(question, 100, fp) == NULL) {
        return NULL;
    }
    if (strcmp(question, "$\n") == 0) {
        return NULL;
    }

    question[strlen(question) - 1] = '\0';
    Node* root = create_node(_strdup(question));

    root->right = load_tree(fp);
    root->left = load_tree(fp);
    return root;
}

int check_r(Node** node) {
    if ((*node)->right == NULL) {
        return 1;
    }
    else return 0;
}

int check_l(Node** node) {
    if ((*node)->left == NULL) {
        new_node_l(node);
        return 1;
    }
    return 0;
}

void traverse(Node* node) {
    if (node == NULL) {
        return;
    }
    if (node->question != NULL) {
        printf("%s?\n", node->question);
        char word[4];
        while (!scanf_s("%3s", word, _countof(word)) || (strcmp(word, "yes") != 0 && strcmp(word, "no") != 0)) {
            printf_s("Invalid answer\n");
            rewind(stdin);
            printf_s("Your answer: ");
        }
        int check = 0;
        if (strcmp(word, "yes") == 0) {
            check = check_r(&node);
            if (check == 1) printf("I guessed! Good luck next time :)");
            traverse(node->right);
        }
        else {
            check = check_l(&node);
            if (check == 1) return;
            traverse(node->left);
        }
    }
}