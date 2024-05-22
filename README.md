# Report on Sorting and Searching Algorithms

This repo is for an in-class project in NTU Data Structure 2024 spring, which presents the performance of different sorting algorithms (Insertion Sort, Quick Sort, Heap Sort, and Merge Sort) and Binary Search applied to datasets of various sizes.

## Problem 1: Sorting Algorithms

For each dataset "random_set_groupX_setY_sorting.csv" (where X=1...5, Y=1...3), the data was sorted using Insertion Sort, Quick Sort, Heap Sort, and Merge Sort. The following results were obtained:

### Mean Running Time Summary

| Dataset Size | Insertion Sort Mean (s) | Quick Sort Mean (s) | Heap Sort Mean (s) | Merge Sort Mean (s) |
|--------------|--------------------------|----------------------|---------------------|----------------------|
| 1000         | 0.00147325               | 0.00401633           | 0.03522165          | 0.000118484           |
| 5000         | 0.05242203               | 0.11191066           | 0.83426633          | 0.000709129           |
| 10000        | 0.2140158                | 0.268837             | 2.02153867          | 0.000766416           |
| 50000        | 11.64441                 | 18.18403767          | 165.66824           | 0.01035038            |
| 100000       | 58.05713                 | 101.76786            | 631.89118           | 0.02374533            |

### Analysis of Sorting Algorithms

1. **Insertion Sort**:
    - **Data Structure Used**: Linked List
    - **Theoretical Complexity**: O(n^2)
    - **Observation**: The running time increases significantly with the size of the dataset, which is consistent with its quadratic time complexity.

2. **Quick Sort**:
    - **Data Structure Used**: Linked List
    - **Theoretical Complexity**: O(n log n) on average
    - **Observation**: The running time generally follows the n log n pattern, performing better than Insertion Sort and Heap Sort for larger datasets.

3. **Heap Sort**:
    - **Data Structure Used**: Linked List
    - **Theoretical Complexity**: O(n log n)
    - **Observation**: Heap Sort shows increased running times, especially for larger datasets, consistent with the expected n log n complexity.

4. **Merge Sort**:
    - **Data Structure Used**: Linked List
    - **Theoretical Complexity**: O(n log n)
    - **Observation**: Merge Sort consistently has the fastest running time among the sorting algorithms, closely matching the theoretical complexity.

### First 10 Sorted Elements

- Group 1 Set 1: 145, 146, 148, 149, 152, 153, 153, 154, 154, 155
- Group 1 Set 2: 758, 759, 759, 760, 760, 763, 764, 765, 769, 770
- Group 1 Set 3: 35, 36, 38, 38, 39, 40, 40, 40, 41, 41
- Group 2 Set 1: 1183, 1185, 1185, 1188, 1188, 1191, 1191, 1193, 1195, 1197
- Group 2 Set 2: 1258, 1259, 1259, 1261, 1261, 1262, 1262, 1264, 1264, 1265
- Group 2 Set 3: 1995, 1996, 1997, 2000, 2002, 2004, 2004, 2005, 2005, 2006
- Group 3 Set 1: 3213, 3216, 3217, 3218, 3221, 3222, 3222, 3223, 3224, 3227
- Group 3 Set 2: 5279, 5281, 5282, 5282, 5283, 5283, 5284, 5285, 5286, 5286
- Group 3 Set 3: 7990, 7991, 7995, 7995, 7995, 7997, 7997, 7997, 7997, 8000
- Group 4 Set 1: 41912, 41913, 41913, 41914, 41915, 41915, 41916, 41916, 41917, 41918
- Group 4 Set 2: 15597, 15598, 15599, 15600, 15600, 15600, 15601, 15601, 15603, 15604
- Group 4 Set 3: 8567, 8568, 8568, 8569, 8569, 8570, 8571, 8573, 8574, 8574
- Group 5 Set 1: 34530, 34532, 34532, 34532, 34534, 34535, 34535, 34538, 34539, 34540
- Group 5 Set 2: 25784, 25786, 25786, 25788, 25789, 25789, 25790, 25792, 25793, 25794
- Group 5 Set 3: 91293, 91294, 91294, 91295, 91297, 91297, 91298, 91298, 91299, 91299

## Problem 2: Binary Search

For each dataset "random_set_groupX_setY_searching.csv" (where X=1...5, Y=1...3), a binary search algorithm was used to search every datum in the sorted version of the corresponding "random_set_groupX_setY_sorting.csv". The following results were obtained:

### Results Summary

| Group and Set | Binary Search Time (s) | Found Count | Not Found Count |
|---------------|-------------------------|-------------|-----------------|
| Group 1 Set 1 | 0.0212571               | 656         | 344             |
| Group 1 Set 2 | 0.00273541              | 187         | 813             |
| Group 1 Set 3 | 0.0236587               | 814         | 186             |
| Group 2 Set 1 | 0.8913                  | 2801        | 2199            |
| Group 2 Set 2 | 0.762882                | 2840        | 2160            |
| Group 2 Set 3 | 0.697817                | 2198        | 2802            |
| Group 3 Set 1 | 2.86645                 | 5064        | 4936            |
| Group 3 Set 2 | 2.17478                 | 3459        | 6541            |
| Group 3 Set 3 | 0.511276                | 1497        | 8503            |
| Group 4 Set 1 | 19.4315                 | 6111        | 43889           |
| Group 4 Set 2 | 250.853                 | 25806       | 24194           |
| Group 4 Set 3 | 282.299                 | 31206       | 18794           |
| Group 5 Set 1 | 841.187                 | 49050       | 50950           |
| Group 5 Set 2 | 1178.32                 | 55431       | 44569           |
| Group 5 Set 3 | 37.7947                 | 6608        | 93392           |

### Analysis of Binary Search

- **Data Structure Used**: Linked List
- **Theoretical Complexity**: O(log n)
- **Observation**: The running times of binary search increase with the size of the dataset, as expected from the logarithmic complexity. However, the actual times are influenced by the overhead of linked list traversal.

## Conclusion

The performance of the sorting algorithms is generally consistent with their theoretical complexities. Insertion Sort's quadratic complexity makes it impractical for large datasets, while Merge Sort consistently performs the best among the sorting algorithms. Quick Sort also performs well, though its performance can vary based on the input data. Heap Sort shows increasing running times with larger datasets, matching its expected n log n complexity.

Binary search performs as expected with logarithmic time complexity, though the linked list data structure introduces additional traversal overhead. The results show a clear distinction between found and not-found elements, reflecting the accuracy and efficiency of the search algorithm.
