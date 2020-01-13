#UP201800174
#João Pedro Olinto Dossena
def f(x,y):
    return 3*x*x - x*y + 11*y + y*y - 8*x
def fx(x,y):
    return -y + 6*x -8
def fy(x,y):
    return 2*y - x + 11

def grad(x, y, h):
    xn = x
    yn = y
    for i in range(1):
        yn = y - h*fy(x,y)
        xn = x - h*fx(x,y)
        if(f(xn, yn) < f(x,y)):
            x = xn
            y = yn
            h *= 2
        elif(f(xn, yn) > f(x,y)):
            h /= 2
        #print((xn, yn, f(xn, yn)))
        return f(xn,yn)
    
#grad(2,2,0.5)
#fx(2,2)
#fy(2,2)