all:
	@echo 'Please enter a target. Exampel: for PC enter "make pc"'

pc:
	$(MAKE) -f Makefile.pc

mac:
	$(MAKE) -f Makefile.mac

psp:
	$(MAKE) -f Makefile.psp
