CC              = clang
CFLAGS          = -Wall -std=c++11 -Iinc/
LDFLAGS         = -lstdc++ -ltermgl
BUILDDIR        = build
SOURCEDIR       = src
OBJECTDIR       = obj

OUTPUT          = ascedit

SRCS = $(wildcard $(SOURCEDIR)/*.cpp)
OBJS = $(SRCS:.cpp=.o)
OBJ  = $(OBJS:$(SOURCEDIR)/%=$(OBJECTDIR)/%)

build: dir $(OBJ)
	@echo [LD] $(OBJ)
	@$(CC) $(CFLAGS) -o $(BUILDDIR)/$(OUTPUT) $(OBJ) $(LDFLAGS)

debug: CFLAGS += -g -D _DEBUG
debug: build;

dir:
	@mkdir -p $(OBJECTDIR)
	@mkdir -p $(BUILDDIR)

$(OBJECTDIR)/%.o: $(SOURCEDIR)/%.cpp
	@echo [CC] $<
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@echo [RM] $(OBJ)
	@echo [RM] $(BUILDDIR)/$(OUTPUT)
	@rm -df  $(OBJ)
	@rm -Rdf $(BUILDDIR) $(OBJECTDIR)
