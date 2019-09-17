#include <stdio.h>
#include <string.h>
#include <locale.h>


//Struct do contato
typedef struct {
  char nome[30];
  char IP[17];
} tContato;

//Varável/Array global dos contatos
tContato _contatos[30];

//Variável global da posição
int posicao = 0;


//Função com o número de contatos cadastrados
int numeroContatos() {
  int i;
  char stringNula[] = "";
  for (i=0;strcmp(_contatos[i].nome,stringNula) != 0;i++) {
  }
  return i;
}



//Função de Cadastro 
int cadastrar(){
    int resposta;

    do{
    printf("\33[H\33[2J"); 
    printf ("_/*\\_ CADASTRO DE USUÁRIOS_/*\\_ \n\n");
    //Função para pesquisar um espaço do array vazio
    posicao = numeroContatos();
    printf ("Digite o nome de contato: ");
    fgets(_contatos[posicao].nome, 30, stdin);
    printf ("Digite o número de IP do contato: ");
    fgets (_contatos[posicao].IP, 16, stdin);
    printf ("\n\nDigite 1 para cadastrar um novo usuário e 0 para retornar ao menu: ");
    scanf ("%i", &resposta);
    getchar();
    } while (resposta != 0);
    printf("\33[H\33[2J");
  return 0;
}

//Função que exibe a lista de amigos, sendo passado como parâmetro o número de contatos salvos até o momento.
void exibirAmigos(int nContatos){
  int aux;
  int escolha = 0;
  printf("\e[H\e[2J");
  printf ("***********************LISTA DE AMIGOS*************************");
  for (aux = 0;aux < nContatos;aux++) {
      printf ("\n[%d]%s",aux,_contatos[aux].nome);
      printf ("%s\n",_contatos[aux].IP);
  }
}

void remover(tContato *amigos, int i, int numeroDeContatos){
    i++;
    
    //while para mover o conteudo de todos os contatos para o anterior, isso apenas para os contatos que ficam depois do que foi excluido
    while(i<numeroDeContatos){ 
      
      strcpy(amigos[i-1].nome, amigos[i].nome);
      strcpy(amigos[i-1].IP, amigos[i].IP);
      i++;
    }
    
    i--;
    char stringNula[] = "";
    
    //Corrigir o conteudo da ultima string, deixando vazia
    strcpy(amigos[i].nome, stringNula);
    strcpy(amigos[i].IP, stringNula);
  }











void MenuRemocao(){

  printf("===================Remoção de contatos===================\n\n");


  int i = 0;
  int escolha = 0;
  char verificacao = ' ';
  int numeroDeContatos = 0;
  
  //loop para decidir se continua removendo ou se volta para o menu
  do{
    numeroDeContatos = numeroContatos(); //atualizar o numero de Contato
    
    //loop para decidir qual contato excluir
    do{
      exibirAmigos(numeroDeContatos); //exibir a lista de amigos

      printf("Digite o número correspondente ao contato que deseja remover: ");
      scanf("%i", &i);
      getchar();

      printf("Tem certeza que deseja remover o %s ? [s/n]", _contatos[i].nome);
      scanf("%c", &verificacao);
      getchar();
      
    }while(verificacao!='s');

    remover(_contatos, i, numeroDeContatos);
    numeroDeContatos = numeroContatos();
    exibirAmigos(numeroDeContatos);
    
    printf("\n\nDigite 1 para remover outro contato ou 0 para voltar ao menu\n");
    scanf("%i", &escolha);
    printf("\e[H\e[2J");
    
  }while(escolha==1);
}

void conversar(){
  int escolhaUsuario;
  exibirAmigos(numeroContatos());
  printf("\n \n Digite o número do contato que deseja se comunicar: ");
  scanf("%i",&escolhaUsuario);
  getchar();
}

int main(){
    //Função para habilitar Acentos
    setlocale(LC_ALL, "Portuguese");
    int escolhaUsuario,escolha;
    while (escolhaUsuario != 4){
      printf("/////////////////////////////////////////\n");
      printf(" Digite 0 para mostrar a lista de amigos\n Digite 1 para adicionar um amigo\n Digite 2 para conversar com um amigo\n Digite 3 para excluir um amigo da lista\n Digite 4 para sair\n");
      printf("/////////////////////////////////////////\n");
      scanf("%d", &escolhaUsuario);
      getchar();
      //printf("o valor escolhido eh %i ", escolhaUsuario);
      if (escolhaUsuario >= 0 && escolhaUsuario <= 4){ 
      switch(escolhaUsuario)
         {
        case 0:
          exibirAmigos(numeroContatos());
          //segura a fita pra não sair do loop
          printf ("\n\nDigite 0 para retornar a tela inicial: ");
          scanf ("%i", &escolha);
          getchar();
          printf("\e[H\e[2J"); 
          break;
        case 1:
          cadastrar();
          break;
        case 2:
          //função para conversar
          conversar();
          printf("\e[H\e[2J"); 
          break;
        case 3:
          MenuRemocao();
          break;
        case 4:
          //função para sair do programa
          break;
        default:
          printf("\e[H\e[2J"); // dá um clear na tela
          printf("Quer quebrar o código, fdp? Digita isso certo\n\n");
         }
      }
	else if(escolhaUsuario < 0 || escolhaUsuario > 4){
		printf("Valor inválido. Digite novamente!\n");
                getchar();
					
	}
     
    }
    printf("\nFim do Programa! Esse aqui é só o básico, compre a versão pro para Windows Phone!!");
    return 0;
}
