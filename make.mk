plot.png: Data.dat plot.py
	python plot.py

%.dat : a.out
	./a.out 

a.out: Diff.cpp
	g++ Diff.cpp
