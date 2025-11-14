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
};
template<typename thing>
class queue
{
    private:
        node<thing> *Head, *Tail;
        int N=0;
    public:
        queue()
        {
            Head=nullptr;
            Tail=nullptr;
            N=0;
        }
        bool push(thing D)
        {
            node<thing>*p=node<thing>::nodemake(D);
            if(!p) return 0;
            if(!Head) 
            {
                Tail=Head=p;
            }
            else
            {
                Tail->next=p;
                Tail=p;
                
            }
            N++;
            return true;
        }
        void pop()
        {
           if(Head)
           {
               node<thing>*p=Head;
               Head=Head->next;
               N--;
               delete p;
               if(!Head)
               {
                   Tail=Head;
               }
           }
        }
        thing front()
        {
            return Head->data;
        }
        int size()
        {
            return N;
        }
        bool empty()
        {
            return !Head;
        }
        void clear()
        {
            node<thing>*p=Head;
            while(Head)
            {
                Head=Head->next;
                delete p;
                p=Head;
            }
            N=0;
        }
        ~queue()
        {
            node<thing>*p=Head;
            while(Head)
            {
                Head=Head->next;
                delete p;
                p=Head;
            }
        }
};