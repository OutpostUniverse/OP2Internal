# =====
# Makefile used for compiling (testing) from Linux.
# =====

# Set compiler to mingw (can still override from command line)
CXX := i686-w64-mingw32-g++

SRCDIR := src/
BUILDDIR := .build/
BINDIR := $(BUILDDIR)bin/
OBJDIR := $(BUILDDIR)obj/
DEPDIR := $(BUILDDIR)obj/
OUTPUT := OP2Internal.lib

CPPFLAGS :=
CXXFLAGS := -std=c++17 -g -Wall -Wno-unknown-pragmas

DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)$*.Td

COMPILE.cpp = $(CXX) $(DEPFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(TARGET_ARCH) -c
POSTCOMPILE = @mv -f $(DEPDIR)$*.Td $(DEPDIR)$*.d && touch $@

SRCS := $(shell find $(SRCDIR) -name '*.cpp')
OBJS := $(patsubst $(SRCDIR)%.cpp,$(OBJDIR)%.o,$(SRCS))
ASMSRCS :=  $(shell find $(SRCDIR) -name '*.asm')
ASMOBJS := $(patsubst $(SRCDIR)%.asm,$(OBJDIR)%.obj,$(ASMSRCS))
FOLDERS := $(sort $(dir $(SRCS)))

.PHONY:default, all
default: all
all: $(OUTPUT)

$(OUTPUT): $(OBJS) $(ASMOBJS)
	@mkdir -p ${@D}
	ar rcs $@ $^

$(ASMOBJS): $(OBJDIR)%.obj : $(SRCDIR)%.asm | build-folder
	nasm -f win32 -o $@ $^

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.cpp $(DEPDIR)%.d | build-folder
	$(COMPILE.cpp) $(OUTPUT_OPTION) $<
	$(POSTCOMPILE)

.PHONY:build-folder
build-folder:
	@mkdir -p $(patsubst $(SRCDIR)%,$(OBJDIR)%, $(FOLDERS))
	@mkdir -p $(patsubst $(SRCDIR)%,$(DEPDIR)%, $(FOLDERS))

$(DEPDIR)%.d: ;
.PRECIOUS: $(DEPDIR)%.d

include $(wildcard $(patsubst $(SRCDIR)%.cpp,$(DEPDIR)%.d,$(SRCS)))

.PHONY:clean, clean-deps, clean-all
clean:
	-rm -fr $(OBJDIR)
	-rm -fr $(DEPDIR)
	-rm -fr $(BINDIR)
	-rm -f $(OUTPUT)
clean-deps:
	-rm -fr $(DEPDIR)
clean-all:
	-rm -rf $(BUILDDIR)
