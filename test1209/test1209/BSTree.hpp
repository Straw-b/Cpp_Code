#pragma once


template<class T>
struct BSTNode
{
	BSTNode(const T& val = T())
	    : left(nullptr)
	    , right(nullptr)
	    , data(val)
	{}

	BSTNode<T>* left;
	BSTNode<T>* right;
	T data;
};


template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
public:
	BSTree()
		: root(nullptr)
	{}

	~BSTree()
	{
		_Destroy(root);
	}


	Node* Find(const T& data)
	{
		Node* cur = root;
		while (cur)
		{
			if (data == cur->data)
				return cur;
			else if (data < cur->data)
				cur = cur->left;
			else
				cur = cur->right;
		}

		return nullptr;
	}


	bool Insert(const T& data)
	{
		if (nullptr == root)
		{
			root = new Node(data);
			return true;
		}

		// BSTree非空
		// 1. 找待插入节点在树中的位置,并且需要记录其parent的位置
		Node* cur = root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (data == cur->data)
				return false;
			else if (data < cur->data)
				cur = cur->left;
			else
				cur = cur->right;
		}

		// 2. 插入新节点
		cur = new Node(data);
		if (data < parent->data)
			parent->left = cur;
		else
			parent->right = cur;

		return true;
	}


	// 需要使用中序遍历来验证：BSTree正确性
	void InOrder()
	{
		_InOrder(root);
	}


	bool Erase(const T& data)
	{
		if (nullptr == root)
		{
			return false;
		}

		// BSTree非空
		// 1. 找待删除节点在BSTree中的位置，并保存其双亲
		Node* cur = root;
		Node* parent = nullptr;
		while (cur)
		{
			if (data == cur->data)
				break;
			else if (data < cur->data)
			{
				parent = cur;
				cur = cur->left;
			}
			else
			{
				parent = cur;
				cur = cur->right;
			}
		}
		// 值为data的节点不存在
		if (nullptr == cur)
		{
			return false;
		}

		// 2. 删除节点
		// cur如果只有右孩子 或者 叶子节点
		if (nullptr == cur->left)
		{
			if (nullptr == parent)
			{
				root = cur->right;
			}
			else
			{
				if (cur == parent->left)
					parent->left = cur->right;
				else
					parent->right = cur->right;
			}
		}
		// cur只有左孩子
		else if (nullptr == cur->right)
		{
			
			if (nullptr == parent)
			{
				root = cur->left;
			}
			else
			{
				if (cur == parent->left)
					parent->left = cur->left;
				else
					parent->right = cur->left;
			}
		}
		// cur左右孩子均存在
		// 找替代节点--->假设：在右子树中替代节点
		else
		{
			Node* del = cur->right;
			parent = cur;
			while (del->left) // del的左为空找到替代节点
			{
				parent = del; // 先保存del的双亲
				del = del->left;
			}

			// 将替代节点中的值域交给之前要删除的cur
			cur->data = del->data;

			// 相当于变成要删除del
			if (del == parent->left)
				parent->left = del->right;
			else
				parent->right = del->right;

			cur = del;
		}

		delete cur;
		return true;
	}

private:
	void _InOrder(Node* pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->left);
			cout << pRoot->data << " ";
			_InOrder(pRoot->right);
		}
	}

	void _Destroy(Node*& pRoot) // 一级指针的引用
	{
		if (pRoot)
		{
			_Destroy(pRoot->left);
			_Destroy(pRoot->right);
			delete pRoot;
			pRoot = nullptr;
		}
	}

	//void _Destroy(Node** pRoot) // 传二级指针，复杂度高
	//{
	//	if (*pRoot)
	//	{
	//		_Destroy(&pRoot->left);
	//		_Destroy(&pRoot->right);
	//		delete pRoot;
	//		pRoot = nullptr;
	//	}
	//}

private:
	Node* root;
};


void TestBSTree()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };

	BSTree<int> t;
	for (auto e : a)
	{
		t.Insert(e);
	}

	t.InOrder();
}