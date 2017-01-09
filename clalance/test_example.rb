#!/usr/bin/env ruby

require File.join(__FILE__, '../ext/example')

# Example.method 'hello'
# test_example.rb:5:in `method': invalid type for input (TypeError)

# if the method were to be called like this, an exception would be
# raised since no block is given
# retval = Example.method
# test_example.rb:10:in `method': Expected a block (StandardError)

# if the method were to be called like this, an exception would be
# raised since the return value from the block is not a number
# retval = Example.method do |_input|
#   'hello'
# end
# test_example.rb:15:in `method': uncaught throw :catchpoint (UncaughtThrowError)

# this works properly, since the return value is a number
# retval = Example.method do |input|
#   puts "Input is #{input}"
#   6
# end

# retval

# Example.exception_example 'hello'
# test_example.rb:28:in `exception_example': invalid type for input (TypeError)
p Example::Class.new.object_id.to_s(16)
p ec = Example::Class.new
p ec.object_id.to_s(16)
p ec.my_readonly_attr
p ec.my_readwrite_attr = 'hello'
p Example::Class::MYCONST
ec.mymethod 'hello'
ec.myvariablemethod
ec.myvariablemethod 'hello'

Example.method 1
Example.method -1
