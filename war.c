//nivel mestre

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// validação de numeros inteiros
int ler_inteiro() {
    int num;
    char c;
    while (1) {
        if (scanf("%d", &num) == 1) {  
            return num;
        }
        else {
            printf("Entrada inválida! Digite um número válido: ");
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }
}

//struct do territorio
struct territorio 
{
    char nome[30];
    char cor[10];
    int *tropas; //aqui no * que vamos usar no calloc depois
};

//cadastramento de territorios, tropas tem que ter mais de 1 se náo ele nao deixa prosseguir
void cadastrar_territorios(struct territorio *terri) {

    for (int i = 0; i < 5; i++) {

        printf("\nCadastro de território %d\n", i + 1);

        printf("Nome: ");
        scanf("%s", terri[i].nome);

        printf("Cor: ");
        scanf("%s", terri[i].cor);

        // alocando a tropa com calloc
        terri[i].tropas = calloc(1, sizeof(int));

        // validação pra nao dar erro se digitar letras
        do {
            printf("Numero de tropas (min 1): ");
            *terri[i].tropas = ler_inteiro();

            if (*terri[i].tropas < 1)
                printf("Valor inválido! Tropas devem ser >= 1.\n");

        } while (*terri[i].tropas < 1);
    }
}

//mapa mundi em ascii pra dar um visual legal
void exibir_mapa(struct territorio territorios[5]) {

    // --- sua arte inteira mantida ---
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣄⣠⣀⡀⣀⣠⣤⣤⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣄⢠⣠⣼⣿⣿⣿⣟⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⢠⣤⣦⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⢦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣟⣾⣿⣽⣿⣿⣅⠈⠉⠻⣿⣿⣿⣿⣿⡿⠇⠀⠀⠀⠀⠀⠉⠀⠀⠀⠀⠀⢀⡶⠒⢉⡀⢠⣤⣶⣶⣿⣷⣆⣀⡀⠀⢲⣖⠒⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⢀⣤⣾⣶⣦⣤⣤⣶⣿⣿⣿⣿⣿⣿⣽⡿⠻⣷⣀⠀⢻⣿⣿⣿⡿⠟⠀⠀⠀⠀⠀⠀⣤⣶⣶⣤⣀⣀⣬⣷⣦⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣦⣤⣦⣼⣀⠀\n");
    printf("⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠓⣿⣿⠟⠁⠘⣿⡟⠁⠀⠘⠛⠁⠀⠀⢠⣾⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠏⠙⠁\n");
    printf("⠀⠸⠟⠋⠀⠈⠙⣿⣿⣿⣿⣿⣿⣷⣦⡄⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⣼⣆⢘⣿⣯⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡉⠉⢱⡿⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⡿⠦⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⡗⠀⠈⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣉⣿⡿⢿⢷⣾⣾⣿⣞⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠋⣠⠟⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⠿⠿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣾⣿⣿⣷⣦⣶⣦⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠈⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⣿⣤⡖⠛⠶⠤⡀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠙⣿⣿⠿⢻⣿⣿⡿⠋⢩⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠧⣤⣦⣤⣄⡀⠀⠀⠀⠀⠀⠘⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠘⣧⠀⠈⣹⡻⠇⢀⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⣿⣿⣿⣤⣀⡀⠀⠀⠀⠀⠀⠀⠈⢽⣿⣿⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠹⣷⣴⣿⣷⢲⣦⣤⡀⢀⡀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿⣿⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣷⢀⡄⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠂⠛⣆⣤⡜⣟⠋⠙⠂⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣿⣿⠉⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣾⣿⣿⣿⣿⣆⠀⠰⠄⠀⠉⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⠿⠿⣿⣿⣿⠇⠀⠀⢀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⡿⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⡇⠀⠀⢀⣼⠗⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠃⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠁⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠒⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");

    printf("\n    ====================================================    \n");
    printf("\n    |> > > > > > >> > MAPA MUNDI WAR < < < < < < < < < |    \n");
    printf("\n    ====================++++++++++======================    \n");

    for (int i = 0; i < 5; i++) {
        printf(" %d .%s    |>>  Exército %s    |>> Tropas: %d\n",
            i + 1,
            territorios[i].nome,
            territorios[i].cor,
            *territorios[i].tropas // aqui tem que usar * por causa do calloc
        );
    }
}

//função que mostra o placar quando a pessoa seleciona o menu depois do cadastro
void mostrar_placar(struct territorio t[5]) {
    printf("\n========== PLACAR ==========\n");
    for (int i = 0; i < 5; i++) {
        printf("%s (%s) -> %d tropas\n",
               t[i].nome, t[i].cor, *t[i].tropas);
    }
    printf("===========================\n");
}

//aqui é onde mostramos a missão sorteada(bem simples mesmo)
void mostrar_missao(int tipo, char cor_alvo[10]) {

    printf("\n========== MISSÃO ==========\n");

    if (tipo == 1) {
        printf("Missão: Eliminar a cor: %s\n", cor_alvo);
    }
    else {
        printf("Missão: Eliminar 2 países (2 territórios zerados)\n");
    }

    printf("===========================\n");
}
//validando se a missão foi cumprida
int checar_missao(struct territorio t[5], int tipo, char cor_alvo[10]) {

    if (tipo == 1) {
        // missão 1: eliminar uma cor
        for (int i = 0; i < 5; i++) {
            if (strcmp(t[i].cor, cor_alvo) == 0) {
                if (*t[i].tropas > 0)
                    return 0;  // ainda não eliminou a cor
            }
        }
        return 1;  // eliminação concluída
    }
    else {
        // missão 2: zerar 2 territórios
        int mortos = 0;
        for (int i = 0; i < 5; i++) {
            if (*t[i].tropas == 0)
                mortos++;
        }
        if (mortos >= 2) return 1;
        return 0;
    }
}

//funcao da batalha, com validação se ataca exercito zerado ou a si mesmo
void batalha(struct territorio territorios[5], int tipo_missao, char cor_alvo[10]) {

    int a, d; 
    char pausa;

    while (1) {

        printf("\nQual país vai atacar (1 a 5)? ");
        a = ler_inteiro();

        printf("Quem defende (1 a 5)? ");
        d = ler_inteiro();

        // validacoes, a seleção nao pode sair da faixa de paises cadastrados entre 1 e 5 apenas
        if (a < 1 || a > 5 || d < 1 || d > 5) {
            printf("Numero inválido!\n");
            continue;
        }

        if (a == d) {
            printf("Um país não pode atacar ele mesmo!\n");
            continue;
        }

        if (*territorios[a-1].tropas == 0) {
            printf("O atacante está destruído!\n");
            continue;
        }

        if (*territorios[d-1].tropas == 0) {
            printf("O defensor já está destruído!\n");
            continue;
        }

        a--; d--;

        int dado1 = rand() % 6 + 1;
        int dado2 = rand() % 6 + 1;

        printf("\nDado atacante: %d\n", dado1);
        printf("Dado defensor: %d\n", dado2);

        if (dado1 > dado2) {
            (*territorios[d].tropas)--;
            if (*territorios[d].tropas < 0) 
                *territorios[d].tropas = 0;
            printf("Atacante venceu!\n");
        } 
        else if (dado2 > dado1) {
            (*territorios[a].tropas)--;
            if (*territorios[a].tropas < 0) 
                *territorios[a].tropas = 0;
            printf("Defensor venceu!\n");
        } 
        else {
            printf("Empate\n");
        }

        // mostrar mapa após ataque
        exibir_mapa(territorios);

        // checar missão
        if (checar_missao(territorios, tipo_missao, cor_alvo)) {
            printf("\nPARABÉNS !!! MISSÃO CUMPRIDA!!!\n");
        }

        printf("\nPressione ENTER para voltar ao menu...");
        while ((pausa = getchar()) != '\n');
        return; // volta ao menu
    }
}

//Main com as funçoes para rodar o codigo
int main() {

    srand(time(NULL));

    struct territorio territorios[5];

    // cadastro inicial
    cadastrar_territorios(territorios);

    exibir_mapa(territorios);
    
    //gerar a missao
    int tipo_missao = (rand() % 2) + 1; // 1 ou 2
    char cor_alvo[10];

    if (tipo_missao == 1) {
        int sorteio = rand() % 5;
        strcpy(cor_alvo, territorios[sorteio].cor);
    }
    //menu com as opcoes
    int opcao = 0;

    while (opcao != 4) {

        printf("\n=========== MENU ===========\n");
        printf("1 - Atacar\n");
        printf("2 - Mostrar Missão\n");
        printf("3 - Mostrar Placar\n");
        printf("4 - Sair\n");
        printf("============================\n");
        printf("Escolha: ");

        opcao = ler_inteiro(); //validando os dados inseridos novamente

        if (opcao == 1)
            batalha(territorios, tipo_missao, cor_alvo);

        else if (opcao == 2)
            mostrar_missao(tipo_missao, cor_alvo);

        else if (opcao == 3)
            mostrar_placar(territorios);

        else if (opcao == 4)
            printf("Saindo...\n");

        else
            printf("Opção inválida!\n");
    }

    // liberar memoria das tropas do caloc
    for (int i = 0; i < 5; i++)
        free(territorios[i].tropas);

    return 0;
}
