#ifndef NODE
#define NODE
template <class Entry>
struct Node
{
         Entry entry;
         Node<Entry> *left;
         Node<Entry> *right;

};
#endif
// 二叉树的先序遍历
template <class Entry>
void preorder(Node<Entry> *root, void (*visit)(Entry &))
{
	if (root != NULL)
	{
		(*visit)(root->entry);
		preorder(root->left, visit);
		preorder(root->right, visit);
	}
}


