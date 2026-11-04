val1 = input("Enter first value: ")
val2 = input("Enter second value: ")

print(f"Before swapping: First = {val1}, Second = {val2}")

temp = val1
val1 = val2
val2 = temp


print(f"After swapping: First = {val1}, Second = {val2}")