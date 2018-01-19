SHELL=/usr/bin/sh
CC=/usr/bin/cc
PROC=$(ORACLE_HOME)/bin/proc
HOME_SIC=/home/app_sicp_exe/sic
SIC_HOME=$(HOME_SIC)
SIC_DIR_LIB=$(SIC_HOME)/lib
SIC_INCLUDE=$(SIC_DIR_LIB)/include
ORA_LIB=$(ORACLE_HOME)/lib
C_FLAGS=-I$(SIC_INCLUDE) -g
LD_FLAGS=-L$(ORA_LIB) -L/usr/lib -L$(SIC_DIR_LIB)/clib -L$(SIC_DIR_LIB)/olib -L$(SIC_DIR_LIB)/blib -L$(SIC_DIR_LIB)/wrep /home/app_sicp_exe/sic/lib/clib/clib.a /home/app_sicp_exe/sic/lib/olib/olib.a /home/app_sicp_exe/sic/lib/blib/blib.a /home/app_sicp_exe/sic/lib/wrep/rwwclib.a -L/home/oracle/OraHome1/lib/ -lclntsh -ldl -lm -lpthread -lnsl -lirc -lm -lpthread -lpthread -lpthread
PROC_FLAGS=include=$(SIC_INCLUDE) ireclen=255 oreclen=255 select_error=no  sqlcheck=full userid=lgas/$(PasswordDeLGAS)@$(ORACLE_SID) lines=n hold_cursor=yes maxopencursors=300
FUENTES_PC=depura.pc impint.pc
FUENTES_C=$(FUENTES_PC:.pc=.c)
OBJETOS=$(FUENTES_C:.c=.o)
.SUFFIXES:	.o .c .pc
impint:	$(OBJETOS)
	@echo -e ".o -> impint.exe"
	@$(CC) -I$(SIC_INCLUDE) $(C_FLAGS) -o impint.exe $(OBJETOS) $(LD_FLAGS) >make.log
	@cp impint.exe .#${ALAMO_BIN} 
	#@rm -f *.c *.o *.lis
depura.o:	depura.c
	@echo -e "-> $*.o"
	@$(CC) -c depura.c $(C_FLAGS) >make.log
depura.c:	depura.pc
	@echo -e -n "depura.pc -> depura.c "
	@$(PROC) $(PROC_FLAGS) iname=depura.pc >make.log
impint.o:	impint.c gen_txt.h depura.h
	@echo -e "-> $*.o"
	@$(CC) -c impint.c $(C_FLAGS) >make.log
impint.c:	impint.pc gen_txt.h depura.h
	@echo -e -n "impint.pc -> impint.c "
	@$(PROC) $(PROC_FLAGS) iname=impint.pc >make.log
clean:
	@rm -f *.o *.c
