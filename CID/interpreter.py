# -*- coding: utf-8 -*-
from sklearn.neighbors import KNeighborsClassifier
import sys
import csv

File = open('csv/train.csv')
Reader = csv.reader(File)
outputFile = open('csv/response.csv', 'a')
outputWriter = csv.writer(outputFile)

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
        outputWriter.writerow([word.encode('utf-8'),len(word)])
    else:
        outputWriter.writerow([word.encode('utf-8'),0])
    k_words.append(word)
outputFile.close()
