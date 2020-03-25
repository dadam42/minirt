#-- TARGET definition :
TARGET_TYPE=lib#one of : exe, lib, default to exe
TARGET=libbmpfile.a
#-- libs definition :
LIBS=libft libd42_sys#list of libs which must be recompiled by this Makefile
STDLIBS=#list of list which must be include to compile
#-- definitions for each lib from $(LIBS):
ft_DIR=../libft#mandatory, directory containing both library and its Makefile.
ft_INC=#optionnal, default to lib_DIR : dirname containing lib's headers files.
d42_sys_DIR=../endianess
#-- srcs definition :
SRCS=bmpfile_save.c
SRCS_DIRS=
SRCS_INCS=.#
#
#---- dont change anything after this
#--------------------------------------------------------------------------------------

RTARGET_TYPE=$(if $(TARGET_TYPE),$(TARGET_TYPE),exe)
LIBS_FPATHS=$(foreach lib,$(LIBS:lib%=%),$($(lib)_DIR)/lib$(lib).a)
LIBS_DIRS=$(foreach lib,$(LIBS:lib%=%),$($(lib)_DIR))
CPPFLAGS=$(LIBS_DIRS:%=-L%) $(LIBS:lib%=-l%) $(STDLIBS:lib%=-l%)
LIBS_INCS=$(foreach lib,$(LIBS:lib%=%),$(if $($(lib)_INC),$($(lib)_INC),$($(lib)_DIR)))
IFLAGS=$(SRCS_INCS:%=-I%) $(LIBS_INCS:%=-I%)
CFLAGS=-Wall -Wextra -Werror -g $(IFLAGS)
empty=
space=$(empty) $(empty)
VPATH=$(subst $(space),:,$(SRCS_DIRS))
vpath lib%.a $(subst $(space),:,$(LIBS_DIRS))

.PHONY:all
all:$(TARGET)

ifeq ($(RTARGET_TYPE),exe)
$(TARGET):$(LIBS:%=%.a) $(SRCS:%.c=%.o)
	gcc $(CFLAGS) $(SRCS:%.c=%.o)  -o $@ $(CPPFLAGS)
else
$(TARGET):$(SRCS:%.c=%.o)
	ar -rc $@ $?
	ranlib $@
endif

ifneq ($(LIBS),)
lib%.a:
	$(MAKE) -C $($*_DIR)
endif

.PHONY:clean
clean:
	rm -f $(wildcard *.o)

.PHONY:fclean
fclean:clean
	rm -f $(TARGET)

.PHONY:re
re:fclean $(TARGET)
