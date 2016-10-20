# -*- coding: utf-8 -*-
"""Lê o csv que foi gerado em splitter.py, e depois vai perguntando palavra
por palavra para o usuário se é ou não é tag. Em seguida, guarda em um outro
arquivo os resultados. Não pergunta a mesma palavra duas vezes.
"""
from vectorize import vectorize
import csv, os

File = open('csv/source.csv')
Reader = csv.reader(File)

isfile = False
if os.path.isfile('csv/response.csv'):
    isfile = True

outputFile = open('csv/response.csv', 'a')
outputWriter = csv.writer(outputFile)

if not isfile:
    outputWriter.writerow(['PALAVRA','Q1','Q2','Q3','Q4','VOGAIS','CONSOANTES','É TAG'])

k_words = []
print 'Responda para as palavras a seguir:\nÉ tag? 0-Não 1-Sim\n'
for row in Reader:
    word = row[0].decode('utf-8').lower()
    if word in k_words:
        continue
    print '%20s' % word,
    is_tag = input()
    print "\033[A                                             \033[A"
    if is_tag:
        outputWriter.writerow([word.encode('utf-8')] + vectorize(word) + [1])
    else:
        outputWriter.writerow([word.encode('utf-8')] + vectorize(word) + [0])
    k_words.append(word)
outputFile.close()
