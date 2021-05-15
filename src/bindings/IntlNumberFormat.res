type t

@new @scope("Intl")
external make: (~lang: @string [@as("en-US") #en]) => t = "NumberFormat"

@send external format: (t, float) => string = "format"
