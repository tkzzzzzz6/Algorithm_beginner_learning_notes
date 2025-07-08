# D - Make Geometric Sequence 算法流程图

## 主程序流程

```mermaid
flowchart TD
    A[开始] --> B[读取测试用例数量 T]
    B --> C[T > 0?]
    C -->|否| Z[结束]
    C -->|是| D[读取序列长度 N]
    D --> E[读取序列 A[1...N]]
    E --> F[调用 canFormGeometricSequence函数]
    F --> G[输出结果 Yes/No]
    G --> H[T = T - 1]
    H --> C
```

## 核心算法流程

```mermaid
flowchart TD
    A[开始检查等比数列] --> B[统计元素频率 count]
    B --> C[N == 1?]
    C -->|是| D[返回 true]
    C -->|否| E[计算所有可能的公比值 ratios]
    E --> F[遍历每个公比值 r]
    F --> G[还有未处理的公比值?]
    G -->|否| H[返回 false]
    G -->|是| I[选择公比值 r]
    I --> J[遍历每个元素作为第一个元素]
    J --> K[还有未处理的起始元素?]
    K -->|否| F
    K -->|是| L[选择起始元素 first]
    L --> M[初始化临时计数 temp_count]
    M --> N[尝试构造等比数列]
    N --> O[序列构造成功?]
    O -->|是| P[返回 true]
    O -->|否| J
```

## 序列构造验证流程

```mermaid
flowchart TD
    A[开始构造验证] --> B[i = 1]
    B --> C[i < N?]
    C -->|否| D[返回 true - 构造成功]
    C -->|是| E[计算第i个元素值: first * r^i]
    E --> F[四舍五入到最接近整数 next_int]
    F --> G[next_int 在剩余元素中?]
    G -->|否| H[返回 false - 构造失败]
    G -->|是| I[从 temp_count 中移除 next_int]
    I --> J[i = i + 1]
    J --> C
```

## 公比值计算流程

```mermaid
flowchart TD
    A[开始计算公比值] --> B[i = 0]
    B --> C[i < N?]
    C -->|否| F[返回所有公比值]
    C -->|是| D[j = 0]
    D --> E[j < N?]
    E -->|否| G[i = i + 1]
    G --> C
    E -->|是| H[i != j 且 A[j] != 0?]
    H -->|否| I[j = j + 1]
    I --> E
    H -->|是| J[计算 ratio = A[i] / A[j]]
    J --> K[将 ratio 加入集合]
    K --> I
```

## 完整算法决策树

```mermaid
flowchart TD
    A[输入序列 A] --> B[序列长度 N]
    B --> C{N == 1?}
    C -->|是| D[Yes - 单元素序列]
    C -->|否| E[计算所有公比值]
    E --> F[遍历公比值]
    F --> G{还有公比值?}
    G -->|否| H[No - 无法构造]
    G -->|是| I[选择公比值 r]
    I --> J[遍历起始元素]
    J --> K{还有起始元素?}
    K -->|否| F
    K -->|是| L[选择起始元素]
    L --> M[尝试构造序列]
    M --> N{构造成功?}
    N -->|是| O[Yes - 找到等比数列]
    N -->|否| J
```

## 时间复杂度分析

```mermaid
flowchart LR
    A[输入规模 N] --> B[计算公比值 O(N²)]
    B --> C[验证每个公比 O(N²)]
    C --> D[构造序列验证 O(N)]
    D --> E[总体复杂度 O(N³)]
```

## 空间复杂度分析

```mermaid
flowchart LR
    A[输入序列] --> B[元素频率统计 O(N)]
    B --> C[公比值集合 O(N²)]
    C --> D[临时计数映射 O(N)]
    D --> E[总体空间 O(N²)]
```

## 关键优化点

```mermaid
flowchart TD
    A[算法优化策略] --> B[浮点数精度处理]
    A --> C[元素重数管理]
    A --> D[提前返回优化]
    A --> E[去重公比值]
    
    B --> F[使用 round() 函数]
    C --> G[使用 map 统计频率]
    D --> H[找到解立即返回]
    E --> I[使用 set 去重]
```

## 边界情况处理

```mermaid
flowchart TD
    A[边界情况] --> B[N = 1]
    A --> C[包含负数]
    A --> D[元素重复]
    A --> E[大数值]
    
    B --> F[直接返回 true]
    C --> G[正常处理负数公比]
    D --> H[使用频率统计]
    E --> I[使用 long long]
``` 