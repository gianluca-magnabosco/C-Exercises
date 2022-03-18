# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <ctype.h>

// matriz de strings
char *palavra[46] = {"None", "Amarelo", "Amendoim", "Banheiro", "Branco", "Cachorro", "Caneca", "Celular", "Dragao", "Elefante", "Eletrico", "Engenharia", "Felicidade", "Foton", "Geleia", "Girafa", "Helicoptero", "Hospital", "Indigena", "Jabuticaba", "Janela", "Kamikaze", "Laticinio", "Literatura", "Mangueira", "Melancia", "Novela", "Naufrago", "Origami", "Osteopata", "Perigoso", "Porteiro", "Questionario", "Rapido", "Respeito", "Samambaia", "Sorvete", "Tarantula", "Televisao", "Uniao", "Vassoura", "Vegetal", "Washington", "Xicara", "Youtube", "Zoologico"};

// prototipos de funcao
int menu();
void comecarJogo();
void gerarNumeroAleatorio(int *px);
void jogadaUsuario(char *palavra_atual, int tam, int *dano);
void listaPalavras();

// variavel global de opcao do menu
int opcao = 0;

// variavel global de vida
int vida = 6;

// funcao principal
void main(){
    // chamada da funcao menu e armazenamento de retorno da funcao menu
    int opcao_escolhida = menu();
    
    // opcao 3 do menu cai aqui
    system("cls");
    printf("\n\nJogo encerrado!");
    printf("\nVolte sempre!!!\n\n");
    system("pause");
}


int menu(){
    // limpar tela
    system("cls");

    // inicio menu
    printf("\n\n-----------MENU PRINCIPAL-----------\n");
    printf("1- Novo jogo\n");
    printf("2- Lista de palavras disponiveis\n");
    printf("3- Sair do jogo\n");
    printf("\nSelecione a opcao desejada: ");
    scanf("%d", &opcao);

    // switch case do menu
    switch(opcao){
        case 1:
            comecarJogo();
            break;
        case 2:
            listaPalavras();
            break;
        case 3:
            break;
        default:
            printf("\nDigite uma opcao valida!\n\n");
            opcao = menu();
    }

    // retorno da funcao menu
    return opcao;
}


// funcao para incializar jogo
void comecarJogo(){
    // variaveis locais
    int x = 0;
    int dano = 0;
    int tam = 0;

    // passagem de valor por referencia para funcao gerarNumeroAleatorio
    gerarNumeroAleatorio(&x);

    // declaracao da string palavra_atual que armazenara a palavra atual
    char palavra_atual[x];

    // insercao da palavra sorteada na string palavra_atual
    strcpy(palavra_atual, palavra[x]);

    // declaracao da variavel tam que contem o tamanho da string atual
    tam = strlen(palavra_atual) + 1;

    // passagem de parametros para funcao jogadaUsuario
    jogadaUsuario(palavra_atual, tam, &dano);
}



void jogadaUsuario(char *palavra_atual, int tam, int *dano){
    // variaveis locais
    char input_usuario = '1';
    char auxiliar[tam];
    int tamanho_da_palavra = strlen(palavra_atual) + 1;

    // declarando ultimo caractere da string auxiliar como \0
    auxiliar[tam-1] = '\0';

    // loop de conferencia e mostragem do estado atual do jogo
    do{
        // mostragem
        system("cls");
        printf("\nEscolha uma letra ou insira '1' para sair.\n");
        printf("\nPalavra: \n\n\n");

        // mostrar palavra de acordo com as letras ja acertadas
        for (int i = 0; i < tamanho_da_palavra; i++){
            if (auxiliar[i] == palavra_atual[i]){
                printf("%c ", toupper(auxiliar[i]));
            }else{
                printf("__ ");
            }
        }

        // mostrar barra de vida de acordo com numero de vidas
        printf("\n\n\nVida: [");
        for (int i = 0; i <= (vida * 4); i++){
            if (vida == 0){
                printf(" ");
                break;
            }else{
                printf("#");
            }
        }
        for (int i = (vida * 4); i < 24; i++){
            printf(" ");
        }
        printf("] %d vidas\n", vida);


        // conferencia se string auxiliar = palavra atual, se for encerra o jogo e mostra que venceu
        if (!strcmp(auxiliar, palavra_atual)){
            printf("\n\nParabens!!!!!!!\n");
            printf("Voce venceu!!!\n");
            printf("A palavra era: %s.\n\n", palavra_atual);
            break;
        }

        // conferencia se vidas ja acabaram, se sim, encerra o jogo e mostra que perdeu
        if (vida == 0){
            printf("\n\nGAME OVER\n");
            printf("Voce perdeu!\n");
            printf("A palavra era: %s.\n\n", palavra_atual);
            break;
        }


        // input do usuario
        printf("\n\nDigite uma letra: ");
        scanf("%*c%c", &input_usuario);
        
        printf("\n\n");
        
        input_usuario = toupper(input_usuario);


        // confere, compara e atualiza relacao entre input do usuario e palavra atual
        for (int i = 0; i < tamanho_da_palavra; i++){
            if ((toupper(palavra_atual[i]) != input_usuario) && (auxiliar[i] != palavra_atual[i])){
                auxiliar[i] = '0';
            }else{
                auxiliar[i] = palavra_atual[i];
            }
        }



        // decrementa a vida a cada erro
        *dano = 0;
        for (int i = 0; i < tamanho_da_palavra; i++){
            if ((toupper(palavra_atual[i]) != input_usuario)){
                (*dano)++;
            }
        }

        if (*dano == tamanho_da_palavra){
            vida--;
        }


    }while((vida >= 0) && (input_usuario != '1'));

    // pede para pressionar qualquer tecla para continuar
    system("pause");
    
    // volta para o menu apos pressionar qualquer tecla
    menu();
}


// funcao para geracao de numero aleatorio para pegar palavra aleatoria na matriz de strings
void gerarNumeroAleatorio(int *px){
    srand(time(0));
    *px = rand() % 46;
    if (*px == 0){
        *px = 1;
    }
}


// funcao para listagem de todas as palavras disponiveis no jogo
void listaPalavras(){
    int i = 1;
    
    system("cls");

    printf("\n----------------------------------------------------\n");
    printf("Lista de todas as palavras disponiveis nesse jogo: \n");

    do{
        printf("\n%s", palavra[i]); 
        i++;
    }while (i < 46);
    
    printf("\n------------------FIM DA LISTAGEM------------------\n\n");

    system("pause");
    menu();
}