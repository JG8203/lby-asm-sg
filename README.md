# Grayscale Image Processing with x86-64 Assembly

This project implements grayscale image format conversion between uint8 and double precision floating point representations using C and x86-64 assembly with SIMD instructions.

## Overview

### Grayscale Image Representation

Grayscale images are represented as 2D arrays where each cell contains a pixel value:

- **8-bit Unsigned Integer Format (0-255)**
  - Black: 0
  - White: 255
  - Light Gray: ~64
  - Dark Gray: ~191

Example:
```
64,  89,  114, 84
140, 166, 191, 84
216, 242, 38,  84
```

- **Double Floating Point Format (0-1)**
  - Black: 0.0
  - White: 1.0
  - Light Gray: ~0.25
  - Dark Gray: ~0.75

Example:
```
0.25, 0.35, 0.45, 0.33
0.55, 0.65, 0.75, 0.33
0.85, 0.95, 0.15, 0.33
```

### Conversion Formula

The conversion from integer to floating point uses the following ratio:

```
f = i/255
```
where:
- f = output float pixel value
- i = input integer pixel value

## Implementation Requirements

### Core Function
Implement `imgCvtGrayIntToDouble()` in x86-64 assembly with:
- Functional scalar SIMD registers
- Functional scalar SIMD floating-point instructions

### Input Format
```
height width
pixel_values[height][width]
```

Example:
```
3 4
64,  89,  114, 84
140, 166, 191, 84
216, 242, 38,  84
```

### Output Format
Converted floating point values formatted as:
```
0.25 0.35 0.45 0.33
0.55 0.65 0.75 0.33
0.85 0.95 0.15 0.33
```

## Development Guidelines

### Responsibilities

1. **C Program**
   - Input collection
   - Memory allocation
   - Output display
   - Function timing
   - Correctness verification

2. **Assembly Function**
   - Pixel value conversion
   - Data type transformation

### Performance Testing

- Test image sizes:
  - 10x10
  - 100x100
  - 1000x1000 (or maximum supported size)
- Minimum 30 runs per size for average timing
- Random pixel value generation allowed

## Deliverables

### GitHub Repository Contents

1. **Documentation**
   - Execution time analysis
   - Performance evaluation
   - Screenshots showing correctness verification
   - 5-10 minute video demonstrating:
     - Source code walkthrough
     - Compilation process
     - Program execution

2. **Source Code**
   - C implementation
   - x86-64 assembly implementation
   - Supporting files

## Grading Criteria

| Component | Points |
|-----------|--------|
| C main program implementation | 25 |
| Assembly output correctness | 45 |
| Performance analysis | 20 |
| Documentation video | 10 |

**Penalties**: -10 points per missing requirement

**Critical Note**: Zero grade if implementation lacks SIMD registers/instructions or if core function isn't in assembly.
