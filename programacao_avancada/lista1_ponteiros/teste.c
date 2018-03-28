#include <stdio.h>

/* QUESTÃO 2:

	p == &i: 1
	*p - *q: -2
	**&p: 3
	3 - *p/(*q) + 7: 10
*/
void questao_dois(){
	int i = 3, j = 5;
	int *p = &i, *q = &j;
	printf("%d\n", p == &i);
	printf("%d\n", *p - *q);
	printf("%d\n", *(*(&p)));
	printf("%d\n", 3+*p/(*q)+7);

}

/* QUESTÃO 3:
	p: 4094
	*p + 2: 7
	**&p: 5
	3**p: 15 (achei que ** seria elevado mas um * é pra multiplicar e * é pra referenciar o ponteiro)
	**&p+4: 9
*/
void questao_tres(){
	int i = 5, *p;
	p = &i;
	printf("%p\n %d\n %d\n %d\n %d\n", p, *p+2, **&p, 3**p, **&p+4);
}
/* QUESTÃO 4:
	p = i: NAO
	q = &j: SIM, vai retornar o endereço de J
	p = &*&i: SIM, vai retornar o endereço de I
	i = (*&)j: NAO
	i = *&j: SIM, vai retornar o valor de J
	i = *&*&j: SIM, vai retornar o valor de J
	q = *p: NAO
	i = (*p)++ + *q: SIM, vai retornar o valor de p+1+valor de q
*/
void questao_quatro(){
	int i = 0, j = 5;
	int *p, *q;
	//p = i;
	q = &j;
	p = &*&i;
	printf("%p\n%p\n", q, p);
	//i = (*&)j;
	i = *&j;
	printf("%d\n", i);
	i = *&*&j;
	printf("%d\n", i);
	//q = *p;
	i = (*p)++ + *q;
	printf("%d\n", i);
}

/* QUESTÃO 5:
--a--
valor: 20

--b--
temp: 29.0

--c--
aux: 'P'

--d--
aux: 'e'

--e--
aux: 'P'

--f--
aux: 'e'

--g--
aux: 't'

--h--
idade: 31

--i--
idade: 45

--j--
idade: 27

--l--
idade:31

--m--
idade:45

--n--
idade: 27
*/
void questao_cinco(){
	int valor, *p1, idade, vetor[3], *p4, *p5;
	float temp, *p2;
	char aux, *nome = "Ponteiros", *p3;

//a
	valor = 10;
	p1 = &valor;
	*p1 = 20;
	printf("%d\n", valor);

//b
	temp = 26.5;
	p2 = &temp;
	*p2 = 29.0;
	printf("%.1f \n", temp);

//c
	p3 = &nome[0];
	aux = *p3;
	printf("%c\n", aux);

//d
	p3 = &nome[4];
	aux = *p3;
	printf("%c\n", aux);

//e
	p3 = nome;
	printf("%c\n", *p3);

//f
	p3 = p3+4;
	printf("%c\n", *p3);

//g
	p3--;
	printf("%c\n", *p3);

//h
	vetor[0] = 31;
	vetor[1] = 45;
	vetor[2] = 27;
	p4 = vetor;
	idade = *p4;
	printf("%d\n", idade);

//i
	p5 = p4+1;
	idade = *p5;
	printf("%d\n", idade);
//j
	p4 = p5+1;
	idade = *p4;
	printf("%d\n", idade);

//l
	p4 = p4 - 2;
	idade = *p4;
	printf("%d \n", idade);

//m
	p5 = &vetor[2] - 1;
	printf("%d \n", *p5);

//n
	p5++;
	printf("%d \n", *p5);


}


/*  QUESTAO 6:

A cada iteração, os valores serão iguais e os endereços também.
Vai mostrando o 1.1, 2.2, 3.3, 4.4 e 5.5 duas vezes e seus respectivos endereços

Resultado: a lógica que falei estava correta, mas o compilador deu erro no

printf("&vet[%d] = %X",i, &vet[i]);
printf("(f + %d) = %X",i, f+i);

então troquei para %p e deu certo. Isso aconteceu pq era um tipo ponteiro pra float,
e %X significa unigned int.

*/
void questao_seis(){
	float vet[5] = {1.1,2.2,3.3,4.4,5.5};
	float *f;
	int i;
	f = vet;
	printf("contador/valor/valor/endereco/endereco");
	for(i = 0 ; i <= 4 ; i++){
		printf("\ni = %d",i);
		printf("vet[%d] = %.1f",i, vet[i]);
		printf("*(f + %d) = %.1f",i, *(f+i));
		printf("&vet[%d] = %p",i, &vet[i]);
		printf("(f + %d) = %p",i, f+i);
	}
}

/* QUESTAO 7:

Apenas a primeira expressao vai imprimir o valor da terceira posição


*/

void questao_sete(){
	int p[5] = {1,2,3,4,5};
	int *pulo;
	pulo=p;
	printf("%d\n", *(pulo + 2));
	printf("%d\n", *(pulo + 4));
	printf("%p\n", pulo + 4);
	printf("%p\n", pulo + 2);
}

/* QUESTÃO 8:

nao vai dar erro e vai imprimir o segundo elemento de mat
vai dar erro
vai dar erro
nao vai dar erro e vai imprimir o primeiro elemento de mat
*/
void questao_oito(){
	int mat[4]={2,4,8,10}, *p, x;
	p = mat + 1;
	printf("%d\n", *p);
	//p = mat++;
	//p = ++mat;
	x = (*mat)++;
	printf("%d", x);

}

/* QUESTÃO 9:

O primeiro imprime todos os valores de vet[]
O segundo imprime o endereço de cada elemento de vet[]

Resultado:
A minha lógica estava certa, mas deu erro no 
printf("%X\n ",vet+i);
E deu certo quando eu troquei %X por %p
*/
void questao_nove(){
	int vet[] = {4,9,13};
	int i;
	for(i=0;i<3;i++){
		printf("%d\n ",*(vet+i));
	}
	for(i=0;i<3;i++){
		printf("%p\n ",vet+i);
  	}

}

/* QUESTAO 10

A) 4093, 4094, 4095
B)4094. 9096, 4098
C) 4096, 4100,4114
D) 4100, 4108, 4116

*/

// QUESTAO 11 - int e float ocuparam 4 na nossa maquina
void questao_onze(){
	char xc[4];
	int xi[4];
	float xf[4];
	double xd[4];
	int i;
	for(i=0;i<=3;i++){
		printf("%p\n ",xc+i);
	}
	for(i=0;i<=3;i++){
		printf("%p\n ",xi+i);
	}
	for(i=0;i<=3;i++){
		printf("%p\n ",xf+i);
	}
	for(i=0;i<=3;i++){
		printf("%p\n ",xd+i);
	}
}

/* QUESTAO 12

VALIDO
aloha[2] = value;
VALIDO
scanf("%f", &aloha);
INVALIDO
aloha = value";
INVALIDO
printf("%f", aloha);
VALIDO
coisas[4][4] = aloha[3];
INVALIDO
coisas[5] = aloha;
INVALIDO
pf = value;
VALIDO
pf = aloha;

*/

void questao_doze(){
	float aloha[10], coisas[10][5], *pf, value = 2.2;
	int i=3;
	aloha[2] = value;
	scanf("%f", &aloha);
	printf("%f", aloha);
	coisas[4][4] = aloha[3];
	pf = aloha;
}

// 
// QUESTAO 13
// 
//
/*
Um ponteiro para uma funcao eh uma variavel que armazena o endereco
de uma funcao. Assim, com o ponteiro para uma funcao em maos, eh
possivel resgatar essa funcao e executar o seu codigo.
Isso eh util quando queremos definir um bloco de codigo onde, em
um certo trecho, temos que performar um comportamento, mas sendo que
esse comportamento nao eh especifico.
Ou seja: podemos deixar uma "abertura" para que o comportamento
seja variavel, dentro do codigo, basta mudar o ponteiro de funcao.

Vamos demonstrar ao criar uma imitacao da funcao 'map()' da linguagem
Python, que recebe uma funcao e uma lista (array), e aplica a funcao
a cada elemento da lista, resultando numa nova lista.
*/

int ao_quadrado (const int x){
    // Uma funcao qualquer que define um certo comportamento
    return x*x;
}

void map(int (*op)(int), int *l, int tam){
    // (*op) = um ponteiro de funcao
    // *l = alguma lista
    // tam = quantidade de elementos
    // --------
    // vamos aplicar a funcao op na lista l
    // seja la qual for a funcao op,
    // seja la qual for a lista l.

    int i;

    for (i=0; i<tam; i++){
        l[i] = op( l[i] );
    }

}


int main(){
    int v[] = {1,2,3,4};
    int i, tam=4;

    map(ao_quadrado, v, tam);

    // Printar vetor
    for (i=0; i<tam; i++){
		printf("%d\n", v[i]);
	}    
    
	
}


// 
// QUESTAO 14
// 

void questao_14(float *v, const int tam){
	int i, j;
	float aux;
	for (i=0; i<tam; i++){
		for (j=i; j<tam; j++){
			if (v[i]>v[j]){
				aux=v[i];
				v[i]=v[j];
				v[j]=aux;			
			}		
		}
	}
for (i=0; i<tam; i++){ printf("%.1f\n", v[i]);}
}
int main(){
	float *v;
	int tam, i;
	printf("Digite o tamanho do vetor q tu quer");
	scanf ("%d", &tam);
	v = (float *) malloc(tam*sizeof(float));
	for (i=0; i<tam; i++){
		scanf("%f", v+i);
	}

	questao_14(v, tam);
	return 0;
}

// 
// QUESTAO 15
// 

int comparador (const void * a, const void * b) {
    /* 
	Funcao para comparar dois elementos do nosso array.
    Como a funcao qsort()  demanda que  o retorno
    dessa funcao seja do tipo inteiro, precisamos pegar
    as casas decimais dos nossos numeros float ao
    multiplicar por uma potencia de 10.
	OBS: uma alternativa a isso seria fazer if/else
	para retornar 1, 0 ou -1.
	*/

    int casas_decimais = 10000;
    return ( *(float*)a*casas_decimais - *(float*)b*casas_decimais );
}

int main(){
    // Declarar um ponteiro para float
    float *v;
    // Declarar logo no inicio a variavel de loop (i) e
    // tamanho
	int tam, i;

	printf("Digite o tamanho do vetor q tu quer\n");
	scanf ("%d", &tam);

    // Alocar dinamicamente espaco na memoria para
    // o nosso vetor de float
	v = (float *) malloc(tam*sizeof(float));
	for (i=0; i<tam; i++){
		scanf("%f", v+i);
	}

    // A funcao qsort() recebe:
    // - ponteiro para o primeiro elemento do vetor
    // - quantidade de elementos
    // - tamanho de cada elemento em byte
    // - uma funcao que abstrai o conceito de maior e menor
    //   (um comparador)
    qsort(v, tam, sizeof(float), comparador);

    for (i=0; i<tam; i++){
		printf("%.1f\n", v[i]);
	}
    return 0;
}

// 
// QUESTAO 16
// 
void questao_16(float *v,
                const int tam,
                float (*cmp)( float, float)
                ){
	int i, j;
    float comparativo;
	float aux;
	for (i=0; i<tam; i++){
		for (j=i; j<tam; j++){
            /*
            Aqui, usamos a funcao cmp
            para decidir se v[i] vem depois de v[j].
            Se cmp(v[i],v[j]) > 0, entao 
            v[i] vem depois de v[j].
            */
            comparativo = cmp(v[i], v[j]);
			if (comparativo > 0){
				aux=v[i];
				v[i]=v[j];
				v[j]=aux;			
			}		
		}
	}
for (i=0; i<tam; i++){ printf("%.1f\n", v[i]);}
}

float comparador (float a, float b){
    return a - b;
}
int main(){
	float *v;
	int tam, i;
	printf("Digite o tamanho do vetor q tu quer\n");
	scanf ("%d", &tam);
	v = (float *) malloc(tam*sizeof(float));
	for (i=0; i<tam; i++){
		scanf("%f", v+i);
	}

	questao_16(v, tam, comparador);
	return 0;
}

// 
// QUESTAO 18
// 
void questao_18(int *v1,
                int *v2,
                int *v3,
                const int tam
                ){
    int i = 0;
    for (i=0; i<tam; i++){
        v3[i] = v1[i] + v2[i];
    }

                    
}

int main(){
	int *v1, *v2, *v3;
	int tam, i;
	printf("Digite o tamanho do vetor q tu quer\n");
	scanf ("%d", &tam);

	v1 = (int *) malloc(tam*sizeof(int));
    v2 = (int *) malloc(tam*sizeof(int));
    // Ler v1
    printf("Entre o primeiro:\n");
	for (i=0; i<tam; i++){
		scanf("%d", v1+i);
	}

    // Ler v2
    printf("Entre o segundo:\n");
	for (i=0; i<tam; i++){
		scanf("%d", v2+i);
	}

	questao_18(v1,v2,v3,tam);
    printf("Resultado:\n");
    for (i=0; i<tam; i++){
		printf("%d\n", v3[i]);
	}
	return 0;
}

// 
// QUESTAO 19
// 
void matmul(float **A,
            float **B,
            float **C,
            const int nl_A,
            const int nc_A,
            const int nc_B
                ){
    const int nl_B = nc_A;
    int i, j, k;
    float soma;
    for (i=0; i<nl_A; i++){
        // Iterando nas linhas de C
        for (j=0; j<nc_B; j++){
            // Iterando nas colunas de C
            soma = 0;
            for (k=0; k<nl_B; k++){
                // Iterando na linha i de A e coluna j de B
                // simultaneamente
                soma = soma + A[i][k] * B[k][j];
            }
            C[i][j] = soma;

        }

    }

                    
}

int main(){
	float **A, **B, **C;
	int nl_A, nc_A, nl_B, nc_B, i, j;
	printf("NLinha A : ");
	scanf ("%d", &nl_A);
    printf("NColuna A : ");
	scanf ("%d", &nc_A);

    printf("NLinha B : ");
	scanf ("%d", &nl_B);
    printf("NColuna B : ");
	scanf ("%d", &nc_B);

    // 
    // MATRIZ A
    // 
    // Alocar
    A = (float**) malloc(nl_A*sizeof(float*));
    A[0] = (float*) malloc(nl_A*nc_A*sizeof(float));
    for (i = 1; i<nl_A; i++){
        A[i] = A[i-1] + nc_A;
    }
    // Preencher
    for(i=0; i<nl_A; i++){
        for(j=0; j<nc_A; j++){
        A[i][j] = i*(nl_A+1) + j+1;
        }
    }
    // Printar
    for(i=0; i<nl_A; i++){
        for(j=0; j<nc_A; j++){
        printf("%.1f ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // 
    // MATRIZ B
    // 
    // ALocar
    B = (float**) malloc(nl_B*sizeof(float*));
    B[0] = (float*) malloc(nl_B*nc_B*sizeof(float));
    for (i = 1; i<nl_B; i++){
        B[i] = B[i-1] + nc_B;
    }
    // Preencher
    for(i=0; i<nl_B; i++){
        for(j=0; j<nc_B; j++){
        if (i == j) B[i][j] = 1;
        else B[i][j] = 0;
        }
    }
    // Printar
    for(i=0; i<nl_B; i++){
        for(j=0; j<nc_B; j++){
        printf("%.1f ", B[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // 
    // MATRIZ C
    // 
    // ALocar
    C = (float**) malloc(nl_A*sizeof(float*));
    C[0] = (float*) malloc(nl_A*nc_B*sizeof(float));
    for (i = 1; i<nl_A; i++){
        C[i] = C[i-1] + nc_B;
    }
    // Preencher
    matmul(A, B, C, nl_A, nc_A, nc_B);
    // Printar
    for(i=0; i<nl_A; i++){
        for(j=0; j<nc_B; j++){
        printf("%.1f ", C[i][j]);
        }
        printf("\n");
    }


    free(A[0]);
    free(A);
    free(B[0]);
    free(B);
	return 0;
}


// 
// QUESTAO 20
// 
/*
https://launchpad.net/libgc
doc/simple_example.html
*/