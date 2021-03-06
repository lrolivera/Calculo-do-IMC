#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define TAM 5

//Variáveis Globais
struct dados
{
    char nome[20];
    float altura;
    float peso;
    float imc;
};

struct dados r[TAM];
int i;

//Função Principal
int main(void)
{
    void receberDados(struct dados r[TAM]);
    void imprimirDados(struct dados r[TAM]);
    void calculo_imc(struct dados r[TAM]);

    receberDados(r);
    calculo_imc(r);
    system("cls");
    imprimirDados(r);

    system("pause");
    return 0;
}

//Função de Registro
void receberDados(struct dados r[TAM])
{
    //informação visual de orientação ao usuário

    setlocale(LC_ALL, "");
    printf("\t\t      Registro IMC      \n");
    printf("=========================================================================== \n");
    printf("\t\t      Tabela de Acompanhamento       \n");
    printf("============================================================================ \n");
    printf("      Menos do que 18,5 - abaixo do peso. \n");
    printf("      Entre 18,5 e 24,9 - peso normal. \n");
    printf("      Entre 25,0 e 29,9 - sobrepeso. \n");
    printf("      Entre 30,0 e 34,9 - obesidade grau 1. \n");
    printf("============================================================================ \n");
    printf("*******Obs.: usar ponto em vez de virgula ao digitar a altura************.\n\n");
    printf("===========================================================================\n");
    system("color 03 "); // Deixar o usuário com um ambiente com cor

    for (i = 0; i < TAM; i++)
    {
        printf("\n%dª Pessoa:\n", i + 1);
        printf("Nome da pessoa: ");
        scanf("%s", r[i].nome);
        printf("Altura da pessoa: ");
        scanf("%f", &r[i].altura);
        printf("Peso da pessoa: ");
        scanf("%f", &r[i].peso);
    }
}

//Função de Impressão de Registro
void imprimirDados(struct dados r[TAM])
{
    printf("\n\t\t      Usuários que estão no sistema  \n");
    printf("*******Quem estiver abaixo do peso ou sobrepeso, por favor ir ao médico*******\n\n");

    for (i = 0; i < TAM; i++)
    {
        printf("=====================================");
        printf("\n%dª Pessoa:\n", i + 1);
        printf("Nome: %s\n", r[i].nome);
        printf("Altura: %.2f\n", r[i].altura);
        printf("Peso: %.2f\n", r[i].peso);
        printf("IMC: %1.1f \n", r[i].imc);

        if (r[i].imc < 17.0)
            printf("Status: Muito abaixo do peso\n");
        else if (r[i].imc < 18.5)
            printf("Status: Abaixo do peso\n");
        else if (r[i].imc < 25.0)
            printf("Status: Peso nomal\n");
        else if (r[i].imc < 30.0)
            printf("Status: Sobrepeso\n");
        else if (r[i].imc < 35.0)
            printf("Status: Obesidade grau 1\n");
        else if (r[i].imc < 40.0)
            printf("Status: Obesidade grau 2\n");
        else
            printf("Status: Obesidade grau 3\n");
        printf("=====================================\n\n");
    }
}

//Calculo do IMC
void calculo_imc(struct dados r[TAM])
{
    for (i = 0; i < TAM; i++)
    {
        r[i].imc = (r[i].peso / (r[i].altura * r[i].altura));
    }
    return;
}
