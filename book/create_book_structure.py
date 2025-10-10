#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
书籍目录结构创建脚本
可扩展的脚本，用于创建各种算法书籍的目录结构
"""

import os
import json
from pathlib import Path

def create_directory_structure(base_path, book_config):
    """
    根据配置创建目录结构
    
    Args:
        base_path: 基础路径
        book_config: 书籍配置字典
    """
    book_name = book_config['name']
    book_path = Path(base_path) / book_name
    
    # 创建书籍主目录
    book_path.mkdir(exist_ok=True)
    
    # 创建README文件
    readme_content = f"""# {book_config['title']}

**英文名**: {book_config['english_title']}
**作者**: {book_config['author']}
**学习进度**: 开始学习

## 目录结构

"""
    
    for chapter in book_config['chapters']:
        chapter_path = book_path / f"chapter{chapter['number']}"
        chapter_path.mkdir(exist_ok=True)
        
        # 创建章节README
        chapter_readme = f"""# Chapter {chapter['number']}: {chapter['title']}

**章节名**: {chapter['name_cn']}

## 本章节内容

{chapter.get('description', '待补充章节描述')}

## 代码文件

"""
        
        # 创建子目录
        if 'sections' in chapter:
            for section in chapter['sections']:
                section_path = chapter_path / section
                section_path.mkdir(exist_ok=True)
                
                # 创建示例代码文件
                example_file = section_path / "example.cpp"
                if not example_file.exists():
                    example_content = f"""/*
 * {book_config['title']} - Chapter {chapter['number']}
 * Section: {section}
 * 
 * 示例代码模板
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {{
    // 在这里编写代码
    
    return 0;
}}
"""
                    example_file.write_text(example_content, encoding='utf-8')
        
        # 写入章节README
        (chapter_path / "README.md").write_text(chapter_readme, encoding='utf-8')
        
        readme_content += f"- [Chapter {chapter['number']}: {chapter['title']}](./chapter{chapter['number']}/)\n"
    
    # 写入主README文件
    (book_path / "README.md").write_text(readme_content, encoding='utf-8')
    
    print(f"✅ 成功创建 '{book_config['title']}' 的目录结构")
    print(f"📁 路径: {book_path}")

def load_book_config(config_file):
    """加载书籍配置文件"""
    with open(config_file, 'r', encoding='utf-8') as f:
        return json.load(f)

def main():
    """主函数"""
    script_dir = Path(__file__).parent
    config_dir = script_dir / "configs"
    
    print("📚 书籍目录结构创建工具")
    print("=" * 50)
    
    # 如果配置目录不存在，创建它
    config_dir.mkdir(exist_ok=True)
    
    # 列出可用的配置文件
    config_files = list(config_dir.glob("*.json"))
    
    if not config_files:
        print("❌ 没有找到配置文件，请先创建配置文件")
        return
    
    print("可用的书籍配置:")
    for i, config_file in enumerate(config_files, 1):
        print(f"{i}. {config_file.stem}")
    
    try:
        choice = int(input(f"\n请选择要创建的书籍 (1-{len(config_files)}): ")) - 1
        if 0 <= choice < len(config_files):
            config = load_book_config(config_files[choice])
            create_directory_structure(script_dir, config)
        else:
            print("❌ 无效的选择")
    except (ValueError, KeyboardInterrupt):
        print("❌ 操作取消")

if __name__ == "__main__":
    main()