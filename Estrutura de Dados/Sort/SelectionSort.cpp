void selectionSort(int * V, int n)
{
    int i, j, aux, menor;
    for(i=0; i<n-1; i++)
    {
        menor=i;
        for(j=i+1; j<n; j++)
        {
            if(V[j]<V[menor])
            {
                menor=j;
            }
        }
        aux=V[menor];
        V[menor]=V[i];
        V[i]=aux;
    }
}