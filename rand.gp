reset
set ylabel 'time(sec)'
set xlabel 'N'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'times.png'



plot [:32780][0:] "detail.txt" using 1:2 with points title 'time1'

