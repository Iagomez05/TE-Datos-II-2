//
// Created by Ian on 18/9/2024.
//

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

class BinarySearchTree {
public:
    struct BSTNode {
        int data;
        BSTNode* left;
        BSTNode* right;

        BSTNode(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    void inorderTraversal() const {
        inorderRecursive(root);
        std::cout << std::endl;
    }

private:
    BSTNode* root;

    BSTNode* insertRecursive(BSTNode* node, int value) {
        if (!node)
            return new BSTNode(value);

        if (value < node->data)
            node->left = insertRecursive(node->left, value);
        else
            node->right = insertRecursive(node->right, value);

        return node;
    }

    void inorderRecursive(BSTNode* node) const {
        if (node) {
            inorderRecursive(node->left);
            std::cout << node->data << " ";
            inorderRecursive(node->right);
        }
    }
};

#endif

