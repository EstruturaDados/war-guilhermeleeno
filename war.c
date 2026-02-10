
#include <stdio.h>
#include <string.h>


//CADASTRA O LIMITE DE CARACTERES


struct territorio
{
    char nome[30];
    char cor[10];
    int tropas;
};

int main(){
       
    printf("\n ------------------------------------------");
    
    struct territorio territorios[5]; 

    //LAÇO DE CADASTROS 5X
    for (int i=0; i<5; i++)
    {
        printf("\nCadastro de territórios:%d\n", i + 1);//+1 PRA COMEÇAR DO 1 NÃO DO ZERO

        printf("Nome: ");
        scanf(" %29[^\n]", territorios[i].nome); // ESSE CODIGO NO COMEÇO PERMITE USAR ESPAÇO ENTRE AS PALAVRAS, SE NÃO ELE DA O ENTER E PULA UM CAMPO

        printf("Cor: ");
        scanf(" %9[^\n]", territorios[i].cor);   // MESMA COISA, PODE USAR 2 NOMES P/ COR

        printf("Numero de tropas: ");
        scanf("%d", &territorios[i].tropas); // 

        printf("\n =============================================");

        
    }

    printf("\n \n Territorios Cadastrados: \n \n"); //MOSTRA O QUE  EU CADASTRAR NESSE LOOP

    for (int i=0; i<5; i++)
    {
        printf("\n =============================================");
        
        printf("\nTerritório Nº  %d\n", i+1); 

        printf("Nome: %s\n", territorios[i].nome);

        printf("Cor: %s\n", territorios[i].cor);
 
        printf("Numero de tropas: %d\n", territorios[i].tropas);

    }
        
    return 0;
}
