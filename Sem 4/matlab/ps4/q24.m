sum = 0;
for x = 2:999,
pri = 0;
for i = 2:(x-1),
    if (i != x)
      if (rem(x,i) == 0)
        pri = 1;
      endif
    endif
endfor
if (pri == 0)
  sum = sum + x;
endif
endfor
disp(["The sum of the prime nos is : ",num2str(sum)]);