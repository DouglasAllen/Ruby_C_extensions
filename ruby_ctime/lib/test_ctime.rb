require_relative 'ctime'

puts "Time now is #{get_time}"

t1 = Time.new(1970,01,01,0,0,0, "+00:00")
puts "#{e_sec} seconds have elapsed since January 01 1970"
puts "Time now is #{t1 + e_sec}"
puts "#{system 'date'}"

require 'time'
get_time = ->(t) { [t.iso8601(6)] }
get_usec = ->(t) { [t.usec] }
report = 'a detailed string format for time: %s'
puts report % get_time[Time.now.utc]
puts report % get_usec[Time.now.utc]


#~ loop do	
	#~ sleep 1.0
	#~ p get_time
#~ end