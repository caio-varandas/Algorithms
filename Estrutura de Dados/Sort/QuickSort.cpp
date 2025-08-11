int q;
int Partition(int*V, int l, int r)
{
    //l left r right esquerda e direita
    //X representa o pivo o numero que comparado deve ser trocado
    //elementos da esquerda sao menores, da direita maiores ou iguais
    int X;
    X=V[l];
    while(l<r)
    {
        //Comparando os menores com o pivo e movimentando
        while(l<r and V[l]<X)
        {
            l++;
        }
        //Comparando os maiores com o pivo e movimentando
        while(l<r and V[r]>=X)
        {
            r--;
        }
        //aqui ocorre a troca caso as condições não sejam compridas de ambos os lados
        if(l<r)
        {
            swap(V[l], V[r]);
        }
    }
    return r;
}
void QuickSort(int*V, int l, int r)
{
    //Particion particionar, olhar imagem do whatsapp para entender
    if(l<r)
    {
        q=Partition(V,l, r);
        QuickSort(V, l, q);
        QuickSort(V, q+1, r);
    }
}