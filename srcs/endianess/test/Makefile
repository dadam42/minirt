#-- TARGET definition :
TARGET_TYPE=exe#one of : exe, lib, default to exe
TARGET=test
#-- libs definition :
LIBS=libd42_sys
#-- definitions for each lib :
d42_sys_DIR=..#mandatory, directory containing both library and its Makefile.
d42_sys_INC=#optionnal, default to lib_DIR : dirname containing lib's headers files.
#-- srcs definition :
SRCS=sys_get_endianess.c
SRCS_DIRS=.
SRCS_INCS=#
#
#---- dont change anything after this
#--------------------------------------------------------------------------------------

RTARGET_TYPE=$(if $(TARGET_TYPE),$(TARGET_TYPE),exe)
LIBS_FPATHS=$(foreach lib,$(LIBS:lib%=%),$($(lib)_DIR)/lib$(lib).a)
LIBS_DIRS=$(foreach lib,$(LIBS:lib%=%),$($(lib)_DIR))
LDFLAGS=$(LIBS_DIRS:%=-L%) $(LIBS:lib%=-l%)
LIBS_INCS=$(foreach lib,$(LIBS:lib%=%),$(if $($(lib)_INC),$($(lib)_INC),$($(lib)_DIR)))
IFLAGS=$(SRCS_INCS:%=-I%) $(LIBS_INCS:%=-I%)
CFLAGS=-Wall -Wextra -Werror $(IFLAGS)
empty=
space=$(empty) $(empty)
VPATH=$(subst $(space),:,$(SRCS_DIRS))
vpath lib%.a $(subst $(space),:,$(LIBS_DIRS))

.PHONY:all
all:$(TARGET)

ifeq ($(RTARGET_TYPE),exe)
$(TARGET):$(LIBS:%=%.a) $(SRCS:%.c=%.o)
	gcc $(CFLAGS) $(SRCS:%.c=%.o)  -o $@ $(LDFLAGS)
else
$(TARGET):$(SRCS:%.c=%.o)
	ar -rc $@ $?
	ranlib $@
endif

lib%.a:
	$(MAKE) -C $($*_DIR)

.PHONY:clean
clean:
	rm -f $(wildcard *.o)

.PHONY:fclean
fclean:clean
	rm -f $(TARGET)

.PHONY:re
re:fclean $(TARGET)
