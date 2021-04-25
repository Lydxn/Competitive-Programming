def cigar_party(cigars, is_weekend):
  return cigars >= 40 if is_weekend else cigars in range(40, 61)
