// Kurt Kaiser
// kurtkaiser.us
// Simple Binary Search Tree

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "tree.h"

struct Leaf {
	TYPE value;
	struct Leaf *left;
	struct Leaf *right;
};

struct Tree {
	struct Leaf *root;
	int leafCount;
};

void initTree(struct Tree *tree) {
	tree->leafCount = 0;
	tree->root = 0;
}

struct Tree* newTree() {
	struct Tree *tree = (struct Tree*)malloc(sizeof(struct Tree));
	assert(tree != 0);
	initTree(tree);
	return tree;
}

int getLeafCount(struct Tree *tree) {
	return tree->leafCount;
}

struct Leaf *addLeaf(struct Leaf *node, TYPE newValue) {
	assert(newValue != NULL);
	struct Leaf *leaf = node;
	if (node == 0) {
		leaf = (struct Leaf*) malloc(sizeof(struct Leaf));
		leaf->value = newValue;
		leaf->right = 0;
		leaf->left = 0;
	}
	else if (node->value > newValue) {
		node->left = addLeaf(node->left, newValue);
	}
	else if (node->value < newValue) {
		node->right = addLeaf(node->right, newValue);
	}
	return leaf;
}

void addTree(struct Tree *tree, TYPE value) {
	tree->root = addLeaf(tree->root, value);
	tree->leafCount++;
}

int searchTree(struct Tree *tree, TYPE value) {
	assert(tree != 0 && value != NULL);
	struct Leaf *node = tree->root;
	while (node != 0) {
		if (node->value == value) {
			printf("Node Found: %d\n", value);
			return 1;
		}
		else if (node->value < value) {
			node = node->right;
		}
		else if (node->value > value) {
			node = node->left;
		}
	}
	return 0;
}

void printLeaf(struct Leaf *leaf) {
	if (leaf == 0) return;
	printf("[");
	printLeaf(leaf->left);
	printf(" %d ", leaf->value);
	printLeaf(leaf->right);
	printf("]");
}

void printTree(struct Tree *tree) {
	printLeaf(tree->root);
	printf("\n");
}

struct Tree *buildTree() {
	struct Tree *tree = newTree();
	addTree(tree, 19);
	addTree(tree, 8);
	addTree(tree, 53);
	addTree(tree, 44);
	addTree(tree, 12);
	addTree(tree, 22);
	addTree(tree, 14);
	addTree(tree, 111);
	return tree;
}

void testPrint(struct Tree *tree) {
	printf("Root: %d\n", tree->root->value);
	printf("Left of Root: %d\n", tree->root->left->value);
	printf("Left Right: %d\n", tree->root->left->right->value);
	printf("Left Right Right: %d\n", tree->root->left->right->right->value);
	printf("Right of Root: %d\n", tree->root->right->value);
	printf("Right Left: %d\n", tree->root->right->left->value);
	printf("Right Left Left: %d\n", tree->root->right->left->left->value);
	printf("Right Right: %d\n", tree->root->right->right->value);
}

int main() {
	printf("AVL Tree Program\n");
	struct Tree *oak = newTree();
	oak = buildTree();
	printTree(oak);

	searchTree(oak, 44);
	testPrint(oak);
	return 0;
}
