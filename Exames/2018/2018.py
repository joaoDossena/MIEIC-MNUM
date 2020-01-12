import math as m
######################## Pergunta 1 ########################
def f1(x, y):
	return m.sin(x+y) - m.exp(x-y)
def f1x(x,y):
	return m.cos(x+y) - m.exp(x-y)
def f1y(x,y):
	return m.cos(x+y) + m.exp(x-y)
def f2(x, y):
	return m.cos(x+y) - (x*y)**2
def f2x(x,y):
	return -1*m.sin(x+y) - 2*y*y*x
def f2y(x,y):
	return -1*m.sin(x+y) - 2*y*x*x

def hn(x,y):
	return -1*(f1(x,y) * f2y(x,y) - (f1y(x,y) * f2(x,y)))/(f1x(x,y)*f2y(x,y) - (f2x(x,y) * f1y(x,y)))
def kn(x,y):
	return -1* (f1x(x,y) * f2(x,y) - (f1(x,y) * f2x(x,y)))/(f1x(x,y)*f2y(x,y) - (f2x(x,y) * f1y(x,y)))

def newton(x, y):
	xn = x
	yn = y
	for i in range(2):
		x = xn + hn(xn, yn)
		y = yn + kn(xn, yn)
		xn = x
		yn = y
		print("(", x, ", ", y, ")")
	return

#newton(0.5, 0.25)

######################## Pergunta 2 ########################
#Vou fazer no maxima na hora do exame


######################## Pergunta 3 ########################
def simpson():
	hx = 1
	hy = 1
	soma = 7.8 + 1.1 + 9.8 + 1.2
	soma += 4*(2.1 + 1.4 + 2.2 + 1.5)
	soma += 16*4
	print(soma * hx*hy/9)
	return
#simpson()

######################## Pergunta 4 ########################
#dy/dx = z

#dz/dx = A*z - B*y

#h = 0.2

def dydx(x, y, z):
	return z
def dzdx(x,y,z):
	return -7*z - 4*y

def euler(x, y, z, h):
	xn = x
	yn = y
	zn = z
	for i in range(3):
		z += dzdx(xn, yn, zn)*h
		y += dydx(xn, yn, zn)*h
		x += h
		print((x, y, z))
		xn = x
		yn = y
		zn = z
	return


#euler(0.4, 2, 1, 0.2)

######################## Pergunta 5 ########################
#Plot the graph of the function on maxima to know where the function's minima is
#Take that interval and plug it in the thirds algo, then the result of that in the sequential search, and then the intQ

def f(x):
	return (x-4)**2 + x**4
def thirds(a, b):
	h = (b-a)/3
	c = a + h
	d = b - h
	for i in range(20):
		if(f(a) > f(c)):
			a = c
		if(f(b) > f(d)):
			b = d
		h = (b-a)/3
		c = a + h
		d = b - h
	print((a, b))
	return

def seq(a, b, n):
	h = (b-a)/n
	for i in range(n):
		if(f(a+h)<f(a)):
			a += h
	print((a, (a+b)/2, b))
	return 

def intQ(x1, x2, x3):
	return x2 + ((x2-x1)*(f(x1)	- (f(x3))))/(2*(f(x3) - 2*f(x2) + f(x1)))

#thirds(1.1259797843176138, 1.1260173754000915)
#seq(1.1260173640953757, 1.1260173754000915, 100000)
#print(intQ(1.126017365249204, 1.1260173703246479, 1.1260173754000915))

######################## Pergunta 6 ########################
#I don't know