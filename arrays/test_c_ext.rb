
require_relative 'arrays'
require 'minitest/autorun'
require 'benchmark'
#
class TestCExt < MiniTest::Test
  def test_time
    n = 1_000_000
    Benchmark.bm(7) do |x|
      x.report('arrays_c:') { n.times { ; t1 = Arrays.new.ary; } }
      x.report('array:') { n.times { ; t2 = []; } }
    end
  end

  def test_c_ext
    the_extension = Arrays.new
    assert_equal Object, Arrays.superclass
    assert_equal Arrays, the_extension.class
  end

  def test_ary
    array = Arrays.new
    assert_equal [], array.ary
    new_array = array.push('a string')
    assert_equal ['a string'], new_array
    assert_equal 1, array.size(new_array)
    p array.push(10)
    new_array.push
    p new_array
  end
end

