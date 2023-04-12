#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
#include "TreeAPI.h"
#include <locale.h>
#include <string.h>

int main() {
    FILE* fp = fopen("database.txt", "r");
    Node* loaded_tree = load_tree(fp);
    if (loaded_tree == NULL) loaded_tree = create_node("Egypt");
    traverse(loaded_tree);
    fp = fopen("database.txt", "w");
    save_tree(loaded_tree, fp);
    fclose(fp);
    free_tree(loaded_tree);
    return 0;
}