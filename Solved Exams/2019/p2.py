#UP201800174
#João Pedro Olinto Dossena
def f1(x,y):
    return x*x - y - 1.2
def f2(x,y):
    return -x + y*y - 0.5
def jac(x,y):
    return 2*x + 2*y - 1
def f1x(x,y):
    return 2*x
def f1y(x,y):
    return -1
def f2x(x,y):
    return -1
def f2y(x,y):
    return 2*y
def hn(x,y):
    return - (f1(x,y) * f2y(x,y) - f1y(x,y)*f2(x,y))/jac(x,y)
def kn(x,y):
    return - (f1x(x,y)*f2(x,y) - f1(x,y)*f2x(x,y))/jac(x,y)
def newton(x, y):
    xn = x
    yn = y
    for i in range(3):
        x = xn + hn(xn,yn)
        y = yn + kn(xn, yn)
        xn = x
        yn = y
        print((x, y))
        
    return

newton(1.1, 1.1)