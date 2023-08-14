# gnuplot file
# generates the graph for bublesort test

set term png                        # will produce .png output
set output "graficoQuick.png"      # output to any filename.png you want
set grid                            # grid background
set title 'Quick Sort'             # plot title
set xlabel 'Tamanho do Vetor'       # x-axis label
set ylabel 'Microssegundos'         # y-axis label

# plot the graphic
plot '../resultados/quicksort.txt' with linespoints
