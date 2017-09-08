# -*- coding: utf-8 -*-
ALFABETO = (('A','B','C','D','E','F'), #quartil 1
            ('G','H','I','J','K','L'), #quartil 2
            ('M','N','O','P','Q','R'), #quartil 3
            ('R','S','T','U','V','W','X','Y','Z')) #quartil 4
VOGAIS = ('A','E','I','O','U')
def vectorize(word):
    """Retorna uma tupla com base em word.
    tupla = (q1, q2, q3, q4, n. vogais, n. consoantes)
    onde qn é o numero de letras da palavra que fazem parte do quartil n
    """
    vector = [0,0,0,0,0,0]
    for letter in str(word):
        for index, quartil in enumerate(ALFABETO):
            if letter.upper() in quartil:
                vector[index] += 1
        if letter.upper() in VOGAIS:
            vector[4] +=1
        else:
            vector[5] +=1
    return vector

def constant(level, length):
    result = []
    for i in range(1,length):
        result.append(level)
    return result
