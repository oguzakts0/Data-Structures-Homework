#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* newNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node* buildTreeFromArray(int arr[], int n, int i) {
    if (i >= n) return NULL;

    Node* root = newNode(arr[i]);
    root->left = buildTreeFromArray(arr, n, 2*i + 1);
    root->right = buildTreeFromArray(arr, n, 2*i + 2);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int arr[] = {10, 21, 7, 71, 41, 9, 15, 54, 12, 81, 20, 52, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = buildTreeFromArray(arr, n, 0);

    preorder(root); printf("\n");
    inorder(root);  printf("\n");
    postorder(root);printf("\n");

    freeTree(root);
    return 0;
}
