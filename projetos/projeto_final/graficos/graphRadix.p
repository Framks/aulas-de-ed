# gnuplot file
# generates the graph for bublesort test

set term png                        # will produce .png output
set output "graficoRadix.png"      # output to any filename.png you want
set grid                            # grid background
set title 'Radix Sort'             # plot title
set xlabel 'Tamanho do Vetor'       # x-axis label
set ylabel 'Microssegundos'         # y-axis label

# plot the graphic
plot '../resultados/radixsort.txt' with linespoints
