
#include "Node.h"


template<typename trem>class Stack{
public:
	int N;
	node<trem>* Top;
	
	Stack();
	~Stack();
	bool push(trem x);
	trem pop();
	int size();
	bool empty();
	trem top();	
	void clear();
};

template <typename trem> Stack<trem>::Stack(){
	Top=0;
	N=0;
	
}

template <typename trem> Stack<trem>::~Stack(){
	node<trem>* P;
	while(Top){
		P=Top;
		Top=Top->Next;
		node<trem>::DesmontaNode(P);
	}	
}

template <typename trem> bool Stack<trem>::push(trem x){
	node<trem>* P=node<trem>::MontaNode(x);
	if(!P){
		return false;
	}
	P->Next=Top;
	Top=P;
	N++;
	return true;
}

template <typename trem>  trem Stack<trem>::pop(){
	trem x;
	if(Top){
		node<trem>* P=Top;
		Top=P->Next;
		x=node<trem>::DesmontaNode(P);
		N--;
	}
	return x;
}

template <typename trem> int Stack<trem>::size(){
	return N;
}

template <typename trem>  bool Stack<trem>::empty(){
	return !Top;
}

template <typename trem> trem Stack<trem>::top(){
	trem x;
	if(Top){
		x=Top->D;
	}
	return x;
}
template <typename trem> void Stack<trem>::clear(){
	node<trem>* P;
	while(Top){
		P=Top;
		Top=Top->Next;
		node<trem>::DesmontaNode(P);
	}
	N=0;
}
