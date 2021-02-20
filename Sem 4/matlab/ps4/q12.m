x = 5
y = (x-1)/2
for i = 1:x
    for j = 1:i/2
        fprintf(' ')
    end
    for j = 1:i
        fprintf('*')
    end
    fprintf('\n')
end