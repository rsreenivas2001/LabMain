fn = @(x) (95000./(x.^2));
fplot(fn,[10,22])
text(1000,5,"Comparision between theory and exeriment");
title('Light Intensity as a Function of Distance');
legend('Theory');
xlabel('Distance(cm)');
ylabel('Intensity(lux)');
axis([8 24 0 1200]);