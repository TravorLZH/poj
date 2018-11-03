TARGETS=dividing filemap

all:	$(TARGETS)

$(TARGETS):	%:	%.o

%:	%.o
	$(CC) -o$@ $<

clean:
	rm -rf $(TARGETS)
	rm -rf *.o
