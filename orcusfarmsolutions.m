clc;
clear all;
close all;
 count1=0;
 count2=0;
[fname path] = uigetfile('*.*','Enter an image');
fname = strcat(path,fname);
im = imread(fname);
imshow(im)
title('Your input image');
im = imresize(im,[256,256]);

imGray = rgb2gray(im);
subplot(2,1,1);
figure(1);
imshow(imGray);
subplot(2,1,2);
imhist(imGray);
[COUNTS,X]=imhist(imGray);
xlabel('Intensity of grayscale');
ylabel('Number of pixels of the image');
n = 256;
title('GrayScale');
%%Thresholding
imA = imGray>150;
subplot(2,1,1)
figure(2);
imshow(imA);
display([COUNTS,X]);

