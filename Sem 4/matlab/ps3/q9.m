vec1 = linspace(-2,4);
y = 3.*((vec1).^3)-26.*vec1+10;
f1x = diff(y);
f2x = diff(f1x);
vec2 = vec1(1:end-1);
vec3 = vec1(1:end-2);
x = [vec1 vec2 vec3]
z = [y f1x f2x]
line(x,z)