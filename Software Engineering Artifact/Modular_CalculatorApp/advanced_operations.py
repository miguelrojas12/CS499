# In this new enhancement module, I decided to add advanced expresions and operations such as
# sin, cos, tan, natural base logarithms, square root and factorial. It will resemble a

import math

def sin(a): return math.sin(a)
def cos(a): return math.cos(a)
def tan(a): return math.tan(a)
def log(a): return math.log(a)
def sqrt(a): return math.sqrt(a) if a >= 0 else "Error: Negative square root"
def factorial(a): return math.factorial(int(a)) if a >= 0 and a.is_integer() else "Error: Invalid factorial"

advanced_ops = {
    'sin': sin,
    'cos': cos,
    'tan': tan,
    'log': log,
    'sqrt': sqrt,
    '!': factorial
}