CC     = gcc
CFLAGS = -g -Wall -Wextra -Wpedantic -std=c99
CLIBS  = -lc -lm

%:
	$(CC) $@.c $(CFLAGS) $(CLIBS) -o $@.out

clean:
	find . -type f -name *.out | xargs rm -rf

.PHONY: clean
