#include <iostream>
using namespace std;

struct BSTNode {
	int key;
	struct BSTNode *left, *right;
};

BSTNode* binary_tree_search(BSTNode* head, int data)
{
	BSTNode* temp = head;
	while (temp)
	{
		if(temp->key == data) return temp;
		else if (temp->key > data) temp = temp->left;
		else temp = temp->right;
	}
	return NULL;
}

int main()
{
	return 0;	
} 
