# On top of the previous enhancements that I had in mind for this calculator, I decided to add support
# for decimal numbers, negative numbers, and common constants like Pi, e, and Tau.
import re
import math

CONSTANTS = {
    'pi': math.pi,
    'e': math.e,
    'tau': math.tau
}

def substitute_constants(expression):
    for name, value in CONSTANTS.items():
        expression = expression.replace(name, str(value))
    return expression

def parse_expression(expression):
    expression = substitute_constants(expression)
    pattern = r'(-?\d*\.?\d+)\s*([\+\-\*/\^%])\s*(-?\d*\.?\d+)'
    tokens = re.findall(pattern, expression)

    if not tokens:
        return None

    op1, operator, op2 = tokens[0]
    return float(op1), operator, float(op2)