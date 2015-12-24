set term pdf
set output 'nishima.pdf'

set encoding iso_8859_1 

set linetype 1 lw 2 lc rgb "blue" pointtype 7 ps 0.5

#f(x)=a*x+b

#fit f(x) 'calib_ind.txt' using 1:($2-$3):(0.001):(1) xyerrors via a,b

set xlabel "{/Symbol q}"
set ylabel "(d{/Symbol s}/d{/Symbol q})/(d{/Symbol s}/d{/Symbol q})_{20}"

set xrange [0:2]
set yrange [0:2]

#plot 'dados_teo.txt' using 1:(abs(($2-$3))*1e-3):(0.001):(0.1e-3) title  "Campo paralelo experimental" with xyerrorbars,\

r=2.818e-15
z=13
a=1.29550178492553
c=8.38713647899768e-29

f(x)=(1/c)*z*(r**2)*(1/(1+a*(1-cos(x))))**2*((1+cos(x)**2)/2)*(1+(a**2)*(1-cos(x))**2/((1+cos(x)**2)*(1+a*(1-cos(x)))))


plot f(x) title 'Klein-Nishima'


#print "declive"
#print a
#print "ordenada"
#print b
