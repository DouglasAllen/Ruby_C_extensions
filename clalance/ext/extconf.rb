#!/usr/bin/env ruby

require 'mkmf'

# easily use alternate compilers to build the extension.
# Since mkmf detects the compiler at Makefile creation time, this isn't very interesting until you consider static analysis tools,
# which tend to substitute the standard compiler with their own enhanced version.
# By having this line of code at the top, the Rakefile is prepared to let these static analysis tools do their thing
# (and help improve your code).
# RbConfig::MAKEFILE_CONFIG['CC'] = ENV['CC'] if ENV['CC']

# the extension name
extension_name = 'example'

# check to see if the library necessary to build this extension exists
# unless pkg_config('library_to_link_to')
#   raise "library_to_link_to not found"
# end

# uses the mkmf function have_func() to determine if the library installed on the build system has the function
# 'useful_function' defined in the header file 'library_to_link_to/lib.h'.
# If the function is found, then a macro called HAVE_ will be defined in extconf.h
# (which all of the C files in the project should #include).
# have_func('useful_function', 'library_to_link_to/lib.h')

# uses the mkmf function have_type() to determine if the library installed on the build system has the structure
# 'useful_type' defined in the header file 'library_to_link_to/lib.h'.
# If the structure is found, then a macro called HAVE_TYPE_ will be defined in extconf.h.
# have_type('useful_type', 'library_to_link_to/lib.h')

# creates the header file extconf.h, based on the results from all of the previous have_*() functions
# create_header

# creates the Makefile based on all of the previous information
create_makefile(extension_name)
