
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
    char anoCurricular[6];
    char semestreCurricular[11];
    int ectsUnidadeCurricular;
    int totalAvaliacoes;
}t_uc;

//#### 02 - DECLARACAO DE FUNCOES  #### 
int menuPrincipal();
void desenhar(int,int);
int registarDadosEstudantes(t_estudante* estudante);
void gravacaoDados(t_estudante* estudante);
void lerDadosEstudantes(t_estudante* estudante);
int registarDadosUc(t_estudante* estudante,t_uc* unidade_curricular);
void registarAvaliacao(t_estudante* estudante, t_uc* unidade_curricular);
void mostrarAvaliacoes(t_estudante* estudante);
int menuAvaliacao();
int menuDadosEstudantes(t_estudante* estudante);
int menuUnidadeCurricular();
int menuEstatistico();

//####  03 - MAIN    #### 
int main ()
{
    int opcao;
    t_estudante estudante; //Variável para armazenar os dados do estudante
    t_uc unidade_curricular; //Varíavel para guardar as informações da Unidade Curricular
    t_avaliacao avaliacao; //Variável para guardar as informações d avaliação
   
    //### 03.1 Menu Principal
    do
    {
        opcao=menuPrincipal();
        switch (opcao)
        {
            case 1:
                registarDadosEstudantes(&estudante);//DONE
                fflush(stdin);
                getchar();
                break;
            case 2:
                lerDadosEstudantes(&estudante);
                //fflush(stdin);
                //getchar();
                break;
            case 3:
                //menuAvaliacao();
                fflush(stdin);
                getchar();
                break;
            case 4:
                ///menuEstatistico();
                fflush(stdin);
                getchar();
                break;   
            case 0:
                exit(0);
                system("cls");
                fflush(stdin);
                getchar();
                break;       
            default:
                printf("Opção inválida. Tente Novamente!\n");
                fflush(stdin);
                getchar();
                break;
        }
        
    } while (opcao !=0);
    
    gravacaoDados(&estudante);
    
    return 0;
}

//#### 04 - FUNÇÕES DE MENUS #### 
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
    
    return opcao;
}

//#### 05 - FUNÇÕES DE REGISTOS ####

int registarDadosEstudantes(t_estudante* estudante)//Passando por paremetro a variável estudante da Struct Estudante
{
    char opcao;
    do{
        printf("\nEntre com o ID do estudante: \n");
        scanf("%d",&(estudante->idEstudante));
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
    return 0 ;
}

void gravacaoDados(t_estudante* estudante) {
    FILE *arquivoDados = fopen("arquivoEstudante.bin","wb"); // Criando a variável ponteiro para o arquivo

    if(arquivoDados == NULL){
        perror("Erro na abertura do arquivo!");//TESTE DE PERROR EM E VEZ DE PRINTF
        return;
    }

    // Gravando os dados no arquivo
   // fprintf(arquivoDados, "%d,%d,%s,%d,%s\n", estudante->idEstudante, estudante->nrEstudante, estudante->nomeEstudante, estudante->codigoCursoEstudante, estudante->emailEstudante);
    fwrite(estudante,sizeof(t_estudante),1,arquivoDados);
    fclose(arquivoDados); // Fechando o arquivo

    printf("Dados gravados com sucesso no arquivo!\n");
}

void lerDadosEstudantes(t_estudante* estudante)
{
    FILE *arquivoDados = fopen("arquivoEstudante.bin","rb");
    system('clear');
    if(arquivoDados == NULL)
    {
        printf("\nArquivo nao encontrado ou corrompido!");
        return;
    }
    

    while (fread(estudante,sizeof(t_estudante),1,arquivoDados)==1)
    {
       printf("ID : %d ", estudante->idEstudante);
       printf("Numero : %d \n",estudante->nrEstudante);
       printf("Nome Estudande: %c",estudante->nomeEstudante);
       printf("Email : %s ",estudante->emailEstudante);
       printf("Código Curso %d ", estudante->codigoCursoEstudante);

    }

    fclose(arquivoDados);
}
/*
int registarDadosUc(t_estudante* estudante,t_uc* unidade_curricular){
    char opcao;

    do
    {
        printf("\nEntre com o ID da unidade curricular: \n");
        scanf("%d",&(unidade_curricular->idUnidadeCurricular));
        printf("Entre com o codigo da unidade curricular: \n");
        scanf("%d",unidade_curricular->codigoUnidadeCurricular);
        printf("Entre com o NOME da unidade curricular: \n");
        fflush(stdin);
        scanf("%49[^\n]",unidade_curricular->nomeUnidadeCurricular);
        if(strlen(unidade_curricular->nomeUnidadeCurricular)>50)
        {
            printf("Nome da UC possui mais de que 50 caractees.\n");
        }
        else
        {
            printf("\nEntre com o ano da Unidade Curricullar \n");
            scanf("%5s",unidade_curricular->anoCurricular);
            printf("\nEntre com o semestre da Unidade Curricullar \n");
            scanf("%10s",unidade_curricular->semestreCurricular);
            printf("Entre com o ects da Unidade Curricular:\n");
            scanf("%d",&(unidade_curricular->ectsUnidadeCurricular));
            printf("Deseja inserir outra Unidade Curricular?\n");
            scanf(" %c", &opcao);//aqui é importante ainda dar um enter após escolher o n ou s.
        }
    } while (opcao != 'n' && opcao != 'N');
    return 0;   
}

void registarAvaliacao(t_estudante* estudante, t_uc*  unidade_curricular)// Passando parâmetros por referência 
 {

}

//#### 06 - FUNÇÕES DE CALCULOS ####

float calcularMedia(t_estudante* estudante){
   
}

void mostrarAvaliacoes(t_estudante* estudante){
   
    
}

void calculoEstatistico()
{

    
}

void totalEctsAprovadosEstudante(){

}

void mediaClassificacaoUC(){

}

void percentagemEctsAprovadosSemestre(){


}

int telaAgradecimento(){

    printf("++++++++++++++++++++++++++");
    return 0;
}
*/

