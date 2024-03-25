#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main(){
	setlocale(LC_ALL, "Portuguese");

	printf("=======================\n");
	printf("* Jogo de adivinha��o *\n");
	printf("=======================\n");

	srand(time(NULL));
	int numerosecreto = rand() % 100;

	int chute, dificuldade, quantidadetentativas;
	double pontos = 1000;

	printf("(1) F�CIL / (2) M�DIO / (3) DIF�CIL \n");

	while(dificuldade > 3 || dificuldade < 1){
		printf("Digite a dificuldade: ");
		scanf("%d", &dificuldade);
		switch (dificuldade){
			case 1:
				quantidadetentativas = 15;
				break;
			case 2:
				quantidadetentativas = 10;
				break;
			case 3:	
				quantidadetentativas = 5;
				break;
			default:
				printf("Deve ser 1-3!!!");
				break;
		}
	}
	
	for (int i = 1; i <= quantidadetentativas; i++) {
		printf("Tentativa %d \n", i);

		printf("Qual � o seu chute?: ");
		scanf("%d", &chute);

		if (chute < 0){
			printf("Voc� n�o pode digitar n�meros negativos...");
			i--;
			continue;
		}

		printf("Seu chute foi: %d \n", chute);

		if (chute == numerosecreto) {
			printf("Voc� acertou!!! \n");
			printf("Pontos: %.2f \n", pontos);
			break;
		}

		printf("Voc� errou!!! \n");	

		if (chute > numerosecreto)
			printf("Seu chute foi maior que o n�mero secreto. \n");
		else
			printf("Seu chute foi menor que o n�mero secreto. \n");

		pontos = pontos - abs(numerosecreto - chute) / 2.0;
	}
	printf("Fim de jogo!\n");
	return 0;
}
