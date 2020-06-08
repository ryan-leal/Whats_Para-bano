//Função que retorna a quantidade de contatos salvos até então.
int numeroContatos() {
  int i;
  for (i=0;strcmp(_contatos[i].nome,"") != 0;i++) {
  }
  return i;
}
