x = input("Enter the number : ");
fact = 1;
for i = 1:x,
  fact = fact*i;
endfor
printf("The factorial of the number entered is : %d \n", fact)