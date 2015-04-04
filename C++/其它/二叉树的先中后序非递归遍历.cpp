void preorder(void(*visit)(Entry&))
{
	stack<Binary_node<entry>*>s;
	Binary_node<entry>*p = root;
	while (p || !s.empty())
	{
		while (p)
		{
			visit(p->entry);
			s.push(p);
			p = p->left;
		}
		p = s.top();
		s.pop();
		p = p->right;
	}
}

void inorder(void(*visit)(Entry&))
{
	stack<Binary_node<entry>*>s;
	Binary_node<entry>*p = root;
	while (p || !s.empty())
	{
		while (p)
		{
			s.push(p);
			p = p->left;
		}
		p = s.top();
		s.pop();
		visit(p->entry);
		p = p->right;
	}
}


void postorder(void (*visit)(entry&))
{
	int flag[20]; 
	stack<Binary_node<entry>*>s;
	Binary_node *p = root;

		while (p)
		{
			s.push(p);
			flag[s.size()] = 0;
			p = p->left;
		}
		while (!s.empty())
		{
			p = s.top();
			while (p->right && flag[s.size] == 0)
			{
				flag[s.size()] = 1;
				p = p->right;
				while (p)
				{
					s.push();
					flag[s.size()] = 0;
					p = p->left;
				}
			}
			p = s.top();
			visit(p->data);
			s.pop();			
		}
}
