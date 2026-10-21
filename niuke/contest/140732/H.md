# H. World Finals

## 题目描述

The ICPC World Finals are coming. Due to some reasons, the 46th and 47th World Finals will be held simultaneously. For the teams qualified in both competitions, they should choose one to take part in.  

As we know, lzr010506's team is double-qualified and should make a choice. To make a wiser choice, lzr010506 looked up the qualified lists for two competitions and trained a magic model to predict the results for all participants among the two competitions. Moreover, a result contains the number of solved problems and the time penalty. The more solved problems, the better the result is, and if two teams solved the same number of problems, the result with the lower time penalty is better.  

Now, lzr010506 wants to know the best possible ranking if the actual results are all the same as predicted and that the competition choices of the double-qualified teams can be arbitrarily arranged by him.  


## 输入描述

The first line contains one integer $n\,(1 \le n \le 10^5)$ , denoting the number of teams qualified in the 46th World Finals.  

Next $n$ lines each contain one string $S\,(1 \le |S| \le 10)$ and two integers $p,t\,(1 \le p,t \le 10^9)$ , denoting the name, the predicted number of solved problems, and time penalty of one team in the 46th World Finals respectively.  

Next one line contains one integer $m\,(1 \le m \le 10^5)$ , denoting the number of teams qualified in the 47th World Finals.  

Next $m$ lines each contain one string $S\,(1 \le |S| \le 10)$ and two integers $p,t\,(1 \le p,t \le 10^9)$ , denoting the name, the predicted number of solved problems, and time penalty of one team in the 47th World Finals respectively.  

It is guaranteed that:  
· the team names only containdigits andEnglish letters;  
·the team names in one competition are different from each other;  
·no two teams have the same predicted number of solved problems and the time penalty simultaneously in one competition;  
·the same names among two qualified name lists refer to the same team in real;  
·``lzr010506'' appears in both two qualified name lists.  
  


## 输出描述

Output one line containing one integer, denoting the best possible ranking of lzr010506's team.  


## 样例

### 样例 1
**输入**:
```
5
pku 10 1513
thu 8 1195
lzr010506 8 1234
MIT 9 816
ntu 8 1325
4
mipt 9 1143
ntu 7 962
lzr010506 9 1523
pku 9 1068
```

**输出**:
```
2
```

**说明**:  

There are three double-qualified teams: lzr010506, pku, ntu.  

One possible arrangement is that pku takes part in the 46th World Finals while lzr010506 and ntu take part in the 47th World Finals. As a result, lzr010506's team could get rank 2 in the 47th World Finals. According to the arrangement, we can get the boards of the two competitions as follows:  

· The board of the 46th World Finals:  
1. pku, solved 10, penalty 1513  
2. MIT, solved 9, penalty 816  
3. thu, solved 8, penalty 1195  

·The board of the 47th World Finals:  
1.mipt, solved 9, penalty 1143  
2.lzr010506, solved 9, penalty 1523  
3. ntu, solved 7, penalty 962  


