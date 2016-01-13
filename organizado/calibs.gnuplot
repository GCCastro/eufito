set term pdf
set output '3calibs.pdf'

f1(x)=4.52259e-3*x+4.65988e-3
f2(x)=4.54239e-3*x+6.69368e-4
f3(x)=4.47637e-3*x+9.42809e-3

set xrange [200.:270]
set yrange [0.9:1.3]

plot f1(x), f2(x), f3(x)
