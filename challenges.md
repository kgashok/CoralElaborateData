
# Factorial Module Challenges

## Challenge 1: Handling Large Numbers (factorial(100))

**Problem**: 
When calculating factorial(100), you'll encounter an overflow issue since the result exceeds the maximum value that can be stored in a C long type.

```python
import factorial_module
print(factorial_module.factorial(100))  # Will produce incorrect result
```

**Solution**:
To fix this, modify the C module to use Python's arbitrary-precision integers (PyLongObject) internally instead of C's long type. Here's how:

1. Modify fact() to use PyLongObject instead of long
2. Update the function signatures and arithmetic operations
3. Use Python's math.factorial() for very large numbers instead

For now, stick to numbers under 20 to get accurate results with the current implementation.

## Challenge 2: Remove Debug Print Statement

**Problem**: 
The factorial_module.c contains a debug print statement that outputs calculation progress:
```c
printf("Calculating for %d\n", n);
```

**Solution**:
1. Comment out or remove the print statement in factorial_module.c
2. Rebuild the module:
```bash
python3 setup.py build
python3 setup.py install
```

After rebuilding, the factorial calculations will run silently without the debug output.

**Note**: If you need to restore the debug output later, simply uncomment the printf line and rebuild the module.
