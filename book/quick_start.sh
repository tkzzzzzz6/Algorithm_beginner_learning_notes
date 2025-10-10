#!/bin/bash
# 快速创建书籍目录结构的脚本

echo "🚀 快速启动书籍目录创建工具"
echo "================================"

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

# 检查Python是否可用
if ! command -v python3 &> /dev/null; then
    echo "❌ Python3 未找到，请先安装Python3"
    exit 1
fi

# 运行主脚本
python3 create_book_structure.py

echo ""
echo "✨ 使用提示："
echo "1. 查看生成的目录结构和README文件"
echo "2. 在各章节的example.cpp文件中编写学习代码"
echo "3. 添加新书籍配置到 configs/ 目录"
echo "4. 再次运行此脚本创建更多书籍目录"