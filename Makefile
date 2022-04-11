all: parallel serial 

parallel:

	g++ crivo_p.cpp -o parallel -fopenmp


serial:

	g++ crivo_s.cpp -o serial

clean:

	rm -rf parallel serial

runp: 

	./parallel

runs: 

	./serial
