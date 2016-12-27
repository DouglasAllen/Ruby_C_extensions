
require_relative 'a_ruby_c_extension'
require 'minitest/autorun'
#
class TestCExt < MiniTest::Test
  def test_c_ext
    the_extension = ARubyCExtension.new
    assert_equal Object, ARubyCExtension.superclass
    assert_equal ARubyCExtension, the_extension.class
  end
end
