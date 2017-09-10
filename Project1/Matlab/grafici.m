%% Plot generator for project1
%% Import data
import_dati_p1_10;
import_dati_p1_100;
import_dati_p1_1000;

%% Generate data matrices for each run
%Create matrix for analytical solution
A = [x3 s3];
%Create martix for 1st, 2nd, 3rd run (n=10,100,1000)
N10 = [x1 ss1];
N100 = [x2 ss2];
N1000 = [x3 ss3];

%% Plot
%Plot numerical solution for n=1000
plot(N1000(:,1),N1000(:,2),'Linestyle','none','Linewidth',0.2,...
    'Marker','.','Markersize',5,'color','b');
hold on
%Plot numerical solution for n=100
plot(N100(:,1),N100(:,2),'Linestyle','--','Linewidth',0.2,...
    'Marker','.','Markersize',8,'color',[0 230 77]/256);
hold on
%Plot numerical solution for n=10
plot(N10(:,1),N10(:,2),'Linestyle','--','Linewidth',0.2,...
    'Marker','.','Markersize',8,'color',[255 204 0]/256);
hold on
%Plot analytical solution
plot(A(:,1),A(:,2),'Linestyle','-','Linewidth',0.5...
    ,'color','r');

% Make a legend
axs = gca;
ll=legend([axs],'show','$n = 1000$','$n=100$','$n=10$',...
    'analytical s.');
set(ll,'FontSize',10);
set(ll,'Interpreter','LaTeX');

% Set the rest of the features
title('Numerical and analytical solutions - comparison',...
    'Interpreter','LateX','FontSize',18);
xlabel('$x$','Interpreter','LaTeX','FontSize',15);
ylabel('$u(x)$','Interpreter','LaTeX','FontSize',15);