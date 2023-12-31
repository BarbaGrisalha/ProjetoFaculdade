
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Definição da estrutura
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

typedef struct 
{
    int idEstudante;
    int nrEstudante;
    char nomeEstudante[50];
    int codigoCursoEstudante;
    char emailEstudante[50];
    int totalAvaliacoes;
    Avaliacao avaliacoes[50];
    
}Estudante;

typedef struct 
{
    int idUnidadeCurricular;
    int codigoUnidadeCurricular[7];
    char nomeUnidadeCurricular[50];
    char anoCurricular[6];
    char semestreCurricular[11];
    int ectsUnidadeCurricular;
     int totalAvaliacoes;
    Avaliacao avaliacoes[50];
}Uc;



//###### função declarada   ######
int menu();
void desenhar(int,int);
int registarDadosEstudantes(Estudante* estudante);
void gravacaoDados(Estudante* estudante);
int registarDadosUc(Uc* unidade_curricular);
void registarAvaliacao(Estudante* estudante, Uc* unidade_curricular);
void mostrarAvaliacoes(Estudante* estudante);
int menuAvaliacao();

//###### MAIN    ######
int main ()
{
    int opcao;
    //system("clear");
    Estudante estudante; //Variável para armazenar os dados do estudante
    Uc unidade_curricular; //Varíavel para guardar as informações da Unidade Curricular
   
    
    do
    {
        opcao=menu();
        switch (opcao)
        {
            case 1:
                printf("Registar Dados Estudante :");
                registarDadosEstudantes(&estudante);//Passando o endereço da variável
                gravacaoDados(&estudante);//Chamando aqui a função com o endereço da variável
                fflush(stdin);
                getchar();
                break;
            case 2:
                printf("Selecionou 2\n");
                registarDadosUc(&unidade_curricular);
                fflush(stdin);
                break;
            case 3:
                printf("Selecionou 3\n");
                menuAvaliacao();
                //registarAvaliacao(&estudante,&unidade_curricular);
                fflush(stdin);
                getchar();
                break;
            case 4:
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
    
    gravacaoDados(&estudante);

    do
    {
       opcao = menuAvaliacao();
       switch (opcao)
       {
       case 1/* constant-expression */:
        registarAvaliacao(&estudante,&unidade_curricular);
        break;

        case 2:
        mostrarAvaliacoes(&estudante);
        break;

        case 0:
        menu();
       
       default:
        break;
       } /* code */
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
        printf("\t\t\t#        Menu Principal                 #\n");
        printf("\t\t\t#                                       #\n");
        printf("\t\t\t#  [1] Registar Dados Estudante         #\n");
        printf("\t\t\t#  [2] Unidades Curriculares - UC       #\n");
        printf("\t\t\t#  [3] Avaliações                       #\n");
        printf("\t\t\t#  [4] N/U - Nao utilizado              #\n");
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

void gravacaoDados(Estudante* estudante) {
    FILE *arquivoDados; // Criando a variável ponteiro para o arquivo

    arquivoDados = fopen("arquivo.txt", "a"); // Abrindo o arquivo no modo de adição ("a")

    // Verificando se o arquivo foi aberto corretamente
    if (arquivoDados == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Gravando os dados no arquivo
    fprintf(arquivoDados, "%d,%d,%s,%d,%s\n", estudante->idEstudante, estudante->nrEstudante, estudante->nomeEstudante, estudante->codigoCursoEstudante, estudante->emailEstudante);

    fclose(arquivoDados); // Fechando o arquivo

    printf("Dados gravados com sucesso no arquivo!\n");
}

int registarDadosUc(Uc* unidade_curricular){
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

void registarAvaliacao(Estudante* estudante, Uc* unidade_curricular)// Passando parâmetros por referência 
 {
if(estudante->totalAvaliacoes <50 && unidade_curricular->totalAvaliacoes <50){
    Avaliacao novaAvaliacao;

    printf("\n Entre com o ID da avaliação : \n");
    scanf("%d",&novaAvaliacao.idAvaliacao);
    // Preencha os detalhes da avaliação, como a nota, a data, etc.

        // Adiciona a nova avaliação ao estudante e à unidade curricular
        estudante->avaliacoes[estudante->totalAvaliacoes] = novaAvaliacao;
        unidade_curricular->avaliacoes[unidade_curricular->totalAvaliacoes] = novaAvaliacao;

        // Incrementa o contador de avaliações
        estudante->totalAvaliacoes++;
        unidade_curricular->totalAvaliacoes++;
         printf("Avaliacao registrada com sucesso!\n");
}
else {
        printf("Nao foi possivel adicionar mais avaliacoes. Limite atingido.\n");
    }

}

float calcularMedia(Estudante* estudante){
    float soma = 0;

    for(int i= 0;i < estudante->totalAvaliacoes;i++){
        soma += estudante->avaliacoes[i].classificacaoFinal;
    }
    if(estudante->totalAvaliacoes >0){
        return soma/estudante->totalAvaliacoes;
    }else{
        return 0.0;
    }
}

void mostrarAvaliacoes(Estudante* estudante){
    printf("\nAvaliacoes do estudante:\n");
    for (int i = 0; i < estudante->totalAvaliacoes; i++)
    {
        printf("ID Avaliacao: %d, Nota: %d\n",estudante->avaliacoes[i].idAvaliacao, estudante->avaliacoes[i].classificacaoFinal);
    }
    
}


int menuAvaliacao()
{
    //Registar e consultar os dados das avaliações;
    int opcao;
    system("clear");
  
        printf("\t\t\t#########################################\n");
        printf("\t\t\t#                                       #\n");
        printf("\t\t\t#         Menu Avaliacoes               #\n");
        printf("\t\t\t#                                       #\n");
        printf("\t\t\t#  [1] Registar Dados Avaliacoes        #\n");
        printf("\t\t\t#  [2] Mostrar Avaliacoes               #\n");
        printf("\t\t\t#  [3] N/U - Nao Utilizada              #\n");
        printf("\t\t\t#  [4] N/U - Nao Utilizada              #\n");
        printf("\t\t\t#  [0] Voltar                           #\n");
        printf("\t\t\t#                                       #\n");
        printf("\t\t\t#      Insira a opção desejada:         #\n");
        printf("\t\t\t#########################################\n");
        scanf("%d", &opcao);
    
    return opcao;
}













int telaAgradecimento(){

    printf("++++++++++++++++++++++++++");
}