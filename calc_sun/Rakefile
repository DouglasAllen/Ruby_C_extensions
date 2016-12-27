# -*- ruby -*-

require 'rubygems'
require 'hoe'
require 'rake/testtask'
require 'rake/extensiontask'
# Hoe.plugin :compiler
# Hoe.plugin :cucumberfeatures
# Hoe.plugin :gem_prelude_sucks
# Hoe.plugin :inline
Hoe.plugin :manifest
# Hoe.plugin :minitest
# Hoe.plugin :newgem
# Hoe.plugin :racc
# Hoe.plugin :rcov
# Hoe.plugin :rdoc
# Hoe.plugin :website

Hoe.spec 'calc_sun' do
  developer('kb9agt', 'kb9agt@gmail.com')
  self.readme_file   = 'README.rdoc'
  self.history_file  = 'HISTORY.rdoc'
  self.extra_rdoc_files = FileList['*.rdoc']
  extra_dev_deps << ['rake-compiler', '>= 0']
  self.spec_extras = { extensions: ['ext/calc_sun/extconf.rb'] }

  Rake::ExtensionTask.new('calc_sun', spec) do |ext|
    ext.lib_dir = File.join('lib', 'calc_sun')
  end
end

Rake::Task[:test].prerequisites << :compile
# vim: syntax=ruby
