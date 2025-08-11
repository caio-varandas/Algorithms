template<typename thing>
class node
{
    public:
        thing data;
        node *next;
    
        static node* nodemake(thing d)
        {
            node* p=new node;
            if(p)
            {
                p->data=d;
                p->next=0;
            }
            return p;
        }
        static void desmontanode(node*p)
        {
            delete p;
        }
};

template<typename thing>
class stack
{
    private:
        node<thing>* TOP;
        int N;
    public:
        stack()
        {
            TOP=nullptr;
            N=0;
        }
        bool push(thing D)
        {
            node<thing>*p=node<thing>::nodemake(D);
            if(!p) return false;
            p->next=TOP;
            TOP=p;
            N++;
            return true;
        }
        void pop()
        {
           if(TOP)
           {
               node<thing>*p=TOP;
               TOP=TOP->next;
               delete p;
               N--;
           }
        }
        thing top()
        {
            return TOP->data;
        }
        int size()
        {
            return N;
        }
        bool empty()
        {
            return (!TOP);
        }
        void clear()
        {
            TOP=0;
        }
        ~stack()
        {
            node<thing>*p;
            while(TOP)
            {
                p=TOP;
                TOP=TOP->next;
                delete p;
            }
        }
};