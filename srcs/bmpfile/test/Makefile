CFLAGS=-Wall -Wextra -Werror -I..
CPPFLAGS=-lm

test_bmpfile_save: bmpfile_save.c ../bmpfile_save.c
	gcc ${CFLAGS} bmpfile_save.c ../bmpfile_save.c -g ${CPPFLAGS} -o $@
