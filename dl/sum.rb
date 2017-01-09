#!/usr/bin/env ruby
# be sure libsum.so is in the same directory
require File.join(__FILE__, '../libsum')

require 'fiddle'

a = [2.0, 3.0, 4.0]
p a
a_packed = a.pack('d*')
p a_packed
p a.inject() {|acc, var| acc + var}
lsum = LibSum.new
sum = lsum.sum(a)
p sum
# p LibSum.split(sum)
