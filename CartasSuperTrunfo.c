#include <stdio.h>
#include <string.h>

struct Carta {
    char estado[3];           // Ex: "SP"
    char codigo[4];           // Ex: "A01"
    char cidade[30];          // Nome da cidade
    int populacao;            // População
    float area;               // Área em km²
    float pib;                // PIB em bilhões
    int pontosTuristicos;     // Quantidade de pontos turísticos
};

int main() {
    struct Carta carta1, carta2;
    int escolha;

    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (ex: SP): ");
    scanf("%s", carta1.estado);
    printf("Código da carta (ex: A01): ");
    scanf("%s", carta1.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.cidade); // ler com espaços
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (ex: RJ): ");
    scanf("%s", carta2.estado);
    printf("Código da carta (ex: A02): ");
    scanf("%s", carta2.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.cidade);
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    printf("\n=== Escolha o atributo para comparar ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    float valor1, valor2;

    switch (escolha) {
        case 1:
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            printf("\nComparando População...\n");
            break;
        case 2:
            valor1 = carta1.area;
            valor2 = carta2.area;
            printf("\nComparando Área...\n");
            break;
        case 3:
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            printf("\nComparando PIB...\n");
            break;
        case 4:
            valor1 = carta1.pontosTuristicos;
            valor2 = carta2.pontosTuristicos;
            printf("\nComparando Pontos Turísticos...\n");
            break;
        case 5:
            valor1 = carta1.populacao / carta1.area;
            valor2 = carta2.populacao / carta2.area;
            printf("\nComparando Densidade Populacional...\n");
            printf("Densidade %s: %.2f hab/km²\n", carta1.cidade, valor1);
            printf("Densidade %s: %.2f hab/km²\n", carta2.cidade, valor2);
            break;
        default:
            printf("Opção inválida!\n");
            return 0;
    }

    // Regra de comparação
    if (escolha == 5) { // densidade: menor vence
        if (valor1 < valor2) {
            printf("A vencedora é %s (%s)!\n", carta1.cidade, carta1.codigo);
        } else if (valor2 < valor1) {
            printf("A vencedora é %s (%s)!\n", carta2.cidade, carta2.codigo);
        } else {
            printf("Empate!\n");
        }
    } else { // outros: maior vence
        if (valor1 > valor2) {
            printf("A vencedora é %s (%s)!\n", carta1.cidade, carta1.codigo);
        } else if (valor2 > valor1) {
            printf("A vencedora é %s (%s)!\n", carta2.cidade, carta2.codigo);
        } else {
            printf("Empate!\n");
        }
    }

    return 0;
}
