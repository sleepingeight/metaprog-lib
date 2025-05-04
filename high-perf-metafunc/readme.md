# Optimising build time of a metafunction

The goal was to optimise a metafunction `remove_if`, which takes a type list (a list of types), and removes the types which satisfies the condition. The optimisations were made keeping the following table in mind.

### cost of operations
1. looking up a memoized type
2. adding a paramter to alias call
3. adding a paramter to type
4. calling an alias
5. INSTANTIATING A TYPE
6. INSTANTIATING A FUNCTION TEMPLATE
7. SFINAE

5, 6, 7 are the expensive, whereas the remaining ops are cheap.


## Benchmark setup
1. We would like to compare only the overhead caused due to the metafunction for which, we'll create a baseline measurement. This will be subtracted from the different versions providing a nearly accurate measurement.
2. Here `n` is the number of types in a type list.

## Results

1. `n = 16`
```
$ ./benchmark.pl 1 input16_different
========= gcc x 1 ==========
baseline: 0.750s
eager - baseline: 7.620s
lazy - baseline: -0.190s
composed - baseline: -0.230s
composed_fasttrack - baseline: -0.280s
composed_defaults - baseline: -0.210s
composed_selection - baseline: -0.310s
```

2. `n = 18`
```
$ ./benchmark.pl 1 input18_different
========= gcc x 1 ==========
baseline: 0.570s
eager - baseline: 28.860s
lazy - baseline: -0.180s
composed - baseline: -0.140s
composed_fasttrack - baseline: -0.130s
composed_defaults - baseline: -0.150s
composed_selection - baseline: -0.120s
```

The above benchmarks show that the optimised versions are faster than the baseline version.

3. `n = 20`

For the eager version -- PC crash, mostly due to full RAM usage by the compiler (stack space exhaustion). 

**`reached limit for eager version`**

4. `n = 64`

```
$ ./benchmark.pl 1 input64_different
========= gcc x 1 ==========
baseline: 0.780s
lazy - baseline: -0.100s
composed - baseline: -0.130s
composed_fasttrack - baseline: -0.110s
composed_defaults - baseline: -0.130s
composed_selection - baseline: -0.150s
```

5. `n = 1024`

```
$ ./benchmark.pl 1 input1024_different
========= gcc x 1 ==========
baseline: 1.950s
lazy - baseline: 1.270s
composed - baseline: 1.340s
composed_fasttrack - baseline: 0.060s
composed_defaults - baseline: 0.000s
composed_selection - baseline: 0.070s
```
`composed` version performs similar to `lazy`.

6. `n = 2048`
```
$ ./benchmark.pl 1 input2048_different
========= gcc x 1 ==========
baseline: 1.930s
lazy - baseline: 4.220s
composed - baseline: 5.300s
composed_fasttrack - baseline: 0.220s
composed_defaults - baseline: 0.160s
composed_selection - baseline: 0.210s
```

7. `n = 4096`
```
$ ./benchmark.pl 1 input4096_different
========= gcc x 1 ==========
baseline: 1.940s
lazy - baseline: 11.310s
composed - baseline: 22.080s
composed_fasttrack - baseline: 0.730s
composed_defaults - baseline: 0.440s
composed_selection - baseline: 0.440s
```

8. `n = 8192`

For the lazy and composed version -- PC crash, mostly due to full RAM usage by the compiler (stack space exhaustion). 

**`reached limit for lazy and composed version`**

9. `n = 50000`

only the optimised versions can run in this case
```
$ ./benchmark.pl 1 input50000_different
========= gcc x 1 ==========
baseline: 0.790s
composed_fasttrack - baseline: 58.360s
composed_defaults - baseline: 30.410s
composed_selection - baseline: 30.260s
```

We were able to run the `remove_if` metafunction on a type list having 500000 parameters in approximately 30s, whereas the standard ways of instantiating templates -- `eager` and `lazy` were crashing my PC for inputs greater than ~10 and ~4500 respectively. This is due to the exponential nature of `eager` method and quadratic nature of `lazy` instantiation.


The best performing of all is the composed_selection version, which can handle both small input and large inputs more efficiently.

The above statement is understood perfectly after knowing how each algorithm is implemented.

```
$ ./benchmark.pl 1 input50000_different
========= gcc x 1 ==========
baseline: 1.880s
composed_fasttrack - baseline: 74.970s
composed_defaults - baseline: 31.830s
composed_selection - baseline: 30.260s
composed_selection1024 - baseline: 7.440s
```

the final version can compile 50000 parameters in ~7.5s which is than the `eager` (the first version) compiling 16 parameters.

for n = 4096, we can observe a 90x improvement from `lazy` to `composed_selection1024`.

for n = 18, we can observe a 300x improvement from `eager` to `lazy`.

extrapolating, we can assume an approx 2700x improvement from the original original version.

## Algorithms implemented (explaination)



## To-do
0. complete readme
1. there is an extra type_list which is being generated after transform, which can be removed.