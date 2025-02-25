#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.


// função para calcular o Pib per Capita
unsigned long int perCapita(float pib, int populacao)
{
    if (populacao == 0)
        return -1;
    return (unsigned long int)pib / populacao;
}

//função para calcular a densidade populacional
float densidadePopulacional(int populacao, float area)
{
    if (area == 0)
        return -1;
    return (float)populacao / area;
}

// função para calcular o superPoder
long long int superPoder(int populacao, float area, float pib, int pontosTuristicos)
{
    long double resuldado = populacao + area + pib + perCapita(pib, populacao) + densidadePopulacional(populacao, area) + pontosTuristicos;
    return resuldado;
}

// função para criar a carta com todos os atributos//
int carta(char *estado, char *codigo, char *nome, int *populacao, float *area, float *pib, int *pontosTuristicos)
{
    printf("Digite o Estado: ");
    scanf(" %c", estado);

    printf("Digite o código da cidade: ");
    scanf("%s", codigo);

    printf("Digite o nome da Cidade: ");
    scanf(" %[^\n]", nome);

    printf("Digite a população da cidade: ");
    scanf("%d", populacao);

    printf("Digite a Área da cidade: ");
    scanf("%f", area);

    printf("Digite o PIB da cidade: ");
    scanf("%f", pib);
    *pib *= 1000000000;

    printf("Digite a quantidade de pontos turísticos da cidade: ");
    scanf("%d", pontosTuristicos);

    return 0;
}

//Função para retornar a carta com todas informações necessárias com o formato pedido do desafio //
int cartaPronta(char estado, char *codigo, char *nome, int populacao, float area, float pib, int pontosTuristicos)
{   // Usando o toupper Para que a saída do Caracter seja maiúscula , independente de como o usuário digitar
    printf("\nEstado: %c",toupper(estado));
    printf("\nCódigo da Carta: %c%02d", toupper(estado), atoi(codigo)); // atoi para converter a string em int para que a saída dos dados fique conforme o exemplo pedido
    printf("\nNome da Cidade: %s", nome);
    printf("\nPopulação: %d", populacao);
    printf("\nÁrea: %.2f km²", area);
    printf("\nDensidade Populacional: %.2f pessoas/km²", densidadePopulacional(populacao, area));
    printf("\nPIB: %.2f bilhões de reais", pib / 1000000000);
    printf("\nPIB per Capita: %lu reais", perCapita(pib, populacao));
    printf("\nNúmero de Pontos Turísticos: %d\n", pontosTuristicos);
    printf("\nSeu SuperPoder é de: %lld\n", superPoder(populacao, area, pib, pontosTuristicos));

    return 0;
}

int main()
{
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio
    char estado, estado2;
    char codigoDaCidade[3], codigoDaCidade2[3];
    char nomeDaCidade[50], nomeDaCidade2[50];
    int populacao, quantidadePontosTuristicos, populacao2, quantidadePontosTuristicos2;
    float area, PIB, area2, PIB2;
    int opcao1, opcao2, opcao3, opcao4, opcao5, opcao6, opcao7, opcao8;
    int pontuacao1 = 0, pontuacao2 = 0;


    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio
    printf("Bem-Vindo ao Jogo Super-Trunfo!\n\n");
    printf("Crie a carta do primeiro jogador:\n");

    // CRIAÇÃO DA CARTA DO PRIMEIRO JOGADOR//
    printf("Digite os dados da primera carta: \n\n");
    carta(&estado, codigoDaCidade, nomeDaCidade, &populacao, &area, &PIB, &quantidadePontosTuristicos);
    
    //RETORNO DA PRMEIRA CARTA//
    printf("\n--------Essa é a carta do primeiro jogador--------");
    cartaPronta(estado, codigoDaCidade, nomeDaCidade, populacao, area, PIB, quantidadePontosTuristicos);
    
    printf("\nAgora crie a carta do segundo jogador\n");

    //CRIAÇÃO DA CARTA DO SEGUNDO JOGADOR//
    printf("Digite os dados da segunda carta: \n\n");
    carta(&estado2, codigoDaCidade2, nomeDaCidade2, &populacao2, &area2, &PIB2, &quantidadePontosTuristicos2);

    // RETORNO DA CARTA DO SEGUNDO JOGADOR //
    printf("\n--------Essa é a carta do segundo jogador--------");
    cartaPronta(estado2, codigoDaCidade2, nomeDaCidade2, populacao2, area2, PIB2, quantidadePontosTuristicos2);

    // Exemplo:
    // printf("Digite o código da cidade: ");
    // scanf("%s", codigo);

    // (Repita para cada propriedade)
    printf("\n\nQue comece a batalha!\n");

    // Escolha de atributos //
    printf("Escolha com qual dos atributos você quer competir:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Per Capita\n");
    printf("5. Densidade Populacional");
    printf("6. Pontos Turísticos\n");
    printf("7. Super Poder\n");
    printf("8. Total (só pode ser escolhida se já tiver escolhido algum atributo antes...)\n");
    scanf("%d", &opcao1);
    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.


    switch (opcao1){
        case 1 :
        if (populacao > populacao2)
        {
            printf("\nPrimeiro jogador ganhou na propriedade: população\n\n");
            pontuacao1 += 1;
        } else {
            printf("\nSegundo Jogador ganhou na propriedade: população\n\n");
            pontuacao2 += 1;
        }
            break;
        default:
            printf("--------Opção inválida!--------\n\n");
            break;
    }

    printf("Escolha com qual dos atributos você quer competir:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Per Capita\n");
    printf("5. Densidade Populacional\n");
    printf("6. Pontos Turísticos\n");
    printf("7. Super Poder\n");
    printf("8. Total (só pode ser escolhida se já tiver escolhido algum atributo antes...)\n");
    scanf("%d", &opcao2);

    if(opcao2 == opcao1) {
        printf("\nVocê já escolheu esta opção!\n");
        printf("--------------------------------------------\n\n");
    } else {
     switch(opcao2) {
        case 2 :
        if (area > area2)
        {
            printf("\nPrimeiro jogador ganhou na propriedade: área\n");
            pontuacao1 += 1;
        } else {
            printf("\nSegundo Jogador na propriedade: área\n");
            pontuacao2 += 1;
        }
            break;
        default:
        printf("--------Opção inválida!--------\n\n");
           return;
        }
    }
   
    printf("Escolha com qual dos atributos você quer competir:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Per Capita\n");
    printf("5. Densidade Populacional");
    printf("6. Pontos Turísticos\n");
    printf("7. Super Poder\n");
    printf("8. Total (só pode ser escolhida se já tiver escolhido algum atributo antes...)\n");
    scanf("%d", &opcao3);

   /* if((opcao3 == opcao1) || (opcao3 == opcao2)) {
        printf("Você já escolheu esta opção!\n");
    } else {

     switch(opcao3) { 
        case 3 :
        if (PIB > PIB2)
        {
            printf("\nPrimeiro Jogador ganhou na propriedade: PIB\n");
            pontuacao1 += 1;
        }
        else
        {
            printf("\nSegundo Jogador ganhou na propriedade: PIB\n");
            pontuacao2 += 1;
        }
            break;
        default:
        printf("--------Opção inválida!--------\n\n");
            return;
        }
    }

    printf("Escolha com qual dos atributos você quer competir:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Per Capita\n");
    printf("5. Densidade Populacional");
    printf("6. Pontos Turísticos\n");
    printf("7. Super Poder\n");
    printf("8. Total (só pode ser escolhida se já tiver escolhido algum atributo antes...)\n");
    scanf("%d", &opcao4);
    
    if((opcao4 == opcao1) || (opcao4 == opcao2) || (opcao4 == opcao3)) {
        printf("Você já escolheu esta opção!\n");
    } else {

     switch(opcao4) {
        case 4 :
        if (perCapita(PIB, populacao) > perCapita(PIB2, populacao2))
        {
            printf("\nPrimeiro Jogador ganhou na propriedade: renda per capita\n");
            pontuacao1 += 1;
        } else {
            printf("\nSegundo Jogador ganhou na propriedade: renda per capita\n");
            pontuacao2 += 1;
        }
            break;
            default:
            printf("--------Opção inválida!--------\n\n");
            break;
        }
    }



   case 5 :
    if (densidadePopulacional(populacao, area) < densidadePopulacional(populacao2, area2))
    {
        printf("\nPrimeiro Jogador ganhou na propriedade: densidade populacional\n");
        pontuacao1 += 1;
    }
    else
    {
        printf("\nSegundo Jogador ganhou na propriedade: densidade populacional\n");
        pontuacao2 += 1;
    }
    break;

    case 6:
    if (quantidadePontosTuristicos > quantidadePontosTuristicos2)
    {
        printf("\nPrimeiro Jogador ganhou na propriedade: números de pontos turísticos\n");
        pontuacao1 += 1;
    }
    else
    {
        printf("\nSegundo Jogador ganhou na propriedade: números de pontos turísticos\n");
        pontuacao2 += 1;
    
    }
    break;

    case 7 :
    if (superPoder(populacao, area, PIB, quantidadePontosTuristicos) > superPoder(populacao2, area2, PIB2, quantidadePontosTuristicos2))
    {
        printf("\nPrimeiro Jogador ganhou com o seu superPoder maior\n");
        pontuacao1 += 1;
    }
    else
    {
        printf("\nSegundo Jogador ganhou com o seu superPoder maior\n");
        pontuacao2 += 1;
    }
    break;
    

    case 8 :
    if (pontuacao1 > pontuacao2)
    {
        printf("Primeiro jogador venceu!\n");
    }
    else
    {
        printf("\nSegundo Jogador venceu!\n");
    }

    printf("\nPontuação da carta do Primeiro Jogador é: %d", pontuacao1);
    printf("\nPontuação da carta do Segundo Jogador é: %d\n", pontuacao2);
    break;
    default: printf("Escolha uma opção válida!");
        break;
    }
        */

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);

    return 0;
}
