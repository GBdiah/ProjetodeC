#include <stdio.h>
#include <stdlib.h>

int x1,x2,y1,y2;
typedef enum{TRUE,FALSE} boolean;
int fim_do_jogo = FALSE;

typedef struct corpo_do_jogador{
    int play = 1;
    int pontos = 0;
}jogadores;

jogadores player1,player2;

player2.play=2;

int jogador = player1.play;

int resultado;

int map[6][6] = {
        {2,2,2,2,2,2},
        {2,2,2,2,2,2},
        {2,2,2,2,2,2},
        {2,2,2,2,2,2},
        {2,2,2,2,2,2},
        {2,2,2,2,2,2}
    };

int verifica(int x1, int y1,int x2,int y2,int map[][6]){//ESSA FUNÇÃO VAI VERIFICAR SE OS PONTOS ESCOLHIDOS SÃO PASSIVES DE
//DE LIGAMENTO.
        int ponto1 = map[x1][y1];
        int ponto2 = map[x2][y2];
        if(ponto1 == 2 || ponto2 == 2){
                map[x1][y1] = 1;
                map[x2][y2] = 1;
                return 1;//RETORNA 1 SE FOREM
        }
        else{
            return 0;//RETORNA 0 SE NÃO
        }
}
int Wjogador(int jogador,int x1,int y1,int x2,int y2,jogadores *player1,jogadores *player2){//ESSA FUNÇÃO VAI DETERMINAR SE QUEM VAI PROSSEGUIR NO JOGO É O JOGADOR 1 OU O 2
            int continua = quadrante(x1,y1,x2,y2,jogador,&player1,&player2);
            if (jogador == 1){
                if (continua == 1){
                jogador = 1;
                }
                else{
                    jogador = 2;
                }

            }
            else{
                if(continua == 1){
                    jogador == 2;
                }
                else{
                    jogador = 1;
                }
            return jogador;
}
}
//VAI VERIFICAR NO QUADRANTE SE ELE FECHOU O QUADRANTE. PS: NÃO TOQUE NELA ANIMAL.
int quadrante(int x1, int y1,int x2,int y2,int map[][6],int jogador,jogadores *player1,jogadores *player2){
    if(map[x1][y1] == 1 && map[x2][y2] == 1 && map[x1+6][y1+6] == 1 && map[x2+6][y2+6] == 1){
        if (jogador == 1){
            player1->pontos += 1;
        }
        else{
            player2->pontos += 1;
        }
        return 1;
    }
    else{
        return 0;
    }

}
void desenha(int x1,int x2,int y1,int y2,int map[][6]){
    int i,j,x,y,soma;
    for(i = 0; i<6; i++){
        for(j = 0; j<6;j++){
                x = map[i];
                y = map[j];
                soma = x+y;
                if(soma%2 == 0){
                    printf("o   ");
                }
                else{

                }
        }
        printf("\n\n");
    }
}
//======================================================================================================================
int main()
{

    while( fim_do_jogo == FALSE){
        desenha(x1,x2,y1,y2,map);
        printf("----------------------------");
        printf("Jogador %d",jogador);
        printf("----------------------------\n\n");
        printf("Posição do Traço, ponto 1(x,y): ");scanf("%d%d",&x1, &y1);
        printf("Ponto 2(x,y): ");scanf("%d%d",&x2, &y2);
        resultado = verificar(x1,y1,x2,y2, map);//CHAMA A FUNÇÃO QUE VERIFICA SE A LIGAÇÃO DE PONTOS É POSSIVEL
        if (resultado == 1){//SE FOR POSSIVEL ELE ADICIONA CHAMA...
                Wjogador(jogador,x1,y1,x2,y2,&player1,&player2);//...A FUNÇÃO SEM RETORNO Wjogador QUE POR SUA VEZ VERIFICA SE ELE COMPLETOU O QUADRANTE DAQUELE PONTO
                           // SE O QUADRANTE ESTIVER COMPLETO O JOGADOR CONTINUARÁ NA VEZ DELE E ADICIONARÁ +1PONTO NO JOGADOR DA
                           //VEZ.
            }
        else{//SE NÃO, ELE PEDE OUTRA VEZ QUE ELE DECLARE OS PONTOS
            printf("Digite outros ponto, ligação invalida, observe o atentamente o diagrama");
        }

    getchar();
    return 0;

}
}
