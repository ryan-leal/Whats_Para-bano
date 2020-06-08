#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
/* Bibliotecas usadas para criar a conexão usando sockets
	e enviar dados pela rede*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* Constante que define o tamanho máximo da mensagem enviada ou recebida*/
#define TAM_MAX 100
/* Constante que define a porta utilizada para conexão */
#define PORTA 12345

/* Variáveis globais usadas na conexão, envio e recebimento de dados*/
static int sockfd, newFD;


/*
	Função que cria uma conexão com o cliente.
	A função é bloqueante e fica esperando um pedido de conexão do cliente.
	Quando esse pedido é feito pelo cliente, se estiver tudo ok, a conexão é aceita.
	Retorno: 1 se a conexão foi realizada com sucesso e -1 caso contrário.
 */
int conecta(){
	struct sockaddr_in myAddr;
	struct sockaddr_in cliente;

	// Cria o socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if ( sockfd ==-1){
		printf("Socket não pode ser criado\n");
		return -1;
	}

	//Prepara a estrutura sockaddr_in
	myAddr.sin_family = AF_INET; 			// Protocolo IP
	myAddr.sin_addr.s_addr = INADDR_ANY; 	// Permite receber conexoes de qualquer cliente
	myAddr.sin_port = htons( PORTA ); 		// Porta utilizada na conexão

	//Bind
	if(bind(sockfd,(struct sockaddr *)&myAddr , sizeof(myAddr)) < 0){
    	printf("Bind falhou\n");
	}
	printf("Bind feito com sucesso\n");

    //Listen
    listen(sockfd, 3);

    // Esperando e aceitando conexões
    printf("Esperando por conexões...\n");
    int c = sizeof(struct sockaddr_in);
    newFD = accept(sockfd, (struct sockaddr *)&cliente,
    	(socklen_t*)&c);

    if (newFD<0){
        printf("Conexão não aceita\n");
    }

    printf("Conexão aceita de %s \n", inet_ntoa(cliente.sin_addr));
    return 1;
}

/**
	Envia uma mensagem (pacote) pela rede para o cliente conectado.
	Parametros: uma string com a mensagem a ser enviada e o tamanho (numero de bytes) dessa string.
	IMPORTANTE: A mensagem só será recebida se o cliente tiver chamada a função para receber a mensagem.
	Retorno: o número de bytes enviados na mensagem
 */
int enviaMensagem(char *msg, int tamMsg){
	return send(newFD, msg, tamMsg, 0);
}

/**
	Recebe uma mensagem (pacote) do cliente conectado.
	A função é bloqueante, e fica esperando o cliente enviar o pacote.
	Parametros: uma string com a mensagem a ser enviada e o tamanho maximo de caracteres que podem ser preenchidos na mensagem.
	Retorno: número de bytes recebidos na mensagem
 */
int recebeMensagem(char *msg, int tamMsg){

	return recv(newFD, msg, tamMsg, 0);
}





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
    system ("clear");
    printf ("_/*\\_ CADASTRO DE USUÁRIOS_/*\\_ \n\n");
    //Função para pesquisar um espaço do array vazio
    posicao = numeroContatos();
    printf ("Digite o nome de contato: ");
    scanf("%[^\n]s",_contatos[posicao].nome);
    getchar();
    printf ("Digite o número de IP do contato: ");
    scanf("%[^\n]s",_contatos[posicao].IP);
    getchar();
    printf ("\n\nDigite 1 para cadastrar um novo usuário e 0 para retornar ao menu: ");
    scanf ("%i", &resposta);
    getchar();
    } while (resposta != 0);
    system ("clear");
  return 0;
}

//Função que exibe a lista de amigos, sendo passado como parâmetro o número de contatos salvos até o momento.
void exibirAmigos(int nContatos){
  int aux;
  int escolha = 0;
  system ("clear");
  printf ("***********************LISTA DE AMIGOS*************************");
  for (aux = 0;aux < nContatos;aux++) {
      printf ("\n[%d]%s",aux,_contatos[aux].nome);
      printf ("\n");
      printf ("%s\n",_contatos[aux].IP);
  }
}

//Função de Remoção
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


//Menu de remoção
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
    system ("clear");

  }while(escolha==1);
}

void conversar(){
  int contador = 0;
  int ret;
  int tamMsg;
  char msgEnv[TAM_MAX];
  char msgRec[TAM_MAX];
  int escolhaUsuario;

  do {
      exibirAmigos(numeroContatos());
      printf("\n \n Digite o número do contato que deseja se comunicar ou digite 123: ");
      scanf("%i",&escolhaUsuario);
      getchar();
      if (escolhaUsuario == 123) {
        return;
      }
      system ("clear");
      ret = conecta();
      system ("clear");
      printf ("Bem-Vindo ao chat Digite /m para voltar ao menu ou /l para voltar para a lista de amigos\n\n");
      while (ret != -1){


              memset(msgEnv, 0, sizeof(tContato));
              memset(msgRec, 0, sizeof(tContato));

              /* Recebe uma mensagem pela rede */
              ret = recebeMensagem(msgRec, TAM_MAX);
              
              if (strcmp(msgRec, "/s") == 0) {
                 printf("O usuário desconectou-se digite 0 para voltar ao menu ou digite 1 para retornar a lista de amigos: ");
                 scanf("%i", &escolhaUsuario);
                 getchar();
                        if (escolhaUsuario == 0) {
                            return;
                        } else if (escolhaUsuario == 1) {
                            break;
                        }
              }

              printf("\nMsg recebida: %s \n", msgRec);

              /* Lê uma mensagem do usuário e envia pela rede*/
              printf("\nDigite a mensagem para enviar: ");
              scanf("%[^\n]s",msgEnv);
              getchar();
              tamMsg = strlen(msgEnv);

               //if para sair da conversa/ir para o menu
	           if ((strcmp(msgEnv,"/m")==0)||(strcmp(msgEnv,"/l")==0)){
	              enviaMensagem("/s", tamMsg);
	              break;
               }

	         ret = enviaMensagem(msgEnv, tamMsg);

	        // printf("Enviou uma mensagem com %d bytes\n", ret);
             if (ret == -1) {
                break;
             }




	  }
	//Comparação para ficar na lista
  }while((strcmp(msgEnv, "/m")!=0));
  system ("clear");

}

int main(){
	system ("clear");
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
          system ("clear");
          break;
        case 1:
          cadastrar();
          break;
        case 2:
          //função para conversar
          conversar();
          system ("clear");
          break;
        case 3:
          MenuRemocao();
          break;
        case 4:
          //função para sair do programa
          break;
        default:
          system ("clear"); // dá um clear na tela
          printf("Quer quebrar o código, fdp? Digita isso certo\n\n");
         }
      }
	else if(escolhaUsuario < 0 || escolhaUsuario > 4){
		system ("clear");
		printf("Valor inválido. Digite novamente!\n");
                getchar();

	}

    }
    printf("\nFim do Programa! Esse aqui é só o básico, compre a versão pro para Windows Phone!!");
    return 0;
}

