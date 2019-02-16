TARGETS=average telephone dividing webnav spellchecker filemap hangover

all:	$(TARGETS)

$(TARGETS):	%:	%.o

%:	%.o
	$(CC) -o$@ $<

clean:
	rm -rf $(TARGETS)
	rm -rf *.o
