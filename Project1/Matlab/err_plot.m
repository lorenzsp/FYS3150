%% Import data from text file.
% Script for importing data from the following text file:
%
%    C:\Users\Davide\Documents\GitHub\FYS3150\Project1\build-p1_1c-Desktop-Debug\dat_err.txt
%
% To extend the code to different selected data or a different text file,
% generate a function instead of a script.

% Auto-generated by MATLAB on 2017/09/09 21:37:37

%% Initialize variables.
filename = 'C:\Users\Federico\Documents\GitHub\FYS3150\Project1\build-p1_1c-Desktop-Debug\dat_err.txt';
delimiter = ' ';
startRow = 2;

%% Format for each line of text:
%   column1: double (%f)
%	column2: double (%f)
% For more information, see the TEXTSCAN documentation.
formatSpec = '%f%f%[^\n\r]';

%% Open the text file.
fileID = fopen(filename,'r');

%% Read columns of data according to the format.
% This call is based on the structure of the file used to generate this
% code. If an error occurs for a different file, try regenerating the code
% from the Import Tool.
dataArray = textscan(fileID, formatSpec, 'Delimiter', delimiter, 'MultipleDelimsAsOne', true, 'HeaderLines' ,startRow-1, 'ReturnOnError', false, 'EndOfLine', '\r\n');

%% Close the text file.
fclose(fileID);

%% Allocate imported array to column variable names
n = dataArray{:, 1};
max_err = dataArray{:, 2};


%% Clear temporary variables
clearvars filename delimiter startRow formatSpec fileID dataArray ans;

%% Generate plot
figure();
plot(-log10(n+1), max_err,'marker','.','markersize',5,'color','r');
% Make a legend
axs = gca;
ll=legend([axs],'show','relative error');
set(ll,'FontSize',10);
set(ll,'Interpreter','LaTeX','Location','northwest');

% Set the rest of the features
title('Step size dependence for relative error $\varepsilon$',...
    'Interpreter','LateX','FontSize',18);
xlabel('$log_{10}(h)$','Interpreter','LaTeX','FontSize',15);
ylabel('$log_{10}(\varepsilon)$','Interpreter','LaTeX','FontSize',15);
xlim([-7.5 -0.5])