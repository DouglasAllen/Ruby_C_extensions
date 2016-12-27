# be sure libsum.so is in the same directory
require 'dl'
require 'dl/import'

module LibSum
  extend DL::Importer
  dlload './libsum.so'
  extern 'double sum(double*, int)'
  extern 'double split(double)'
end

a = [2.0, 3.0, 4.0]
p a
a_packed = a.pack("d*")
p a_packed
sum = LibSum.sum(a_packed, a.count)
=begin
double sum(double *arry, int len)
  {
          double ret = 0;
          int i;
          for(i = 0; i < len; i++){
                  ret = ret + arry[i];
          }
          return ret;
  }
=end
p sum
p LibSum.split(sum)
=begin
 double split(double num)
  {
          double ret = 0;
          ret = num / 2;
          return ret;
  }
=end
