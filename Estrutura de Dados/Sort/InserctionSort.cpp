void InserctionSort(int * V, int n)
{
    int i, j, x;
    // Percorre o array a partir do segundo elemento até o último.
    for(i=1; i<n; i++)
    {
        x=V[i]; // Armazena o valor do elemento atual para posterior inserção.
        // Percorre os elementos anteriores ao elemento atual e move-os uma posição à frente
        // caso sejam maiores que o elemento atual.
        for(j=i-1; j>=0 and x<V[j]; j--)
        {
            // Desloca o elemento uma posição à frente.
            V[j+1]=V[j];
        }
        // Insere o elemento atual na posição correta após o término do loop interno.
        V[j+1]=x;
    }
}