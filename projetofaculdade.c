
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Definição da estrutura

typedef struct 
{
    int idEstudante;
    int nrEstudante;
    char nomeEstudante[50];
    int codigoCursoEstudante;
    char emailEstudante[50];
    
}Estudante;

typedef struct 
{
    int idUnidadeCurricular;
    int codigoUnidadeCurricular[7];
    char nomeUnidadeCurricular[50];
    char anoCurricular[6];
    char semestreCurricular[11];
    int ectsUnidadeCurricular;
}Uc;

typedef struct 
{
   int idAvaliacao;
   int idEstudante;
   int idUnidadeCurricular;
   char anoLetivo[7];
   char epocaAvaliacao[40];
   char dataAvaliacao[10];
   int classificacaoFinal;
}Avaliacao;

//###### função declarada   ######
int menu();
void desenhar(int,int);
int registarDadosEstudantes(Estudante* estudante);
//###### MAIN    ######
int main ()
{
    int opcao;
    //system("clear");
    Estudante estudante; //Variável para armazenar os dados do estudante
    
    do
    {
        opcao=menu();
        switch (opcao)
        {
            case 1:
                //printf("Selecionou 1\n");
                printf("Registar Dados Estudante :");
                registarDadosEstudantes(&estudante);//Passando o endereço da variável

                fflush(stdin);
                getchar();
                break;
            case 2:
                printf("Selecionou 2\n");
                fflush(stdin);
                break;
            case 3:
                printf("Selecionou 3\n");
                fflush(stdin);
                getchar();
                break;
            case 0:
                exit(0);
                system("cls");
                //printf("Selecionou 0\n");
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
    

    return 0;
}

//#### funções criada ####
int menu()
{
    //Registar e consultar os dados dos estudantes;
    int opcao;
    system("clear");
  
        printf("\t\t\t#########################################\n");
        printf("\t\t\t#                                       #\n");
        printf("\t\t\t#                  Menu                 #\n");
        printf("\t\t\t#                                       #\n");
        printf("\t\t\t#  [1] Registar Dados Estudante         #\n");
        printf("\t\t\t#  [2] Unidades Curriculares - UC       #\n");
        printf("\t\t\t#  [3] Avaliações                       #\n");
        printf("\t\t\t#  [0] Sair                             #\n");
        printf("\t\t\t#                                       #\n");
        printf("\t\t\t#      Insira a opção desejada:         #\n");
        printf("\t\t\t#########################################\n");
        scanf("%d", &opcao);
    
    return opcao;
}

int registarDadosEstudantes(Estudante* estudante)
{
    char opcao;
    do{
        printf("\nEntre com o ID do estudante: \n");
        scanf("%d",&(estudante->idEstudante));
        printf("Entre com o NR do estudante: \n");
        scanf("%d",&(estudante->nrEstudante));
        printf("Entre com o NOME do estudante: \n");
        fflush(stdin);
        scanf("%50[^\n]",&(estudante->nomeEstudante));
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
            scanf("%[^\n]",&(estudante->emailEstudante[50]));
            printf("Deseja inserir outro estudante?\n");
            scanf(" %c", &opcao);//aqui é importante ainda dar um enter após escolher o n ou s.
        }
    } while (opcao !='n' && opcao !='N');
    return 0 ;
}
/*
void consultarDadosEstudante(struct Estudante estudante)
{
   
    estudante.nomeEstudante;
    estudante.nomeUnidadeCurricular;
    
    printf("Dados inseridos na struct estudantes.");
    printf(estudante.nomeEstudante);

   
}

*/
