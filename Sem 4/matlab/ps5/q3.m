syms x;
a = ((x^2)-5)*((x^3)-2*x+3);
eval(subs(diff(a),x,2))
b = sin(x)*cos(x);
eval(subs(diff(b),x,2))
c = abs(x);
eval(subs(diff(c),x,2))
d = x*abs(x);
eval(subs(diff(d),x,2))
e = (sqrt(x)+2*x)*(4*x^2-1);
eval(subs(diff(e),x,2))