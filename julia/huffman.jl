 
abstract type HuffmanTree end
 
struct HuffmanLeaf{N<:Number, C} <: HuffmanTree
    ch::C
    freq::N
end
 
struct HuffmanNode{M, N<:Number} <: HuffmanTree
    freq::N
    children::NTuple{M, HuffmanTree}
end
 
function makefreqdict(s::String)
    d = Dict{Char, Int}()
    for c in s
        if !haskey(d, c)
            d[c] = 1
        else
            d[c] += 1
        end
    end
    d
end
 
function huffmantree(ftable::Dict, arity)
    trees::Vector{HuffmanTree} = [HuffmanLeaf(ch, fq) for (ch, fq) in ftable]
    padding = mod(1 - length(trees), arity - 1)
    append!(trees, (HuffmanLeaf(nothing, 0) for _ in 1:padding))
    
    while length(trees) >= arity
        sort!(trees, lt = (x, y) -> x.freq < y.freq)
        losers = trees[1:arity]
        deleteat!(trees, 1:arity)
        push!(trees, HuffmanNode(sum(t -> t.freq, losers), tuple(losers...)))
    end
    trees[1]
end
 
printencoding(lf::HuffmanLeaf, code) = println(lf.ch, "\t", lf.freq, "\t", code)
 
function printencoding(nd::HuffmanNode{M}, code) where {M}
  for m in 1:M
    code *= string(m - 1)
    printencoding(nd.children[m], code)
    code = code[1:end-1]
  end
end