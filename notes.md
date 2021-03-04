# the notes about mistakes made in practices

## Date: 2021/3/1
1. 大数计算的时候vector<int>是从小到大存的数字，和字符串正好相反。所以字符串转vector<int>的时候要注意i递减循环。大数减法的时候也要注意i递减循环。

## Date: 2021/3/2
1.大数加法的时候剩余t得处理方式是`if(t) C.push_back(t);`，大数乘法得时候剩余t的处理方式是`while(t) C.push_back(t);`  
2.大数乘法的时候，得到结果vector<int> C之后如果C中包含多个0，那么要把0清除。  
3.大数除法得时候，不用用10除t，而是除数  
4.双指针的题目要注意两个指针从头开始扫描还是尾部  

## Date: 2022/3/3
1.循环队列: hh == tt为空, (tt + 1) % N == hh为满, hh为头, tt - 1为尾  
2.多次使用队列要记得清零  