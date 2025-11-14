void BubbleSort(int * V, int n)
{
    int i, j, aux, k=1;
    for(i=0; i<n-1 and k; i++)
    {
        k=0;
        //n-i-1 serve para não comparar de novo
        //os elementos finais que ja foram trocados
        //os maiores
        for(j=0; j<n-i-1; j++)
        {
            if(V[j]>V[j+1])
            {
                swap(V[j], V[j+1]);
                k++;
            }
        }
    }
}