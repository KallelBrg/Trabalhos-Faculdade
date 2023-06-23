#include <bits/stdc++.h>

#define pb push_back

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
    void insertItem(vector<node<coisa>*> &dado, int tam);
    bool searchItemTree(coisa);
    void getMinMax(coisa &, coisa &);
    bool isEmpty();
    void clearTree();
    void breadthSearch();
    void espelho(node<coisa>*p, vector<int> &str);
    bool verifica(int);
    virtual ~tree();

    private:
    void clearNodes(node<coisa>*);
    bool searchItem(coisa,node<coisa>*);
    void visit(node<coisa>*);

};

template <class coisa>
bool tree<coisa>::verifica(int x)
{
	return pow(2, ceil(log2(x))) - 1 == x;
}

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
void tree<coisa>::espelho(node<coisa>*p, vector<int> &txt)
{
    if(p!=NULL)
    {
        espelho(p->left, txt);
        txt.push_back(p->key);
        espelho(p->right, txt);
    }
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
void tree<coisa>::insertItem(vector<node<coisa>*> &dado, int tam)
{
    root=dado[0];
    n++;
    int i=0, j=1;
    while(j<tam)
    {
        if(dado[i]->left == NULL)
        {
            dado[i]->left=dado[j++];
            n++;
        }
        else if(dado[i]->right == NULL)
        {
            dado[i]->right=dado[j++];
            n++;
        }
        else
        {
            i++;
        }
    }

}

template <class coisa>
void tree<coisa>::visit(node<coisa>* p)
{
    cout << p->key << " ";
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


int main()
{
	 cout << "Insira o numero de nodes que deseja colocar na arvre: ";
    int n; cin >> n;
    cout << endl;
    vector<node<int>*> vec;
    vector<int> str;
    for(int i=0; i<n; i++)
    {
        int x; cin >> x;
        node<int>* p=new node<int>(x);
        vec.pb(p);
    }
    tree<int> arvre;
    arvre.insertItem(vec,n); //Chama a o método para inserir os numeros na arvore
    //Inserção dos node na árvore por nível
    //arvre.breadthSearch();
    arvre.espelho(arvre.root, str);
    vector<int> aux=str;
    reverse(aux.begin(), aux.end());
    //cout << str << " " << aux << endl;
    if((aux == str && arvre.verifica(n)) || n==1) cout << "Espelhada\n";
    else cout << "Nao eh espelhada\n";
    
    return 0;
}
