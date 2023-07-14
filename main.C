#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição das estruturas de dados
typedef struct {
    int id;
    char nome[50];
    char cpf[15];
    char telefone[15];
    char email[50];
} Aluno;

typedef struct {
    int id;
    char nome[50];
    char cpf[15];
    char telefone[15];
    char email[50];
} Professor;

typedef struct {
    int id;
    char tipo;
    int dia;
    char horario[6];
    int id_professor;
    int min_alunos;
    int max_alunos;
    char faixa_etaria[10];
} Turma;

typedef struct {
    int id_aluno;
    int id_aula;
}Inscricao;

// Funções para cadastrar alunos, professores e turmas
void cadastrarAluno();
void cadastrarProfessor();
void cadastrarTurma();

// Funções para processar as inscrições
void inscreverAluno();
void cancelarInscricao();
void fecharTurmas();
void confirmarTurmas();

// Função para fechar o programa e salvar os dados
void fecharPrograma();

int main() {
    int opcao;

    do {
        printf("Menu:\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Cadastrar professor\n");
        printf("3 - Cadastrar turma\n");
        printf("4 - Inscrever aluno\n");
        printf("5 - Cancelar inscrição\n");
        printf("6 - Fechar turmas\n");
        printf("7 - Confirmar turmas\n");
        printf("8 - Fechar programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAluno();
                break;
            case 2:
                cadastrarProfessor();
                break;
            case 3:
                cadastrarTurma();
                break;
            case 4:
                inscreverAluno();
                break;
            case 5:
                cancelarInscricao();
                break;
            case 6:
                fecharTurmas();
                break;
            case 7:
                confirmarTurmas();
                break;
            case 8:
                fecharPrograma();
                break;
            default:
                printf("Opção inválida!\n");
        }

        printf("\n");
    } while(opcao>0 && opcao<9);

    return 0;
}

void checkFile(FILE *arquivo) {
    if (arquivo == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }
}

// Implementação do cadastro de aluno

void cadastrarAluno() {
    printf("Opção 1 - Cadastrar aluno\n");
    FILE *arquivo = fopen("alunos.csv", "a");
    checkFile(arquivo);

    Aluno aluno;

    printf("----- Cadastrar Aluno -----\n");
    printf("ID do aluno: ");
    scanf("%d", &aluno.id);
    getchar();

    printf("Nome do aluno: ");
    fgets(aluno.nome, 100, stdin);
    aluno.nome[strcspn(aluno.nome, "\n")] = '\0';// remove o caractere ('\n') da string aluno.nome, atribuindo o caractere nulo ('\0') à posição na string

    printf("CPF do aluno: ");
    fgets(aluno.cpf, 15, stdin);
    aluno.cpf[strcspn(aluno.cpf, "\n")] = '\0';

    printf("Telefone do aluno: ");
    fgets(aluno.telefone, 15, stdin);
    aluno.telefone[strcspn(aluno.telefone, "\n")] = '\0';

    printf("E-mail do aluno: ");
    fgets(aluno.email, 100, stdin);
    aluno.email[strcspn(aluno.email, "\n")] = '\0';

    fprintf(arquivo, "%d,%s,%s,%s,%s\n", aluno.id, aluno.nome, aluno.cpf, aluno.telefone, aluno.email);

    fclose(arquivo);

    printf("Aluno cadastrado com sucesso!\n");
}

// Implementação do cadastro de professor

void cadastrarProfessor() {
  printf("Opção 2 - Cadastrar professor\n");
  FILE *arquivo = fopen("professores.csv", "a");
  checkFile(arquivo);

  Professor professor;

    printf("----- Cadastrar Professor -----\n");
    printf("ID do professor: ");
    scanf("%d", &professor.id);
    getchar(); 

    printf("Nome do professor: ");
    fgets(professor.nome, 100, stdin);
    professor.nome[strcspn(professor.nome, "\n")] = '\0';

    printf("CPF do professor: ");
    fgets(professor.cpf, 15, stdin);
    professor.cpf[strcspn(professor.cpf, "\n")] = '\0';

    printf("Telefone do professor: ");
    fgets(professor.telefone, 15, stdin);
    professor.telefone[strcspn(professor.telefone, "\n")] = '\0';

    printf("E-mail do professor: ");
    fgets(professor.email, 100, stdin);
    professor.email[strcspn(professor.email, "\n")] = '\0';

    fprintf(arquivo, "%d,%s,%s,%s,%s\n", professor.id, professor.nome, professor.cpf, professor.telefone, professor.email);

    fclose(arquivo);

    printf("Professor cadastrado com sucesso!\n");
}

 // Implementação do cadastro de turma
  

void cadastrarTurma() {
  printf("Opção 3 - Cadastrar turma\n");
  FILE *arquivo = fopen("aulas.csv", "a");
    checkFile(arquivo);

    Turma turma;

    printf("----- Cadastrar Turma -----\n");
    printf("ID da turma: ");
    scanf("%d", &turma.id);
    getchar(); 

    printf("Tipo de aula (A, B, C ou D): ");
    scanf("%c", &turma.tipo);
    getchar(); 
    printf("Dia da semana (1 a 7): ");
    scanf("%d", &turma.dia);
    getchar(); 

    printf("Horário da aula (HH:MM): ");
    fgets(turma.horario, 6, stdin);
    turma.horario[strcspn(turma.horario, "\n")] = '\0';

    printf("ID do professor: ");
    scanf("%d", &turma.id_professor);
    getchar();

    printf("Número mínimo de alunos: ");
    scanf("%d", &turma.min_alunos);
    getchar();
  
    printf("Número máximo de alunos: ");
    scanf("%d", &turma.max_alunos);
    getchar(); 

    printf("Faixa etária (XX-XX): ");
    fgets(turma.faixa_etaria, 6, stdin);
    turma.faixa_etaria[strcspn(turma.faixa_etaria, "\n")] = '\0';

    fprintf(arquivo, "%d,%c,%d,%s,%d,%d,%d,%s\n", turma.id, turma.tipo, turma.dia, turma.horario, turma.id_professor, turma.min_alunos, turma.max_alunos, turma.faixa_etaria);

    fclose(arquivo);

    printf("Turma cadastrada com sucesso!\n");
}

// Implementação da inscrição de aluno

void inscreverAluno() {
  printf("Opção 4 - Inscrever aluno\n");
  FILE *arquivo = fopen("inscricoes.csv", "a");
    checkFile(arquivo);

    Inscricao inscricao;

    printf("----- Inscrever Aluno -----\n");
    printf("ID do aluno: ");
    scanf("%d", &inscricao.id_aluno);
    getchar(); 

    printf("ID da turma: ");
    scanf("%d", &inscricao.id_aula);
    getchar(); 

    fprintf(arquivo, "%d,%d\n", inscricao.id_aluno, inscricao.id_aula);

    fclose(arquivo);

    printf("Aluno inscrito com sucesso!\n");
}

// Implementação do cancelamento de inscrição

void cancelarInscricao() {
  printf("Opção 5 - Cancelar inscrição\n");
  FILE *arquivo = fopen("inscricoes.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo inscricoes.csv.\n");
        return;
    }

    FILE *arquivo_canceladas = fopen("r_inscricoesCanceladas.csv", "a");
    if (arquivo_canceladas == NULL) {
        printf("Erro ao abrir o arquivo r_inscricoesCanceladas.csv.\n");
        fclose(arquivo);
        return;
    }

    int id_aluno;
    int id_aula;

    printf("----- Cancelar Inscrição -----\n");
    printf("ID do aluno: ");
    scanf("%d", &id_aluno);
    getchar(); // Consumir o caractere de nova linha

    printf("ID da turma: ");
    scanf("%d", &id_aula);
    getchar(); // Consumir o caractere de nova linha

    // Criar um arquivo temporário para armazenar as inscrições não canceladas
    FILE *arquivo_temp = fopen("temp.csv", "w");
    if (arquivo_temp == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(arquivo);
        fclose(arquivo_canceladas);
        return;
    }

    int encontrou = 0;
    char linha[100];

    while (fgets(linha, sizeof(linha), arquivo)) {
        int aluno_id, aula_id;
        sscanf(linha, "%d,%d", &aluno_id, &aula_id);

        // Verificar se a inscrição corresponde ao aluno e turma informados
        if (aluno_id == id_aluno && aula_id == id_aula) {
            // Adicionar a inscrição cancelada ao arquivo r_inscricoesCanceladas.csv
            fprintf(arquivo_canceladas, "%d,%d\n", aluno_id, aula_id);
            encontrou = 1;
        } else {
            // Escrever a inscrição não cancelada no arquivo temporário
            fprintf(arquivo_temp, "%d,%d\n", aluno_id, aula_id);
        }
    }

    fclose(arquivo);
    fclose(arquivo_canceladas);
    fclose(arquivo_temp);

    remove("inscricoes.csv");
    rename("temp.csv", "inscricoes.csv");

    if (encontrou) {
        printf("Inscrição cancelada com sucesso!\n");
    } else {
        printf("Inscrição não encontrada.\n");
    }
}

 // Implementação do fechamento de turmas

void fecharTurmas() {
  printf("Opção 6 - Fechar turmas\n");
    FILE *arquivo_aulas = fopen("aulas.csv", "r");
    if (arquivo_aulas == NULL) {
        printf("Erro ao abrir o arquivo aulas.csv.\n");
        return;
    }

    FILE *arquivo_inscricoes = fopen("inscricoes.csv", "r");
    if (arquivo_inscricoes == NULL) {
        printf("Erro ao abrir o arquivo inscricoes.csv.\n");
        fclose(arquivo_aulas);
        return;
    }

    FILE *arquivo_canceladas = fopen("r_aulascanceladas.csv", "a");
    if (arquivo_canceladas == NULL) {
        printf("Erro ao abrir o arquivo r_aulascanceladas.csv.\n");
        fclose(arquivo_aulas);
        fclose(arquivo_inscricoes);
        return;
    }

    int id_turma;
    printf("----- Fechar Turmas -----\n");
    printf("ID da turma: ");
    scanf("%d", &id_turma);
    getchar(); // Consumir o caractere de nova linha

    char linha_aula[100];
    char linha_inscricao[100];
    int encontrou = 0;

    FILE *arquivo_aulas_temp = fopen("aulas_temp.csv", "w");
    if (arquivo_aulas_temp == NULL) {
        printf("Erro ao abrir o arquivo aulas_temp.csv.\n");
        fclose(arquivo_aulas);
        fclose(arquivo_inscricoes);
        fclose(arquivo_canceladas);
        return;
    }

    FILE *arquivo_inscricoes_temp = fopen("inscricoes_temp.csv", "w");
    if (arquivo_inscricoes_temp == NULL) {
        printf("Erro ao abrir o arquivo inscricoes_temp.csv.\n");
        fclose(arquivo_aulas);
        fclose(arquivo_inscricoes);
        fclose(arquivo_canceladas);
        fclose(arquivo_aulas_temp);
        return;
    }

    // Copiar as aulas não fechadas para o arquivo temporário e excluir da aulas.csv
    while (fgets(linha_aula, sizeof(linha_aula), arquivo_aulas)) {
        int id_turma_atual;
        sscanf(linha_aula, "%d,", &id_turma_atual);

        // Verificar se o ID da turma coincide
        if (id_turma_atual == id_turma) {
            encontrou = 1;
            // Escrever a linha da aula no arquivo temporário
            fprintf(arquivo_canceladas, "%s", linha_aula);
        } else {
            // Escrever a linha da aula no arquivo temporário
            fprintf(arquivo_aulas_temp, "%s", linha_aula);
        }
    }

    // Copiar as inscrições não canceladas para o arquivo temporário e excluir da inscricoes.csv
    while (fgets(linha_inscricao, sizeof(linha_inscricao), arquivo_inscricoes)) {
        int id_turma_inscricao;
        sscanf(linha_inscricao, "%*d,%d,", &id_turma_inscricao);

        // Verificar se o ID da turma coincide
        if (id_turma_inscricao != id_turma) {
            // Escrever a linha da inscrição no arquivo temporário
            fprintf(arquivo_inscricoes_temp, "%s", linha_inscricao);
        }
    }

    fclose(arquivo_aulas);
    fclose(arquivo_inscricoes);
    fclose(arquivo_canceladas);
    fclose(arquivo_aulas_temp);
    fclose(arquivo_inscricoes_temp);

    remove("aulas.csv");
    rename("aulas_temp.csv", "aulas.csv");

    remove("inscricoes.csv");
    rename("inscricoes_temp.csv", "inscricoes.csv");

    printf("Turma fechada com sucesso!\n");
}

// Implementação da confirmação de turmas

void confirmarTurmas() {
  printf("Opção 7 - Confirmar turmas\n");
 FILE *arquivo_aulas = fopen("aulas.csv", "r");
    if (arquivo_aulas == NULL) {
        printf("Erro ao abrir o arquivo aulas.csv.\n");
        return;
    }

    FILE *arquivo_confirmadas = fopen("r_aulasConfirmadas.csv", "a");
    if (arquivo_confirmadas == NULL) {
        printf("Erro ao abrir o arquivo r_aulasConfirmadas.csv.\n");
        fclose(arquivo_aulas);
        return;
    }

    char linha_aula[100];
    int encontrou = 0;

    // Copiar todas as linhas do arquivo aulas.csv para o arquivo de aulas confirmadas
    while (fgets(linha_aula, sizeof(linha_aula), arquivo_aulas)) {
        encontrou = 1;
        // Escrever a linha da aula no arquivo de aulas confirmadas
        fprintf(arquivo_confirmadas, "%s", linha_aula);
    }

    fclose(arquivo_aulas);
    fclose(arquivo_confirmadas);

    if (encontrou) {
        printf("Turmas confirmadas copiadas para o arquivo r_aulasConfirmadas.csv.\n");
    } else {
        printf("Nenhuma turma encontrada.\n");
    }
}

// Implementação para fechar o programa e salvar os dados

void fecharPrograma() {
    printf("Fechando o programa...\n");
    printf("Salvando as informações em arquivos...\n");
    printf("Programa encerrado. Até mais!\n");
    exit(0);
}
