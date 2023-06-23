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

class Stack{
public:
    int Size;
    Node* Top;
    
    Stack();
    bool push(int x);
    int pop();
    int top();
    bool empty();
    int size();
};

Stack::Stack(){
    Size=0;
    Top=NULL;
}
bool Stack::push(int x){
    Node* P=Node::MontaNode(x);
    if(!P) return false;
    P->Next=Top;
    Top=P;
    Size++;
    return true;
}
int Stack::pop(){
    int x;
    if(Top)
    {
		Node* P=Top;
		Top=Top->Next;
		x=Node::DesmontaNode(P);
		Size--;
	}
	return x;
}
int Stack::top(){
    int x;
    if(Top)x=Top->Data;
    return x;
}
bool Stack::empty(){
    return !Top;
}
int Stack::size(){
    return Size;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    Stack MyStack;
    for(int i=1; i<=15; i++){
        MyStack.push(i);
    }
    cout<<"Size: "<<MyStack.size()<<endl;
    while(!MyStack.empty()){
        cout<<MyStack.top()<<endl;
        MyStack.pop();
    }
}
