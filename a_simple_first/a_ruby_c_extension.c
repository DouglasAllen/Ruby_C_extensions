#include "ruby.h"

static VALUE 
t_init(VALUE self)
{
	return self;
}

VALUE cKlass;
void Init_a_ruby_c_extension()
{
	cKlass = rb_define_class("ARubyCExtension", rb_cObject);
	rb_define_method(cKlass, "initialize", t_init, 0);
}