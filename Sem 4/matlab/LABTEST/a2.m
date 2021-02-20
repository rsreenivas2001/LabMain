#x = 2:0.01:6;
#plot((2*x + 3 + exp(x))/(4*x -5));

%1
%b
%1
%b
fun = @(x) (((2.*x) + 3 + exp(x))./((4.*x) - 5));
fplot(fun,[2,6], ':og');
hold on 
fplot(fun,[2 6], 'MarkerFaceColor','red');
hold on
fplot(fun,[2 6],'MarkerEdgeColor','yellow');
hold on
fplot(fun,[2 6], 'MarkerSize',14);
hold on
fplot(fun,[2 6],'LineWidth',2)
hold off
