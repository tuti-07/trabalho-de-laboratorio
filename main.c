#include <stdio.h>
#include <string.h>

#define MAX_FUNCIONARIOS 100

typedef struct {
    int id;
    char nome[50];
    float horasSolicitadas;
    float horasAprovadas;
    int aprovado;   // 0 = pendente, 1 = aprovado, 2 = negado
} Registro;

Registro registros[MAX_FUNCIONARIOS];
int totalRegistros = 0;

void registrarHoras() {
    if (totalRegistros >= MAX_FUNCIONARIOS) {
        printf("\nLimite máximo atingido!\n");
        return;
    }

    Registro r;
    r.id = totalRegistros + 1;

    printf("\n--- Registro de Horas Extras ---\n");
    printf("Nome do funcionário: ");
    scanf(" %[^\n]", r.nome);

    printf("Horas solicitadas: ");
    scanf("%f", &r.horasSolicitadas);

    r.aprovado = 0;
    r.horasAprovadas = 0;

    registros[totalRegistros] = r;
    totalRegistros++;

    printf("\nRegistro efetuado com sucesso! ID: %d\n", r.id);
}

void aprovarHoras() {
    int id, opcao;

    printf("\n--- Aprovação de Horas Extras ---\n");
    printf("Informe o ID do registro: ");
    scanf("%d", &id);

    if (id < 1 || id > totalRegistros) {
        printf("ID inválido.\n");
        return;
    }

    Registro *r = &registros[id - 1];

    printf("\nFuncionário: %s\n", r->nome);
    printf("Horas solicitadas: %.2f\n", r->horasSolicitadas);
    printf("Status atual: %s\n", 
        r->aprovado == 0 ? "Pendente" : (r->aprovado == 1 ? "Aprovado" : "Negado")
    );

    printf("\n1 - Aprovar\n2 - Negar\nEscolha: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        r->aprovado = 1;
        r->horasAprovadas = r->horasSolicitadas;
        printf("Horas aprovadas com sucesso!\n");
    } else if (opcao == 2) {
        r->aprovado = 2;
        r->horasAprovadas = 0;
        printf("Horas negadas.\n");
    } else {
        printf("Opção inválida.\n");
    }
}

void listarRegistros() {
    if (totalRegistros == 0) {
        printf("\nNenhum registro encontrado.\n");
        return;
    }

    printf("\n--- Lista de Registros ---\n");
    for (int i = 0; i < totalRegistros; i++) {
        Registro r = registros[i];
        printf("\nID: %d\nNome: %s\nHoras solicitadas: %.2f\nHoras aprovadas: %.2f\nStatus: %s\n",
            r.id, r.nome, r.horasSolicitadas, r.horasAprovadas,
            r.aprovado == 0 ? "Pendente" : (r.aprovado == 1 ? "Aprovado" : "Negado")
        );
    }
}

int main() {
    int opcao;

    do {
        printf("\n===== Sistema de Controle de Horas Extras =====\n");
        printf("1 - Registrar horas extras\n");
        printf("2 - Aprovar/Negar horas\n");
        printf("3 - Listar registros\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: registrarHoras(); break;
            case 2: aprovarHoras(); break;
            case 3: listarRegistros(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
