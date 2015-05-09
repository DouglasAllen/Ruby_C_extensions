#include <ruby.h>

VALUE fizz(VALUE self, VALUE n_value)
{
  int n = NUM2INT(n_value);
  if (n % 15 == 0) {return rb_str_new2("fizzbuzz");}
  if (n % 5 == 0) {return rb_str_new2("buzz");}
  if (n % 3 == 0) {return rb_str_new2("fizz");}
  return INT2NUM(n);
}

void Init_fizzbuzz()
{
  rb_define_global_function("fizz", fizz, 1);
}