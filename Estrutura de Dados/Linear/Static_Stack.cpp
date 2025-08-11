class stack
{
    private:
        int*V;
        int TOP;
        int n;
    public:
        bool push(int D);
        void pop();
        int top();
        bool empty();
        int size();
        void clear();
        stack(int Qt);
};
stack::stack(int Qt)
{
    V=new int[Qt];
    n=Qt;
    TOP=0;
}
bool stack::push(int D)
{
    if(TOP<n)
    {
        V[TOP]=D;
        TOP++;
        return true;
    }
    return false;
}
void stack::pop()
{
    if(TOP)
    {
        TOP--;
    }
}
int stack::top()
{
    if(TOP)
    {
        return V[TOP-1];
    }
    return V[0];
}
void stack::clear()
{
    TOP=0;
}
bool stack::empty()
{
    return !TOP;
}
int stack::size()
{
    return TOP;
}