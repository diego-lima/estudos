# -*- coding: utf-8 -*-
import csv
File = open('csv/train.csv')
Reader = csv.reader(File)
outputFile = open('csv/train.csv', 'w')
outputWriter = csv.writer(outputFile)
outputWriter.writerow(['PALAVRA','IS_TAG'])

start = input("Começa em que linha ?")
end = input ("Até que linha? ")
for row in Reader:
    if Reader.line_num == 1:
        continue

    if Reader.line_num >= start:
        row = row[0].split(';')[4].decode('iso8859-1').encode('utf-8')

        for word in row.split(' '):
            outputWriter.writerow([word,0])

    if Reader.line_num > end:
        break
outputFile.close()
