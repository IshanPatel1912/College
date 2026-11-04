gross_salary = float(input("Enter Gross Salary: "))

allowance = 0.10 * gross_salary
deduction = 0.03 * gross_salary

net_salary = gross_salary + allowance - deduction

print(f"Allowances: {allowance}")
print(f"Deductions: {deduction}")
print(f"Net Salary: {net_salary}")