
require 'test/unit'
require File.join(__FILE__, '../../lib/stree/stree')
require 'date'
#
class TestStree < Test::Unit::TestCase

  def setup
    @t = Stree.new
    @t_ajd = 2_457_717.0 - 2_451_545
  end

  def test_hello_world
    assert_equal 'hello world', @t.hello_world
  end

  def test_initialize
    assert_equal(Object, Stree.superclass)
    assert_equal(Stree, @t.class)

    @t.add(1)
    @t.add(2)
    assert_equal([1, 2], @t.instance_eval('@arr'))
  end

  def test_timespec_now
    # assert_equal(Time.now.to_f.round(6), @t.timespec_now.to_f)
  end

  def test_mean_anomally
    assert_equal(320.65402816000005, @t.mean_anomally(@t_ajd))
  end

  def test_equation_of_center
    assert_equal(1.6635302999387296,
                 @t.equation_of_center(0))
  end

  def test_true_anomally
    assert_equal(320.65402816000005, @t.true_anomally(@t_ajd))
  end
end
