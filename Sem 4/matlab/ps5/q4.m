syms x;
syms y;
f = cos(2*x) - x^2*exp(5*y) + 3*y^2;
a = diff(f,x);
eval(subs(a,[x y],[2 3]))
b = diff(f,y);
eval(subs(b,[x y],[2 3]))
c = diff(f,x,2);
eval(subs(c,[x y],[2 3]))
d = diff(f,y,2);
eval(subs(d,[x y],[2 3]))
e = diff(b,x);
eval(subs(e,[x y],[2 3]))
g = diff(a,y);
eval(subs(g,[x y],[2 3]))
h = diff(f,x,4);
eval(subs(h,[x y],[2 3]))
i = diff(g,x);
eval(subs(i,[x y],[2 3]))