#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1024


int main()
{
    int v[N];

        //n = quantidade de numeros no vetor dado pelo user ; i eh um contador
    int n,i;

    scanf("%d",&n);

        //enche o vetor
    srand((unsigned)time(NULL));
    for(i=0;i<n;i++)
        v[i]= ((rand()%201)-100);
    for(i=0;i<n;i++)
        printf("\n %d",v[i]);

        //maior = "pedacinho" dentro de um somatório antes dele ser redefinido
        //somatório inicializado fora do loop por isso i=1 (direita pq ele corre pra direita)
    int maior=0, somatorioDireita=v[0];

        //contadores pra fazer graça
    int inicio2=0,inicio=0,fim;

        //corre todo o vetor
    for(i=1;i<n;i++)
    {
            //se o novo "pedacinho"  do somatório for maior que o maior o maior eh redefinido
        if(v[i]<0 && somatorioDireita>maior)
        {
            maior  = somatorioDireita;
                //o v[i] termina a contagem do maior
            fim = i-1;
                //o inicio eh o inicio o somatorio q estava sendo contado
            inicio= inicio2;
        }
            //se o somatório for maior que zero ainda "vale a pena" voltar pra pegar os positivos, então nao eh preciso redefinir
        if(somatorioDireita>=0)
            somatorioDireita += v[i];
            //se o somatório eh menor que zero nao "vale mais a pena" voltar para pegar aqueles positivos deixados pra tras, então eh preciso redefinir o somatorio
        else
        {
            somatorioDireita=v[i];
                //o v[i] inicia a contagem do somatorio
            inicio2=i;
        }
    }

        //se o maior "pedacinho" dos somatorios anterios for maior que o ultimo somatorio printa maior
    if(maior>somatorioDireita)
    {
        printf("\n\n%d\n",maior);
        printf("inicio %d, fim %d\n",inicio,fim);

    for(i=inicio;i<=fim;i++)
        printf("%d, ",v[i]);
    }

    else
    {
        printf("\n\n%d\n",somatorioDireita);
            //se o somatorioDireita for o maior eh pq o maior somatorio eh pq o maior somatorio foi o que leu até o último número(indice n-1)
        printf("inicio %d, fim %d\n",inicio2,n-1);

    for(i=inicio2;i<=n-1;i++)
        printf("%d, ",v[i]);
    }

    return 0;
}
