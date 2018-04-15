def py_fact(n):
	"""Computes n!"""
	if n <= 1:
		return 1
	return n * py_fact(n - 1)

def py_typed_fact(long n):
	"""Computes n!"""
	if n <= 1:
		return 1
	return n * py_typed_fact(n - 1)

cdef long cdef_fact(long n):
	"""Computes n!"""
	if n <= 1:
		return 1
	return n * cdef_fact(n - 1)

def wrap_cdef_fact(n):
	return cdef_fact(n)
