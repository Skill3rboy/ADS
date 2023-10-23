reset

set autoscale x
set autoscale y
set xlabel "n [-]"
set ylabel "t [s]"
set key top left




plot \
"heapsort.txt" with linespoints title 'Heapsort',\
"quicksort.txt" with linespoints title 'Quicksort',\
"mergesort.txt" with linespoints title 'Mergesort',\
"shellsort.txt" with linespoints title 'Shellsort',\

