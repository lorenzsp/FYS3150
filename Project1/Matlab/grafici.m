%% n=10

import_dati_p1_10

fig1=figure();

axs1=gca;
set(axs1, 'NextPlot', 'add');
yl1= ylabel(['solution']);
set(yl1, 'Fontsize', 18);

xl1 = xlabel(['x']);
set(xl1, 'Fontsize', 18);

tl1 = title('Comparison between analytical and numerical solution with n=10');
set(tl1, 'Fontsize', 24);

plot(x1, s1);
hold on
plot(x1,ss1);
% n=100
import_dati_p1_100

%fig2=figure();

axs2=gca;
set(axs2, 'NextPlot', 'add');
yl2 = ylabel(['Solution']);
set(yl2, 'Fontsize', 18);

xl2 = xlabel(['x']);
set(xl2, 'Fontsize', 18);

tl2 = title('Comparison between analytical and numerical solution with n=100');
set(tl2, 'Fontsize', 24);

plot(x2, s2);
hold on
plot(x2,ss2);

% n=100
import_dati_p1_1000

%fig3=figure();

axs3=gca;
set(axs3, 'NextPlot', 'add');
yl3 = ylabel(['solution']);
set(yl3, 'Fontsize', 18);

xl3 = xlabel(['x']);
set(xl3, 'Fontsize', 18);

tl3 = title('Comparison between analytical and numerical solution with n=1000');
set(tl3, 'Fontsize', 24);

plot(x3, s3);
hold on
plot(x3,ss3);
