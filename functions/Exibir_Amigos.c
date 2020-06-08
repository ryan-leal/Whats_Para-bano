//Função que exibe a lista de amigos, sendo passado como parâmetro o número de contatos salvos até o momento.
void exibirAmigos(int nContatos){
  int aux;
  printf("\e[H\e[2J");
  printf ("***********************LISTA DE AMIGOS*************************");
  for (aux = 0;aux < nContatos;aux++) {
      printf ("[%d]%s",aux,_contatos[aux].nome);
      printf ("[%d]%s\n",aux,_contatos[aux].IP);
  }
  
}
