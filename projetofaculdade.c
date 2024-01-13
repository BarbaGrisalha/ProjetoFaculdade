#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//####  01 - DEFINICAO DE ESTRUTURAS    #### 
typedef struct 
{
   int idAvaliacao;
   int idEstudante;
   int idUnidadeCurricular;
   char anoLetivo[7];
   char epocaAvaliacao[40];
   char dataAvaliacao[10];
   int classificacaoFinal;
}t_avaliacao;

typedef struct 
{
    int idEstudante;
    int nrEstudante;
    char nomeEstudante[50];
    int codigoCursoEstudante;
    char emailEstudante[50];
    int totalAvaliacoes;
    t_avaliacao avaliacoes[50];
    
}t_estudante;

typedef struct 
{
    int idUnidadeCurricular;
    int codigoUnidadeCurricular[7];
    char nomeUnidadeCurricular[50];
    char anoCurricular[7];
    char semestreCurricular[11];
    int ectsUnidadeCurricular;
    int totalAvaliacoes;
}t_uc;

//#### 02 - DECLARACAO DE CONSTANTES  #### 
#define MAX_ESTUDANTES 150
#define MAX_UNIDADES_CURRICULARES 18
#define MAX_AVALIACOES 5000

//#### 03 - DECLARACAO DE FUNCOES  #### 
int menuPrincipal(void);
int registarDadosEstudantes(t_estudante* estudante,int* proximoIdEstudante, t_estudante* registros, int* totalRegistros);
void gravacaoDados(t_estudante* estudante);
void lerDadosEstudantes(t_estudante* registros, int totalRegistros);
int registarDadosUnidadeCurricular(t_uc* unidadeCurricular,int* totalUCs);
void gravacaoDadosUnidadeCurricular(t_uc* unidadeCurricular);
void lerDadosUnidadeCurricular(t_uc* unidadeCurricular);
int cadastrarAvaliacao(int* proximoIdAvaliacao, t_avaliacao* registros, int* totalRegistros,t_avaliacao avaliacao);
void lerAvaliacoes(t_avaliacao* registros, int totalRegistros);

void gravacaoAvaliacoes(t_avaliacao* avaliacao); 


//####  04 - MAIN    #### 
int main ()
{
    int opcao;
    t_estudante estudante; //Variável para armazenar os dados do estudante
    t_uc unidadeCurricular; //Varíavel para guardar as informações da Unidade Curricular
    t_avaliacao avaliacao; //Variável para guardar as informações d avaliação
    int proximoIdEstudante = 1;
    t_estudante registros[MAX_ESTUDANTES];
    int totalRegistros=0;
    int totalUCs=0;
    int proximoAvaliacao=0;
    int proximoIdAvaliacao=0;
    //### 04.1 Menu Principal
    do
    {
        opcao=menuPrincipal();
        switch (opcao)
        {
            case 1:
                registarDadosEstudantes(&estudante,&proximoIdEstudante,registros, &totalRegistros);
                fflush(stdin);
                getchar();
                break;
            case 2:
                lerDadosEstudantes(registros, totalRegistros);
                fflush(stdin);
                getchar();
                break;
            case 3:
                registarDadosUnidadeCurricular(&unidadeCurricular,&totalUCs);
                fflush(stdin);
                getchar();
                break;
            case 4:
                lerDadosUnidadeCurricular(&unidadeCurricular);
                fflush(stdin);
                getchar();
                break; 
            case 5:
                cadastrarAvaliacao(&proximoIdAvaliacao, registros, &totalRegistros, avaliacao);
                fflush(stdin);
                getchar();
                break;    
            case 6:
                lerAvaliacoes(registros, totalRegistros);
                break;
            case 7:
                printf("Estatísticas!!!!");
                break;
            case 0:
                exit(0);
                getchar();
                break;       
            default:
                printf("Opção inválida. Tente Novamente!\n");
                fflush(stdin);
                getchar();
                break;
        }
        
    } while (opcao !=0);
    
    
    
    return 0;
}

//#### 05 - FUNÇÕES DE MENUS #### 
int menuPrincipal()
{
    int opcao;
    system("clear");
  
        printf("\t\t\t###########################################\n");
        printf("\t\t\t#        Menu Principal                   #\n");
        printf("\t\t\t#  [1] Registar Dados Estudante           #\n");
        printf("\t\t\t#  [2] Consultar Dados Estudante          #\n");
        printf("\t\t\t#  [3] Registar Unidade Curricular        #\n");
        printf("\t\t\t#  [4] Consultar Unidade Curricular       #\n");
        printf("\t\t\t#  [5] Registar Avaliações                #\n");
        printf("\t\t\t#  [6] Consultar Avaliações               #\n");
        printf("\t\t\t#  [7] Estatisticas                       #\n");
        printf("\t\t\t#  [0] Sair                               #\n");
        printf("\t\t\t#      Insira a opção desejada:           #\n");
        printf("\t\t\t###########################################\n");
        scanf("%d", &opcao);
    system("clear");
    return opcao;
}

//#### 06 - FUNÇÕES DE REGISTOS DE ESTUDANTE ####
int gerarIdEstudante(int* proximoIdEstudante, t_estudante* registros,int totalRegistros)
{
    int novoId=(*proximoIdEstudante)++;
    for (int i = 0; i < totalRegistros; i++)
    {
        if(registros[i].idEstudante == novoId)
        {
            return gerarIdEstudante(proximoIdEstudante,registros,totalRegistros);
        }
    }
    
   


    return novoId;
}

int registarDadosEstudantes(t_estudante* estudante,int* proximoIdEstudante, t_estudante* registros, int* totalRegistros)//Passando por paremetro a variável estudante da Struct Estudante
{
    char opcao;
    do{ 
        estudante->idEstudante =gerarIdEstudante(proximoIdEstudante, registros,*totalRegistros);
        printf("Entre com o NR do estudante: \n");
        scanf("%d",&(estudante->nrEstudante));
        printf("Entre com o NOME do estudante: \n");
        fflush(stdin);
        scanf("%49[^\n]",estudante->nomeEstudante);
        if(strlen(estudante->nomeEstudante)>50)
        {
            printf("Nome do estudante possui mais de que 50 caractees.\n");
        }
        else
        {
            printf("Entre com o CODIGO do curso do estudante: \n");
            scanf("%d",&(estudante->codigoCursoEstudante));
            printf("Entre com o EMAIL do estudante: \n");
            fflush(stdin);
            scanf("%49[^\n]",estudante->emailEstudante);
            printf("Deseja inserir outro estudante?\n");
            scanf(" %c", &opcao);//aqui é importante ainda dar um enter após escolher o n ou s.
        }
    } while (opcao !='n' && opcao !='N');
   gravacaoDados(estudante);
    return 0 ;
}

void gravacaoDados(t_estudante* estudante) {
    FILE *arquivoDados = fopen("arquivoEstudante.bin","ab"); // Criando a variável ponteiro para o arquivo

    if(arquivoDados == NULL){
        printf("Erro na abertura do arquivo!");//TESTE DE PERROR EM E VEZ DE PRINTF
        return;
    } 
    // Gravando os dados no arquivo
    fwrite(estudante,sizeof(t_estudante),1,arquivoDados);
    fclose(arquivoDados); // Fechando o arquivo

    printf("Dados gravados com sucesso no arquivo!\n");
}

int compararIDEstudantes(const void *a, const void *b)
{
     const t_estudante *estudanteA = (const t_estudante *)a;
    const t_estudante *estudanteB = (const t_estudante *)b;
    return estudanteA->idEstudante - estudanteB->idEstudante;
}

void lerDadosEstudantes(t_estudante* registros,int totalRegistros)
{
    FILE *arquivoDados = fopen("arquivoEstudante.bin","rb");
    
    if(arquivoDados == NULL)
    {
        printf("\nArquivo nao encontrado ou corrompido!");
        return;
    }
    int totalRegistos = 0;
    system("clear");
    while (fread(&registros[totalRegistos],sizeof(t_estudante),1,arquivoDados)>0)
    {
        totalRegistos++;     
    }
    qsort(registros,totalRegistos,sizeof(t_estudante), compararIDEstudantes);
    for (int i = 0; i < totalRegistos; i++)
    {
            printf("\t\t\nID : %d \n", registros[i].idEstudante);
            printf("Nome Estudande: %s ", registros[i].nomeEstudante);
            printf("|| Numero : %d \n", registros[i].nrEstudante);
            printf("Código Curso %d ", registros[i].codigoCursoEstudante);
            printf("|| Email : %s \n", registros[i].emailEstudante);
            printf("------------------------------------------------"); 
    }
    fclose(arquivoDados);
}

//#### 07 - FUNÇÕES DE REGISTOS DE UNIDADES CURRICULARES ####
int gerarIdUnidadeCurricular( t_uc* ucs, int totalUCs){
    int novoId=totalUCs++;
    for (int  i = 0; i < totalUCs; i++)
    {
        if(ucs[i].idUnidadeCurricular == novoId)
        {
            return gerarIdUnidadeCurricular(ucs,totalUCs);
        }
    }
    return novoId;
}

int registarDadosUnidadeCurricular(t_uc* unidadeCurricular, int* totalUCs)
{
    char opcao;
    do
    {
        unidadeCurricular->idUnidadeCurricular = gerarIdUnidadeCurricular(unidadeCurricular, *totalUCs);

        printf("Entre com o CÓDIGO da unidade curricular: \n");
        scanf("%d", &(unidadeCurricular->codigoUnidadeCurricular));
        printf("Entre com o NOME da unidade curricular: \n");
        fflush(stdin);
        scanf("%49[^\n]", unidadeCurricular->nomeUnidadeCurricular);
        if (strlen(unidadeCurricular->nomeUnidadeCurricular) > 50)
        {
            printf("Nome da unidade curricular possui mais de 50 caracteres.\n");
        }
        else
        {
            printf("Entre com o ANO CURRICULAR: \n");
            scanf("%5s", unidadeCurricular->anoCurricular);
            printf("Entre com o SEMESTRE CURRICULAR: \n");
            scanf("%10s", unidadeCurricular->semestreCurricular);
            printf("Entre com os ECTS da unidade curricular: \n");
            scanf("%d", &unidadeCurricular->ectsUnidadeCurricular);
            printf("Deseja inserir outra unidade curricular?\n");
            scanf(" %c", &opcao);
        }
    } while (opcao!= 'n' && opcao !='N');

    gravacaoDadosUnidadeCurricular(unidadeCurricular);
    return 0;
    
}

void gravacaoDadosUnidadeCurricular(t_uc* unidadeCurricular)
{
    FILE* arquivoDadosUC = fopen("arquivoUC.bin","ab");

    if(arquivoDadosUC == NULL)
    {
        printf("Erro abertura arquivo!!!!\n");
        return;
    }
    fwrite(unidadeCurricular, sizeof(t_uc), 1,arquivoDadosUC);
    fclose(arquivoDadosUC);
    printf("Dados gravados com sucesso em ficheiro");
}

int compararIDUnidadeCurricular(const void* a, const void* b)
{
    const t_uc* ucA = (const t_uc*)a;
    const t_uc* ucB = (const t_uc*)b;
    return ucA->idUnidadeCurricular - ucB->idUnidadeCurricular;
}

void lerDadosUnidadeCurricular(t_uc* unidadeCurricular)
{
    FILE* arquivoDadosUC = fopen("arquivoUC.bin", "rb");

    if (arquivoDadosUC == NULL)
    {
        printf("\nArquivo nao encontrado ou corrompido!\n");
        return;
    }

    int totalUCsLidos = 0;
    system("clear");
    while (fread(&unidadeCurricular[totalUCsLidos], sizeof(t_uc), 1, arquivoDadosUC) > 0)
    {
        totalUCsLidos++;
    }

    qsort(unidadeCurricular, totalUCsLidos, sizeof(t_uc), compararIDUnidadeCurricular);

    for (int i = 0; i < totalUCsLidos; i++)
    {
        printf("\t\t\nID Unidade Curricular: %d \n", unidadeCurricular[i].idUnidadeCurricular);
        printf("Código Unidade Curricular: %d \n", unidadeCurricular[i].codigoUnidadeCurricular);
        printf("Nome Unidade Curricular: %s \n", unidadeCurricular[i].nomeUnidadeCurricular);
        printf("Ano Curricular: %s \n", unidadeCurricular[i].anoCurricular);
        printf("Semestre Curricular: %s \n", unidadeCurricular[i].semestreCurricular);
        printf("ECTS Unidade Curricular: %d \n", unidadeCurricular[i].ectsUnidadeCurricular);
        printf("------------------------------------------------\n");
    }

    fclose(arquivoDadosUC);
}

//#### 08 - FUNÇÕES DE REGISTAR AVALIAÇÕES ####

int gerarIdAvaliacao(int* proximoIdAvaliacao, t_avaliacao* registros, int totalRegistros)
{
    int novoId = (*proximoIdAvaliacao)++;
    for (int i = 0; i < totalRegistros; i++) {
        if (registros[i].idAvaliacao == novoId) {
            return gerarIdAvaliacao(proximoIdAvaliacao, registros, totalRegistros);
        }
    }
    return novoId;
}
int cadastrarAvaliacao(int* proximoIdAvaliacao, t_avaliacao* registros, int* totalRegistros, t_avaliacao avaliacao)
{
    char opcao;
    
  
    do{ 
        avaliacao.idAvaliacao = gerarIdAvaliacao(proximoIdAvaliacao, registros, *totalRegistros);
        printf("Entre com o ID do Estudante: \n");
        scanf("%d", &(avaliacao.idEstudante));
        printf("Entre com o ID da Unidade Curricular: \n");
        scanf("%d", &(avaliacao.idUnidadeCurricular));
        printf("Entre com o Ano Letivo: \n");
        scanf("%6s", avaliacao.anoLetivo);
        printf("Entre com a Época da Avaliação: \n");
        scanf("%39s", avaliacao.epocaAvaliacao);
        printf("Entre com a Data da Avaliação (formato DD/MM/AAAA): \n");
        scanf("%9s", avaliacao.dataAvaliacao);
        printf("Entre com a Classificação Final: \n");
        scanf("%d", &(avaliacao.classificacaoFinal));

        printf("Deseja inserir outra avaliação? (s/n)\n");
        scanf(" %c", &opcao);
        
    } while (opcao !='n' && opcao !='N');
   gravacaoAvaliacoes(&avaliacao);
    return 0 ;
}

void gravacaoAvaliacoes(t_avaliacao* avaliacao) {
    FILE* arquivoAvaliacoes = fopen("arquivoAvaliacoes.bin", "ab");

    if (arquivoAvaliacoes == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return;
    }

    fwrite(avaliacao, sizeof(t_avaliacao), 1, arquivoAvaliacoes);
    fclose(arquivoAvaliacoes);

    printf("Dados da avaliação gravados com sucesso no arquivo!\n");
}
int compararIDAvaliacoes(const void *a, const void *b)
{
    const t_avaliacao *avaliacaoA = (const t_avaliacao *)a;
    const t_avaliacao *avaliacaoB = (const t_avaliacao *)b;
    return avaliacaoA->idAvaliacao - avaliacaoB->idAvaliacao;
}

void lerAvaliacoes(t_avaliacao* registros, int totalRegistros)
{
    FILE* arquivoAvaliacoes = fopen("arquivoAvaliacoes.bin", "rb");
    
    if(arquivoAvaliacoes == NULL)
    {
        printf("\nArquivo nao encontrado ou corrompido!");
        return;
    }
   
    
    int totalAvaliacoes = 0;
    system("clear");

    while (fread(&registros[totalAvaliacoes],sizeof(t_avaliacao),1,arquivoAvaliacoes)>0)
    {
        totalAvaliacoes++;     
    }
    qsort(registros,totalRegistros,sizeof(t_avaliacao), compararIDAvaliacoes);
    for (int i = 0; i < totalAvaliacoes; i++) {
        printf("\t\t\nID da Avaliação: %d \n", registros[i].idAvaliacao);
        printf("ID do Estudante: %d \n", registros[i].idEstudante);
        printf("ID da Unidade Curricular: %d \n", registros[i].idUnidadeCurricular);
        printf("Ano Letivo: %s \n", registros[i].anoLetivo);
        printf("Época da Avaliação: %s \n", registros[i].epocaAvaliacao);
        printf("Data da Avaliação: %s \n", registros[i].dataAvaliacao);
        printf("Classificação Final: %d \n", registros[i].classificacaoFinal);
        printf("------------------------------------------------\n");
    }

    fclose(arquivoAvaliacoes);
}






//#### 09 - FUNÇÕES DE CALCULOS ####
/*
int telaAgradecimento(){

    printf("++++++++++++++++++++++++++");
    return 0;
}
*/

