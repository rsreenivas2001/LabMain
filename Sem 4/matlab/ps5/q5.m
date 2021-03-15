syms x;
a = sin(2*x)*cos(x);
int(a)
b = 1/((x^2) + 5*x + 6);
int(b)
c = sqrt(9 - 4*(x^2));
int(c)
d = log(tan(x));
vpa(int(d,[0 (pi/2)]))