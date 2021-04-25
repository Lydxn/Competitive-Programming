def pr(x): print x
code = foo.__code__
type(pr)(type(code)(code.co_argcount, code.co_nlocals, code.co_stacksize, code.co_flags, code.co_code, tuple([pr.__code__ if type(x) == type(code) else x for x in code.co_consts]), code.co_names, code.co_varnames, code.co_filename, code.co_name, code.co_firstlineno, code.co_lnotab, code.co_freevars, code.co_cellvars), globals())()
