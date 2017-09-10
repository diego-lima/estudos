from random import seed
from random import randrange
from csv import reader
from math import sqrt

# Load a CSV file
def carregar_csv(nome_arquivo):
	conjunto_dados = list()
	with open(nome_arquivo, 'r') as file:
		csv_reader = reader(file)
		for linha in csv_reader:
			if not linha:
				continue
			conjunto_dados.append(linha)
	return conjunto_dados

# Convert string coluna to float
def str_coluna_para_float(conjunto_dados, coluna):
	for linha in conjunto_dados:
		linha[coluna] = float(linha[coluna].strip())

# Convert string coluna to integer
def str_coluna_para_int(conjunto_dados, coluna):
	classes = [linha[coluna] for linha in conjunto_dados]
	unicas = set(classes)
	resultado = dict()
	for i, valor in enumerate(unicas):
		resultado[valor] = i
	for linha in conjunto_dados:
		linha[coluna] = resultado[linha[coluna]]
	return resultado

# Split a conjunto_dados into k partes
def cross_validation(conjunto_dados, qtd_partes):
	parte_conjunto = list()
	copia_conjunto = list(conjunto_dados)
	tamanho_parte = int(len(conjunto_dados) / qtd_partes)
	for i in range(qtd_partes):
		parte = list()
		while len(parte) < tamanho_parte:
			indice = randrange(len(copia_conjunto))
			parte.append(copia_conjunto.pop(indice))
		parte_conjunto.append(parte)
	return parte_conjunto

# Calculate eficacia percentage
def medida_eficacia(real, predicao):
	corretos = 0
	for i in range(len(real)):
		if real[i] == predicao[i]:
			corretos += 1
	return corretos / float(len(real)) * 100.0

# Evaluate an algoritmo using a cross validation split
def avaliar_algoritmo(conjunto_dados, algoritmo, qtd_partes, *args):
	partes = cross_validation(conjunto_dados, qtd_partes)
	acertos = list()
	for parte in partes:
		conjunto_treino = list(partes)
		conjunto_treino.remove(parte)
		conjunto_treino = sum(conjunto_treino, [])
		conjunto_teste = list()
		for linha in parte:
			copia_linha = list(linha)
			conjunto_teste.append(copia_linha)
			copia_linha[-1] = None
		predicao = algoritmo(conjunto_treino, conjunto_teste, *args)
		real = [linha[-1] for linha in parte]
		eficacia = medida_eficacia(real, predicao)
		acertos.append(eficacia)
	return acertos

# calculate the Euclidean distancia between two vectors
def distancia_euclidiana(linha1, linha2):
	distancia = 0.0
	for i in range(len(linha1)-1):
		distancia += (linha1[i] - linha2[i])**2
	return sqrt(distancia)

# Locate the best matching unit
def pegar_vetor_mais_proximo(vetores, instancia_teste):
	distancias = list()
	for vetor in vetores:
		dist = distancia_euclidiana(vetor, instancia_teste)
		distancias.append((vetor, dist))
	distancias.sort(key=lambda tup: tup[1])
	return distancias[0][0]

# Make a prediction with vetor vectors
def predizer(vetores, instancia_teste):
	vetor = pegar_vetor_mais_proximo(vetores, instancia_teste)
	return vetor[-1]

# Create a random vetor vector
def vetor_aleatorio(dados):
	qtd_registros = len(dados)
	qtd_colunas = len(dados[0])
	vetor = [dados[randrange(qtd_registros)][i] for i in range(qtd_colunas)]
	return vetor

# Train a set of vetor vectors
def treinar_vetores(dados, qtd_vetores, taxa_aprendizado, epocas):
	vetores = [vetor_aleatorio(dados) for i in range(qtd_vetores)]
	for epoca in range(epocas):
		taxa = taxa_aprendizado * (1.0-(epoca/float(epocas)))
		for linha in dados:
			vetor = pegar_vetor_mais_proximo(vetores, linha)
			for i in range(len(linha)-1):
				erro = linha[i] - vetor[i]
				if vetor[-1] == linha[-1]:
					vetor[i] += taxa * erro
				else:
					vetor[i] -= taxa * erro
	return vetores

# LVQ Algorithm
def learning_vector_quantization(dados, teste, qtd_vetores, taxa_aprendizado, epocas):
	vetores = treinar_vetores(dados, qtd_vetores, taxa_aprendizado, epocas)
	predicoes = list()
	for linha in teste:
		output = predizer(vetores, linha)
		predicoes.append(output)
	return(predicoes)

# Test LVQ on Ionosphere conjunto_dados
seed(1)
# load and prepare data
nome_arquivo = 'src/ionosfera.csv'
conjunto_dados = carregar_csv(nome_arquivo)
for i in range(len(conjunto_dados[0])-1):
	str_coluna_para_float(conjunto_dados, i)
# convert class coluna to integers
str_coluna_para_int(conjunto_dados, len(conjunto_dados[0])-1)
# evaluate algoritmo
qtd_partes = 5
taxa_aprendizado = 0.3
qtd_epocas = 50
qtd_vetores = 20
acertos = avaliar_algoritmo(conjunto_dados, learning_vector_quantization, qtd_partes, qtd_vetores, taxa_aprendizado, qtd_epocas)
print('Acertos: %s' % acertos)
print('Media de acertos: %.3f%%' % (sum(acertos)/float(len(acertos))))
