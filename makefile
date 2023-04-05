CC     = gcc
CFLAGS = -g -Wall -Wextra -Wpedantic -std=c99
CLIBS  = -lc -lm
TE     = xelatex
BE     = bibtex
OS     = $(shell uname -s)

ifeq ($(OS), Darwin)
	DC = open -a Preview
else
	DC = zathura
endif

%:
	$(CC) src/$@.c $(CFLAGS) $(CLIBS) -o src/$@.out

draft:
	$(TE) main
	$(TE) main
	$(DC) main.pdf

final:
	$(TE) main
	$(BE) main
	$(TE) main
	$(TE) main
	$(DC) main.pdf

clean:
	find . -type f -name main.aux | xargs rm -rf
	find . -type f -name main.bbl | xargs rm -rf
	find . -type f -name main.blg | xargs rm -rf
	find . -type f -name main.log | xargs rm -rf
	find . -type f -name main.lol | xargs rm -rf
	find . -type f -name main.pdf | xargs rm -rf
	find . -type f -name main.toc | xargs rm -rf
	find . -type f -name    *.out | xargs rm -rf

.PHONY: draft final clean
