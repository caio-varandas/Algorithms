typedef int Thing;
class Node
{
    public:
        int Key;
        Thing D;
        Node* left;
        Node* right;
        int fb;
        static Node* NodeMaker(int K, Thing D)
        {
            Node* P=new Node;
            if(P)
            {
                P->Key=K;
                P->D=D;
                P->left=NULL;
                P->right=NULL;
                P->fb=0;
            }
            return P;
        }
};
class AVLTree
{
    private:
        Node*Root;
        int N;
        static Node* Min(Node*P)
        { 
            if(!P->left)
            {
                return P;
            }
            return AVLTree::Min(P->left);
        }
        int altura(Node *N)
        {
            if(!N) return 0;
            return max(altura(N->left), altura(N->right))+1;
        }
       void Nivel(Node* P) 
        {
            int altura_total=altura(P);
            queue<pair<Node*, int>> q;
            q.push({Root, 1});
            queue<int>pegue;
            
            while(!q.empty()) 
            {
                int nivel=q.front().second;
                pegue.push(q.front().first->Key);
                if(q.front().first->left)
                {
                    q.push({q.front().first->left, nivel+1});
                }
                else
                {
                    if(nivel<altura_total)
                    {
                        Node* fantasma=Node::NodeMaker((nivel+1)*-1, 1);
                        q.push({fantasma, nivel+1});
                    }
                }
                if(q.front().first->right)
                {
                    q.push({q.front().first->right, nivel+1});
                }
                else
                {
                    if(nivel<altura_total)
                    {
                        Node* fantasma=Node::NodeMaker((nivel+1)*-1, 1);
                        q.push({fantasma, nivel+1});
                    }
                }
                q.pop();
            }
            int entre_nos=0;
            string espa2, espa1;
            for(int nivel = 1; nivel <= altura_total; nivel++)
            {
                //resetar o espaço antes
                espa1="";
                //quantos espaços devem ter o -1 e para não ter espaço adicional no primeiro nó
                int divisao_tela=pow(2, altura_total-nivel)-1;
                //antes do primeiro nó
                for(int j=0; j<divisao_tela; j++) 
                {
                    espa1+="   ";
                }
                //quantidade de nós daquele nivel
                int total=pow(2, nivel-1);
                //se eu não fizer isso ele vai bugar a impressão necessario imprimir o primeiro antes para imprimir os espaços de antes
                //se eu coloco junto do outro no ele repete os espaços e isso da errado e faltam espaços
                cout<<espa1;
                //se eu não tirar o primeiro nó primeiro ele buga
                if(pegue.front()>0)
                {
                    string espa=to_string(pegue.front());
                    if(espa.size()==1) cout<<" ";
                    if(espa.size()==2) cout<<" ";
                    cout<<espa;
                    if(espa.size()==1) cout<<" ";
                }
                else cout<<"   ";
                pegue.pop();
                for(int j=0; j<total-1; j++){
                    cout<<espa2;
                    if(pegue.front()>0)
                    {
                        string espa=to_string(pegue.front());
                        if(espa.size()==1) cout<<" ";
                        if(espa.size()==2) cout<<" ";
                        cout<<espa;
                        if(espa.size()==1) cout<<" ";
                    }
                    else cout<<"   ";
                    pegue.pop();
                }
                cout<<endl;
                entre_nos=divisao_tela;
                //resetar o espaço depois
                espa2="";
                for(int j=0; j<entre_nos; j++) 
                {
                    espa2+="   ";
                }
                cout<<endl;
            }
        }
        
    public:
        AVLTree()
        {
            Root=NULL;
            N=0;
        }
        void RSE(Node**R)
        {
            Node*a=*R;
            Node*b=a->right;
            a->right=b->left;
            b->left=a;
            if(b->fb==0)
            {
                a->fb=1;
                b->fb=-1;
            }
            else
            {
                a->fb=0;
                b->fb=0;
            }
            *R=b;
        }
        void RSD(Node**R)
        {
            Node*a=*R;
            Node*b=a->left;
            a->left=b->right;
            b->right=a;

            if(b->fb==0)
            {
                b->fb=1;
                a->fb=-1;
            }
            else
            {
                a->fb=0;
                b->fb=0;
            }
            *R=b;
        }
        void RDE(Node**R)
        {
            Node*a=*R;
            Node*b=a->right;
            Node*c=b->left;
            a->right=c->left;
            b->left=c->right;
            c->left=a;
            c->right=b;
            if(c->fb==-1)
            {
                a->fb=0;
                b->fb=1;
            }
            else
            {
                if(c->fb==1)
                {
                    a->fb=-1;
                    b->fb=0;
                }
                else
                {
                    a->fb=0;
                    b->fb=0;
                }
            }
            c->fb=0;
            *R=c;
        }
        void RDD(Node**R)
        {
            Node*a=*R;
            Node*b=a->left;
            Node*c=b->right;
            a->left=c->right;
            b->right=c->left;
            c->right=a;
            c->left=b;
            if(c->fb==-1)
            {
                a->fb=1;
                b->fb=0;
            }
            else
            {
                if(c->fb==1)
                {
                    a->fb=0;
                    b->fb=-1;
                }
                else
                {
                    a->fb=0;
                    b->fb=0;
                }
            }
            c->fb=0;
            *R=c;
        }
        bool Insert(Node**R, int K, Node*P)
        {
            if(!(*R))
            {
                *R=P;
                P->fb=0;
                return true;
            }
            if(K<(*R)->Key)
            {
                if(AVLTree::Insert(&(*R)->left, K, P))
                {
                    if((*R)->fb==0)
                    {
                        (*R)->fb=-1;
                        return true;
                    }
                    if((*R)->fb==1)
                    {
                        (*R)->fb=0;
                        return false;
                    }
                    if(((*R)->left)->fb==-1)
                    {
                        AVLTree::RSD(R);
                    }
                    else
                    {
                        AVLTree::RDD(R);
                    }
                    return false;
                }
                return false;
            }
            if(K>(*R)->Key)
            {
                if(AVLTree::Insert(&(*R)->right, K, P))
                {
                    if((*R)->fb==0)
                    {
                        (*R)->fb=1;
                        return true;
                    }
                    if((*R)->fb==-1)
                    {
                        (*R)->fb=0;
                        return false;
                    }
                    if(((*R)->right)->fb==1)
                    {
                        AVLTree::RSE(R);
                        return false;
                    }
                    AVLTree::RDE(R);
                    return false;
                }
                return false;
            }
        }
        void push(int K, Thing T)
        {
            Node*P=Node::NodeMaker(K, T);
            if(P)
            {
                AVLTree::Insert(&Root, K, P);
                N++;
            }
        }
        bool Erase(int K, Node**R)
        {
            if(!(*R))
            {
                return false;
            }
            if((*R)->Key==K)
            {
                if(!(*R)->left)
                {
                    Node*P=*R;
                    (*R)=(*R)->right;
                    delete P;
                    N--;
                    return true;
                }
                if(!(*R)->right)
                {
                    Node*P=*R;
                    (*R)=(*R)->left;
                    delete P;
                    N--;
                    return true;
                }
                Node*P=Min((*R)->right);
                swap((*R)->Key, P->Key);
                swap((*R)->D, P->D);
                if(Erase(K, &(*R)->right))
                {
                    if((*R)->fb==1)
                    {
                        (*R)->fb=0;
                        return true;
                    }
                    if((*R)->fb==0)
                    {
                        (*R)->fb=-1;
                        return false;
                    }
                    if(((*R)->left)->fb==-1)
                    {
                        AVLTree::RSD(R);
                        return true;
                    }
                    if(((*R)->left)->fb==0)
                    {
                        AVLTree::RSD(R);
                        return false;
                    }
                    AVLTree::RDD(R);
                    return true;
                }
                return false;
            }
            if(K<(*R)->Key)
            {
                if(Erase(K, &(*R)->left))
                {//excluir e reduzir
                    if((*R)->fb==-1)
                    {
                        (*R)->fb=0;
                        return true;
                    }
                    if((*R)->fb==0)
                    {
                        (*R)->fb=1;
                        return false;
                    }
                    //vai rotacionar
                    if(((*R)->right)->fb==1)
                    {
                        AVLTree::RSE(R);
                        return true;
                    }
                    if(((*R)->right)->fb==0)
                    {
                        AVLTree::RSE(R);
                        return false;
                    }
                    AVLTree::RDE(R);
                    return true;
                }
                return false;
            }
            if(Erase(K, &(*R)->right))
            {//excluir e reduzir
                if((*R)->fb==1)
                {
                    (*R)->fb=0;
                    return true;
                }
                if((*R)->fb==0)
                {
                    (*R)->fb=-1;
                    return false;
                }
                //vai rotacionar
                if(((*R)->left)->fb==-1)
                {
                    AVLTree::RSD(R);
                    return true;
                }
                if(((*R)->left)->fb==0)
                {
                    AVLTree::RSD(R);
                    return false;
                }
                AVLTree::RDD(R);
                return true;
            }
            return false;
        }
        void erase(int K){
            Erase(K, &Root);
        }
        void imprimePorNivel(){
            Nivel(Root);
        }
};