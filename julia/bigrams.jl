using DelimitedFiles
using Chain

identdefault(x::Number) = x
identdefault(x) = 0

table = readdlm("bigrams.txt")
freq = @chain table[:, 2:end] identdefault.() exp.()
letters = table[:, 1]

fingers = [indexin(f, letters) for f in [["a", "q"], ["w", "s"], ["d", "r", "e"], ["f", "t", "g", "v", "c", "b"],
  ["h", "n", "m", "u"], ["k", "i", "y"], ["l", "o"]]]

overlap(f, g) = sum(freq[f, g]) + sum(freq[g, f])

costs(ls...) = [overlap(indexin(ls, letters), f) for f in fingers]
enemies(l) = @chain indexin([l], letters)[1] freq[_, :] + freq[:, _] [letters _][sortperm(_), :]