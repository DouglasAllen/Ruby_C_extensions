#include <ruby.h>

#ifndef DBL2NUM
# define DBL2NUM(dbl) rb_float_new(dbl)
#endif

ID id_status;
static ID id_push;

static VALUE 
t_init(VALUE self)
{
  VALUE arr;
  arr = rb_ary_new();
  rb_iv_set(self, "@arr", arr);
  return self;
}

static VALUE 
t_add(VALUE self, VALUE obj)
{
  VALUE arr;
  arr = rb_iv_get(self, "@arr");
  rb_funcall(arr, id_push, 1, obj);
  return arr;
}

static VALUE 
hello_world(VALUE mod)
{
  return rb_str_new2("hello world");
}


static VALUE
bug_time_s_timespec_now(VALUE cStree)
{
    struct timespec ts;
    VALUE v;
    rb_timespec_now(&ts);
    v = rb_Rational(LONG2NUM(ts.tv_nsec), LONG2NUM(1000000000L));
    return rb_num_coerce_bin(TIMET2NUM(ts.tv_sec), v, '+');
}

static VALUE
func_mean_anomally(VALUE klass, VALUE vd)
{
  rb_ivar_set(klass, id_status, INT2FIX(0));
  return DBL2NUM(fmod(357.5291 + 0.98560028 * (NUM2DBL(vd)), 360));
}

static VALUE
func_equation_of_center(VALUE klass, VALUE vd)
{
  VALUE ma;
  rb_ivar_set(klass, id_status, INT2FIX(0));
  ma = NUM2DBL(fmod(357.5291 + 0.98560028 * (NUM2DBL(vd)), 360));
  return DBL2NUM(1.9148 * sin(ma) + 0.0200 * sin(2 * ma) + 0.0003 * sin(3 * ma));
}

static VALUE
func_true_anomally(VALUE klass, VALUE vd)
{
  return DBL2NUM(func_mean_anomally(klass, NUM2DBL(vd))) +
    DBL2NUM(func_equation_of_center(klass, NUM2DBL(vd)));
}

void Init_stree(void)
{
  VALUE cStree = rb_define_class("Stree", rb_cObject);
  rb_define_method(cStree, "initialize", t_init, 0);
  rb_define_method(cStree, "add", t_add, 1);
  id_push = rb_intern("push");
  rb_define_method(cStree, "hello_world", hello_world, 0);
  rb_define_method(cStree, "timespec_now", bug_time_s_timespec_now, 0);  
  rb_define_method(cStree, "mean_anomally", func_mean_anomally, 1);
  rb_define_method(cStree, "equation_of_center", func_equation_of_center, 1);
  rb_define_method(cStree, "true_anomally", func_true_anomally, 1);
}