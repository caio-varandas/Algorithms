class queue
{
    private:
        int *V;
        int N;
        int Head, Tail;
    
    public:
        queue(int tam);
        bool push (int D);
        void pop();
        int front();
        bool empty();
        void clear();
        int size();
        ~ queue();
};
queue::queue(int tam)
{
    N=tam+1;
    V=new int[N];
    Head=Tail=0;
}
bool queue::push(int D)
{
    if((Tail+1)%N==Head)
    return false;
    V[Tail]=D;
    Tail=(Tail+1)%N;
    return true;
    
}
void queue::pop()
{
    if(Tail!=Head)
    {
        Head=(Head+1)%N;
    }
}
int queue::front()
{
    return V[Head];
}
bool queue::empty()
{
    return Tail==Head;
}
void queue::clear()
{
    Head=Tail=0;
}
int queue::size()
{
    if(Head<=Tail)
    {
        return Tail-Head;
    }
    return N-(Tail-Head);
}
queue::~queue()
{
    delete[]V;
}