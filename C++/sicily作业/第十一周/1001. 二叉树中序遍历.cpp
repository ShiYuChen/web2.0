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
// ���������������
template <class Entry>
void inorder(Node<Entry> *root, void (*visit)(Entry &))
{
	if (root != NULL)
	{
		inorder(root->left, visit);
		(*visit)(root->entry);
		inorder(root->right, visit);
	}
}



