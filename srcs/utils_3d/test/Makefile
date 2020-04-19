CFLAGS=-Wall -Wextra -Werror -I.. -g
CPPFLAGS=-lm
VPATH=..

.PHONY: all
all : test_add test_lcomb test_vprod

test_add : vec3_operators.o test.o vec3_add.o
	gcc $^ -o $@
	./$@

test_lcomb : vec3_operators.o test.o vec3_lcomb.o
	gcc $^ -o $@
	./$@

test_vprod : vec3_operators.o test.o vec3_vprod.o
	gcc $^ -o $@
	./$@

test_rot : rotations.o mat3_rotations.o test.o
	gcc  -g $^ -o $@ -lm -lft -L../../ft -lutils_3d -L..

.PHONY: clean
clean:
	rm -f *.o
