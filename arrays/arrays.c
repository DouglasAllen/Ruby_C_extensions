#include "ruby.h"
/*
 * call-seq:
 *  initialize()
 *
 * Create Arrays class Ruby object.
 *
 */
static VALUE
t_init(VALUE self)
{
	return self;
}

static VALUE new_ary(VALUE self){
  VALUE ary;
  ary = rb_ary_new();
  return ary;
}

static VALUE ary_push(VALUE self, VALUE in_){
  VALUE ary = rb_ary_new();
  ary = rb_ary_push(ary, in_);
  return ary;
}

static VALUE ary_size(VALUE self, VALUE in_ary){
  VALUE len = RARRAY_LEN(in_ary);
  return INT2NUM(len);
}

VALUE cArrays;
void Init_arrays()
{
  cArrays = rb_define_class("Arrays", rb_cObject);
  rb_define_method(cArrays, "initialize", t_init, 0);
  rb_define_method(cArrays, "ary", new_ary, 0);
  rb_define_method(cArrays, "push", ary_push, 1);
  rb_define_method(cArrays, "size", ary_size, 1);
}

// aptr = RARRAY_PTR(ary);