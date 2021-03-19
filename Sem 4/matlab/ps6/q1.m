
syms t
f1=3*(t^2)-(4*t)+(5);
laplace(f1)
f2=(cos(t)^2)+(2*exp(-3*t))-7;
laplace(f2)
f3=exp(3*t)*cosh(2*t);
laplace(f3)
f4=sinh(t)*cos(3*t);
laplace(f4)
f5=((t+1)^2)*exp(3*t);
laplace(f5)