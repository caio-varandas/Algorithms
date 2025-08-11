void heapify(int*V, int i, int n)
{
    int l, r, maior;
    l=2*i+1;
    r=2*i+2;
    maior=i;
    if(l<n)
    {
        if(V[l]>V[i])
        {
            maior=l;
        }
    }
    if(r<n)
    {
        if(V[r]>V[maior])
        {
            maior=r;
        }
    }
    if(maior!=i)
    {
        swap(V[i], V[maior]);
        heapify(V, maior, n);
    }
}
void build_max_heap(int*V, int n)
{
    for(int i=(n-2)/2; i>=0; i--)
    {
        heapify(V, i, n);
    }
}
void HeapSort(int*V, int n)
{
    build_max_heap(V, n);
    for(int i=n; i>0; i--)
    {
        swap(V[0], V[i-1]);
        heapify(V, 0, i-1);
    }
}