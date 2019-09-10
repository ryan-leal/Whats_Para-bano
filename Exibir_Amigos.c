//Função que exibe a lista de amigos, sendo passado como parâmetro o número de contatos salvos até o momento.
void exibirAmigos(int i){
  int aux;
  printf ("***********************LISTA DE AMIGOS*************************");
  for (aux = 0;aux < i;aux++) {
      printf ("[%d]%s",aux,_contatos[aux].nome);
      printf ("[%d]%s\n",aux,_contatos[aux].IP);
  }

}
