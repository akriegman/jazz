include("huffman.jl")

using DelimitedFiles
using Chain

freq = @chain readdlm("letterfreq.txt") eachrow Dict

tree = @chain freq huffmantree(8)
printencoding(tree, "")
for c in tree.children
  println(c.freq)
end