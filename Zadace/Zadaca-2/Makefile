z1: zadatak1/zadatak1.o tests.o
	g++ $? -o $@

z2: zadatak2/zadatak2.o tests.o
	g++ -o $@ $?

z3: zadatak3/zadatak3.o tests.o
	g++ -o $@ $?

z4: zadatak4/zadatak4.o tests.o
	g++ -o $@ $?

z5: zadatak5/zadatak5.o tests.o
	g++ -o $@ $?

z6: zadatak6/zadatak6.o tests.o
	g++ -o $@ $?

z7: zadatak7/zadatak7.o tests.o
	g++ -o $@ $?

clean:
	find . -maxdepth 2 -iname "*.o" -type f -delete
	find . -maxdepth 2 -iname "z*" ! -name "*.*" -type f -delete
