# This module handles basic operations

def add(a, b): return a + b
def subtract(a, b): return a - b
def multiply(a, b): return a * b
def divide(a, b): return a / b if b != 0 else "Error: Division by zero"
def exponent(a, b): return a ** b
def modulo(a, b): return a % b if b != 0 else "Error: Modulo by zero"

operations = {
    '+': add,
    '-': subtract,
    '*': multiply,
    '/': divide,
    '^': exponent,
    '%': modulo
}