#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tabuleiro[10][10] = { 
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

int espacoVazios()
{   int contador = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(tabuleiro[i][j] == 0)
                contador++;
        }

    }
    return contador;
}

void ImprimeTabuleiro()
{
    for(int i = 0; i < 10; i++)
    {
        printf("%d\t", i + 1);
        for(int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[j][i]);
        }
        printf("\n");
    }
    printf("-\t");
    char letra = 'A';
    for (size_t i = 0; i < 10; i++)
    {
        printf("%c ", letra);
        letra++;
    }
    
}
int ChecaEspacoNaHorizontal(int posX, int posY, int tamanho)
{
    if(posX + tamanho < 10)
    {
        for(int i = 0; i < tamanho; i++)
        {
            if(tabuleiro[posX + i][posY] == 3)
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
    
    int posX = rand() % 10;
    int posY = rand() % 10;
    
    //imprime na horizontal
    if(ChecaEspacoNaHorizontal(posX, posY, tamanho))
    {
        for(int i = 0; i < tamanho; i++)
        {
            tabuleiro[posX + i] [posY] = navio[i]; // 3 representa o navio, 0 a água
        }
    }else {
        if(tamanho < espacoVazios() && tentativas > 0)
        {
            tentativas--;
            PoeNavioNaHorizontal(navio, tamanho);
        }
        
     }
}
int ChecaEspacoNaVertical(int posX, int posY, int tamanho)
{
    if(posY + tamanho < 10)
    {
        for(int i = 0; i < tamanho; i++)
        {
             if(tabuleiro[posX][posY + i] == 3)
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
    
    int posX = rand() % 10;
    int posY = rand() % 10;
    
    //imprime na vertical
    if(ChecaEspacoNaVertical(posX, posY, tamanho)) //checa se há espaço para o navio a partir da posição gerada aleatoriamente
    {
        for(int i = 0; i < tamanho; i++)
        {
            //Imprime no tabuleiro, o navio na posição vertical
            tabuleiro[posX] [posY + i] = navio[i]; // 3 representa o navio, 0 a água
        }
    }else {
        if(tamanho < espacoVazios() && tentativas > 0) //os espaços vazios precisam ser maiores que o navio
        {
            tentativas--; //dez tentativas no máximo, evita erro de loop infinito
            PoeNavioNaVertical(navio, tamanho); //tenta inserir novamente o navio se falhar na primeira tentativa
        }
        
     }
}

int main() {
    srand(time(0)); //Inicia a geração de numeros aleatórios a partir do horário de execução
    PoeNavioNaHorizontal(navio1, 3);
    PoeNavioNaVertical (navio2, 4);
    ImprimeTabuleiro();
    return 0;
}
