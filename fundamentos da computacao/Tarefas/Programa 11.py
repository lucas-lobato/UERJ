#DATA DE NASCIMENTO POR EXTENSO

meses=['janeiro','fevereiro','março','abril','maio','junho','julho','agosto','setembro','outubro','novembro','dezembro']

def pergunta():
    data=input('Digite a sua data de aniversário (dd/mm/aaaa):')
    return data

def calculo(data):
    dia,mes,ano=data.split('/')
    nData = 'Data de nascimento: ' + dia + ' de ' + meses[int(mes) - 1] + ' de ' + ano
    print(nData)

data=pergunta()
calculo(data)