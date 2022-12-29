#exercicio 1

def comp (c1, c2):
    if len(c1) == len(c2):
        print("O comprimento das frases eh igual.")
    else:
        print("O comprimento das frases nao sao iguais.")

def igual (fr1, fr2):
    if fr1 == fr2:
        print("Sao iguais.")
    else:
        print("Nao sao iguais")


f1 = raw_input("Digite uma frase:")
f2 = raw_input("Digite outra frase:")
print("A primera frase eh:", f1, "e o comprimento eh: ", len(f1))
print("A segunda frase eh:", f2, "e o comprimento eh: ", len(f2))

comp(f1, f2)
igual(f1, f2)
