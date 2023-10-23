clear;clc;close all;

 fid=fopen("quicksort.txt");
 data=textscan(fid,'%d %f');
 fclose(fid);
 x=data{1};
quicksort_y=data{2};

 fid=fopen("mergesort.txt");
 data=textscan(fid,'%d %f');
 fclose(fid);
 mergesort_y=data{2};

 fid=fopen("heapsort.txt");
data=textscan(fid,'%d %f');
 fclose(fid);
 heapsort_y=data{2};

 fid=fopen("shellsort_2n.txt");
data=textscan(fid,'%d %f');
 fclose(fid);
 shellsort_y=data{2};


 figure;
 title("sorting algorithms");
 xlabel("n [-]");
 ylabel("t [s]");
 hold on;
 plot(x,quicksort_y);
 plot(x,mergesort_y);
 plot(x,heapsort_y);
 plot(x,shellsort_2n_y);
 legend("quicksort","mergesort","heapsort","shellsort_2n","Location","northwest");
 hold off;