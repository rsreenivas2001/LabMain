i = 1;
x = 1:10;
while (i<11),
  x(i) = randi([3,10]);
  i = i+1;
endwhile
x
