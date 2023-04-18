#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
#include "TreeAPI.h"
#include <locale.h>
#include <string.h>


int main()
{
    errno_t err;
    FILE* fp;
    err = fopen_s(&fp, "database.txt", "r");
    file_open(err);
    Node* loaded_tree = load_tree(fp);
    if (loaded_tree == NULL) loaded_tree = create_node("Egypt");
    traverse(loaded_tree);
    fclose(fp);
    errno_t err_2;
    FILE* fp_out;
    err_2 = fopen_s(&fp_out, "database.txt", "w");
    file_open(err_2);
    save_tree(loaded_tree, fp_out);
    fclose(fp_out);
    free_tree(loaded_tree);
    return 0;
}
