#include <ruby.h>

static inline double
func_sum(double *arry, int len)
{
  double ret = 0;
  int i;
  for(i = 0; i < len; i++){
    ret = ret + arry[i];
  }
  return ret;
}

static inline
double split(double num)
{
   double ret = 0;
   ret = num / 2;
   return ret;
}

static VALUE lsum(VALUE self, VALUE in_ary){
  // int len;
  // double sum;
  VALUE ary;
  // VALUE * aptr;
  ary = rb_ary_new();
  ary = rb_ary_push(ary, in_ary);
  // len = RARRAY_LEN(ary);
  // aptr = RARRAY_PTR(ary);
  // sum = func_sum(aptr, len);
  return ary;
}

static VALUE t_init(VALUE self){
  VALUE arr;
  arr = rb_ary_new();
  rb_iv_set(self, "@arr", arr);
  return self;
}

void Init_libsum(void){
  VALUE cLibSum = rb_define_class("LibSum", rb_cObject);
  rb_define_method(cLibSum, "initialize", t_init, 0);
  rb_define_method(cLibSum, "sum", lsum, 1);
}