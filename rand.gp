reset
set ylabel 'times'
set xlabel 'N'
set style fill solid
set title 'number appear times'
set term png enhanced font 'Verdana,10'
set output 'times.png'



plot [:32780][0:] "detail.txt" using 1:2 with points title 'time1'

