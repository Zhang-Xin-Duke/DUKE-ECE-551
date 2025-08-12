#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "BST.h"

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(void) {

	BST* tree = bst_create();

	bst_insert(tree, 9);
	bst_insert(tree, 42);
	bst_insert(tree, 5);
	bst_insert(tree, 3);
	bst_insert(tree, 13);
	bst_insert(tree, 57);

	// bst_inorder(tree);
	// bst_levelorder1(tree);

	// bst_delete(tree, 13);
	// bst_delete(tree, 5);
	// bst_delete(tree, 9);
	return 0;
}