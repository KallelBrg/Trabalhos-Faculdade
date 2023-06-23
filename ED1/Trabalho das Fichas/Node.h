template<typename trem> class node{
public:
	trem D;
	node* Next;
	static node* MontaNode(trem d);
	static trem DesmontaNode(node<trem>* P);
};

template <typename trem> node<trem>* node<trem> :: MontaNode(trem d){
	node* P=new node;
	if(P){
		P->D=d;
		P->Next=0;
	}
	return P;
	
}
template <typename trem> trem node<trem>:: DesmontaNode(node<trem>* P){
	trem x;
	if(P){
		x=P->D;
		delete P;
	}
	return x;
}
