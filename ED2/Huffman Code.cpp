#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

template <class T>
class node
{
public:
    T key;
    node<T>* left;
    node<T>* right;
    node()
    {
        left=right=0;
    }
    node(T d, node<T>* l=NULL, node<T>* r=NULL)
    {
        key=d;
        left=l;
        right=r;
    }
    //virtual ~node();

};

template <class coisa>
class tree
{
    public:
    node<coisa>* root;
    int n;
    tree();
    void insertItem(coisa);
    bool searchItemTree(coisa);
    void getMinMax(coisa &, coisa &);
    bool isEmpty();
    void clearTree();
    void breadthSearch();
    virtual ~tree();

    private:
    void clearNodes(node<coisa>*);
    bool searchItem(coisa,node<coisa>*);
    void visit(node<coisa>*);

};

template <class coisa>
tree<coisa>::tree()
{
    root=0;
    n=0;
}

template <class coisa>
tree<coisa>::~tree()
{
    clearTree();
}

template <class coisa>
void tree<coisa>::clearTree()
{
    clearNodes(root);
    root=NULL;
    n=0;
}

template <class coisa>
bool tree<coisa>::isEmpty()
{
    return root==NULL;
}

template <class coisa>
void tree<coisa>::insertItem(coisa dado)
{
    node<coisa> *p=root;
    node<coisa> *prev=NULL;
    if(isEmpty())
    {
        root=new node<coisa>(dado);
    }
    else
    {
        while(p!=NULL)
        {
            prev=p;
            if(prev->key < dado)
            {//direita
                p=p->right;
            }
            else
            {//esquerda
                p=p->left;
            }
        }
        if(prev->key < dado)
        {//direita
            prev->right = new node<coisa>(dado);
        }
        else
        {
            prev->left = new node<coisa>(dado);
        }
    }
    n++;
}

template <class coisa>
void tree<coisa>::visit(node<coisa>* p)
{
    cout << p->key.first << " ";
}

template <class coisa>
bool tree<coisa>::searchItem(coisa dado, node<coisa>* p)
{
    if(p==NULL) return false;

    if(dado==p->key) return true;

    if(dado<p->key)
    {
        searchItem(dado,p->left);
    }
    else
    {
        searchItem(dado,p->right);
    }
}

template <class coisa>
void tree<coisa>::getMinMax(coisa &minimo, coisa &maximo)
{
    node<coisa> *p=root;
    while(p->left!=NULL)
    {
        p=p->left;
    }
    minimo=p->key;
    p=root;
    while(p->right!=NULL)
    {
        p=p->right;
    }
    maximo=p->key;

}

template <class coisa>
void tree<coisa>::breadthSearch()
{
    queue<node<coisa>*> fila;
    node<coisa> *p=root;
    if(p!=NULL)
    {
        fila.push(p);
        while(!fila.empty())
        {
            p=fila.front();
            fila.pop();
            visit(p);
            if(p->left!=NULL)
            {
                fila.push(p->left);
            }
            if(p->right!=NULL)
            {
                fila.push(p->right);
            }
        }
    }
    else
        cout << "Arvore vazia" << endl;
}

template <class coisa>
void tree<coisa>::clearNodes(node<coisa> *p)
{
    queue<node<coisa>*> fila;
    //~ cout << "\nDeletando Arvore..." << endl;
    if(!isEmpty())
    {
        fila.push(p);
        while(!fila.empty())
        {
            p=fila.front();
            fila.pop();
            if(p->left!=NULL)
            {
                fila.push(p->left);
            }
            if(p->right!=NULL)
            {
                fila.push(p->right);
            }
            delete p;
            n--;
        }
    }
    else
        cout << "Arvore vazia" << endl;
}

template <class coisa>
bool tree<coisa>::searchItemTree(coisa dado)
{
    if(!isEmpty())
        return searchItem(dado,root);
    else
        return false;
}

void decodifica(node<pair<int,char>>* arvre, string str, map<char,string> &value)
{
    if(arvre->left == NULL and arvre->right == NULL)
    {
		value[arvre->key.second]= str;
	}
    else
    {
        decodifica(arvre->left, str+='0', value);
        str.pop_back();
        decodifica(arvre->right, str+='1', value);
    }
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    string str, txt="";
    getline(cin, str);
    for(int i=0; i<str.size(); i++) if(str[i]!=' ')txt+=str[i];
    // String txt com o texto sem espaços

    map<char,int> mp;
    map<char,int>::iterator it;
    for(int i=0; i<txt.size(); i++)
    {
        mp[txt[i]]++;
    } //Contar as letras.

    priority_queue<pair<int,char>, vector<pair<int,char>>, greater<pair<int,char>>> pq;
    for(it=mp.begin(); it!=mp.end(); it++)
    {
        pq.push({it->second,it->first});
    }//Colocando a frequencia e os respectivos char na priority queue
    vector<node<pair<int,char>>*> vec; //vector de ponteiro para node para ir guardando os nós e n perder o endereço
    while(pq.size()!=1)
    {
        int sum=0;
        node<pair<int,char> >* x;
        node<pair<int,char> >* y;
        node<pair<int,char> >* z;
        if(pq.top().second == '}')
        {
            bool ok=true;
            for(int i=0; i<vec.size() && ok; i++)
            {
                if(pq.top().first == vec[i]->key.first)
                {
                    x=vec[i];
                    vec.erase(vec.begin()+i);
                    ok=false;
                }
            }
        }
        else
        {
            x = new node<pair<int,char>>({pq.top().first,pq.top().second});
        }
        sum+=pq.top().first;
        pq.pop();
        if(pq.top().second == '}')
        {
            bool ok=true;
            for(int i=0; i<vec.size() && ok; i++)
            {
                if(pq.top().first == vec[i]->key.first)
                {
                    y=vec[i];
                    vec.erase(vec.begin()+i);
                    ok=false;
                }
            }
        }
        else
        {
            y = new node<pair<int,char>>({pq.top().first,pq.top().second});
        }
        sum+=pq.top().first;
        pq.pop();
        z = new node<pair<int,char>>({sum,'}'});
        if(x->key.second!='}' && y->key.second=='}')
        {
            z->left = y;
            z->right = x;
        }
        else
        {
            z->left = x;
            z->right = y;
        }
        vec.push_back(z);
        pq.push({sum,'}'});
    }
    tree<pair<int,char> > arvre;
    if(!vec.size())
    {
		vec.push_back(new node<pair<int,char>>({pq.top().first, pq.top().second}));
	} // Esse if eh para caso no arquivo de entrada tenha apenas um caracter ou o msm caracter repetidas vezes
    arvre.root = vec[0]; // No vector sobra apenas o ultimo nó que tem o endereço de todos os outros nodes, entao a raiz recebe esse node, logo a arvore tem acesso a todos os nos
	
	map<char,string> value;
	if(arvre.root->left == NULL && arvre.root->right == NULL)
	{
		value[pq.top().second] = "1";
	} // Se a arvore tiver apenas um node, significa que so tem 1 caracter, entao coloco a codificacao dele em 1
	else
	{
		decodifica(arvre.root,"",value); // funcao recursiva para decodificar e colocar no map
	}// se nao, significa q ela tem mais de 1 node, e chama o decodificador para colocar no map
    map<char,string>::iterator it2;
    cout << endl;
    cout << "## Tabela com os caracteres e seus respectivos codigos binarios ##" << endl << endl;
    
    for(it2=value.begin(); it2 != value.end(); it2++)
    {
        cout<< it2->first << " " << it2->second << "\n";
    } // imprimir a tabela decodificada, com os respectivos caracteres e seu codigo
    
    cout << endl;
	cout << "## Mensagem ja decodificada em binario ##" << endl << endl;
	
    for(int i=0; i<txt.size(); i++)
    {
        cout << value[txt[i]] << " ";
    } // imprimir a mensagem ja codificada

    return 0;
}
