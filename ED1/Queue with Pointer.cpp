#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int Data;
    Node* Next;
    
    static Node* MontaNode(int Data);
    static int DesmontaNode(Node* Next);
};

Node* Node::MontaNode(int Dados){
    Node* ptr=new Node;
    if(ptr!=NULL){
        ptr->Data=Dados;
        ptr->Next=NULL;
    }
    return ptr;
}
int Node::DesmontaNode(Node* ptr){
    int x;
    if(ptr!=NULL){
        x=ptr->Data;
        delete ptr;
    }
    return x;
}

class Queue
{
public:
	Node* Head;
	Node* Tail;
	int N;
	
	Queue();
	~Queue();
	bool push(int x);
	int front();
	int pop();
	int size();
	bool empty();
	void clear();
};

Queue::Queue()
{
	Head=NULL;
	Tail=NULL;
	N=0;
}

Queue::~Queue()
{
	Node* P=Head;
	while(Head)
	{
		Head=P->Next;
		Node::DesmontaNode(P);
		P=Head;
	}
}	

int Queue::front()
{
	int x;
	if(Head) x=Head->Data;
	return x;
}

bool Queue::push(int x)
{
	Node* P=Node::MontaNode(x);
	if(!P)
	{
		return false;
	}
	if(Head)
	{
		Tail->Next=P;
	}
	else
	{
		Head=P;
	}
	Tail=P;
	Tail->Next=NULL;
	N++;
	return true;
}

void Queue::clear()
{
	Node* P=Head;
	while(Head)
	{
		Head=P->Next;
		Node::DesmontaNode(P);
		P=Head;
	}
	N=0;
	Tail=NULL;
}

int Queue::size()
{
	return N;
}

bool Queue::empty()
{
	return !Head;
}

int Queue::pop()
{
	int x;
	if(Head)
	{
		Node* P=Head;
		Head=Head->Next;
		x=Node::DesmontaNode(P);
		if(Head) Tail=NULL;
		N--;
	}
	return x;
}

int main()
{
	Queue Q;
	for(int i=1; i<=10; i++)
	{
		Q.push(i);
	}
	while(!Q.empty())
	{
		cout << Q.front() << endl;
		Q.pop();
	}
	if(Q.empty()) cout << "VAZIA" << endl;
    
}
