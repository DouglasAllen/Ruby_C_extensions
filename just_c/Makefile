.cc.o:
	$(ECHO) compiling $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -c $<
	
#~ NAMES = 
#~ SRCS_C = 
#~ OBJS = $(SRCS_C:.c=.o)

all: asctime clock_t clock_t1 ctime ctime1 difftime \
      facebook_ruby \
      gettime gettimeofday gmtime gmtime1\
			localtime mktime strftime sunriset \
      time time_t time_func yesterday
			
.PHONY : all

#~ asctime : asctime.o
	#~ cc -o asctime asctime.o
#~ asctime.o : asctime.c
	#~ cc -c asctime.c
	
#~ clock_t : clock_t.o
	#~ cc -o clock_t clock_t.o
#~ clock_t.o : clock_t.c
	#~ cc -c clock_t.c
	
#~ clock_t1 : clock_t1.o
	#~ cc -o clock_t1 clock_t1.o
#~ clock_t1.o : clock_t1.c
	#~ cc -c clock_t1.c	
	
#~ ctime : ctime.o
	#~ cc -o ctime ctime.o
#~ ctime.o : ctime.c
	#~ cc -c ctime.c

#~ facebook_ruby : facebook_ruby.o
	#~ cc -o facebook_ruby facebook_ruby.o
#~ facebook_ruby.o : facebook_ruby.c
	#~ cc -c facebook_ruby.c
	
gettime : gettime.o
	cc -o gettime gettime.o
gettime.o : gettime.c
	cc -c gettime.c -std=gnu99	
	
#~ gettimeofday : gettimeofday.o
	#~ cc -o gettimeofday gettimeofday.o 
#~ gettimeofday.o : gettimeofday.c
	#~ cc -c gettimeofday.c	
	
#~ gmtime : gmtime.o
	#~ cc -o gmtime gmtime.o
#~ gmtime.o : gmtime.c
	#~ cc -c gmtime.c	

sunriset : sunriset.o
	cc -o sunriset sunriset.o -lm
sunriset.o : sunriset.c
	cc -c sunriset.c
	
#~ time : time.o
	#~ cc -o time time.o
#~ time.o : time.c
	#~ cc -c time.c
	
#~ time_t : time_t.o
	#~ cc -o time_t time_t.o
#~ time_t.o : time_t.c
	#~ cc -c time_t.c	
	
#~ time_func : time_func.o
	#~ cc -o time_func time_func.o
#~ time_func.o : time_func.c
	#~ cc -c time_func.c
	
#~ yesterday : yesterday.o
	#~ cc -o yesterday yesterday.o
#~ yesterday.o : yesterday.c
	#~ cc -c yesterday.c

.PHONY: clean
clean:
	rm *.o


.PHONY: delete
delete:
	rm asctime clock_t clock_t1 ctime ctime1 difftime \
	facebook_ruby \
	gettime gettimeofday gmtime gmtime1 \
	localtime mktime strftime sunriset \
	time time_t time_func yesterday			