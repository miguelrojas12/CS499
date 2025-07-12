# This module evaluates and interprets complex math expressions, respects the order of operations
# and supports parentheses.

import math

SAFE_GLOBALS = {
    "__builtins__": None,
    "pi": math.pi,
    "e": math.e,
    "tau": math.tau,
    "sin": math.sin,
    "cos": math.cos,
    "tan": math.tan,
    "log": math.log,
    "sqrt": math.sqrt,
    "abs": abs,
    "pow": pow
}

def evaluate_expression(expr):
    try:
        return eval(expr, SAFE_GLOBALS)
    except ZeroDivisionError:
        return "Error: Division by zero"
    except Exception:
        return "Error: Invalid expression"