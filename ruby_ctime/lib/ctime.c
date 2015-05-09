#include <time.h>
#include <sys/time.h>
#include <ruby.h>
	
VALUE get_time(VALUE self)
{
  time_t now;
	time(&now);
	return rb_str_new2(ctime(&now));
}

VALUE e_sec(VALUE self)
{
	struct timeval tval;
	gettimeofday(&tval, NULL);
  return INT2NUM(tval.tv_sec);
}



void Init_ctime()
{
  rb_define_global_function("get_time", get_time, 0);
	rb_define_global_function("e_sec", e_sec, 0);
}