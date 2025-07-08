# 等比数列判断算法总览

## 算法核心思想

```mermaid
graph TD
    A[输入整数序列 A] --> B[统计元素频率]
    B --> C[计算所有可能的公比值]
    C --> D[遍历每个公比值]
    D --> E[尝试构造等比数列]
    E --> F{构造成功?}
    F -->|是| G[输出 Yes]
    F -->|否| H{还有公比值?}
    H -->|是| D
    H -->|否| I[输出 No]
```

## 详细执行流程

```mermaid
flowchart TD
    Start([开始]) --> Input[读取序列 A]
    Input --> Count[统计元素频率 count]
    Count --> CheckN{序列长度 N == 1?}
    CheckN -->|是| ReturnYes[返回 Yes]
    CheckN -->|否| CalcRatios[计算所有公比值 ratios]
    CalcRatios --> ForRatio[遍历公比值 r]
    ForRatio --> HasRatio{还有公比值?}
    HasRatio -->|否| ReturnNo[返回 No]
    HasRatio -->|是| SelectRatio[选择公比值 r]
    SelectRatio --> ForFirst[遍历起始元素 first]
    ForFirst --> HasFirst{还有起始元素?}
    HasFirst -->|否| ForRatio
    HasFirst -->|是| SelectFirst[选择起始元素 first]
    SelectFirst --> InitTemp[初始化临时计数]
    InitTemp --> TryConstruct[尝试构造等比数列]
    TryConstruct --> Success{构造成功?}
    Success -->|是| ReturnYes
    Success -->|否| HasFirst
```

## 序列构造验证流程

```mermaid
flowchart TD
    Start([开始构造]) --> Init[初始化: i=1, temp_count=count]
    Init --> CheckI{i < N?}
    CheckI -->|否| Success[返回成功]
    CheckI -->|是| Calc[计算: next_val = first * r^i]
    Calc --> Round[四舍五入: next_int = round(next_val)]
    Round --> CheckExist{next_int 在 temp_count 中?}
    CheckExist -->|否| Fail[返回失败]
    CheckExist -->|是| Remove[从 temp_count 移除 next_int]
    Remove --> IncI[i = i + 1]
    IncI --> CheckI
```

## 关键数据结构

```mermaid
graph LR
    A[输入序列] --> B[map<int, int> count<br/>元素频率统计]
    C[set<double> ratios<br/>公比值集合] --> D[去重和排序]
    E[map<int, int> temp_count<br/>临时计数] --> F[构造验证]
```

## 时间复杂度分析

```mermaid
graph LR
    A[输入规模 N] --> B[计算公比值<br/>O(N²)]
    B --> C[遍历公比值<br/>O(N²)]
    C --> D[构造验证<br/>O(N)]
    D --> E[总体复杂度<br/>O(N³)]
```

## 优化策略

```mermaid
graph TD
    A[优化策略] --> B[浮点数精度<br/>使用 round() 函数]
    A --> C[元素重数<br/>使用 map 统计]
    A --> D[提前返回<br/>找到解立即退出]
    A --> E[去重公比<br/>使用 set 集合]
```

## 边界情况

```mermaid
graph TD
    A[边界情况] --> B[N = 1<br/>直接返回 Yes]
    A --> C[负数元素<br/>正常处理负数公比]
    A --> D[重复元素<br/>使用频率统计]
    A --> E[大数值<br/>使用 long long]
``` 