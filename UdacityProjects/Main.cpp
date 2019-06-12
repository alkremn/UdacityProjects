#include <iostream>


class Binary_tree
{
public:
	void Add(int num);
	//bool Search(int num) const;
	Binary_tree();
	~Binary_tree();

private:
	struct Node
	{
		int mData;
		Node* mLeft;
		Node* mRight;
		Node(int data, Node* left, Node* right) : mData(), mLeft(left), mRight(right) {}
		~Node();
	};
	void mAdd(Node* nodeP, Node* next);
	//bool mSearch(int num, Node* left, Node* right) const;
	Node* mRoot;
};

void Binary_tree::Add(int num)
{
	Node* newNode = new Node(num, nullptr, nullptr);
	mAdd(newNode, mRoot);
}

void Binary_tree::mAdd(Node* nodeP, Node* next)
{
	if (next && nodeP->mData < next->mData)
	{
		mAdd(nodeP, next->mLeft);
	}
	else if(next && nodeP->mData > next->mData)
	{
		mAdd(nodeP, next->mRight);
	}
	next = nodeP;
}

Binary_tree::Node::~Node()
{
	delete mLeft;
	delete mRight;
}
Binary_tree::~Binary_tree()
{
	delete mRoot;
}



