#pragma once
#include<iostream>
#include<fstream>
#include<stack>
#include<cmath>
using namespace std;
template<class T>
struct BinTreeNode
{
	T data;
	BinTreeNode<T>* leftChild, *rightChild;
	BinTreeNode():leftChild(nullptr),rightChild(nullptr){}
	BinTreeNode(T x, BinTreeNode<T>*l = nullptr, BinTreeNode<T>*r = nullptr)
		:data(x), leftChild(l), rightChild(r){}


};

template<class T>
class BinaryTree
{
public:
	BinaryTree() :root(nullptr) {}//����
	BinaryTree(T value) :RefValue(value), root(nullptr) {}//����
	BinaryTree(BinaryTree<T>&s);//���ƹ���
	~BinaryTree() { destroy(root); }//����
	bool isEmpty(){return(root == nullptr) ? true : false;}//�п�
	void Parent(BinTreeNode<T>*current,int &pos,BinTreeNode<T>*&parent)//����current���ڵ�,����֪currentΪ���������
	{
		if (root == nullptr || root == current)
		{
			pos = 0;
			parent = nullptr;
		}
		
		else
			Parent(root, current,pos,parent);
	}

	
	void CreateBinTree(ifstream &fin,BinTreeNode<T>*&subTree);//����
	void getLevel(BinTreeNode<T>* node, BinTreeNode<T>*subTree, int &level,int tempLevel = 1);//�����
	void Find(T x,BinTreeNode<T>*subTree,BinTreeNode<T>*&p);//�������в���ֵΪx�Ľڵ�

	void landscapeOutput(BinTreeNode<T>*subTree);//����������
	int Height(BinTreeNode<T>*subTree);//������
	void store(BinTreeNode<T>*p,T **&a);//�ǵݹ�ǰ����������洢���ά����
	int getVolumn(BinTreeNode<T>*p);//�õ�p����
	int Find(BinTreeNode<T>*subTree);//�������ж�Ϊ1�����


	BinTreeNode<T>* root;
	T RefValue;//the symbol to stop inputing


protected:


	



	void Parent(BinTreeNode<T>*subTree, BinTreeNode<T>*current,int&pos, BinTreeNode<T>*&parent);//��subTree��ʼ����������current���ڵ�

	void destroy(BinTreeNode<T>* &subTree);//destory


	BinTreeNode<T>* Copy(BinTreeNode<T>*orignode);

};





template<class T>
BinaryTree<T>::BinaryTree(BinaryTree<T>&s)
{
	root = Copy(s.root);
}

//destroy
template<class T>
void BinaryTree<T>::destroy(BinTreeNode<T>* &subTree)
{
	if (subTree != nullptr)
	{
		destroy(subTree->leftChild);
		destroy(subTree->rightChild);
		delete subTree;
	}
}



//copy
template<class T>
BinTreeNode<T>* BinaryTree<T>::Copy(BinTreeNode<T>*orignode)
{
	if (orignode == nullptr)
		return nullptr;
	BinTreeNode<T>* temp = new BinTreeNode<T>;
	temp->data = orignode->data;
	temp->leftChild = Copy(orignode->leftChild);
	temp->rightChild = Copy(orignode->rightChild);
	return temp;

}


//���ظ��ڵ�
template<class T>
void BinaryTree<T>::Parent(BinTreeNode<T>*subTree, BinTreeNode<T>* current,int&pos,BinTreeNode<T>*&parent)
{
	if (subTree != nullptr)
	{
		if (subTree->leftChild == current)
		{
			parent = subTree;
			pos = 1;
		}
		if (subTree->rightChild == current)
		{
			parent = subTree;
			pos = 2;
		}
		else
		{
			Parent(subTree->leftChild, current, pos, parent);
			Parent(subTree->rightChild, current, pos, parent);
		}
	}

}
//����
template<class T>
void BinaryTree<T>::CreateBinTree(ifstream &fin, BinTreeNode<T>*&subTree)
{
	T item;
	if (fin >> item)
	{
		if (item != RefValue)
		{
			subTree = new BinTreeNode<T>(item);
			if (subTree == nullptr)
			{
				cerr << "�洢�������" << endl;
				exit(1);
			}
			CreateBinTree(fin, subTree->leftChild);
			CreateBinTree(fin, subTree->rightChild);
		}
		else subTree = nullptr;
	}



}

//�����
template<class T>
void BinaryTree<T>::getLevel(BinTreeNode<T>* node, BinTreeNode<T>*subTree,int& level,int tempLevel)
{
	if (subTree != nullptr)
	{
		if (subTree->data == node->data)
			level = tempLevel;
		else
		{
			getLevel(node, subTree->leftChild, level,tempLevel + 1);
			getLevel(node, subTree->rightChild, level,tempLevel + 1);
		}
	}
}

//����
template<class T>
void BinaryTree<T>::Find(T x, BinTreeNode<T>*subTree,BinTreeNode<T>*&p)
{
	if (subTree != nullptr)
		if (subTree->data == x)
			p = subTree;
		else
		{
			Find(x,subTree->leftChild,p);
			Find(x, subTree->rightChild, p);
		}

	
}

//�������
template<class T>
void BinaryTree<T>::landscapeOutput(BinTreeNode<T>*subTree)
{
	if (subTree != nullptr)
	{
		landscapeOutput(subTree->rightChild);
		int level = 0;
		getLevel(subTree, root, level);
		for (int i = 0; i < level-1; i++)
		{
			cout << "  ";
		}
		cout << ".."<<subTree->data<<endl;
		landscapeOutput(subTree->leftChild);

	}
}

//������
template<class T>
int BinaryTree<T>::Height(BinTreeNode<T>*subTree)
{
	if (subTree == nullptr)
		return 0;
	else
	{
		int i = Height(subTree->leftChild);
		int j = Height(subTree->rightChild);
		return(i < j) ? j + 1 : i + 1;
	}
}
//������
template<class T>
void BinaryTree<T>::store(BinTreeNode<T>*p, T **&a)
{
	stack<BinTreeNode<T>*>S;
	p = root;
	S.push(nullptr);
	while (p != nullptr)
	{
		int level = 0;
		getLevel(p, root, level);
	
		int volumn = getVolumn(p)-1;
		
		a[level-1][volumn] = p->data;
		if (p->rightChild != nullptr)
			S.push(p->rightChild);
		if (p->leftChild != nullptr)
			p = p->leftChild;
		else
		{
			p = S.top();
			S.pop();
		}

	}

}

template<class T>
int BinaryTree<T>::getVolumn(BinTreeNode<T>*p)
{
	if (p==root)
		return 1;
	else
	{
		BinTreeNode<T>* parent;
		int pos = 0;
		Parent(p, pos, parent);
		if (pos == 1)
			return 2 * getVolumn(parent) - 1;
		if (pos == 2)
			return 2 * getVolumn(parent);
	}

}

template<class T>
int BinaryTree<T>::Find(BinTreeNode<T>*subTree)
{
	if (subTree->leftChild == nullptr&&subTree->rightChild == nullptr)
		return 0;
	else if (subTree->leftChild != nullptr&&subTree->rightChild == nullptr)
		return 1 + Find(subTree->leftChild);
	else if (subTree->leftChild == nullptr&&subTree->rightChild != nullptr)
		return 1 + Find(subTree->rightChild);
	else
		return Find(subTree->leftChild) + Find(subTree->rightChild);
}