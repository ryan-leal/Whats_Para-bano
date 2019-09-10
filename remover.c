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
