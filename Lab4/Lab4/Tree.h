#ifndef LAB4_TREE
#define LAB4_TREE
typedef struct Node {
    char* question;         // �������� ����
    struct Node* left;  // ��������� �� ������ �������
    struct Node* right; // ��������� �� ������� �������
} Node;

#endif