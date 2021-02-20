m = input("Enter the number of students :");
for i=1:m
    for j=1:10
        R(i,j)=input('elements : ');
    end
end
R=reshape(R,m,10)
g = fgrade(R)