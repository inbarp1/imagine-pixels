all:
	gcc pic.c
	./a.out
clean:
	rm image.ppm
	rm a.out
	rm *~