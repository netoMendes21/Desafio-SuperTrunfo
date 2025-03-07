#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

#define MAX_CARTAS 32

typedef struct
{
    char Estado;
    char CodigoDaCidade[3];
    char NomeDaCidade[50];
    int Populacao;
    float Area;
    float DensidadePopulacional;
    double PIB;
    double PercaCapita;
    int PontosTuristicos;
    double SuperPoder;
} CartaType;

// variável que representa o valor máximo possível de cartas cadastradas
CartaType listaDeCartas[MAX_CARTAS];

// funcão para criar uma nova carta
CartaType criarCarta()
{

    CartaType carta;
    printf("Digite o Estado entre A e H: ");
    scanf(" %c", &carta.Estado);

    printf("Digite o código da cidade entre 1 e 4: ");
    scanf("%s", carta.CodigoDaCidade);

    printf("Digite o nome da Cidade: ");
    scanf(" %[^\n]", carta.NomeDaCidade);

    printf("Digite a população da cidade: ");
    scanf("%d", &carta.Populacao);

    printf("Digite a Área da cidade: ");
    scanf("%f", &carta.Area);

    printf("Digite o PIB da cidade: ");
    scanf("%lf", &carta.PIB);

    printf("Digite a quantidade de pontos turísticos da cidade: ");
    scanf("%d", &carta.PontosTuristicos);

    carta.PercaCapita = (carta.PIB * 1000000000.0) / carta.Populacao;
    carta.DensidadePopulacional = carta.Populacao / carta.Area;
    carta.SuperPoder = carta.Populacao + carta.Area + carta.PIB + carta.PontosTuristicos + carta.PercaCapita + (1 / carta.DensidadePopulacional);
    return carta;
}

// Função que retorna a carta com todos os valores que foram requeridos formatada como pedido
void imprimirCarta(CartaType C)
{
    printf("\nEstado: %c", toupper(C.Estado));
    printf("\nCódigo da Carta: %c%02d", toupper(C.Estado), atoi(C.CodigoDaCidade));
    printf("\nNome da Cidade: %s", C.NomeDaCidade);
    printf("\nPopulação: %d", C.Populacao);
    printf("\nÁrea: %.2f km²", C.Area);
    printf("\nPIB: %.2f bilhões de reais", C.PIB);
    printf("\nNúmero de Pontos Turísticos: %d", C.PontosTuristicos);
    printf("\nDensidade Populacional: %.2f hab/km²", C.DensidadePopulacional);
    printf("\nPIB per Capita: %.2lf reais", C.PercaCapita);
    printf("\nSeu SuperPoder é de: %.2lf\n", C.SuperPoder);
}

// função para para controlar o loop nas comparações , determinando até quando será renderizado no terminal
int isAvailable(int opcoes[], int iterador)
{
    for (int i = 0; i < iterador; i++)
    {
        if (opcoes[i] == opcoes[iterador])
        {
            return 0;
        }
    }
    return 1;
}

// Função de Menu dos atributos inicial
void MenuAtributos()
{
    printf("\n*****---------COMPARANDO OS ATRIBUTOS---------*****\n\n");

    printf("Escolha com qual dos atributos você quer comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("6. Per Capita\n");
    printf("7. Super Poder\n");
    printf("8. Mostrar Carta vencedora!\n");
    printf("9. Voltar para o menu do Jogo\n");

    printf("\nEscolha sua opção: ");
}

// validação para saber se o atributo População já foi selecionado dentro do menu dinâmico
int checkPopulacao(int opcoes[], int iterador)
{
    int populacaoExiste = 0;
    int i = 0;
    for (i = 0; i < iterador; i++)
    {
        if (opcoes[i] == 1)
        {
            populacaoExiste = 1;
        }
    }
    return populacaoExiste;
}

// validação para saber se o atributo Área já foi selecionado dentro do menu dinâmico
int checkArea(int opcoes[], int iterador)
{
    int areaExiste = 0;
    int i = 0;
    for (i = 0; i < iterador; i++)
    {
        if (opcoes[i] == 2)
        {
            areaExiste = 1;
        }
    }
    return areaExiste;
}

// validação para saber se o atributo PIB já foi selecionado dentro do menu dinâmico
int checkPIB(int opcoes[], int iterador)
{
    int PibExiste = 0;
    int i = 0;
    for (i = 0; i < iterador; i++)
    {
        if (opcoes[i] == 3)
        {
            PibExiste = 1;
        }
    }
    return PibExiste;
}

// validação para saber se o atributo Pontos Turísticos já foi selecionado dentro do menu dinâmico
int checkPontosTuristicos(int opcoes[], int iterador)
{
    int pontosTuristicosExiste = 0;
    int i = 0;
    for (i = 0; i < iterador; i++)
    {
        if (opcoes[i] == 4)
        {
            pontosTuristicosExiste = 1;
        }
    }
    return pontosTuristicosExiste;
}

// validação para saber se o atributo densidade populacional já foi selecionado dentro do menu dinâmico
int checkDensidade(int opcoes[], int iterador)
{
    int densidadeExiste = 0;
    int i = 0;
    for (i = 0; i < iterador; i++)
    {
        if (opcoes[i] == 5)
        {
            densidadeExiste = 1;
        }
    }
    return densidadeExiste;
}

// validação para saber se o atributo Per Capita já foi selecionado dentro do menu dinâmico
int checkPerCapita(int opcoes[], int iterador)
{
    int perCapitaExiste = 0;
    int i = 0;
    for (i = 0; i < iterador; i++)
    {
        if (opcoes[i] == 6)
        {
            perCapitaExiste = 1;
        }
    }
    return perCapitaExiste;
}

// validação para saber se o atributo superPoder já foi selecionado dentro do menu dinâmico
int checkSuper(int opcoes[], int iterador)
{
    int superPoderExiste = 0;
    int i = 0;
    for (i = 0; i < iterador; i++)
    {
        if (opcoes[i] == 7)
        {
            superPoderExiste = 1;
        }
    }
    return superPoderExiste;
}

// função para validar se já existe uma carta vencedora
int checkCartaVencedora(int opcoes[], int iterador)
{
    int cartaVencedoraExiste = 0;
    int i = 0;
    for (i = 0; i < iterador; i++)
    {
        if (opcoes[i] == 8)
        {
            cartaVencedoraExiste = 1;
        }
    }
    return cartaVencedoraExiste;
}

// função para manter que o menu de comparações dinâmico, fazendo com que não se repita nenhuma opção escolhida anteriormente
void printDynamicMenu(int opcoes[], int iterador)
{
    if (iterador == 0)
    {
        MenuAtributos();
        return;
    }

    int temPopulacao = checkPopulacao(opcoes, iterador);
    int temArea = checkArea(opcoes, iterador);
    int temPIB = checkPIB(opcoes, iterador);
    int temPontosTuristicos = checkPontosTuristicos(opcoes, iterador);
    int temDensidade = checkDensidade(opcoes, iterador);
    int temPerCapita = checkPerCapita(opcoes, iterador);
    int temSuper = checkSuper(opcoes, iterador);
    int temCartaVencedora = checkCartaVencedora(opcoes, iterador);

    printf("\n*****---------COMPARANDO OS ATRIBUTOS---------*****\n\n");

    printf("Escolha com qual dos atributos você quer comparar:\n");

    if (!temPopulacao)
    {
        printf("1. População.\n");
    }

    if (!temArea)
    {
        printf("2. Área.\n");
    }

    if (!temPIB)
    {
        printf("3. PIB.\n");
    }

    if (!temPontosTuristicos)
    {
        printf("4. Número de Pontos Turísticos.\n");
    }

    if (!temDensidade)
    {
        printf("5. Densidade Populacional.\n");
    }

    if (!temPerCapita)
    {
        printf("6. PIB per Capta.\n");
    }

    if (!temSuper)
    {
        printf("7. Super Poder.\n");
    }

    if (!temCartaVencedora)
    {
        printf("8. Mostrar carta vencedora!\n");
    }

    printf("9. Voltando ao Menu Principal...\n\n");

    printf("Escolha sua opção: ");
}

int main()
{

    // Definição das variáveis para armazenar as propriedades das cidades
    int opcoesDeComparacao[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int iterador = 0;
    int opcao;
    int opcaoMenu;
    int totalCartas = 0;
    float pontuacao1 = 0, pontuacao2 = 0;

    do
    {

        printf("\n----------***Bem-Vindo ao Jogo Super-Trunfo***----------\n\n");
        printf("Selecione uma das opções abaixo: \n");
        printf("1. Cadastrar carta\n");
        printf("2. Mostrar cartas\n");
        printf("3. Compare os atributos das cartas\n");
        printf("4. Sobre o Jogo\n");
        printf("5. Sair do Jogo\n");
        scanf("%d", &opcaoMenu);

        switch (opcaoMenu)
        {
        case 1:
            // Cadastro das Cartas:
            printf("\nDigite os dados da carta (%d): \n", totalCartas + 1);
            listaDeCartas[totalCartas] = criarCarta();
            totalCartas++;
            break;

        case 2:
            // Retorno das cartas cadastradas devidamente formatadas
            if (totalCartas == 0)
            {
                printf("\n****NENHUMA CARTA CADASTRADA AINDA****!!");
            }
            else
            {
                printf("\n--------Cartas Cadastradas--------\n");
                for (int i = 0; i < totalCartas; i++)
                {
                    printf("\nCarta (%d)", i + 1);
                    imprimirCarta(listaDeCartas[i]);
                    printf("\n-----------------------------------");
                }
            }
            break;

        case 3:
            // Escolha de atributos //
            if (totalCartas < 2)
            {
                printf("****É NECESSÁRIO PELO MENOS DUAS CARTAS CADASTRADAS PARA COMPARAR****!\n");
                break;
            }

            CartaType carta1 = listaDeCartas[0];
            CartaType carta2 = listaDeCartas[1];

            for (int i = 0; i < 9; i++)
            {
                opcoesDeComparacao[i] = 0;
            }
            iterador = 0;
            do
            {
                printDynamicMenu(opcoesDeComparacao, iterador);
                scanf("%d", &opcoesDeComparacao[iterador]);

                while (!isAvailable(opcoesDeComparacao, iterador))
                {
                    printf("\n****OPÇÃO JÁ ESCOLHIDA, ESCOLHA OUTRA****\n\n");
                    printDynamicMenu(opcoesDeComparacao, iterador);
                    scanf("%d", &opcoesDeComparacao[iterador]);
                }

                switch (opcoesDeComparacao[iterador])
                {
                case 1:
                    printf("\nPopulação da cidade de %s é: %d pessoas || População da cidade de %s é: %d pessoas", carta1.NomeDaCidade, carta1.Populacao, carta2.NomeDaCidade, carta2.Populacao);
                    if (carta1.Populacao > carta2.Populacao)
                    {
                        printf("\n%s venceu na propriedade: População\n\n", carta1.NomeDaCidade);
                        pontuacao1 = pontuacao1 + carta1.Populacao;
                    }
                    else if (carta1.Populacao < carta2.Populacao)
                    {
                        printf("\n%s venceu na propriedade: População\n\n", carta2.NomeDaCidade);
                        pontuacao2 = pontuacao2 + carta2.Populacao;
                    }
                    else
                    {
                        printf("Empate no atributo População!!!\n\n");
                    }
                    break;

                case 2:
                    printf("\nÁrea da cidade de %s é: %.2f km/² || Área da cidade de %s é: %.2f km/²", carta1.NomeDaCidade, carta1.Area, carta2.NomeDaCidade, carta2.Area);
                    if (carta1.Area > carta2.Area)
                    {
                        printf("\n%s venceu na propriedade: área\n\n", carta1.NomeDaCidade);
                        pontuacao1 += carta1.Area;
                    }
                    else if (carta1.Area < carta2.Area)
                    {
                        printf("\n%s venceu na propriedade: área\n\n", carta2.NomeDaCidade);
                        pontuacao2 += carta2.Area;
                    }
                    else
                    {
                        printf("Empate no atributo área!!!\n\n");
                    }
                    break;

                case 3:
                    printf("\nPIB da cidade de %s é: %.2f bilhões de reais || PIB da cidade de %s é: %.2f bilhões de reais", carta1.NomeDaCidade, carta1.PIB, carta2.NomeDaCidade, carta2.PIB);
                    if (carta1.PIB > carta2.PIB)
                    {
                        printf("\n%s venceu na propriedade: PIB\n\n", carta1.NomeDaCidade);
                        pontuacao1 += carta1.PIB;
                    }
                    else if (carta1.PIB < carta2.PIB)
                    {
                        printf("\n%s venceu na propriedade: PIB\n\n", carta2.NomeDaCidade);
                        pontuacao2 += carta2.PIB;
                    }
                    else
                    {
                        printf("Empate no atributo PIB!!!\n\n");
                    }
                    break;

                case 4:
                    printf("\nPontos Turísticos da cidade de %s é: %d || Pontos Turísticos da cidade de %s é: %d", carta1.NomeDaCidade, carta1.PontosTuristicos, carta2.NomeDaCidade, carta2.PontosTuristicos);
                    if (carta1.PontosTuristicos > carta2.PontosTuristicos)
                    {
                        printf("\n%s venceu na propriedade: Pontos Turísticos\n\n", carta1.NomeDaCidade);
                        pontuacao1 += carta1.PontosTuristicos;
                    }
                    else if (carta1.PontosTuristicos < carta2.PontosTuristicos)
                    {
                        printf("\n%s venceu na propriedade: Pontos Turísticos\n\n", carta2.NomeDaCidade);
                        pontuacao2 += carta2.PontosTuristicos;
                    }
                    else
                    {
                        printf("Empate no atributo Pontos Turísticos!!!\n\n");
                    }
                    break;

                case 5:
                    printf("\nDensidade Populacional da cidade de %s é: %.2f hab/km² || Densidade Populacional da cidade de %s é: %.2f hab/km²", carta1.NomeDaCidade, carta1.DensidadePopulacional, carta2.NomeDaCidade, carta2.DensidadePopulacional);
                    if (carta1.DensidadePopulacional < carta2.DensidadePopulacional)
                    {
                        printf("\n%s venceu na propriedade: Densidade Populacional\n\n", carta1.NomeDaCidade);
                        pontuacao1 += carta1.DensidadePopulacional;
                    }
                    else if (carta1.DensidadePopulacional > carta2.DensidadePopulacional)
                    {
                        printf("\n%s venceu na propriedade: Densidade Populacional\n\n", carta2.NomeDaCidade);
                        pontuacao2 += carta2.DensidadePopulacional;
                    }
                    else
                    {
                        printf("Empate no atributo Densidade Populacional!!!\n\n");
                    }
                    break;

                case 6:
                    printf("\nPIB Per Capita da cidade de %s é: %.2lf reais || PIB Per Capita da cidade de %s é: %.2lf reais", carta1.NomeDaCidade, carta1.PercaCapita, carta2.NomeDaCidade, carta2.PercaCapita);
                    if (carta1.PercaCapita > carta2.PercaCapita)
                    {
                        printf("\n%s venceu na propriedade: PIB Per Capita\n\n", carta1.NomeDaCidade);
                        pontuacao1 += carta1.PercaCapita;
                    }
                    else if (carta1.PercaCapita < carta2.PercaCapita)
                    {
                        printf("\n%s venceu na propriedade: PIB Per Capita\n\n", carta2.NomeDaCidade);
                        pontuacao2 += carta2.PercaCapita;
                    }
                    else
                    {
                        printf("Empate no atributo PIB Per Capita!!!\n\n");
                    }
                    break;

                case 7:
                    printf("\nSuper Poder da cidade de %s é: %lf || Super Poder da cidade de %s é: %lf", carta1.NomeDaCidade, carta1.SuperPoder, carta2.NomeDaCidade, carta2.SuperPoder);
                    if (carta1.SuperPoder > carta2.SuperPoder)
                    {
                        printf("\n%s venceu na propriedade: Super Poder\n\n", carta1.NomeDaCidade);
                        pontuacao1 += carta1.SuperPoder;
                    }
                    else if (carta1.SuperPoder < carta2.SuperPoder)
                    {
                        printf("\n%s venceu na propriedade: Super Poder\n\n", carta2.NomeDaCidade);
                        pontuacao2 += carta2.SuperPoder;
                    }
                    else
                    {
                        printf("Empate no atributo Super Poder!!!\n\n");
                    }
                    break;

                case 8:
                    if (pontuacao1 > pontuacao2)
                    {
                        printf("\nPontuação de %s: %2lf\n", carta1.NomeDaCidade, pontuacao1);
                        printf("\nPontuação de %s: %2lf\n", carta2.NomeDaCidade, pontuacao2);
                        printf("\nCidade de %s venceu!!\n", carta1.NomeDaCidade);
                    }
                    else if (pontuacao2 > pontuacao1)
                    {
                        printf("\nPontuação de %s: %2lf\n", carta1.NomeDaCidade, pontuacao1);
                        printf("\nPontuação de %s: %2lf\n", carta2.NomeDaCidade, pontuacao2);
                        printf("\nCidade de %s venceu!!\n", carta2.NomeDaCidade);
                    }
                    else
                    {
                        printf("\nHouve empate!");
                    }
                    break;

                case 9:
                    printf("Voltando ao menu principal...\n");
                    break;

                default:
                    printf("****OPÇÃO INVÁLIDA! ESCOLHA UM NÚMERO DE 1 À 8.****\n");
                    break;
                    iterador--;
                }
                iterador++;
            } while (opcoesDeComparacao[iterador - 1] != 9);
            break;

        case 4:
            printf("***---------- REGRAS DO JOGO ----------***\n");
            printf("\nPara Jogar é necessário castrar pelo menos 2 cartas antes para que seja possível a comparação de uma com a outra.\n");
            break;
        case 5:
            printf("Saindo do Jogo...\n");
            break;
        default:
            printf("Opção Inválida\n");
            break;
        }

    } while (opcaoMenu != 5); // menu principal finalização

    // Exibição dos Resultados:

    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:

    return 0;
}