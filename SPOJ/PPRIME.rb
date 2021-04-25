# current best score: 69

require'prime'
t=Prime.take 2e5
t.first(1e4).map{|x|p"#{t[x-1]} "}
