#include<stdio.h>

int main(){
    int escolhaUsuario;
    while (escolhaUsuario != 4){
      printf("/////////////////////////////////////////\n");
      printf(" Digite 0 para mostrar a lista de amigos\n Digite 1 para adicionar um amigo\n Digite 2 para conversar com um amigo\n Digite 3 para excluir um amigo da lista\n Digite 4 para sair\n");
      printf("/////////////////////////////////////////\n");
      scanf("%d", &escolhaUsuario);
      //printf("o valor escolhido eh %i ", escolhaUsuario);
      if (escolhaUsuario >= 0 && escolhaUsuario <= 4){ 
      switch(escolhaUsuario)
         {
        case 0:
          //função que mostra a lista de amigos
          break;
        case 1:
          //função que adiciona um amigo
          break;
        case 2:
          //função para conversar
          break;
        case 3:
          //função para excluir um amigo
          break;
        case 4:
          //função para sair do programa
          break;
        default:
          printf("\e[H\e[2J"); // dá um clear na tela
          printf("Digite uma opção válida, por favor\n\n");
         }
      }
	else if(escolhaUsuario < 0 || escolhaUsuario > 4){
		printf("Valor inválido. Digite novamente!\n");
                getchar();
					
	}
     
    }
    printf("\nFim do Programa! Compre a versão pro para Windows Phone!!");
    return 0;
}
