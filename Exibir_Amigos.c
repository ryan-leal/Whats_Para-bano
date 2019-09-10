void exibirAmigos(int i){
  int aux;
  printf ("***********************LISTA DE AMIGOS*************************");
  for (aux = 0;aux < i;aux++) {
      printf ("[%d]%s",aux,_contatos[aux].nome);
      printf ("[%d]%s\n",aux,_contatos[aux].IP);
  }

}
