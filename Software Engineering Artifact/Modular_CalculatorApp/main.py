from evaluator import evaluate_expression
from graphics import plot_expression

def main():
    print(" Welcome to the Modular Calculator, developed by Miguel Rojas Saavedra!")
    print("Type an expression like: 3 + 4 * (2 - 1), pi * 2, or sin(pi / 2)")
    print("Type 'plot <expression>' to graph it (e.g., plot cos(x) + x**2)")
    print("Type 'exit' to quit.\n")

    while True:
        expression = input(">>> ").strip()

        if expression.lower() in ['exit', 'quit']:
            print(" Goodbye!")
            break

        if expression.startswith("plot "):
            expr_to_plot = expression[5:].strip()
            plot_expression(expr_to_plot)
            continue

        result = evaluate_expression(expression)
        print(f"Result: {result}")

if __name__ == "__main__":
    main()