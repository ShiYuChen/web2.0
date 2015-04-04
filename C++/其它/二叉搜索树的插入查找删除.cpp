void insert(Node*&root, const int&data) // ���� 
{
	Node* n = new Node(data);
	if (root == NULL) root = n;
	if (root->data > data) return insert(root->left, data);
	if (root->data < data) return insert(root->right, data);
}

Node* search(Node*root, const int&data)
{
	if (root == NULL || root->data == data) return root;
	if (root->data > data) return search(root->left, data);
	if (root->data < data) return search(root->right, data);
}

void remove(Node*&root) // ʹ������ 
{
	if (root == NULL) return;
	Node* del = root;
	if (root->right == NULL) root = root->left;
	else if (root->left == NULL) root = root->right;
	else //���������е����ֵ�ڵ� ��ֵ�������ڵ㣬ת�����ֵ�ڵ���������� ɾ�����ֵ�ڵ� 
	{
		del = root->left;
		Node* parent = root;
		while (del->right != NULL)
		{
			parent = del;
			del = del->right;
		}
		root->data = del->data;
		if (parent == root) root->left = del->left;
		else parent->right = del->left;
	}
	delete del;
}
