# 书籍目录结构创建工具

## 概述

这是一个可扩展的Python脚本，用于快速创建算法书籍的学习目录结构。

## 使用方法

### 1. 运行脚本
```bash
cd /home/tk3/桌面/code/Algorithm_beginner_learning_notes/book
python3 create_book_structure.py
```

### 2. 选择书籍
运行后会显示可用的书籍配置，输入对应数字选择要创建的书籍目录。

## 目录结构说明

创建的目录结构如下：
```
book/
├── create_book_structure.py          # 主脚本
├── configs/                          # 配置文件目录
│   ├── programming_challenges.json   # 挑战程序设计竞赛配置
│   └── introduction_to_algorithms.json # 算法导论配置
└── [书籍目录]/                       # 生成的书籍目录
    ├── README.md                     # 书籍总览
    ├── chapter1/                     # 章节目录（简洁格式）
    │   ├── README.md                 # 章节说明
    │   ├── [小节目录]/               # 小节目录
    │   │   └── example.cpp           # 示例代码
    │   └── ...
    ├── chapter2/                     # 第2章
    └── ...
```

## 添加新书籍

要添加新的书籍，只需在 `configs/` 目录下创建对应的JSON配置文件：

### 配置文件格式
```json
{
  "name": "书籍文件夹名",
  "title": "中文书名",
  "english_title": "英文书名",
  "author": "作者",
  "chapters": [
    {
      "number": 章节号,
      "title": "英文章节名",
      "name_cn": "中文章节名",
      "name_en": "英文文件夹名",
      "description": "章节描述",
      "sections": ["小节1", "小节2", "小节3"]
    }
  ]
}
```

### 配置参数说明
- `name`: 生成的书籍目录名（建议使用英文下划线格式）
- `title`: 书籍的中文标题
- `english_title`: 书籍的英文标题
- `author`: 作者信息
- `chapters`: 章节数组
  - `number`: 章节编号
  - `title`: 章节英文标题
  - `name_cn`: 章节中文名
  - `name_en`: 章节目录名（英文）
  - `description`: 章节描述
  - `sections`: 小节目录数组

## 特色功能

1. **自动生成README文件**: 为每个书籍和章节生成详细的README文档
2. **代码模板**: 自动为每个小节创建带有注释的C++代码模板
3. **扩展性强**: 通过JSON配置文件轻松添加新书籍
4. **中英文支持**: 同时支持中英文章节名
5. **标准化结构**: 统一的目录命名规范

## 已包含的书籍配置

1. **挑战程序设计竞赛** (Programming Challenges)
   - 14个章节，涵盖从入门到高级的所有竞赛算法
   - 包含数据结构、动态规划、图论、几何等核心主题

2. **算法导论** (Introduction to Algorithms - CLRS)
   - 经典算法教材，理论基础扎实
   - 适合深入学习算法理论

3. **算法竞赛入门经典** (Beginning Algorithm Contests - 刘汝佳)
   - 12个章节，从编程基础到高级算法
   - 适合算法竞赛初学者，实用性强

4. **算法竞赛入门经典——训练指南** (Training Guide - 刘汝佳, 陈锋)
   - 8个章节，进阶算法和数据结构
   - 网络流、字符串算法、计算几何等高级主题

## 扩展建议

你可以根据需要添加更多书籍配置，例如：
- 《算法竞赛入门经典》
- 《算法竞赛进阶指南》
- 《编程珠玑》
- 等等...

只需创建对应的JSON配置文件即可！