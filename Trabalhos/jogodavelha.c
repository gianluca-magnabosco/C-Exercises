# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define CLEARSCREEN  "\033[H\033[J"

int jogada_usuario(int lin, int col, char jog);
void jogada_computador(char jog, int nivel);
int menu();
void escolha_simb(char *jog1, char *jog2);
void inicializa_velha();
int verifica_ganhador(char jog);

void bot_basico();
void bot_intermediario();
void bot_avancado();
int primeira_jogada_computador(int i, int j, int lin, int col);
int habilidade_intermediaria_computador(int i, int j, int k, int m, int n, int p);
int habilidade_avancada_computador(int i, int j, int k, int m, int n, int p);
void solicitar_jogada(int num_jogador, char jog);
void imprimir_tabuleiro();
int checar_velha();
void tabela_posicoes();

char tabuleiro[3][3];
int opcao = 0;
int nivel = 0;
int ganhou = 0;
int perdeu = 0;
char jog1 = ' ';
char jog2 = ' ';
char jog = ' ';
char nivel_computador[14];


void main() {
    int opcao_selecionada;
    int num_jogador = 0;
    int i = 0;
    int velha = 0;

    opcao_selecionada = menu();

    if (opcao_selecionada == 1) {

        num_jogador = 1;

        escolha_simb(&jog1, &jog2);
        jog = jog1;
        inicializa_velha();

        do{
            solicitar_jogada(1, jog1);

            ganhou = verifica_ganhador(jog1);

            velha = checar_velha();

            if (velha == 1) {
                imprimir_tabuleiro();
                break;
            }

            if (ganhou == 1) {
                imprimir_tabuleiro();
                break;
            }

            jogada_computador(jog2, nivel);

            perdeu = verifica_ganhador(jog2);

            if (perdeu == 1) {
                imprimir_tabuleiro();
                break;
            }

            velha = checar_velha();

            if (velha == 1) {
                imprimir_tabuleiro();
                break;
            }

        } while ((ganhou != 1) || (perdeu == 1));
    }


    if (opcao_selecionada == 2) {
        escolha_simb(&jog1, &jog2);
        inicializa_velha();

        do{
            if (i % 2 == 0) {
                jog = jog1;
                num_jogador = 1;
            } else {
                jog = jog2;
                num_jogador = 2;
            }
            i++;

            imprimir_tabuleiro();
            solicitar_jogada(num_jogador, jog);

            ganhou = verifica_ganhador(jog);
            velha = checar_velha();
            
            if (velha == 1) {
                break;
            }

        } while (ganhou != 1);
    } 

    if ((ganhou == 1) && (perdeu != 1)) {
        imprimir_tabuleiro();
        printf("\n\nParabens jogador %d (%c), voce venceu!!!\n\n", num_jogador, jog);
        if (nivel != 0) {
            printf("Contra o computador no nivel %s!!!\n\n", nivel_computador);
        }
    } 

    if (perdeu == 1) {
        printf("\n\nGAME OVER !!!");
        printf("\nVoce perdeu para o computador no nivel %s!!!\n\n", nivel_computador);
    }

    if ((velha == 1) && (ganhou != 1)) {
        imprimir_tabuleiro();
        printf("\n\nDeu velha! Ninguem venceu!\n\n");
    }

}

// funcao menu
int menu() {
    int auxiliar = 0;
    int validar_escolha = 0;

    do{
        // limpar tela

        printf(CLEARSCREEN);
        printf("\n\n-----------MENU PRINCIPAL-----------\n");
        printf("1- Jogar contra computador\n");
        printf("2- Jogar contra humano\n");
        printf("3- Ver tabela de posicoes (Tutorial)\n");

        if (auxiliar != 0) {
            printf("\n\nDigite uma opcao valida!\n\n");
        }

        printf("\nSelecione a opcao desejada: ");
        scanf("%d", &opcao);
        

        if (opcao == 1) {

            auxiliar = 0;

            do{
        
                printf(CLEARSCREEN);
                printf("\n\nEscolhido: Jogar contra computador!\n\n");
                printf("Niveis de dificuldade do computador:\n");
                printf("1- Nivel basico\n");
                printf("2- Nivel intermediario\n");
                printf("3- Nivel avancado\n");

                if (validar_escolha != 0) {
                    printf("\n\nDigite uma opcao valida!\n\n");
                }

                printf("\nEscolha o nivel de dificuldade do computador: ");
                scanf("%d", &nivel);


                if (nivel == 1) {
                    // bot basico 
                    validar_escolha = 0;
                    break;
                }
                if (nivel == 2) {
                    // bot intermediario
                    validar_escolha = 0;
                    break;
                }
                if (nivel == 3) {
                    // bot avancado
                    validar_escolha = 0;
                    break;
                }
                if ((nivel != 1) && (nivel != 2) && (nivel != 3)) {
                    validar_escolha = 1;
                }
    
            } while ((nivel != 1) || (nivel != 2) || (nivel != 3));

            break;
        }

        if (opcao == 2) {
            auxiliar = 0;
            break;
        }

        if (opcao == 3) {
            auxiliar = 0;
            tabela_posicoes();
    
            printf(CLEARSCREEN);
        }

        if ((opcao != 1) && (opcao != 2) && (opcao != 3)) {
            auxiliar = 1;
        }

    } while ((opcao != 1) || (opcao != 2));
    
    // retorno da funcao menu
    return opcao;
}


void inicializa_velha() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}


void escolha_simb(char *jog1, char *jog2) {
    
    int escolha = 0;
    int validar = 0;

    do {

        printf(CLEARSCREEN);
        printf("\n\nEscolha o simbolo desejado para cada jogador: \n");
        printf("1- Jogador 1 (X) vs Jogador 2 (O)\n");
        printf("2- Jogador 1 (O) vs Jogador 2 (X)\n");

        if (nivel != 0) {
            printf("\nO COMPUTADOR SERA SEMPRE JOGADOR 2!!!\n");
        }

        if ((validar != 0)) {
            printf("\n\nDigite uma opcao valida!\n\n");
        }        

        printf("\nInsira uma opcao: ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            validar = 0;
            *jog1 = 'X';
            *jog2 = 'O';
            break;
        }
        if (escolha == 2) {
            validar = 0;
            *jog1 = 'O';
            *jog2 = 'X';
            break;
        }

        if ((escolha != 1) && (escolha != 2)) {
            validar = 1;
        }

    } while ((escolha != 1) || (escolha != 2));
}


int jogada_usuario(int lin, int col, char jog) {
    
    //if ((tabuleiro[lin][col] == 'O') || (tabuleiro[lin][col] == 'X')) {
    if (tabuleiro[lin][col] != ' ') {
        return 2;
    }  

    if ((lin < 0) || (lin > 2) || (col < 0) || (col > 2)) {
        return 1;
    }

    if ((lin < 3) && (col < 3) && (tabuleiro[lin][col] != 'O') && (tabuleiro[lin][col] != 'X')) {
        tabuleiro[lin][col] = jog;   
        return 0;  
    }
}


int verifica_ganhador(char jog) {

    // LINHAS
    if ((tabuleiro[0][0] == jog) && (tabuleiro[0][1] == jog) && (tabuleiro[0][2] == jog)) {
        return 1;
    }
    if ((tabuleiro[1][0] == jog) && (tabuleiro[1][1] == jog) && (tabuleiro[1][2] == jog)) {
        return 1;
    }
    if ((tabuleiro[2][0] == jog) && (tabuleiro[2][1] == jog) && (tabuleiro[2][2] == jog)) {
        return 1;
    }


    // COLUNAS
    if ((tabuleiro[0][0] == jog) && (tabuleiro[1][0] == jog) && (tabuleiro[2][0] == jog)) {
        return 1;
    }
    if ((tabuleiro[0][1] == jog) && (tabuleiro[1][1] == jog) && (tabuleiro[2][1] == jog)) {
        return 1;
    }
    if ((tabuleiro[0][2] == jog) && (tabuleiro[1][2] == jog) && (tabuleiro[2][2] == jog)) {
        return 1;
    }


    // DIAGONAIS
    if ((tabuleiro[0][0] == jog) && (tabuleiro[1][1] == jog) && (tabuleiro[2][2] == jog)) {
        return 1;
    }
    if ((tabuleiro[2][0] == jog) && (tabuleiro[1][1] == jog) && (tabuleiro[0][2] == jog)) {
        return 1;
    }

    return 0;
}


void jogada_computador(char jog, int nivel) {

    ///////////////// fazer bots
    if (nivel == 1) {
        strcpy(nivel_computador, "basico");
        bot_basico();
    }

    if (nivel == 2) {
        strcpy(nivel_computador, "intermediario");
        bot_intermediario();
    }

    if (nivel == 3) {
        strcpy(nivel_computador, "avancado");
        bot_avancado();
    }

    perdeu = verifica_ganhador(jog);

}


void bot_basico() {
    int lin = 0;
    int col = 0;
    int jogada = 0;

    do{ 
        imprimir_tabuleiro();

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tabuleiro[i][j] == ' ') {
                    lin = i;
                    col = j;
                    break;
                } else {
                    continue;
                }
            }
        }

        jogada = jogada_usuario(lin, col, jog2);

    } while (jogada != 0);
}


void bot_intermediario() {
    int jogada = 5;
    int contador = 0;
    int bloqueou = 5;

    do{ 
        imprimir_tabuleiro();

        if (contador == 0) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (tabuleiro[i][j] != ' ') {
                        contador++;
                    }
                }
            }
        }  

        if (contador == 1) {

            jogada = primeira_jogada_computador(0, 0, 2, 2);
            if (jogada == 0) {
                break;
            }

            jogada = primeira_jogada_computador(0, 1, 1, 0);
            if (jogada == 0) {
                break;
            }
            
            jogada = primeira_jogada_computador(0, 2, 2, 0);
            if (jogada == 0) {
                break;
            }

            jogada = primeira_jogada_computador(1, 0, 0, 1);
            if (jogada == 0) {
                break;
            }

            jogada = primeira_jogada_computador(1, 1, 0, 2);
            if (jogada == 0) {
                break;
            }

            jogada = primeira_jogada_computador(1, 2, 2, 1);
            if (jogada == 0) {
                break;
            }

            jogada = primeira_jogada_computador(2, 0, 0, 2);
            if (jogada == 0) {
                break;
            }

            jogada = primeira_jogada_computador(2, 1, 1, 2);
            if (jogada == 0) {
                break;
            }

            jogada = primeira_jogada_computador(2, 2, 0, 0);
            if (jogada == 0) {
                break;
            }
            
        } else {
            
            // LINHAS 0
            bloqueou = habilidade_intermediaria_computador(0, 0, 0, 1, 0, 2);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(0, 1, 0, 2, 0, 0);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(0, 2, 0, 0, 0, 1);
            if (bloqueou == 0) {
                break;
            }

            // LINHAS 1
            bloqueou = habilidade_intermediaria_computador(1, 0, 1, 1, 1, 2);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(1, 1, 1, 2, 1, 0);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(1, 2, 1, 0, 1, 1);
            if (bloqueou == 0) {
                break;
            }

            // LINHAS 2
            bloqueou = habilidade_intermediaria_computador(2, 0, 2, 1, 2, 2);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(2, 1, 2, 2, 2, 0);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(2, 2, 2, 0, 2, 1);
            if (bloqueou == 0) {
                break;
            }


            // COLUNAS 0
            bloqueou = habilidade_intermediaria_computador(0, 0, 1, 0, 2, 0);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(1, 0, 2, 0, 0, 0);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(2, 0, 0, 0, 1, 0);
            if (bloqueou == 0) {
                break;
            }

            // COLUNAS 1
            bloqueou = habilidade_intermediaria_computador(0, 1, 1, 1, 2, 1);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(1, 1, 2, 1, 0, 1);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(2, 1, 0, 1, 1, 1);
            if (bloqueou == 0) {
                break;
            }

            // COLUNAS 2
            bloqueou = habilidade_intermediaria_computador(0, 2, 1, 2, 2, 2);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(1, 2, 2, 2, 0, 2);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(2, 2, 0, 2, 1, 2);
            if (bloqueou == 0) {
                break;
            }


            // DIAGONAL 1
            bloqueou = habilidade_intermediaria_computador(0, 0, 1, 1, 2, 2);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(1, 1, 2, 2, 0, 0);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(2, 2, 0, 0, 1, 1);
            if (bloqueou == 0) {
                break;
            }
 
            // DIAGONAL 2
            bloqueou = habilidade_intermediaria_computador(0, 2, 1, 1, 2, 0);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(1, 1, 2, 0, 0, 2);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(2, 0, 0, 2, 1, 1);
            if (bloqueou == 0) {
                break;
            }
        }


        if (jogada != 0) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (tabuleiro[i][j] == ' ') {
                        jogada = jogada_usuario(i, j, jog2);
                        if (jogada == 0) {
                            break;
                        }
                    }
                }
                if (jogada == 0) {
                    break;
                }  
            }  
            if (jogada == 0) {
                break;
            }         
        }

    } while (jogada != 0);
}


void bot_avancado() {
    // fazer
    int jogada = 5;
    int bloqueou = 5;
    int contador = 0;
    int venceu = 5;

    do{ 

        imprimir_tabuleiro();

        // LINHAS 0
        venceu = habilidade_avancada_computador(0, 0, 0, 1, 0, 2);
        if (venceu == 0) {
            break;
        }
        venceu = habilidade_avancada_computador(0, 1, 0, 2, 0, 0);
        if (venceu == 0) {
            break;
        }
        venceu = habilidade_avancada_computador(0, 2, 0, 0, 0, 1);
        if (venceu == 0) {
            break;
        }

        // LINHAS 1
        venceu = habilidade_avancada_computador(1, 0, 1, 1, 1, 2);
        if (venceu == 0) {
            break;
        }
        venceu = habilidade_avancada_computador(1, 1, 1, 2, 1, 0);
        if (venceu == 0) {
            break;
        }
        venceu = habilidade_avancada_computador(1, 2, 1, 0, 1, 1);
        if (venceu == 0) {
            break;
        }

        // LINHAS 2
        venceu = habilidade_avancada_computador(2, 0, 2, 1, 2, 2);
        if (venceu == 0) {
            break;
        }
        venceu = habilidade_avancada_computador(2, 1, 2, 2, 2, 0);
        if (venceu == 0) {
            break;
        }
        venceu = habilidade_avancada_computador(2, 2, 2, 0, 2, 1);
        if (venceu == 0) {
            break;
        }


        // COLUNAS 0
        venceu = habilidade_avancada_computador(0, 0, 1, 0, 2, 0);
        if (venceu == 0) {
            break;
        }
        venceu = habilidade_avancada_computador(1, 0, 2, 0, 0, 0);
        if (venceu == 0) {
            break;
        }
        venceu = habilidade_avancada_computador(2, 0, 0, 0, 1, 0);
        if (venceu == 0) {
            break;
        }

        // COLUNAS 1
        venceu = habilidade_avancada_computador(0, 1, 1, 1, 2, 1);
        if (venceu == 0) {
            break;
        }
        venceu = habilidade_avancada_computador(1, 1, 2, 1, 0, 1);
        if (venceu == 0) {
            break;
        }
        venceu = habilidade_avancada_computador(2, 1, 0, 1, 1, 1);
        if (venceu == 0) {
            break;
        }

        // COLUNAS 2
        venceu = habilidade_avancada_computador(0, 2, 1, 2, 2, 2);
        if (venceu == 0) {
            break;
        }
        venceu = habilidade_avancada_computador(1, 2, 2, 2, 0, 2);
        if (venceu == 0) {
            break;
        }
        venceu = habilidade_avancada_computador(2, 2, 0, 2, 1, 2);
        if (venceu == 0) {
            break;
        }


        // DIAGONAL 1
        venceu = habilidade_avancada_computador(0, 0, 1, 1, 2, 2);
        if (venceu == 0) {
            break;
        }
        venceu = habilidade_avancada_computador(1, 1, 2, 2, 0, 0);
        if (venceu == 0) {
            break;
        }
        venceu = habilidade_avancada_computador(2, 2, 0, 0, 1, 1);
        if (venceu == 0) {
            break;
        }

        // DIAGONAL 2
        venceu = habilidade_avancada_computador(0, 2, 1, 1, 2, 0);
        if (venceu == 0) {
            break;
        }
        venceu = habilidade_avancada_computador(1, 1, 2, 0, 0, 2);
        if (venceu == 0) {
            break;
        }
        venceu = habilidade_avancada_computador(2, 0, 0, 2, 1, 1);
        if (venceu == 0) {
            break;
        }



        if (contador == 0) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (tabuleiro[i][j] != ' ') {
                        contador++;
                    }
                }
            }
        }  

        if (contador == 1) {

            jogada = primeira_jogada_computador(0, 0, 2, 2);
            if (jogada == 0) {
                break;
            }

            jogada = primeira_jogada_computador(0, 1, 1, 0);
            if (jogada == 0) {
                break;
            }
            
            jogada = primeira_jogada_computador(0, 2, 2, 0);
            if (jogada == 0) {
                break;
            }

            jogada = primeira_jogada_computador(1, 0, 0, 1);
            if (jogada == 0) {
                break;
            }

            jogada = primeira_jogada_computador(1, 1, 0, 2);
            if (jogada == 0) {
                break;
            }

            jogada = primeira_jogada_computador(1, 2, 2, 1);
            if (jogada == 0) {
                break;
            }

            jogada = primeira_jogada_computador(2, 0, 0, 2);
            if (jogada == 0) {
                break;
            }

            jogada = primeira_jogada_computador(2, 1, 1, 2);
            if (jogada == 0) {
                break;
            }

            jogada = primeira_jogada_computador(2, 2, 0, 0);
            if (jogada == 0) {
                break;
            }
            
        } else {

            // LINHAS 0
            bloqueou = habilidade_intermediaria_computador(0, 0, 0, 1, 0, 2);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(0, 1, 0, 2, 0, 0);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(0, 2, 0, 0, 0, 1);
            if (bloqueou == 0) {
                break;
            }

            // LINHAS 1
            bloqueou = habilidade_intermediaria_computador(1, 0, 1, 1, 1, 2);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(1, 1, 1, 2, 1, 0);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(1, 2, 1, 0, 1, 1);
            if (bloqueou == 0) {
                break;
            }

            // LINHAS 2
            bloqueou = habilidade_intermediaria_computador(2, 0, 2, 1, 2, 2);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(2, 1, 2, 2, 2, 0);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(2, 2, 2, 0, 2, 1);
            if (bloqueou == 0) {
                break;
            }


            // COLUNAS 0
            bloqueou = habilidade_intermediaria_computador(0, 0, 1, 0, 2, 0);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(1, 0, 2, 0, 0, 0);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(2, 0, 0, 0, 1, 0);
            if (bloqueou == 0) {
                break;
            }

            // COLUNAS 1
            bloqueou = habilidade_intermediaria_computador(0, 1, 1, 1, 2, 1);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(1, 1, 2, 1, 0, 1);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(2, 1, 0, 1, 1, 1);
            if (bloqueou == 0) {
                break;
            }

            // COLUNAS 2
            bloqueou = habilidade_intermediaria_computador(0, 2, 1, 2, 2, 2);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(1, 2, 2, 2, 0, 2);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(2, 2, 0, 2, 1, 2);
            if (bloqueou == 0) {
                break;
            }


            // DIAGONAL 1
            bloqueou = habilidade_intermediaria_computador(0, 0, 1, 1, 2, 2);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(1, 1, 2, 2, 0, 0);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(2, 2, 0, 0, 1, 1);
            if (bloqueou == 0) {
                break;
            }
 
            // DIAGONAL 2
            bloqueou = habilidade_intermediaria_computador(0, 2, 1, 1, 2, 0);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(1, 1, 2, 0, 0, 2);
            if (bloqueou == 0) {
                break;
            }
            bloqueou = habilidade_intermediaria_computador(2, 0, 0, 2, 1, 1);
            if (bloqueou == 0) {
                break;
            }
        }


        if (jogada != 0) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (tabuleiro[i][j] == ' ') {
                        jogada = jogada_usuario(i, j, jog2);
                        if (jogada == 0) {
                            break;
                        }
                    }
                }
                if (jogada == 0) {
                    break;
                }  
            }  
            if (jogada == 0) {
                break;
            }         
        }

    } while (jogada != 0);

}

int primeira_jogada_computador(int i, int j, int lin, int col) {
    int jogada;
    if (tabuleiro[i][j] == jog1) {
        jogada = jogada_usuario(lin, col, jog2); 
        return jogada;  
    } else {
        return 1;
    }
}


int habilidade_intermediaria_computador(int i, int j, int k, int m, int n, int p) {
    int jogada;
    if ((tabuleiro[i][j] == jog1) && (tabuleiro[k][m] == jog1) && (tabuleiro[n][p] == ' ')) {
        jogada = jogada_usuario(n, p, jog2);   
        return jogada;
    } else {
        return 1;
    }
}


int habilidade_avancada_computador(int i, int j, int k, int m, int n, int p){
    int jogada;
    if ((tabuleiro[i][j] == jog2) && (tabuleiro[k][m] == jog2) && (tabuleiro[n][p] == ' ')) {
        jogada = jogada_usuario(n, p, jog2);   
        return jogada;
    } else {
        return 1;
    }
}


void imprimir_tabuleiro() {
    printf(CLEARSCREEN);
    printf("\n _____________________________________\n");
    printf("|                                     |\n");
    printf("|            JOGO DA VELHA            |\n");
    printf("|_____________________________________|\n");
    printf("|                                     |\n");
    printf("|           [0]   [1]   [2]           |\n"); 
    printf("|          _____ _____ _____          |\n");
    printf("|         |     |     |     |         |\n");
    printf("|    [0]  |  %c  |  %c  |  %c  |  [0]    |\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("|         |_____|_____|_____|         |\n");
    printf("|         |     |     |     |         |\n");
    printf("|    [1]  |  %c  |  %c  |  %c  |  [1]    |\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("|         |_____|_____|_____|         |\n");
    printf("|         |     |     |     |         |\n");
    printf("|    [2]  |  %c  |  %c  |  %c  |  [2]    |\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    printf("|         |_____|_____|_____|         |\n");
    printf("|                                     |\n");
    printf("|           [0]   [1]   [2]           |\n"); 
    printf("|                                     |\n");
    printf("|_____________________________________|\n\n");
}


int checar_velha() {

    int count = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((tabuleiro[i][j] == 'O') || (tabuleiro[i][j] == 'X')) {
                count++;
            }
        }
    }

    if (count == 9) {
        return 1;
    } else {
        return 0;
    }
}


void tabela_posicoes() {
    printf(CLEARSCREEN);
    printf("\n _____________________________________\n");
    printf("|                                     |\n");
    printf("|               TUTORIAL              |\n");
    printf("|_____________________________________|\n");
    printf("|                                     |\n");
    printf("|           [0]   [1]   [2]           |\n"); 
    printf("|          _____ _____ _____          |\n");
    printf("|         |     |     |     |         |\n");
    printf("|    [0]  |(0,0)|(0,1)|(0,2)|  [0]    |\n");
    printf("|         |_____|_____|_____|         |\n");
    printf("|         |     |     |     |         |\n");
    printf("|    [1]  |(1,0)|(1,1)|(1,2)|  [1]    |\n");
    printf("|         |_____|_____|_____|         |\n");
    printf("|         |     |     |     |         |\n");
    printf("|    [2]  |(2,0)|(2,1)|(2,2)|  [2]    |\n");
    printf("|         |_____|_____|_____|         |\n");
    printf("|                                     |\n");
    printf("|           [0]   [1]   [2]           |\n"); 
    printf("|                                     |\n");
    printf("|_____________________________________|\n\n");    

    printf("\nPressione ENTER para retornar ao menu...");
    
    if (getchar() == '\n') {
        getchar();
        return;
    } else {
        getchar();
        return;
    }
}


void solicitar_jogada(int num_jogador, char jog) {

    int jogada = 0;
    int lin = 3;
    int col = 3;
    
    do{ 
        if ((jogada != 1) && (jogada != 2)) {
            imprimir_tabuleiro();  
        }
        printf("\nJOGADA DO JOGADOR %d (%c)\n", num_jogador, jog);
        printf("\nDigite a posicao correspondente a sua jogada (formato: [linha coluna]): ");
        scanf("%d %d", &lin, &col);

        // jogada usuario
        jogada = jogada_usuario(lin, col, jog);

        if (jogada == 1) {
            imprimir_tabuleiro();
            printf("\nEssa posicao nao existe!!!");
            printf("\nInsira uma posicao real!\n\n");
        }
        if (jogada == 2) {
            imprimir_tabuleiro();
            printf("\nEssa posicao ja esta preenchida!!!");
            printf("\nInsira uma posicao disponivel!\n\n");
        }
    } while (jogada != 0);
}