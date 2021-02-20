number = input("Enter a natural number:");
seq = [number];
i = 1;
while(seq(i) != 1)
  if(mod(seq(i),2) == 0)
    temp = seq(i) / 2;
    seq(i+1) = temp;
    i = i + 1;
  elseif(mod(seq(i),2) != 0)
    temp = 3 * seq(i) + 1;
    seq(i+1) = temp;
    i = i + 1;
  endif
endwhile

x = seq;
g = sprintf('%d ', x);
fprintf('Answer: %s\n', g)