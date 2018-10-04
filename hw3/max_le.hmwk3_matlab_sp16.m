x = linspace(0,6);
y1 = x.^3 -8*x.^2 + 6*x + 6;
y2 = 0;
plot(x,y1,'-r')
hold on
plot(x,y2,'xb')
axis([0,2,-8,8]);
grid on
box on
legend('y1 =  x.^3 -8*x.^2 + 6*x + 6','y2 = 0')
xlabel ('x-axis')
ylabel ('y-axis')
title('Graphical representation of f(x)')
idx = find(y1-y2 < eps,1);
px = x(idx);
py = y1(idx);
