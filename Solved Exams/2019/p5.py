#UP201800174
#João Pedro Olinto Dossena
import math as m
def f(x):
    return x + (x-2)*(x-2)/(m.sin(x) + 2)

def aur(x1, x2):
    B = (m.sqrt(5) - 1)/2
    A = B*B
    x3 = A*(x2-x1) + x1
    x4 = B*(x2-x1) + x1
    #print((x1, x2, x3, x4), "\n", (f(x1), f(x2), f(x3), f(x4)), "\n")
    for i in range(2):
        if(f(x3) < f(x4)):
            x2 = x4
            x4 = x3
            x3 = B*(x4-x1) + x1
        elif(f(x3) > f(x4)):
            x1 = x3
            x3 = x4
            x4 = B*(x2-x3) + x3
        print((x1, x2, x3, x4), "\n", (f(x1), f(x2), f(x3), f(x4)), "\n")
    return abs(x2-x1) #Amplitude
    
#print(aur(-1, 1.5))
