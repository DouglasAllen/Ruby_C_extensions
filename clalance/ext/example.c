/*
 * call-seq:
 *   obj.method(required, optional=0) -> retval
 *
 * Call +wrappedLibraryFunction
 * +[http://www.example.org/docs.html#wrappedLibraryFunction]
 * to execute wrappedLibraryFunction.  This method takes a
 * single required argument, and one optional argument that
 * defaults to 0 if not specified.  It returns retval, which
 * can be any valid ruby object
 */

#include "ruby.h"

static VALUE m_example;
static VALUE c_example;
static VALUE e_ExampleError;
/*
static VALUE catch_cb(VALUE val, VALUE args, VALUE self) {
  rb_yield(args);
  return Qnil;
}

static VALUE example_method(VALUE klass) {
  VALUE res;

  if (!rb_block_given_p())
    rb_raise(rb_eStandardError, "Expected a block");

  res = rb_catch("catchpoint", catch_cb, rb_str_new2("val"));

  if (TYPE(res) != T_FIXNUM)
    rb_throw("catchpoint", Qnil);
  return res;
}
*/
static VALUE mymethod(VALUE c, VALUE arg) {
  fprintf(stderr, "Called mymethod with one arguments\n");
  return Qnil;
}

static VALUE myvariablemethod(int argc, VALUE *argv, VALUE c) {
  VALUE optional;

  fprintf(stderr, "Called myvariablemethod with variable arguments\n");

 rb_scan_args(argc, argv, "01", &optional);

 return Qnil;
}

static VALUE exception_impl(VALUE klass, VALUE input) {
  if (TYPE(input) != T_FIXNUM)
    rb_raise(rb_eTypeError, "invalid type for input");

  if (NUM2INT(input) == -1)
    rb_raise(e_ExampleError, "input was < 0");
  return Qnil;
}


static VALUE example_method(VALUE klass, VALUE input) {
  VALUE exception;

  if (TYPE(input) != T_FIXNUM)
    rb_raise(rb_eTypeError, "invalid type for input");

  if (NUM2INT(input) < 0) {
     exception=rb_exc_new2(e_ExampleError, "input was < 0");
     rb_iv_set(exception, "@additional_info",
     rb_str_new2("additional information"));
     rb_exc_raise(exception);
  }

  return Qnil;
}

static VALUE foo_exception_rescue(VALUE args) {
   fprintf(stderr, "foo_exception_rescue value is %s\n",
           StringValueCStr(args));
   return Qnil;
}

static VALUE other_exception_rescue(VALUE args) {
  fprintf(stderr, "other_exception_rescue value is %s\n",
          StringValueCStr(args));
  return Qnil;
}

static VALUE rescue(VALUE args, VALUE exception_object) {
  if (strcmp(rb_obj_classname(exception_object),
             "FooException") == 0)
    return foo_exception_rescue(args);
  else
    return other_exception_rescue(args);
}

static VALUE cb(VALUE args) {
  return rb_rescue(cb, args, rescue, rb_str_new2("data"));
}

static VALUE ensure(VALUE args) {
  fprintf(stderr, "Ensure args %s\n", StringValueCStr(args));
  return Qnil;
}

// VALUE res;

void Init_example() {
  m_example = rb_define_module("Example");
  rb_define_module_function(m_example, "method", example_method, 0);
  rb_define_module_function(m_example, "method", example_method, 1);
  rb_define_module_function(m_example, "exception_example", exception_impl, 1);

  c_example = rb_define_class_under(m_example, "Class", rb_cObject);
  rb_define_attr(c_example, "my_readonly_attr", 1, 0);
  rb_define_attr(c_example, "my_readwrite_attr", 1, 1);
  rb_define_const(c_example, "MYCONST", INT2NUM(5));
  rb_define_method(c_example, "mymethod", mymethod, 1);
  rb_define_method(c_example, "myvariablemethod", myvariablemethod, -1);

  e_ExampleError = rb_define_class_under(m_example, "Error", rb_eStandardError);
  rb_define_attr(e_ExampleError, "additional_info", 1, 0);

  // res = rb_ensure(cb, INT2NUM(0), ensure, rb_str_new2("data"));
  // example_library_initialize();

}