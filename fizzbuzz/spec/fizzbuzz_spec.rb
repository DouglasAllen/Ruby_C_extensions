require "./lib/fizzbuzz"

describe "fizzbuzz" do
  it "returns 1 for 1" do
    expect(fizz(1)).to eq(1)
  end
  it "returns 2 for 2" do
    expect(fizz(2)).to eq(2)
  end
  it "returns fizz for 3" do
    expect(fizz(3)).to eq("fizz")
  end
  it "returns buzz for 5" do
    expect(fizz(5)).to eq("buzz")
  end
  it "returns fizz for 6" do
    expect(fizz(6)).to eq("fizz")
  end
  it "returns buzz for 10" do
    expect(fizz(10)).to eq("buzz")
  end
  it "returns fizzbuzz for 15" do
    expect(fizz(15)).to eq("fizzbuzz")
  end
  it "returns fizzbuzz for 30" do
    expect(fizz(30)).to eq("fizzbuzz")
  end
  (1..100).each do |i|
    puts fizz(i)
  end
end