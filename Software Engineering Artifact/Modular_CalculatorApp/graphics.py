import matplotlib.pyplot as plt #I imported this library so the calculator would support graphic plotting
import numpy as np
from evaluator import evaluate_expression

# This module is for graphic plotting whatever the user wants to graph when entering valid operations

def plot_expression(expr, x_range=(-10, 10), resolution=400):
    x_values = np.linspace(x_range[0], x_range[1], resolution)
    y_values = []

    for x in x_values:
        
        
        substituted_expr = expr.replace("x", f"({x})")
        result = evaluate_expression(substituted_expr)
        try:
            y_values.append(float(result))
        except:
            y_values.append(np.nan)  # In case of math errors like sqrt(-1)

    plt.figure(figsize=(8, 5))
    plt.plot(x_values, y_values, label=expr, color="royalblue", linewidth=2)
    plt.title(f"Graph of: {expr}", fontsize=14)
    plt.xlabel("x")
    plt.ylabel("y")
    plt.axhline(0, color="gray", linewidth=0.5)
    plt.axvline(0, color="gray", linewidth=0.5)
    plt.grid(True, linestyle="--", alpha=0.5)
    plt.legend()
    plt.tight_layout()
    plt.show()