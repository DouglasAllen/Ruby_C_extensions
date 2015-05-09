#include <ruby.h>

VALUE binc(VALUE self)
{
  int i = 5;
	++i;
	++i;
  return INT2NUM(i);
}

VALUE ainc(VALUE self)
{
  int i = 5;
	i++;
	i++;
  return INT2NUM(i);
}

void Init_power_of_c()
{
  rb_define_global_function("binc", binc, 0);
	rb_define_global_function("ainc", ainc, 0);
}