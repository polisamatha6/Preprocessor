mypreprocessor:
	cc main.c comment_removal.c file_inclusion.c macro.c -o mypreprocessor

clean:
	rm -r mypreprocessor
