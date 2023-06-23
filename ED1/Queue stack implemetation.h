class StackVet
{
public:
	int* vet;
	int Top;
	int N;

public:
	StackVet (int n);
	bool push(int x);
	int top();
	void pop();
	int size();
	bool empty();
	bool full();
	~StackVet ();
};

class QueueOfStack
{
public:
	StackVet* stk1, * stk2;
	
public:
	QueueOfStack(int n);
	bool push(int x);
	void pop();
	int size();
	bool empty();
	int front();
	~QueueOfStack();
	
};
