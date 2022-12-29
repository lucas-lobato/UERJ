try:
    a=float(input('Digite um numero:'))
    if a<10:raise
    b=float(input('Digite outro numero:'))
    print('A divisao e{0:5.2f}'.format(a/b))
except Exception:
    print('dado errado')
finally:
    print('Processo encerrado')
