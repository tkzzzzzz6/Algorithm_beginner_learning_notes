# CI/CD 配置说明

## 概述

本仓库配置了 **轻量级 CI（持续集成），但**不包含 CD（持续部署）。

---

## 📋 为什么这样配置？

### ✅ 已添加：CI（持续集成）

**理由：**

| 功能 | 作用 |
|------|------|
| **C++ 编译检查** | 自动检查 `.cpp` 文件语法（仅提示，不阻止提交） |
| **Python 语法检查** | 检查 Python 代码语法（仅提示，不阻止提交） |
| **Go 编译检查** | 检查 Go 代码构建（仅提示，不阻止提交） |

**重要：这是信息性检查，不会阻止提交！**
- 即使 LeetCode 代码缺少 `main` 函数或依赖预定义类型（如 `ListNode`），也能正常提交
- CI 结果仅供参考，帮助你发现明显的语法错误
- 不会因为检查失败而阻止合并 PR

---

### ❌ 不添加：CD（持续部署）

**理由：**

这是一个**算法学习笔记仓库**，不是需要部署到服务器的应用程序，因此不需要 CD。

---

## 🛠 CI 工作原理

```
.github/
├── workflows/
│   └── ci.yml          # GitHub Actions 主配置
└── scripts/
    ├── check_cpp.sh    # C++ 编译检查脚本
    ├── check_python.sh # Python 语法检查脚本
    └── check_go.sh      # Go 编译检查脚本
```

**触发时机：**
- 推送到 `main` / `master` 分支
- 创建 PR 到 `main` / `master` 分支

---

## 📊 包含的检查

| 语言 | 检查方式 | 标准 |
|------|---------|------|
| C++ | `g++ -fsyntax-only` | C++20 (gnu++20) |
| Python | `py_compile` | Python 3.11 |
| Go | `go build` | Go 1.21 |

---

## 🚀 如何使用？

CI 会自动运行，无需手动操作。

查看 CI 结果：
1. 进入仓库的 **Actions** 标签页
2. 点击对应的 workflow run
3. 查看各 job 的详细输出

---

## 💡 本地测试（可选）

如果你想在本地运行检查：

```bash
# C++ 检查
.github/scripts/check_cpp.sh

# Python 检查
.github/scripts/check_python.sh

# Go 检查
.github/scripts/check_go.sh
```
