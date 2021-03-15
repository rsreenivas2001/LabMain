syms y(x);

ode = diff(y,x) == e^(3*x)+ sin(x);

ysol(x) = dsolve(ode)


ode = diff(y,x,2) == 2 + x;

ysol(x) = dsolve(ode)


ode = diff(y,x,10) == 0;

ysol(x) = dsolve(ode)


ode = diff(y,x,3) == x^2;

ysol(x) = dsolve(ode)
