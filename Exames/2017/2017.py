import math as m
######################################### Pergunta 1 #########################################
def f(x):
	return (x-4)**2 + pow(x, 4)

def thirds(a, b, error):
	while(abs(a-b) > error):
		step = abs(b-a)/3
		c = a + step
		d = b - step

		if(f(c) > f(d)):
			a = c
		else:
			b = d
	return [a, b]

def seq(x0, h):
	x1 = x0 + h
	x2 = x1 + h

	while(f(x0) > f(x1)):
		x0 = x1
		x1 = x2
		x2 += h
	return [x0, x1, x2]

def quad(x1, x2, x3):
	h = x3 - x2
	return x2 + (h*(f(x1) - f(x3)))/(2*(f(x3) - 2*f(x2) + f(x1)))


interval = thirds(1.1, 1.13, 0.0001)
interval = seq(interval[0], 0.000000000000001)
#print(quad(interval[0], interval[1], interval[2]))


######################################### Pergunta 2 #########################################
def g(x):
	return (6.25 * m.exp(5*x) + 1)**(1/2)

def simp(a, b, h):
	n = round(abs(b-a)/h)
	soma = g(a) + g(b)
	
	for i in range(1, n, 2):
		soma += 4*g(a+i*h)
	for i in range(2, n, 2):
		soma += 2*g(a+i*h)
	return soma*h/3

def trap(a, b, h):
	n = round(abs(b-a)/h)
	soma = g(a) + g(b)

	for i in range(1, n):
		soma += 2*g(a + i*h)
	return soma * h/2

#print("Simp h = 0.125: ", simp(0, 1, 0.125))
#print("Simp h = 0.0625: ", simp(0, 1, 0.0625))
#print("Simp h = 0.03125: ", simp(0, 1, 0.03125))
#print("QC: ", (simp(0, 1, 0.0625) - simp(0, 1, 0.125))/(simp(0, 1, 0.03125) - simp(0, 1, 0.0625)))
#print("Erro: ", (simp(0, 1, 0.03125) - simp(0, 1, 0.0625))/15)

#print("\n")
#print("Trap h = 0.125: ", trap(0, 1, 0.125))
#print("Trap h = 0.0625: ", trap(0, 1, 0.0625))
#print("Trap h = 0.03125: ", trap(0, 1, 0.03125))
#print("QC: ", (trap(0, 1, 0.0625) - trap(0, 1, 0.125))/(trap(0, 1, 0.03125) - trap(0, 1, 0.0625)), "\n")
#print("Erro: ", (trap(0, 1, 0.03125) - trap(0, 1, 0.0625))/3)

################################### Pergunta 3 ####################################################
def h(x):
	return m.exp(x) - x- 5
def hl(x):
	return m.exp(x) - 1
def r1(x):
	return m.exp(x) - 5
def r2(x):
	return m.log(5 + x)

def pipe(x):
	for i in range(10):
		x = r2(x)
		print(x)
	return x
def newton(x):
	for i in range(10):
		x = x - (h(x)/hl(x))
		print(x)
	return 


#pipe(-4.993216188647903)
#pipe(3)
#print("\n")
#newton(3)

###################################### Pergunta 4 ###############################################
def f1(t, C, T):
	return -m.exp(-0.5/(T+273)) * C
def f2(t, C, T):
	return 30 * m.exp(-0.5/(T+273)) * C - 0.5*(T-20)

def euler(t, C, T, h):
	Tant = T
	Cant = C
	for i in range(2):
		T = Tant + f2(t, Cant, Tant)*h
		C = Cant + f1(t, Cant, Tant)*h
		t += h
		Tant = T
		Cant = C
		print("(", t, ", ", C, ", ", T, ")")
	return
#euler(0, 2.5, 25, 0.25)

def rk4(t, C, T, h):
	for i in range(2):
		Td1 = f2(t, C, T)*h
		Cd1 = f1(t, C, T)*h

		Td2 = f2(t + 0.25/2, C + Cd1/2, T + Td1/2)*h
		Cd2 = f1(t + 0.25/2, C + Cd1/2, T + Td1/2)*h

		Td3 = f2(t + 0.25/2, C + Cd2/2, T + Td2/2)*h
		Cd3 = f1(t + 0.25/2, C + Cd2/2, T + Td2/2)*h

		Td4 = f2(t + 0.25, C + Cd3, T + Td3)*h
		Cd4 = f1(t + 0.25, C + Cd3, T + Td3)*h

		T += (Td2 + Td3)/3 + (Td1 + Td4)/6
		C += (Cd2 + Cd3)/3 + (Cd1 + Cd4)/6

		t += h
		print("(", t, ", ", C, ", ", T, ")")
	return

rk4(0, 2.5, 25, 0.25)

###################################### Pergunta 5 ###############################################
def w(x, y):
	return -1.1*x*y + 12*y + 7*x*x - 8*x
def wx(x, y):
	return -1.1*y + 14*x - 8
def wy(x, y):
	return -1.1*x + 12

def grad(x, y, h):
	xn = 0
	yn = 0

	for i in range(1):
		xn = x - h*wx(x, y)
		yn = y - h*wy(x, y)
		if(w(xn, yn) < w(x, y)):
			x = xn
			y = yn
			h *= 2
		else:
			h /= 2
		print("(", x, ", ", y, ", ", w(x, y), ")")
	return

#grad(3, 1, 0.1)
