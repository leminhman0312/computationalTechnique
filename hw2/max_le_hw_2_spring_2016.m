%% PROGRAM:3D surface & 2D contour plots of  non dimensional shear stress
%% AUTHOR : Max Le 

%% DATA 
xtil = [0:0.1:3];
ytil = [-2:0.1:2];
[X,Y] = meshgrid(xtil,ytil);
A = (4*(X.^4).*Y.^2) + ((X.*Y.^2)-(X.^3)).^2;
B = ((X.^2) + (Y.^2)).^4;
pi_ = 4.0*atan(1.0);
z = (1/pi_)*sqrt((A./B));

%% 3D SURFACE PLOT
figure(1)
colormap jet(16);
surf(X,Y,z,'EdgeColor','none')
colorbar
axis equal
bar_range = [0:1:10]; 
caxis = (bar_range);
xlabel('X tilde [dimensionless]')
ylabel('Y tilde [dimensionless]') 
title('Surface plot of non dimensional shear stress')

%% 2D CONTOUR PLOT

figure(2)
colormap jet(16);
contour(X,Y,z,20)
axis equal 
colorbar
xlabel('X tilde [dimensionless]')
ylabel('Y tilde [dimensionless]')
title('Contour plot of non dimensional shear stress')



