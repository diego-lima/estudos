import csv
with open('src/iris.csv', 'rb') as arquivocsv:
    linhas = csv.reader(arquivocsv)
    for linha in linhas:
        print ', '.join(linha)

import random
def carregarDados(nome_arquivo, corte, conjunto_treino=[] , conjunto_teste=[]):
	with open(nome_arquivo, 'rb') as arquivo_csv:
	    linhas = csv.reader(arquivo_csv)
	    dataset = list(linhas)
	    for x in range(len(dataset)-1):
	        for y in range(4):
	            dataset[x][y] = float(dataset[x][y])
	        if random.random() < corte:
	            conjunto_treino.append(dataset[x])
	        else:
	            conjunto_teste.append(dataset[x])

import math
def distancia_euclidiana(instancia1, instancia2, tamanho):
	distancia = 0
	for x in range(tamanho):
		distancia += pow((instancia1[x] - instancia2[x]), 2)
	return math.sqrt(distancia)

import operator
def localizar_vizinhos(conjunto_treino, instancia_teste, k):
    distancias = []
    tamanho = len(instancia_teste)-1
    for x in range(len(conjunto_treino)):
        dist = distancia_euclidiana(instancia_teste, conjunto_treino[x], tamanho)
        distancias.append((conjunto_treino[x], dist))
    distancias.sort(key=operator.itemgetter(1))
    vizinhos = []
    for x in range(k):
        vizinhos.append(distancias[x][0])
    return vizinhos

import operator
def calcularResposta(vizinhos):
    votos = {}
    for x in range(len(vizinhos)):
        resposta = vizinhos[x][-1]
        if resposta in votos:
            votos[resposta] += 1
        else:
            votos[resposta] = 1
    votosOrdenados = sorted(votos.iteritems(), key=operator.itemgetter(1), reverse=True)
    return votosOrdenados[0][0]

def calcularAcerto(conjunto_teste, respostas):
    corretos = 0
    for x in range(len(conjunto_teste)):
        if conjunto_teste[x][-1] == respostas[x]:
            corretos += 1
    return (corretos/float(len(conjunto_teste))) * 100.0


def main():
    # prerarar os dados
    conjunto_treino = []
    conjunto_teste = []
    corte = 0.7
    carregarDados('src/iris.csv', corte, conjunto_treino, conjunto_teste)
    print 'Conjunto de treino: ' +repr(len(conjunto_treino))
    print 'Conjunto de teste: ' +repr(len(conjunto_teste))
    #gerar respostas
    respostas = []
    k = 3
    for x in range(len(conjunto_teste)):
        vizinhos = localizar_vizinhos(conjunto_treino, conjunto_teste[x], k)
        resultado = calcularResposta(vizinhos)
        respostas.append(resultado)
        print('> previsto=' + repr(resultado) + ', real=' + repr(conjunto_teste[x][-1]))
    acerto = calcularAcerto(conjunto_teste, respostas)
    print('Taxa de acerto: ' + repr(acerto) + '%')

main()
