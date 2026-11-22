run: main
	./main

watch: 
	find *.c | entr -c make run

clean: main
	rm main