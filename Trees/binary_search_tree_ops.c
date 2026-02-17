 #include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node_t;

node_t* create(int data) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node_t* find_min(node_t* root) {
    if (root == NULL || root->left == NULL)
        return root;
    return find_min(root->left);
}

node_t* insert(node_t* root, int data) {
    if (root == NULL)
        return create(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

node_t* delete(node_t* root, int data) {
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = delete(root->left, data);
    else if (data > root->data)
        root->right = delete(root->right, data);
    else {
        if (root->left == NULL) {
            node_t* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node_t* temp = root->left;
            free(root);
            return temp;
        }
        node_t* min_node = find_min(root->right);
        root->data = min_node->data;
        root->right = delete(root->right, min_node->data);
    }
    return root;
}

node_t* search(node_t* root, int data) {
    if (root == NULL || root->data == data)
        return root;
    if (data < root->data)
        return search(root->left, data);
    return search(root->right, data);
}

node_t* find_max(node_t* root) {
    if (root == NULL || root->right == NULL)
        return root;
    return find_max(root->right);
}

void inorder(node_t* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(node_t* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node_t* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int count_nodes(node_t* root) {
    if (root == NULL)
        return 0;
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}
int main() {
    node_t* root = NULL;

    // Insert some nodes to test the tree
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);

    // Display the tree using inorder traversal
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    // Test deleting a node
    root = delete(root, 10);
    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}