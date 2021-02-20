x = 10:0.01:22;
y = 95000./((x).^2);
X = 10:2:22;
Y = [950, 640, 460, 340, 250, 180, 140];
plot(x, y);
hold on;
plot(X,Y,':or');
xlabel('Distance (cm)');
ylabel('Intensity (lux)');
title('Light Intensity as a Function of Distance')
axis([8 24 0 1200])
text(14,640, 'Comparision between theory and exeriment', 'EdgeColor', 'r')
legend('Theory', 'Experiment')