#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

int tabuleiro[TAM][TAM] = { 
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int navio1[3] = {3, 3, 3};
int navio2 [4] = {3, 3, 3, 3};
int navio3[5] = {3, 3, 3, 3, 3};

int espacoVazios()
{   int contador = 0;
    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            if(tabuleiro[i][j] == 0)
                contador++;
        }

    }
    return contador;
}

void ImprimeTabuleiro()
{
    for(int i = 0; i < TAM; i++)
    {
        printf("%d\t", i + 1);
        for(int j = 0; j < TAM; j++)
        {
            printf("%d ", tabuleiro[j][i]);
        }
        printf("\n");
    }
    printf("-\t");
    char letra = 'A';
    for (size_t i = 0; i < TAM; i++)
    {
        printf("%c ", letra);
        letra++;
    }
    
}
int ChecaEspacoNaHorizontal(int posx, int posy, int tamanho)
{
    if(posx + tamanho < TAM)
    {
        for(int i = 0; i < tamanho; i++)
        {
            if(tabuleiro[posx + i][posy] == 3)
            {
                return 0;
            }
        }
    }
    else return 0;

    return 1; //retorna 1 se houver espaço
}
void PoeNavioNaHorizontal(int *navio, int tamanho)
{
    int tentativas = 10;
    while (tentativas -- > 0)
    {
        int posx = rand() % TAM;
        int posy = rand() % TAM;
    
        //imprime na horizontal
        if(ChecaEspacoNaHorizontal(posx, posy, tamanho))
        {
            for(int i = 0; i < tamanho; i++)
            {
                tabuleiro[posx + i] [posy] = navio[i]; // 3 representa o navio, 0 a água
            }
            return;
        }else 
        {
            if(tentativas < 0)
                printf("Não foi possível inserio o návio");
        
        }
    }
    
    
    
}
int ChecaEspacoNaVertical(int posx, int posy, int tamanho)
{
    if(posy + tamanho < TAM)
    {
        for(int i = 0; i < tamanho; i++)
        {
             if(tabuleiro[posx][posy + i] == 3)
            {
                return 0;
            }
        }
    }
    else return 0;
    
    return 1; //retorna 1 se houver espaço
}
void PoeNavioNaVertical(int *navio, int tamanho)
{
    int tentativas = 10;
    while (tentativas -- > 0)
    {
        int posx = rand() % TAM;
        int posy = rand() % TAM;
    
        //imprime na vertical
        if(ChecaEspacoNaVertical(posx, posy, tamanho)) //checa se há espaço para o navio a partir da posição gerada aleatoriamente
        {
            for(int i = 0; i < tamanho; i++)
            {
                //Imprime no tabuleiro, o navio na posição vertical
                tabuleiro[posx] [posy + i] = navio[i]; // 3 representa o navio, 0 a água
            }
            return; //após imprimir encerra o laço
        }
        else 
        {
            if(tentativas == 0) 
                printf("Não foi possível inserir o návio");
        }   
    }
    
    
}
int ChecaEspacoNaDiagonal(int posx, int posy, int tamanho, int dx, int dy)//dx e dy admite 1 ou -1
{
    int nx = posx;
    int ny = posy;
       
        for(int i = 0; i < tamanho; i++)
        {
            if(nx < 0 || nx >= TAM  || ny < 0 || ny >= TAM) return 0;
            if(tabuleiro[nx][ny] == 3) return 0;
            nx += dx;
            ny += dy;
        }
    return 1;
}
//direção dx e dy suportam apenas um 1 ou -1
void PoeNavioNaDiagonal(int *navio, int tamanho, int dx, int dy) 
{
    int tentativas = 10;
    while (tentativas-- > 0)
    {
        int posx = rand() % TAM;
        int posy = rand() % TAM;
        if(ChecaEspacoNaDiagonal(posx, posy, tamanho, dx, dy))
        {
            for(int i = 0; i < tamanho; i++)
            {
                tabuleiro[posx][posy] = 3;
                posx += dx;
                posy += dy;
            }
            return;
        } else{
            if(tentativas == 0){
                printf("Não foi possível inserir o navio!\n");
            }
        }
    }
    
    
    

    
}

int main() {
    srand(time(0)); //Inicia a geração de numeros aleatórios a partir do horário de execução
    PoeNavioNaHorizontal(navio1, 3);
    PoeNavioNaVertical (navio2, 4);
    PoeNavioNaDiagonal(navio3, 5, 1, -1);
    ImprimeTabuleiro();
    return 0;
}
