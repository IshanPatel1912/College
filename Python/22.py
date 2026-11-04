gross_sales = float(input("Enter Gross Sales amount: "))

discount = 0.10 * gross_sales
net_sales = gross_sales - discount

print(f"Discount amount: {discount}")
print(f"Net Sales: {net_sales}")