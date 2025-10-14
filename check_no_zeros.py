import numpy as np

arr1 = np.array([1, 2, 3, 4, 5])

arr2 = np.array([1, 0, 3, 4, 5])

is_none_zero_1 = np.all(arr1 != 0)
is_none_zero_2 = np.all(arr2 != 0)

print("Array 1:", arr1)
print("Are none of the elements zero?", is_none_zero_1)
print("\nArray 2:", arr2)
print("Are none of the elements zero?", is_none_zero_2)
