void Merge(int*V, int i, int m, int f)
{
    int T=f-i+1, x, y, z;
    int A[T];
    for(x=i, y=m+1, z=0; x<=m and y<=f; z++)
    {
        if(V[x]<=V[y])
        {
            A[z]=V[x];
            x++;
        }
        else
        {
            A[z]=V[y];
            y++;
        }
    }
    for(;x<=m; x++, z++)
    {
        A[z]=V[x];
    }
    for(;y<=f; y++, z++)
    {
        A[z]=V[y];
    }
    for(x=0; x<T; x++)
    {
        V[i+x]=A[x];
    }
}
void MergeSort(int*V, int i, int f)
{
    int m;
    if(i<f)
    {
        m=(i+f)/2;
        MergeSort(V, i, m);
        MergeSort(V, m+1, f);
        Merge(V, i, m, f);
    }
}