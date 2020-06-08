
void MenuRemocao(){
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
      exibirAmigos(); //exibir a lista de amigos

      printf("Digite o número correspondente ao contato que deseja remover: \n");
      scanf("%i", &i);

      printf("Tem certeza que deseja remover o %s ? [s/n]", _contatos.nome);
      scanf("%c", &verificacao);
      
    }while(verificacao!='s');

    remover(_contatos, i, numeroDeContatos);
    exibirAmigos();
    
    printf("\n\nDigite 1 para remover outro contato ou 0 para voltar ao menu\n");
    scanf("%i", &escolha);
    
  }while(escolha==1);

  return 0;
}
