# -*- coding: utf-8 -*-
from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeClassifier
from vectorize import *
import numpy as np
import csv

File = open('csv/response.csv')
reader = csv.reader(File)
reader.next()
x = np.ones((332,6), dtype=np.int8)
y = np.ones((332), dtype=np.int8)

for line in reader:
    x_line = []
    for index in range (1,7):
        x_line.append( int(line[index]) )
    x[reader.line_num-1] = (np.array(x_line))
    y[reader.line_num-1] = int(line[7])
    if (reader.line_num > 243):
        break


from sklearn.cross_validation import train_test_split
from sklearn import metrics

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.4)
classifier = DecisionTreeClassifier()
classifier.fit(x_train,y_train)
result = metrics.accuracy_score(y_test, classifier.predict(x_test))
print 'Accuracy ', result

for v in range (3):
    results = []
    x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.4)
    for i in range(1,146):
        knn = KNeighborsClassifier(n_neighbors=i)
        knn.fit(x_train,y_train)

        result = metrics.accuracy_score(y_test, knn.predict(x_test))
        results.append(result)

    import matplotlib.pyplot as plt
    plt.plot(range(1,146), results)
    plt.plot(range(1,146),constant(0.7, 146))
    plt.plot(range(1,146),constant(0.6, 146))
    plt.plot(range(1,146),constant(0.5, 146))
    plt.ylabel('taxa de acerto')
    plt.xlabel('parametro K')
    plt.show()
# knn = KNeighborsClassifier(n_neighbors=25)
# knn.fit(x,y)
# word1 = 'lingua' # gengiva assoalho boca palato glandula
# word2 = 'hepatite'
# print 'word1: ',knn.predict(vectorize(word1))
# print 'word2: ',knn.predict(vectorize(word2))
