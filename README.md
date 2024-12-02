# Grayscale Image Processing with x86-64 Assembly

This project implements grayscale image format conversion between uint8 and double precision floating point representations using C and x86-64 assembly with SIMD instructions.

### Click the image below to watch the video.
[![WATCH OUR WALKTHROUGH HERE](https://img.youtube.com/vi/5TLfXpp9gCY/maxresdefault.jpg)](https://youtu.be/5TLfXpp9gCY)

# Performance Analysis
![image](https://github.com/user-attachments/assets/d261abff-1735-473a-9852-d9af56127bb7)

The comparison between the C and Assembly implementation of the program shows a very significant advantage for the Assembly-based implementation accross every image dimension. The Assembly implementation outperorms its C counterpart with an average speedup factor of 12x, reaching a peak peformance of 39x at 640x640 pixels. It could also be noticed that the runtime of the C code grows a lot faster than the assembly code which maintains its sub-ms execution time, even for large images (0.533ms for 880x880x) whereas the C implementation reaches 3.3ms for the largest image.

# Correctness Verification
![{1337154F-FD59-4353-96D9-91D754BF889E}](https://github.com/user-attachments/assets/99d38cd2-b9b5-43da-a625-9f4d40f5eca3)

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
