# include <stdio.h>
# include <stdlib.h>

void main(){
    int num_jogados, i, empate, vitoria, derrota, gol_marcado, gol_sofrido;
    float media_marcados, media_sofridos, total_gols_marcados, total_gols_sofridos;

    empate = 0;
    vitoria = 0;
    derrota = 0;

    printf("Digite a quantidade de jogos jogados pela sua equipe no campeonato nacional: ");
    scanf("%d", &num_jogados);

    if (num_jogados > 0){
        for(i=0;i<num_jogados;i++){
            printf("\nJogo %d: \n",i+1);
            printf("Digite o numero de gols marcados: ");
            scanf("%d", &gol_marcado);

            printf("Digite o numero de gols sofridos: ");
            scanf("%d", &gol_sofrido);


            total_gols_marcados += gol_marcado;
            total_gols_sofridos += gol_sofrido;

            if (gol_marcado == gol_sofrido){
                empate++;
                continue;
            }
            if (gol_marcado > gol_sofrido){
                vitoria++;
                continue;
            }
            if (gol_marcado < gol_sofrido){
                derrota++;
                continue;
            }
        }

        media_marcados = total_gols_marcados/num_jogados;
        media_sofridos = total_gols_sofridos/num_jogados;

        printf("\nVitorias: %d\nEmpates: %d\nDerrotas: %d\n", vitoria, empate, derrota);
        printf("\nMedia de gols marcados por jogo: %.3f", media_marcados);
        printf("\nMedia de gols sofridos por jogo: %.3f\n\n", media_sofridos);

    }else
    printf("\nDigite um numero valido (inteiro e maior do que 0)!!!\n\n");
    
    system("pause");
}