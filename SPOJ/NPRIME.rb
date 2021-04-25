# current best score: 50

require'prime'
$<.map{|l|p Prime.take(l.to_i)[-1]}
