#include "Stack.h"

template<typename trem>class Queue{
public:
	int N;
	node<trem>* Head;
	node<trem>* Tail;

	Queue();
	~Queue();
	bool push(trem x);
	trem pop();
	int size();
	bool empty();
	trem front();	
	void clear();
};

template <typename trem> Queue<trem>::Queue(){
	Head=Tail=0;
	N=0;
	
}

template <typename trem> Queue<trem>::~Queue(){
	node<trem>* P;
	while(Head){
		P=Head;
		Head=P->Next;
		node<trem>::DesmontaNode(P);
	}	
}

template <typename trem> bool Queue<trem>::push(trem x){
	node<trem>* P=node<trem>::MontaNode(x);
	if(!P){
		return false;
	}
	if(Head){
		Tail->Next=P;
	}
	else{
		Head=P;
	}
	Tail=P;
	Tail->Next=0;
	N++;
	return true;
}

template <typename trem>  trem Queue<trem>::pop(){
	trem x;
	if(Head){
		node<trem>* P=Head;
		Head=Head->Next;
		x=node<trem>::DesmontaNode(P);
		if(!Head){
			Tail=0;
		}
		N--;
	}
	return x;
}

template <typename trem> int Queue<trem>::size(){
	return N;
}

template <typename trem>  bool Queue<trem>::empty(){
	return !Head;
}

template <typename trem> trem Queue<trem>::front(){
	trem x;
	if(Head){
		x=Head->D;
	}
	return x;
}
template <typename trem> void Queue<trem>::clear(){
	node<trem>* P;
	while(Head){
		P=Head;
		Head=P->Next;
		node<trem>::DesmontaNode(P);
	}
	N=0;
}
