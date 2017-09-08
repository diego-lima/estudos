import sqlite3
conn = sqlite3.connect('/home/diego/hitron.db')
cursor = conn.cursor()

cursor.execute(sql)
resultados = cursor.fetchall()
for linha in resultados:
    print linha
