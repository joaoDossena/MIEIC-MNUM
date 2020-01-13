#UP201800174
#João Pedro Olinto Dossena
import math as m
def f(x):
    return m.sqrt(2.25 * m.exp(3*x) + 1)

def trap(a, b, h):
    n = round(abs(b-a)/h)
    soma = f(a) + f(b)
    for i in range(1, n):
        soma += 2*f(a+i*h)
    #print(soma*h/2)
    return soma*h/2

#trap(0,2, 0.25)
#trap(0,2, 0.125)
#trap(0,2, 0.0625)

#QC:   
#print((trap(0,2, 0.125) - trap(0,2, 0.25))/(trap(0,2, 0.0625) - trap(0,2, 0.125)))
    
#Erro:
#print((trap(0,2, 0.125) - trap(0,2, 0.25))*4/3)
#print((trap(0,2, 0.0625) - trap(0,2, 0.125))*16/3)
    
def simp(a,b,h):
    n = round(abs(b-a)/h)
    soma = f(a) + f(b)
    for i in range(1,n,2):
        soma += 4*f(a+i*h)
    for i in range(2,n,2):
        soma += 2*f(a+i*h)
    #print(soma*h/3)
    return soma*h/3

#simp(0,2, 0.25)
#simp(0,2,  0.125)
#simp(0,2,  0.0625)
    
#QC:
#print((simp(0,2, 0.125) - simp(0,2, 0.25))/(simp(0,2, 0.0625) - simp(0,2, 0.125)))
    
#Erro:
#print((simp(0,2, 0.0625) - simp(0,2, 0.125))/15)