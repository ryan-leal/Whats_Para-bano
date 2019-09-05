#include <stdio.h>
#include <string.h>
#include <locale.h>

//Struct do contato
typedef struct {
  char nome[30];
  char IP[16];
} tContato;

//Varável/Array global dos contatos
tContato _contatos[30];

//Função de Cadastro 
int cadastrar(){
    int posicao = 0;
    printf ("////////////////////////////CADASTRO DE USUÁRIOS////////////////////////////////////////\n\n");
    //Função para pesquisar um espaço do array vazio
    //posicao = encontrarPosicao();
    printf ("Digite o nome de contato: ");
    fgets(_contatos[posicao].nome, 30, stdin);
    printf ("Digite o número de IP do contato: ");
    fgets (_contatos[posicao].IP, 16, stdin);

  return 0;
}



int main(void) {
  //Função para habilitar Acentos
  setlocale(LC_ALL, "Portuguese");
  //Chamando função de Cadastro
  cadastrar();
  printf("%s",_contatos[0].nome);
  printf("%s",_contatos[0].IP);
  return 0;
}
