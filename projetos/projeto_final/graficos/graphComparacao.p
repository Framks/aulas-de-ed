# gnuplot file
# generates the graph for cocktail sort and Bubblesort

set term png                        # will produce .png output
set output "graficoComparacao.png"  # output to any filename.png you want
set grid                            # grid background
set title 'Merge x Insertion x Bubble x Selection x Radix x Quick'       # plot title
set xlabel 'Tamanho do Vetor'       # x-axis label
set ylabel 'Microssegundos'         # y-axis label
set multiplot                       # multiplot mode (prompt changes to 'multiplot')

# plot the graphic
plot '../resultados/mergesort.txt' with linespoints title 'Merge', '../resultados/insertionsort.txt' with linespoints title 'Insertion', '../resultados/bubblesort.txt' with linespoints title 'Bubble', '../resultados/selectionsort.txt' with linespoints title 'Selection', '../resultados/radixsort.txt' with linespoints title 'Radix', '../resultados/quicksort.txt' with linespoints title 'Quick'

unset multiplot                     # exit multiplot mode (prompt changes back to 'gnuplot')
