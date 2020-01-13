#UP201800174
#João Pedro Olinto Dossena
def f(t, T):
    return -0.25*(T - 64)

def euler(t, T, h):
    tn = t
    Tn = T
    for i in range(3):
        T += f(tn, Tn)*h
        t += h
        Tn = T
        tn = t
        #print((t, T))
    return T

#euler(3, 5, 0.3)

#Erro: (aprox 2)
#print((euler(3, 5, 0.15) - euler(3, 5, 0.3))/(euler(3,5, 0.075) - euler(3, 5, 0.15)))