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

//Função com o número de contatos cadastrados
int numeroContatos() {
  int i;
  for (i=0;strcmp(_contatos[i].nome,"") != 0;i++) {
  }
  return i;
}


//Função de Cadastro 
int cadastrar(){
    int posicao = 0;
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



int main(void) {
  //Função para habilitar Acentos
  setlocale(LC_ALL, "Portuguese");
  //Chamando função de Cadastro
  cadastrar();
  return 0;
}
