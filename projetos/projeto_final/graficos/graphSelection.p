# gnuplot file
# generates the graph for bublesort test

set term png                        # will produce .png output
set output "graficoSelection.png"      # output to any filename.png you want
set grid                            # grid background
set title 'Selection Sort'             # plot title
set xlabel 'Tamanho do Vetor'       # x-axis label
set ylabel 'Microssegundos'         # y-axis label

# plot the graphic
plot '../resultados/selectionsort.txt' with linespoints
