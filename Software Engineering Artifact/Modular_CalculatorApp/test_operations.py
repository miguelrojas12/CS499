import unittest
from operations import add, subtract, multiply, divide, exponent, modulo

class TestOperations(unittest.TestCase):
    def test_add(self): self.assertEqual(add(3, 5), 8)
    def test_divide_by_zero(self): self.assertEqual(divide(5, 0), "Error: Division by zero")
    def test_exponent(self): self.assertEqual(exponent(2, 3), 8)
    def test_modulo_by_zero(self): self.assertEqual(modulo(4, 0), "Error: Modulo by zero")

if __name__ == '__main__':
    unittest.main()