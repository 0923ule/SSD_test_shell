hi: 	ssd testshell

ssd:	ssd.o 
		gcc -o ssd ssd.o

ssd.o:	ssd.c
		gcc -c ssd.c

testshell:	testshell.o
		gcc -o testshell testshell.o

testshell.o:	testshell.c
		gcc -c testshell.c

clean:	
	rm *.o testshell ssd nand.txt result.txt
