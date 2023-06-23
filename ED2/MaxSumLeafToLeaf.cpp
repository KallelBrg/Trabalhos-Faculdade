#include <bits/stdc++.h>

using namespace std;

#define pb push_back

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
    void pegafolha(vector<node<int>*> &folha);
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
void tree<coisa>::pegafolha(vector<node<int>*> &folha)
{
    queue<node<coisa>*> fila;
    node<coisa> *p=root;
    if(p!=NULL)
    {
        fila.push(p);
        while(!fila.empty())
        {
            p=fila.front();
            if(p->left == NULL && p->right == NULL)
            {
                folha.push_back(p);
            }
            fila.pop();
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
    cout << "\nDeletando Arvore..." << endl;
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

int indi;

void cc(node<int>*p, string str, map<int,string> &mp)
{
    if(p->left == NULL and p->right == NULL)
    {
		mp[indi++]= str;
	}
    else
    {
        cc(p->left, str+='0', mp);
        str.pop_back();
        cc(p->right, str+='1', mp);
    }
}

void c1(node<int>* p, string str, vector<node<int>*>&cam1)
{
    cam1.pb(p);
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='0')
        {
            p=p->left;
            cam1.pb(p);
        }
        else
        {
            p=p->right;
            cam1.pb(p);
        }
    }
}

void c2(node<int>* p, string str, vector<node<int>*>&cam2)
{
    cam2.pb(p);
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='0')
        {
            p=p->left;
            cam2.pb(p);
        }
        else
        {
            p=p->right;
            cam2.pb(p);
        }
    }
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
    vector<node<int>*> leaf;
    map<int,string> mp;
    vector<int>resposta;
    arvre.pegafolha(leaf);
    int sizeleaf=leaf.size();
    //No vector leaf agora so vai ter os nodes que são folhas.

    cc(arvre.root,"",mp);
    int k, sum, guardasoma=0;
    for(int i=0; i<sizeleaf-1; i++)
    {
        vector<node<int>*> cam1;
        string pickpath = mp[i];
        c1(arvre.root,pickpath,cam1);
        for(int j=i+1; j<sizeleaf; j++)
        {
            sum=0;
            vector<node<int>*> cam2;
            string pickpath2 = mp[j];
            c2(arvre.root,pickpath2,cam2);
            for(k=0; cam1[k]==cam2[k]; k++);
            k--;
            for(int kk=cam1.size()-1; kk>k; kk--)
            {
                sum+=cam1[kk]->key;
            }
            sum+=cam1[k]->key;
            for(int kk=cam2.size()-1; kk>k; kk--)
            {
                sum+=cam2[kk]->key;
            }
            if(sum > guardasoma)
            {
                resposta.clear();
                guardasoma=sum;
                for(int kk=cam1.size()-1; kk>k; kk--)
                {
                    resposta.pb(cam1[kk]->key);
                }
                resposta.pb(cam1[k]->key);
                for(int kk=k+1; kk<cam2.size(); kk++)
                {
                    resposta.pb(cam2[kk]->key);
                }
            }

        }

    }

    cout << "Os nodes folhas da arvore que possui o maior caminho sao " << resposta[0] << " e " << resposta[resposta.size()-1] << endl;
    cout << "E a soma do caminho eh = " << resposta[0];
    for(int i=1; i<resposta.size(); i++)
    {
        cout << " " << resposta[i];
    }
    cout << endl;
    cout << "Soma total = " << guardasoma << endl;



    return 0;
}
