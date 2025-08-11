typedef int Thing;

class Node
{
    public:
        int Key;
        Thing D;
        Node* left;
        Node* right;
        static Node* NodeMaker(int K, Thing D)
        {
            Node* P=new Node;
            if(P)
            {
                P->Key=K;
                P->D=D;
                P->left=NULL;
                P->right=NULL;
            }
            return P;
        }
};
class BBinTree
{
    private:
        Node* Root;
        int N, hl, hr;
        void Infixa(Node*R)
        {
            if(R)
            {
                Infixa(R->left);
                cout<<R->D<<" ";
                Infixa(R->right);
            }
        }
        int RHeight(Node*R)
        {
            //se ele for null
            if(!R)
            {
                return 0;
            }
            hl=RHeight(R->left);
            hr=RHeight(R->right);
            return max(hl, hr)+1;
        }
        void PosInfixa(Node*R)
        {
            if(R)
            {
                PosInfixa(R->left);
                PosInfixa(R->right);
                cout<<R->D<<" ";
            }
        }
        void Prefixa(Node*R)
        {
            if(R)
            {
                cout<<R->D<<" ";
                Prefixa(R->left);
                Prefixa(R->right);
            }
        }
        static void Clear(Node*R)
        {
            if(R)
            {
                BBinTree::Clear(R->left);
                BBinTree::Clear(R->right);
                delete R;
            }
        }
        static Node* Min(Node*P)
        {
            //Se o lado que eu cheguei não for null continua a busca
            if(!P->left)
            {
                return P;
            }
            //se for null o filho dele, faz a chamada recursiva para o nó esquerdo
            return BBinTree::Min(P->left);
        }
        static bool Erase(int K, Node**R)
        {
            if(!(*R))
            {
                return false;
            }
            if(K==(*R)->Key)
            {
                if(!(*R)->left)
                {//nao tem filho à esquerda sobe o filho da direita
                    Node*P=(*R);
                    *R=(*R)->right;
                    delete P;
                    return true;
                }
                //se eu cheguei aqui então ele tem filho na esquerda
                if(!(*R)->right)
                {//não tem filho na direita
                    Node*P=(*R);
                    *R=(*R)->left;
                    delete P;
                    return true;
                }
                Node*P=BBinTree::Min((*R)->right);
                swap((*R)->Key, P->Key);
                swap((*R)->D, P->D);
                return BBinTree::Erase(K, &((*R)->right));
            }
            if(K<(*R)->Key)
            {
                return BBinTree::Erase(K, &(*R)->left);
            }
            return BBinTree::Erase(K, &(*R)->right);
        }
    public:
        BBinTree()
        {
            Root=NULL;
            N=0;
        }
        bool Push(int K, Thing T)
        {
            Node*P=Node::NodeMaker(K, T);
            if(!P)
            {
                return false;
            }
            Node**R=&Root;
            while((*R))
            {
                if(P->Key<(*R)->Key)
                {
                    R=&((*R)->left);
                }
                else
                {
                    R=&((*R)->right);
                }
            }
            (*R)=P;
            N++;
            return true;
        }
        //a diferença daqui pro Thing*T
        //e que aqui eu tenho que buscar pelo endereço
        //então eu aponto la pro R da arvore
        
        //para eu fazer a busca eu preciso dos
        //endereços da arvore e o unico que tem o 
        //endereço de tudo e o Root ou seja eu crio um ponteiro que 
        //ira receber o root ou seja eu tenha acesso total 
        //a arvore sem mudar o root 
        bool BSearch(int K, Thing*T)
        {
            //Copia o endereço do root
            Node* R=Root;
            while(R and K!=R->Key)
            {
                if(K<R->Key)
                {
                    R=R->left;
                }
                else
                {
                    R=R->right;
                }
            }
            if(R)
            {
                *T=R->D;
                return true;
            }
            return false;
        }
        
        void bfs()
        {
            if(Root==NULL)
            {
                return;
            }
            queue<Node*>q;
            q.push(Root);
            while(!q.empty())
            {
                int level=q.size();
                Node*Q=q.front();
                for(int i=0; i<level; i++)
                {
                    Q=q.front();
                    q.pop();
                    if(Q)
                    {
                        cout<<Q->Key<<" ";
                        if(Q->left)
                        {//pergunta se o fio existe
                            q.push(Q->left);
                        }
                        else
                        {
                            q.push(NULL);
                        }
                        if(Q->right) 
                        {
                            q.push(Q->right);
                        }
                        else
                        {
                            q.push(NULL);
                        }
                        
                    }
                    else
                    {
                        cout<<" ";
                    }
                }
                cout<<endl;
            }
        }
        void Altura()
        {
            Node*R=Root;
            int altura=RHeight(R);
            cout<<"Receba altura: "<<altura<<'\n';
        }
        void imprimi()
        {
            Node*R=Root;
            Infixa(R);
        }
        void imprimi2()
        {
            Node*R=Root;
            Prefixa(R);
        }
        void imprimi3()
        {
            Node*R=Root;
            PosInfixa(R);
        }
        void clear()
        {
            BBinTree::Clear(Root);
            Root=NULL;
            N=0;
        }
        bool erase(int K)
        {
            if(BBinTree::Erase(K, &Root))
            {
                N--;
                return true;
            }
            return false;
        }
};