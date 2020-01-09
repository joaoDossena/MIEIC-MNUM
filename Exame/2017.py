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
print(quad(interval[0], interval[1], interval[2]))