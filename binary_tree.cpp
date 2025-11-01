#include <iostream>
using namespace std;

template <typename T>
class Node {
    public:
        T value;
        Node<T>* left;
        Node<T>* right;

    Node(T val): value(val), left(nullptr), right(nullptr) {}
};

template <typename T>
class Tree {
    public:
        Node<T>* root;

    Tree() {
        root = nullptr;
    }

    Node<T>* insert(Node<T>* node, T value) {
        if (node == nullptr) {
            return new Node<T>(value);
        }

        if (value < node->value) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    } 

    bool search(Node<T>* node, T value) {
        if (node == nullptr) {
            return false;
        }
        if (node->value == value) {
            return true;
        } else if (value < node->value) {
            return search(node->left, value);
        } else if (value > node->value) {
            return search(node->right, value);
        }
    }

    Node* findMin(Node<T>* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* findMax(Node<T>* node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    Node* remove(Node<T>* root, T value) {
        if (root == nullptr) {
            return root;
        }
        if (value < root->value) {
            root->left = remove(node->left, value);
        } else if (value > root->value) {
            root->right = remove(node->right, value);
        } else {
            if (root->left == nullptr) {
                Node<T>* tmp = root->right;
                delete root;
                return tmp;
            } else if (root->right == nullptr) {
                Node<T>* tmp = root->left;
                delete root;
                return tmp;
            }
        }
        Node<T>* tmp = findMin(root->right);
        root->value = tmp->value;
        root->right = remove(root->right, tmp->value);
    }

    void inOrderTraversal(Node<T>* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->value << " ";
            inOrderTraversal(node->right);
        }
    }

    void preOrderTraversal(Node<T>* node) {
        if (node != nullptr) {
            cout << node->value << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }

    void postOrderTraversal(Node<T>* node) {
        if (node != nullptr) {
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
            cout << node->value << " ";
        }
    }
};