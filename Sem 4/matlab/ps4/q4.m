prompt = "Enter the equation as a vector";
limit=input('Enter limit=');
p = 1:limit;
n=1;
disp("enter the vector");
while n<=limit
  p(n)=input(' ');
  n=n+1;
end;
r = roots(p)