50.times do 
  gets
  line = ""
  9.times do
    line = line + gets.chomp!
  end
  
  puts line.gsub(/0/,'.')
  
end
