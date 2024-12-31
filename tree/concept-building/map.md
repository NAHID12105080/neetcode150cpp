# map in c++

- creating a map

```c++
map<int,int>m;
```

- inser in a map
- `m[key]=val`

-access val using key

```c++
cout<<m[key]
```

# 1 if key present , 0 otherwise

```c++
m.count(key);
```

## loop on a map

```c++
for(auto it : m){
    cout<<m.first<<m.second;
}
```
