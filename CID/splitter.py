# -*- coding: utf-8 -*-
"""Lê o CSV do CID10, pergunta de que linha até que linha fazer um recorte,
depois, nesse intervalo, ele escreve palavra por palavra num csv novo.
"""
import csv, os
import unicodedata

def remover_acentos(input_str):
    """Remove todos acentos e retorna o texto somente em ASCII
    """
    nfkd_form = unicodedata.normalize('NFKD', input_str)
    only_ascii = nfkd_form.encode('ASCII', 'ignore')
    return only_ascii

File = open('CID10/CID-10-CATEGORIAS.CSV')
Reader = csv.reader(File)

isfile = False
if os.path.isfile('csv/source.csv'):
    isfile = True

outputFile = open('csv/source.csv', 'w')
outputWriter = csv.writer(outputFile)

if not isfile:
    outputWriter.writerow(['PALAVRA'])

start = input("Começa em que linha ?")
end = input ("Até que linha? ")
for row in Reader:
    if Reader.line_num == 1:
        continue

    if Reader.line_num >= start:
        row = row[0].split(';')[2].decode('iso8859-1').encode('utf-8')

        for word in row.split(' '):
            outputWriter.writerow([remover_acentos(word.decode('utf-8'))])

    if Reader.line_num + 1 > end:
        break
outputFile.close()
