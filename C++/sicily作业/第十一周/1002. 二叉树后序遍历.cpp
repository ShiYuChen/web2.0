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
// �������ĺ������
template <class Entry>
void postorder(Node<Entry> *root, void (*visit)(Entry &))
{
	if (root != NULL)
	{
		postorder(root->left, visit);
		postorder(root->right, visit);
		(*visit)(root->entry);
	}
}



