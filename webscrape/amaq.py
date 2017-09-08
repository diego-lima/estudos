# -*- coding: utf-8 -*-
import psycopg2
try:
    conn = psycopg2.connect("dbname='postgres' user='postgres' host='localhost' password='asdasd'")
except:
    print 'Não pude conectar...'

cur = conn.cursor()

cur.execute("SELECT grupo_id from autenticacao_perfil")
perfis = cur.fetchall()

contador = [0, 0]

for perfil in perfis:
    if perfil[0] == 8:
        contador[0] += 1
    else:
        contador[1] += 1
print 'Existem %d gestores e %d nao-gestores' % (contador[0], contador[1])

cur.execute("SELECT ine from common_equipesaude ORDER BY id ASC")
ines = cur.fetchall()

k_ine = []
ocorrencias = []
for index, ine in enumerate(ines):
    if ine[0] not in k_ine:
        k_ine.append(ine[0])
        ocorrencias.append([index+1])
    else:
        ocorrencias[k_ine.index(ine[0])].append(index+1)

print 'A seguir os INEs repetidos e em que linhas eles aparecem:'
contador_repetidos = 0
for i in range(len(k_ine)):
    if len(ocorrencias[i]) > 1:
        contador_repetidos += 1
        print '%15s    %10s' % (k_ine[i],ocorrencias[i])

print 'Existem %d ines que aparecem mais de uma vez, e somente %d nao se repetem' % (contador_repetidos, len(k_ine) - contador_repetidos)
