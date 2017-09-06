%% Import data from text file.
% Script for importing data from the following text file:
%
%    C:\Users\Davide\Documents\GitHub\FYS3150\Project1\build-p1_1b-Desktop-Debug\dat_p1_10.txt
%
% To extend the code to different selected data or a different text file,
% generate a function instead of a script.

% Auto-generated by MATLAB on 2017/09/06 18:41:55

%% Initialize variables.
filename = 'C:\Users\Davide\Documents\GitHub\FYS3150\Project1\build-p1_1b-Desktop-Debug\dat_p1_10.txt';
startRow = 2;

%% Format for each line of text:
%   column1: double (%f)
%	column2: double (%f)
%   column3: double (%f)
% For more information, see the TEXTSCAN documentation.
formatSpec = '%15f%15f%f%[^\n\r]';

%% Open the text file.
fileID = fopen(filename,'r');

%% Read columns of data according to the format.
% This call is based on the structure of the file used to generate this
% code. If an error occurs for a different file, try regenerating the code
% from the Import Tool.
dataArray = textscan(fileID, formatSpec, 'Delimiter', '', 'WhiteSpace', '', 'HeaderLines' ,startRow-1, 'ReturnOnError', false, 'EndOfLine', '\r\n');

%% Close the text file.
fclose(fileID);

%% Post processing for unimportable data.
% No unimportable data rules were applied during the import, so no post
% processing code is included. To generate code which works for
% unimportable data, select unimportable cells in a file and regenerate the
% script.

%% Allocate imported array to column variable names
x1 = dataArray{:, 1};
s1 = dataArray{:, 2};
ss1 = dataArray{:, 3};


%% Clear temporary variables
clearvars filename startRow formatSpec fileID dataArray ans;