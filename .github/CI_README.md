# CI/CD 配置说明

## 概述

本仓库配置了 **轻量级 CI（持续集成），但**不包含 CD（持续部署）。

---

## 📋 为什么这样配置？

### ✅ 已添加：CI（持续集成）

**理由：**

| 功能 | 作用 |
|------|------|
| **C++ 编译检查 | 自动验证所有 `.cpp` 文件语法正确，能正常编译 |
| **Python 语法检查 | 验证 Python 代码无语法错误 |
| **Go 编译检查 | 验证 Go 代码可以正常构建 |

**好处：
- 防止提交无法编译的代码
- PR 自动检查，保证代码质量
- 快速发现语法错误，节省调试时间

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
