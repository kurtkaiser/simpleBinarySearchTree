#ifndef TREE_H
#define TREE_H

# ifndef TYPE
# define TYPE void*
# endif

struct Tree;
void initTree(struct Tree *tree);
struct Tree *newTree();
int getLeafCount(struct Tree *tree);
struct Leaf *addLeaf(struct Leaf *node, TYPE value);
int searchTree(struct Tree *tree, TYPE value);
void printTree(struct Tree *tree);

#endif