.SUFFIXES: .cpp .o

CC    = g++  -g -fpermissive
CFLAGS=-D_PTHREAD_USE_D4 $(DEBUG) -D_ORACLE_ -DHISSVR_A -D_OSVer4 -DONE_DAY  -D__EXTENSIONS__ -fPIC
LDFLAGS=`makeopts.sh ldflag`
MAKE_SO = g++  -fpermissive -pthread -g -shared -fPIC
MAKE_LIB= `makeopts.sh mk_lib`
INCDIR=-I.  -I/home/scada/source/include 
LIBDIR=-L. 
LIBS  =

.cpp.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $<

all:my_test 

my_test:my_test.o
	$(CC) $(LIBDIR) $(LIBS) -o my_test my_test.o

.PHONY:clean

clean:
	rm -f  my_test my_test.o 
