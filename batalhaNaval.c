#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 12

int tabuleiro[TAM][TAM] = { 
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int navio1[3] = {3, 3, 3};
int navio2 [4] = {3, 3, 3, 3};
int navio3[5] = {3, 3, 3, 3, 3};

int EspacoVazio()
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
    if(tamanho > EspacoVazio()) return 0;
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
    if(tamanho > EspacoVazio()) return 0;
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
    if(tamanho > EspacoVazio()) return 0;
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
int ChecaEspacoParaCone(int posx, int posy)
{
    int largura = 1;
    if(posx + 2 >= TAM || posx - 2 < 0 || posy + 2 >= TAM ) return 0;
    for(int i = 0; i < 3; i++)
    {
        int linha = posx - i;
        int coluna = posy + i;
        for(int j = 0; j < largura; j++)
        {
            if(linha + j >= TAM || coluna >= TAM || linha + j < 0 || coluna < 0) return 0;
            //verifica se há espaço vazio
            if(tabuleiro[linha + j] [coluna] != 0) return 0;
        }
        largura += 2;
    } 
    return 1;
}
void PoeCone()
{
    int tentativas = 30;
    while (tentativas-- > 0)
    {
        int posx = rand() % TAM;
        int posy = rand() % TAM;

        if(ChecaEspacoParaCone(posx, posy))
        {
            int largura = 1;
            for(int i = 0; i < 3; i++)
            {
                int linha = posx - i;
                int coluna = posy + i;
                for(int j = 0; j < largura; j++)
                {
                    tabuleiro[linha + j][coluna] = 1;
                }
                largura += 2;
            }
            return;
        } 
        else {
            if(tentativas == 0)
                printf("Não foi possível inserir o cone!\n");
        }
    }
}
int ChecaEspacoParaCruz(int posx, int posy)
{
    if(posx + 2 >= TAM || posx - 2 < 0 || posy + 2 >= TAM || posy - 2 < 0) return 0;
    for(int i = -2; i <= 2; i++)
    {
        if(tabuleiro[posx + i][posy] != 0) return 0; //verifica a linha
        if(tabuleiro[posx][posy + i] != 0) return 0; //verifica a coluna
    }
    return 1;
}
void PoeCruz()
{
    int tentativas = 30;
    while (tentativas-- > 0)
    {
        int posx = rand() % TAM;
        int posy = rand() % TAM;

        if(ChecaEspacoParaCruz(posx, posy))
        {
            for(int i = -2; i <= 2; i++)
            {
                tabuleiro[posx + i][posy] = 2; //imprime a linha
                tabuleiro[posx][posy + i] = 2; //imprime a coluna
            }
            return; //retorna após imprimir a cruz
        } else {
            if(tentativas == 0)
                printf("Não foi possível inserir a cruz!\n");
        }
    }
}
int ChecaEspacoParaOctaedro(int posx, int posy)
{
    int raio = 3;
    if(posx + raio >= TAM || posx - raio < 0 || posy + raio >= TAM || posy - raio < 0) return 0;     
    
    for(int i = -raio; i <= raio; i++)
    {
        int largura = raio - abs(i); //largura diminui conforme se afasta do
        for(int j = -largura; j <= largura; j++)
        {
            if(tabuleiro[posx + i][posy + j]) //verifica se há espaço vazio
            {
                return 0;
            }
        }      
    }
    return 1;
}
void PoeOctaedro()
{
    int tentativas = 30;
    while (tentativas-- >0)
    {
        int posx = rand() % TAM;
        int posy = rand() % TAM;

        if(ChecaEspacoParaCone(posx, posy))
        {
            int raio = 3;
            for(int i = -raio; i <= raio; i++)
            {
                int largura = raio - abs(i); //largura diminui conforme se afasta do centro
                for(int j = 0; j < largura; j++)
                {
                    tabuleiro[posx + i][posy + j] = 4; //imprime a parte superior do octaedro
                    tabuleiro[posx + i][posy - j] = 4; //imprime a parte inferior do octaedro
                }

            }  
            
            return;
        } 
        else {
            if(tentativas == 0)
                printf("Não foi possível inserir o octaedro!\n");
        }
    }
}
int main() {
    srand(time(0)); //Inicia a geração de numeros aleatórios a partir do horário de execução
    //PoeNavioNaHorizontal(navio1, 3);
    //PoeNavioNaVertical (navio2, 4);
    //PoeNavioNaDiagonal(navio3, 5, 1, -1);
    PoeCone();
    PoeCruz();
    PoeOctaedro();
    ImprimeTabuleiro();
    return 0;
}
