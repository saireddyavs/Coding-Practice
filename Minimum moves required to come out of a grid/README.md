Given a grid mat[][] of size M * N, consisting of only 0s, 1s, and 2s, where 0 represents empty place, 1 represents a person and 2 represents the fire, the task is to count the minimum number of moves required such that the person comes out from the grid safely. In each step, the fire will burn its side-adjacent cells and the person will move from the current cell to one of its side-adjacent cells. If it is not possible to come out from the grid, then print -1.

Note: A person will come out from the grid if the person reaches one of the border sides of the grid.



```{ { 0, 0, 0, 0 }, 
     { 2, 0, 0, 0 }, 
     { 2, 1, 0, 0 },
      { 2, 2, 0, 0 } } 

      ans=2
```

```
{ { 0, 2, 0, 0 }, 
{ 2, 1, 0, 2 },
 { 2, 0, 0, 0 },
  { 2, 0, 2, 0 }} 
ans=-1
 ```
      
