import math as m
######################## Pergunta 1 ##############################
def f(t, T):
	return -0.25*(T - 37)

def euler(t, T):
	for i in range(3):
		T = T + f(t, T) * 0.4
		t += 0.4
		print("(", t, ", ", T, ")")
	return

#euler(5, 3)

######################## Pergunta 2 ##############################
#Texto que não sei responder
######################## Pergunta 3 ##############################
#Maxima
######################## Pergunta 4 ##############################
def r1(x):
	return 0.5 * m.sqrt(m.exp(x))
def r2(x):
	return m.exp(x)/4*x
def r3(x):
	return -0.5 * m.sqrt(m.exp(x))
def pipe(x):
	for i in range(20):
		x = r1(x)
		print(x)
	return

#pipe(-0.413998)
######################## Pergunta 5 ##############################
def g(x):
	return x**3 - 10*m.sin(x) + 2.8

def bis(a, b):
	for i in range(3):
		m = (a + b)/2
		if(g(a)*g(m) < 0):
			b = m
		else:
			a = m
		print(b)
	return 

#bis(1.5, 4.2)
