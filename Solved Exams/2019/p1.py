#UP201800174
#João Pedro Olinto Dossena
import math as m
def f(x):
    return m.sin(x) + x**5 - 0.2*x + 1
def bis(a, b):
    for i in range(6):
        m = (a+b)/2
        if(f(a)*f(m) < 0):
            b = m
        elif(f(a) * f(m) > 0):
            a = m
        else:
            break
        print(m)
    return

bis(-1, 0)
#Para fazer o erro absoluto subtraimos as duas ultimas iterações
#Para fazer o erro relativo fazemos o mesmo acima e dividimos pela ultima iteração
