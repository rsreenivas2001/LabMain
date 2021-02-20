amount = 5000;
i = 0;
while (amount < 1000000)
    amount = (amount*1.09);
    i = i+1; 
endwhile
printf("He will retire after %d years \n",(i-1));