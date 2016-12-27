require 'rubygems'
gem 'minitest'
require 'minitest/autorun'
require 'test/unit'
lib = File.expand_path('../../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'calc_sun'
require 'date'
#
# class TestCalcSun < MiniTest::Test
class TestCalcSun100 < Test::Unit::TestCase
  def setup
    @t = CalcSun.new
    @t_ajd = 0.0
    @t_lat = 0.0
    @t_lon = 0.0
  end

  def test_mean_anomaly
    assert_equal(
      6.240059966692,
      @t.mean_anomaly(@t_ajd).round(12)
    )
  end

  def test_eccentricity
    assert_equal(
      0.016709,
      @t.eccentricity(@t_ajd)
    )
  end

  def test_equation_of_center
    assert_equal(
      -0.001471380867,
      @t.equation_of_center(@t_ajd).round(12)
    )
  end

  def test_true_anomaly
    assert_equal(
      6.238588585825,
      @t.true_anomaly(@t_ajd).round(12)
    )
  end

  def test_mean_longitude
    assert_equal(
      4.895063110817,
      @t.mean_longitude(@t_ajd).round(12)
    )
  end

  def test_eccentric_anomaly
    assert_equal(
      4.878582250862,
      @t.eccentric_anomaly(@t_ajd).round(12)
    )
  end

  def test_obliquity_of_ecliptic
    assert_equal(
      0.409092802283,
      @t.obliquity_of_ecliptic(@t_ajd).round(12)
    )
  end

  def test_xv
    assert_equal(
      0.148720277673,
      @t.xv(@t_ajd).round(12)
    )
  end

  def test_yv
    assert_equal(
      -0.986083974099,
      @t.yv(@t_ajd).round(12)
    )
  end

  def test_longitude_of_perihelion
    assert_equal(
      4.93824156691,
      @t.longitude_of_perihelion(@t_ajd).round(12)
    )
  end

  def test_true_longitude
    assert_equal(
      4.893644845555,
      @t.true_longitude(@t_ajd).round(12)
    )
  end

  def test_rv
    assert_equal(
      0.997235842199,
      @t.rv(@t_ajd).round(12)
    )
  end
end

#
class TestCalcSun200 < Test::Unit::TestCase
  def setup
    @t = CalcSun.new
    @t_ajd = 0.0
    @t_lat = 0.0
    @t_lon = 0.0
  end

  def test_ecliptic_x
    assert_equal(
      0.17976672602,
      @t.ecliptic_x(@t_ajd).round(12)
    )
  end

  def test_ecliptic_y
    assert_equal(
      -0.980899204395,
      @t.ecliptic_y(@t_ajd).round(12)
    )
  end

  def test_right_ascension
    assert_equal(
      18.753078192426,
      @t.right_ascension(@t_ajd).round(12)
    )
  end

  def test_declination
    assert_equal(
      -0.372949956542,
      @t.declination(@t_ajd).round(12)
    )
  end

  def test_sidereal_time
    assert_equal(
      6.697967333333,
      @t.sidereal_time(@t_ajd).round(12)
    )
  end

  def test_local_sidereal_time
    assert_equal(
      18.697967333333,
      @t.local_sidereal_time(@t_ajd, @t_lon).round(12)
    )
  end

  def test_dlt
    assert_equal(
      12.120732161881,
      @t.dlt(@t_ajd, @t_lat).round(12)
    )
  end

  def test_diurnal_arc
    assert_equal(
      6.06036608094,
      @t.diurnal_arc(@t_ajd, @t_lat).round(12)
    )
  end

  def test_t_south
    assert_equal(
      12.055110859092,
      @t.t_south(@t_ajd, @t_lon).round(12)
    )
  end

  def test_t_rise
    assert_equal(
      5.994744778152,
      @t.t_rise(@t_ajd, @t_lon, @t_lat).round(12)
    )
  end

  def test_t_mid_day
    assert_equal(
      12.055110859092,
      @t.t_mid_day(@t_ajd, @t_lon, @t_lat).round(12)
    )
  end

  def test_t_set
    assert_equal(
      18.115476940033,
      @t.t_set(@t_ajd, @t_lon, @t_lat).round(12)
    )
  end

  def test_rise_time
    rise = @t.t_rise(@t_ajd, @t_lon, @t_lat).round(12)
    assert_equal(
      "Sun rises \t\t\t : 5:59 UTC",
      "Sun rises \t\t\t : #{rise.floor}:#{(rise % 1 * 60.0).floor} UTC"
    )
  end

  def test_midday_time
    midday = @t.t_mid_day(@t_ajd, @t_lon, @t_lat).round(12)
    assert_equal(
      "Sun mid day \t\t\t : 12:3 UTC",
      "Sun mid day \t\t\t : #{midday.floor}:#{((midday % 1.0) * 60).floor} UTC"
    )
  end

  def test_set_time
    set = @t.t_set(@t_ajd, @t_lon, @t_lat).round(12)
    assert_equal(
      "Sun sets \t\t\t : 18:6 UTC",
      "Sun sets \t\t\t : #{set.floor}:#{(set % 1 * 60.0).floor} UTC"
    )
  end
end
