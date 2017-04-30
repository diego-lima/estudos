# coding:utf-8
"""hdb.py: Acesso e controle das configurações do roteador via configurações do Hitron
"""
from bs4 import BeautifulSoup as bsoup
import mechanize
import sqlite3
import urllib
import sys
#Browser
driver = mechanize.Browser()
#URLs
base_url = "http://192.168.0.1"
login_url = base_url+"/goform/login"
mac_filter_url = base_url + "/goform/LanAccess"
#Dados basicos
mac_filter_base_data = "file=feat-firewall-macfilter&dir=admin%2F&access_type=&trustmode=2&mac=1"
#Banco
conn = sqlite3.connect('/home/diego/hitron.db')
cursor = conn.cursor()

"""FUNÇÕES"""
def checar_valores(valores_aceitos, valores_recebidos, tipo):
    """Verifica se os valores fornecidos foram todos valores esperados. Faz essa verificação no tipo especificado.
    """
    if len(valores_aceitos) > 0:
        for valor in valores_recebidos:
            if tipo(valor) not in valores_aceitos:
                return False
    return True

def login(driver):
    """Já faz login submetendo username e senha
    """
    return driver.open(login_url, 'user=cusadmin&pws=password')

def filtro(driver, *values):
    """Escolhe a configuração do filtro de MAC do roteador entre:
    0 - Permitir todos
    1 - Permitir
    2 - Negar
    """
    tamanho_esperado = 1
    valores_aceitos = ('ligado','desligado')
    uso = "acesso {ligado, desligado}"
    mapa = {'ligado':'2','desligado':'0'}

    if len(values) == tamanho_esperado and checar_valores(valores_aceitos, values, str):
        sql = "INSERT INTO "
        return driver.open(mac_filter_url,mac_filter_base_data + "&access_type=" + mapa[values[0]])
    else:
        print 'Atividade realizada de maneira inadequada.\nTente assim:  %s' % uso
        sys.exit(1)

def refresh(driver):
    reset = {'trustmode':'1'}
    data = mac_filter_base_data + '&' + urllib.urlencode(reset)
    driver.open(mac_filter_url,data)
    reset = {'trustmode':'2'}
    data = mac_filter_base_data + '&' + urllib.urlencode(reset)
    driver.open(mac_filter_url,data)

def ativar(driver, *values):
    """Atualiza a permissão de um determinado dispositivo no filtro de mac do roteador.
    """
    tamanho_esperado = 1
    valores_aceitos = []
    uso = "ativar <nome do dispositivo>"

    if len(values) == tamanho_esperado and checar_valores(valores_aceitos, values, str):
        #Atualizar a permissão
        cursor.execute("UPDATE dispositivos SET acesso_permitido = ? WHERE nome LIKE ?", ('TRUE','%s' % ('%'+values[0]+'%')))
        conn.commit()
        #Pegar somente os proibidos
        sql = "SELECT nome, mac FROM dispositivos WHERE acesso_permitido = 'FALSE'"
        cursor.execute(sql)
        resultado = [x for x in cursor.fetchall()]
        payload = {}
        for i, linha in enumerate(resultado):
            payload["mac%d"%i] = "%s,%s" % (linha[0],linha[1])
        data = mac_filter_base_data + '&' + urllib.urlencode(payload)
        driver.open(mac_filter_url,data)
    else:
        print 'Atividade realizada de maneira inadequada.\nTente assim:  %s' % uso
        sys.exit(1)

def desativar(driver, *values):
    """Atualiza a permissão de um determinado dispositivo no filtro de mac do roteador.
    """
    tamanho_esperado = 1
    valores_aceitos = []
    uso = "desativar <nome do dispositivo>"

    if len(values) == tamanho_esperado and checar_valores(valores_aceitos, values, str):
        #Atualizar a permissão
        cursor.execute("UPDATE dispositivos SET acesso_permitido = ? WHERE nome LIKE ?", ('FALSE','%s' % ('%'+values[0]+'%')))
        conn.commit()
        #Pegar somente os proibidos
        sql = "SELECT nome, mac FROM dispositivos WHERE acesso_permitido = 'FALSE'"
        cursor.execute(sql)
        resultado = [x for x in cursor.fetchall()]
        payload = {}
        for i, linha in enumerate(resultado):
            payload["mac%d"%i] = "%s,%s" % (linha[0],linha[1])
        data = mac_filter_base_data + '&' + urllib.urlencode(payload)
        driver.open(mac_filter_url,data)
    else:
        print 'Atividade realizada de maneira inadequada.\nTente assim:  %s' % uso
        sys.exit(1)


def status(driver, *values):
    """Verifica o tipo de acesso do filtro de MAC, bem como os dispositivos cadastrados.
    """
    tamanho_esperado = 0
    valores_aceitos = []
    uso = "status"

    if len(values) == tamanho_esperado and checar_valores(valores_aceitos, values, str):
        sql = """
        SELECT * FROM dispositivos
        """
        print '%s%10s' % ("DISPOSITIVOS",'ACESSO')
        cursor.execute(sql)
        resultados = cursor.fetchall()
        for linha in resultados:
            print "%10s%11s" % (linha[1],linha[-1])
    else:
        print 'Atividade realizada de maneira inadequada.\nTente assim:  %s' % uso
        sys.exit(1)


"""SNIPPET: INSERT"""
# lista = [
#     ('diegopc', 'e0:06:e6:fd:22:2b', 'TRUE'),
#     ('diegocel', '40:78:6a:9a:bb:69', 'TRUE'),
#     ('maetablet', '78:a8:73:90:26:fa', 'TRUE'),
#     ('paicel', 'f8:cf:c5:9c:08:74', 'TRUE'),
#     ('danicel', '44:80:eb:bc:8f:07', 'FALSE'),
# ]
# sql = """
# INSERT INTO dispositivos (nome, mac, acesso_permitido)
# VALUES (?,?,?)
# """

# cursor.executemany(sql, lista)
"""ATOS"""
realizar = {
    'ativar':ativar,
    'desativar':desativar,
    'refresh':refresh,
    'filtro':filtro,
    'status':status
}
"""MAIN"""
if len(sys.argv) < 2:
    print "Uso inadequado."
    sys.exit(1)

ato = sys.argv[1]
args = sys.argv[2:]

login(driver)
realizar[ato](driver, *args)

conn.close()
