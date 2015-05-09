def some_method(x,y,z,h)
  p x,y,z
	p h
end

some_method(10,20,30,:x=>10, y: 30)

def some_method(h)
	p h
end

some_method(:x=>10, y: 30)

def some_method(options = {x: 10, y: 20, z: 30})
	p options
end

some_method(x: 1, y: 2, z: 3)
some_method(x: 1, y: 2)

def some_method(options = {})
	defaults = {x: 10, y: 20, z: 30}
	options = defaults.merge(options)
	p options
end

some_method(x: 1, y: 2, z: 3)
some_method(x: 1, y: 2)

def some_method(x: 10, y: 20, z: 30)
	p x,y,z
end

some_method(x: 1, y: 2, z: 3)
some_method(x: 1, y: 2)

def some_method(a,x: 10, y: 20, z: 30)
	p x,y,z
	p a
end

some_method(x: 1, y: 2, z: 3)
some_method(50,x: 1, y: 2)

def some_method(x,y,z)
  p x,y,z
end

# some_method(x: 1, y: 2)

def some_method(x: nil,y: nil,z: nil)
  p x,y,z
end

some_method(x: 1, y: 2)

def my_method(*args)
	p args
end

my_method(10,20,30)

def my_method(x: 10,y: 20,**args)
	p x,y,args
end

my_method(c: 'test', x: 1,y: 2,z: 100,a: 42)

def my_method(x: 10,y: 20)
	p x,y
end

#my_method(c: 'test', x: 1,y: 2,z: 100,a: 42)

def my_method(**args)
	p args
end

my_method(c: 'test', x: 1,y: 2,z: 100,a: 42)