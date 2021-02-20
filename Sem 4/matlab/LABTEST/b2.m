number = input("Enter a number:");
cnt = 0;
disp("Prime divisors for given number are:");
for i = 1:number
  if (mod(number,i) == 0)
    cnt = cnt + 1;
    if (isprime(i) == 1)
      disp(i);
    endif
  endif
endfor
printf("Number of divisors for given number = %d \n", cnt);