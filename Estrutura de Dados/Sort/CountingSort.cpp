void countingsort(int*V, int n, int max)
{
    int C[max+1]={0};
    int B[n];
    for(int i=0;i<n; i++)
    {
        C[V[i]]++;
    }
    for(int i=1;i<=max; i++)
    {
        C[i]=C[i-1]+C[i];
    }
    for(int i=n-1;i>=0; i--)
    {
        B[C[V[i]]-1]=V[i];
        C[V[i]]--;
    }
    for(int i=0;i<n; i++)
    {
        V[i]=B[i];
    }
}