a = [linspace(2,17,6); linspace(3,18,6); linspace(4,19,6); linspace(5,20,6); linspace(6,21,6)];
b = [linspace(5,30,6); linspace(30,55,6); linspace(55,80,6)];
v = linspace(99,91,9);

a(1,3:6) = b(1,1:4);
a(3,3:6) = b(2,1:4);
a(5,3:6) = b(3,3:6);
a(4,3:6) = v(5:8)