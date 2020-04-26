#include <stdio.h>

int main(){
  int idade = 0;
  
  printf("Digite a sua idade por-favor: ");
  scanf("%d", &idade);
  
  while(idade < 0 || idade > 100){
    printf("ERRO!!!\nPor-favor digite uma idade entre 0 a 100 anos de idade: ");
    scanf("%d", &idade);
  }
  
  //hrmax -> frequência cardiaca máxima
  int hrmax = 207 - (idade * 0.7);
  
  printf("Idade: %d\nHrmax: %d bpm\nHrmax -> Frequência cardiaca máxima", idade, hrmax);
  
  return 0;
}
