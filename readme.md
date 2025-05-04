# Metaprogramming library

This repo contains the implementation of a type list, which implements all the functionalities at compile-time reducing the overhead during run-time.

**type list** : this is a list of types

## features implemented
1. **empty <typename LIST>**: checks whether a given type list is empty or not.
2. **front <typename LIST>**: provides the first type in the given type list
3. **pop_front <typename LIST>**: removes the first type from the given type list and returns the newly formed type list
4. **at <typename LIST, size_t index>**: gives the type present at a given index.
5. **back <typename LIST>**: extracts the type present at the end of the list 
6. **push_back <typename LIST, typename T>**: forms a new type list by inserting a given type into the list
7. **pop_back <typename LIST>**: forms a new type list by removing the last type in the list
8. **any <template<typename> class PREDICATE, typename LIST>**: checks whether a type from the type list satisfies the given predicate/property.


##
the sub-folder contains 

9. **remove_if**: removes all elements from the type list satisfying a given property.

The `remove_if` algorithm is optimised to handle upto 50000 sized type lists (as a learning excercise in metaprogramming performance).

##
i would like to thank @QBouts for his helpful tuts on yt.