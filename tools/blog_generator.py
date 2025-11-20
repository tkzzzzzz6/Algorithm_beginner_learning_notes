#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
算法学习博客自动生成器
Author: Algorithm Learning Assistant
Description: 根据代码文件和题目信息自动生成博客文章
"""

import os
import sys
import re
from datetime import datetime
from pathlib import Path
from typing import Dict, List, Optional, Tuple
import argparse


class BlogGenerator:
    """博客生成器类"""
    
    def __init__(self, template_dir: str = None):
        """
        初始化博客生成器
        
        Args:
            template_dir: 模板文件所在目录
        """
        if template_dir is None:
            # 默认模板目录
            self.template_dir = Path(__file__).parent.parent / "note" / "刷题笔记模板"
        else:
            self.template_dir = Path(template_dir)
    
    def detect_language(self, file_path: str) -> str:
        """
        根据文件扩展名检测编程语言
        
        Args:
            file_path: 代码文件路径
            
        Returns:
            语言名称
        """
        ext = Path(file_path).suffix.lower()
        language_map = {
            '.cpp': 'C++',
            '.c': 'C',
            '.py': 'Python',
            '.java': 'Java',
            '.go': 'Go',
            '.js': 'JavaScript',
            '.ts': 'TypeScript',
            '.rs': 'Rust',
        }
        return language_map.get(ext, 'Unknown')
    
    def read_code_file(self, file_path: str) -> str:
        """
        读取代码文件内容
        
        Args:
            file_path: 代码文件路径
            
        Returns:
            代码内容
        """
        try:
            with open(file_path, 'r', encoding='utf-8') as f:
                return f.read()
        except Exception as e:
            print(f"❌ 读取代码文件失败: {e}")
            return ""
    
    def extract_problem_info_from_path(self, file_path: str) -> Dict[str, str]:
        """
        从文件路径中提取题目信息
        
        Args:
            file_path: 代码文件路径
            
        Returns:
            题目信息字典
        """
        path_parts = Path(file_path).parts
        info = {
            'platform': '',
            'problem_number': '',
            'problem_name': '',
            'difficulty': 'Medium'
        }
        
        # 判断是 LeetCode 还是牛客
        if 'leetcode' in str(file_path).lower():
            info['platform'] = 'LeetCode'
            # 尝试从路径中提取题目信息
            for part in path_parts:
                # 匹配类似 "1437. 是否所有 1 都至少相隔 k 个元素" 的格式
                match = re.match(r'(\d+)[\.\s]*(.+)', part)
                if match:
                    info['problem_number'] = match.group(1)
                    info['problem_name'] = match.group(2).strip()
                    break
        elif 'niuke' in str(file_path).lower():
            info['platform'] = '牛客'
            # 从路径中提取题目名称
            for part in path_parts:
                if 'daily_problem' in part or 'contest' in part:
                    continue
                # 匹配日期格式的文件夹名
                if re.match(r'\d+_\d+-\d+', part):
                    # 提取题目名称（去掉日期前缀）
                    problem_name = re.sub(r'^\d+_\d+-\d+', '', part)
                    info['problem_name'] = problem_name
                    break
        
        return info
    
    def format_code_block(self, code: str, language: str) -> str:
        """
        格式化代码块
        
        Args:
            code: 代码内容
            language: 编程语言
            
        Returns:
            格式化后的代码块
        """
        lang_map = {
            'C++': 'cpp',
            'C': 'c',
            'Python': 'python',
            'Java': 'java',
            'Go': 'go',
            'JavaScript': 'javascript',
            'TypeScript': 'typescript',
            'Rust': 'rust',
        }
        lang_tag = lang_map.get(language, 'text')
        return f"```{lang_tag}\n{code.strip()}\n```"
    
    def analyze_algorithm(self, code: str, language: str) -> Dict[str, str]:
        """
        分析算法的时间和空间复杂度
        
        Args:
            code: 代码内容
            language: 编程语言
            
        Returns:
            包含复杂度分析的字典
        """
        # 简单的启发式分析
        analysis = {
            'time_complexity': 'O(n)',
            'space_complexity': 'O(1)',
            'algorithm_type': '待分析',
            'key_techniques': []
        }
        
        code_lower = code.lower()
        
        # 检测常见算法模式
        if 'sort' in code_lower or 'sorted' in code_lower:
            analysis['time_complexity'] = 'O(n log n)'
            analysis['key_techniques'].append('排序')
        
        if 'dp' in code_lower or 'memo' in code_lower:
            analysis['algorithm_type'] = '动态规划'
            analysis['key_techniques'].append('动态规划')
        
        if 'bfs' in code_lower or 'queue' in code_lower:
            analysis['algorithm_type'] = '广度优先搜索'
            analysis['key_techniques'].append('BFS')
        
        if 'dfs' in code_lower or 'recursion' in code_lower:
            analysis['algorithm_type'] = '深度优先搜索'
            analysis['key_techniques'].append('DFS/递归')
        
        if 'binary' in code_lower or 'bisect' in code_lower:
            analysis['time_complexity'] = 'O(log n)'
            analysis['key_techniques'].append('二分查找')
        
        if 'unionfind' in code_lower or 'union' in code_lower or 'find' in code_lower:
            analysis['algorithm_type'] = '并查集'
            analysis['key_techniques'].append('并查集')
        
        if 'sliding' in code_lower or ('left' in code_lower and 'right' in code_lower):
            analysis['algorithm_type'] = '滑动窗口'
            analysis['key_techniques'].append('滑动窗口')
        
        # 检测嵌套循环
        for_count = code.count('for')
        while_count = code.count('while')
        loop_count = for_count + while_count
        
        if loop_count >= 3:
            analysis['time_complexity'] = 'O(n³) 或更高'
        elif loop_count == 2:
            analysis['time_complexity'] = 'O(n²)'
        
        # 检测空间复杂度
        if 'vector' in code_lower or 'array' in code_lower or 'list' in code_lower:
            if '[][]' in code or 'vector<vector' in code:
                analysis['space_complexity'] = 'O(n²)'
            else:
                analysis['space_complexity'] = 'O(n)'
        
        return analysis
    
    def generate_leetcode_blog(
        self,
        code_file: str,
        problem_url: str = "",
        problem_number: str = "",
        problem_name: str = "",
        difficulty: str = "Medium",
        description: str = "",
        approach: str = "",
        output_file: str = None
    ) -> str:
        """
        生成 LeetCode 博客文章
        
        Args:
            code_file: 代码文件路径
            problem_url: 题目链接
            problem_number: 题目编号
            problem_name: 题目名称
            difficulty: 难度
            description: 题目描述
            approach: 解题思路
            output_file: 输出文件路径
            
        Returns:
            生成的博客内容
        """
        # 读取代码
        code = self.read_code_file(code_file)
        if not code:
            return ""
        
        # 检测语言
        language = self.detect_language(code_file)
        
        # 如果没有提供题目信息，尝试从路径中提取
        if not problem_number or not problem_name:
            info = self.extract_problem_info_from_path(code_file)
            problem_number = problem_number or info['problem_number']
            problem_name = problem_name or info['problem_name']
            difficulty = difficulty or info['difficulty']
        
        # 分析算法
        analysis = self.analyze_algorithm(code, language)
        
        # 生成日期
        today = datetime.now().strftime('%Y-%m-%d')
        
        # 生成博客内容
        blog_content = f"""---
title: {today}-LeetCode刷题笔记-{problem_number}-{problem_name}
date: {today}
tags:
  - 算法学习
  - LeetCode
---

# 题目信息
- 平台：LeetCode
- 题目：{problem_number}. {problem_name}
- 难度：{difficulty}
- 题目链接：[{problem_name}]({problem_url})

---

## 题目描述
> {description if description else '请补充题目描述'}

---

## 初步思路
{approach if approach else '''1. 分析题目要求和约束条件
2. 确定使用的算法和数据结构
3. 设计解决方案
4. 考虑边界情况'''}

---

## 算法分析
- 核心：{analysis['algorithm_type']}
- 关键技巧：{', '.join(analysis['key_techniques']) if analysis['key_techniques'] else '待补充'}
- 时间复杂度：{analysis['time_complexity']}
- 空间复杂度：{analysis['space_complexity']}

---

## 代码实现（{language}）
{self.format_code_block(code, language)}

---

## 测试用例
| 输入 | 输出 | 说明 |
|------|------|------|
| 示例1 | 结果1 | 说明1 |
| 示例2 | 结果2 | 说明2 |

---

## 总结与反思
1. 本题的关键在于{analysis['algorithm_type']}的应用
2. 需要注意的边界情况包括：空输入、单元素等
3. 可以进一步优化的地方：待补充

---
"""
        
        # 如果指定了输出文件，写入文件
        if output_file:
            try:
                with open(output_file, 'w', encoding='utf-8') as f:
                    f.write(blog_content)
                print(f"✅ LeetCode 博客已生成: {output_file}")
            except Exception as e:
                print(f"❌ 写入文件失败: {e}")
        
        return blog_content
    
    def generate_niuke_blog(
        self,
        code_file: str,
        problem_url: str = "",
        problem_name: str = "",
        difficulty: str = "中等",
        description: str = "",
        input_desc: str = "",
        output_desc: str = "",
        examples: List[Dict[str, str]] = None,
        approach: str = "",
        output_file: str = None
    ) -> str:
        """
        生成牛客博客文章
        
        Args:
            code_file: 代码文件路径
            problem_url: 题目链接
            problem_name: 题目名称
            difficulty: 难度
            description: 题目描述
            input_desc: 输入描述
            output_desc: 输出描述
            examples: 示例列表
            approach: 解题思路
            output_file: 输出文件路径
            
        Returns:
            生成的博客内容
        """
        # 读取代码
        code = self.read_code_file(code_file)
        if not code:
            return ""
        
        # 检测语言
        language = self.detect_language(code_file)
        
        # 如果没有提供题目信息，尝试从路径中提取
        if not problem_name:
            info = self.extract_problem_info_from_path(code_file)
            problem_name = problem_name or info['problem_name']
        
        # 分析算法
        analysis = self.analyze_algorithm(code, language)
        
        # 生成日期
        today = datetime.now().strftime('%Y-%m-%d')
        
        # 处理示例
        examples_text = ""
        if examples:
            for i, example in enumerate(examples, 1):
                examples_text += f"\n## 示例{i}\n"
                examples_text += f"```\n输入：\n{example.get('input', '')}\n\n"
                examples_text += f"输出：\n{example.get('output', '')}\n```\n"
                if example.get('explanation'):
                    examples_text += f"说明：{example['explanation']}\n"
        else:
            examples_text = "\n## 示例1\n```\n输入：\n待补充\n\n输出：\n待补充\n```\n"
        
        # 生成博客内容
        blog_content = f"""---
title: {today}-牛客刷题笔记-{problem_name}
date: {today}
tags:
  - 算法学习
  - 牛客
---

# 题目信息
- 平台：牛客
- 题目：{problem_name}
- 难度：{difficulty}
- 题目链接：[{problem_name}]({problem_url})

---

## 题目描述
{description if description else '> 请补充题目描述'}

### 输入描述
{input_desc if input_desc else '待补充'}

### 输出描述
{output_desc if output_desc else '待补充'}

{examples_text}

---

## 初步思路
{approach if approach else '''1. 分析题目要求和数据范围
2. 确定算法策略
3. 设计数据结构
4. 处理特殊情况'''}

---

## 算法分析
- 算法类型：{analysis['algorithm_type']}
- 关键技巧：{', '.join(analysis['key_techniques']) if analysis['key_techniques'] else '待补充'}
- 时间复杂度：{analysis['time_complexity']}
- 空间复杂度：{analysis['space_complexity']}

---

## 代码实现（{language}）
{self.format_code_block(code, language)}

---

## 详细解释
1. **数据结构选择**：待补充
2. **算法流程**：
   - 步骤1：待补充
   - 步骤2：待补充
3. **优化点**：待补充

---

## 测试与验证
- 基本测试用例：通过
- 边界情况：待补充
- 性能测试：待补充

---

## 总结与反思
1. 本题考查了{analysis['algorithm_type']}的应用
2. 解题的关键在于：{'、'.join(analysis['key_techniques']) if analysis['key_techniques'] else '待补充'}
3. 易错点：待补充
4. 优化思路：待补充

---
"""
        
        # 如果指定了输出文件，写入文件
        if output_file:
            try:
                with open(output_file, 'w', encoding='utf-8') as f:
                    f.write(blog_content)
                print(f"✅ 牛客博客已生成: {output_file}")
            except Exception as e:
                print(f"❌ 写入文件失败: {e}")
        
        return blog_content
    
    def interactive_generate(self):
        """交互式生成博客"""
        print("=" * 60)
        print("📝 算法学习博客生成器")
        print("=" * 60)
        print()
        
        # 选择平台
        print("请选择题目平台：")
        print("1. LeetCode")
        print("2. 牛客")
        platform_choice = input("请输入选项 (1/2): ").strip()
        
        # 输入代码文件路径
        code_file = input("\n请输入代码文件路径: ").strip()
        if not os.path.exists(code_file):
            print(f"❌ 文件不存在: {code_file}")
            return
        
        # 输入题目信息
        problem_url = input("请输入题目链接: ").strip()
        
        if platform_choice == "1":
            # LeetCode
            problem_number = input("请输入题目编号: ").strip()
            problem_name = input("请输入题目名称: ").strip()
            difficulty = input("请输入难度 (Easy/Medium/Hard): ").strip() or "Medium"
            description = input("请输入题目描述 (回车跳过): ").strip()
            approach = input("请输入解题思路 (回车跳过): ").strip()
            
            # 生成输出文件名
            today = datetime.now().strftime('%Y-%m-%d')
            output_file = f"{today}-LeetCode刷题笔记-{problem_number}-{problem_name}.md"
            
            # 生成博客
            self.generate_leetcode_blog(
                code_file=code_file,
                problem_url=problem_url,
                problem_number=problem_number,
                problem_name=problem_name,
                difficulty=difficulty,
                description=description,
                approach=approach,
                output_file=output_file
            )
            
        elif platform_choice == "2":
            # 牛客
            problem_name = input("请输入题目名称: ").strip()
            difficulty = input("请输入难度 (简单/中等/困难): ").strip() or "中等"
            description = input("请输入题目描述 (回车跳过): ").strip()
            approach = input("请输入解题思路 (回车跳过): ").strip()
            
            # 生成输出文件名
            today = datetime.now().strftime('%Y-%m-%d')
            output_file = f"{today}-牛客刷题笔记-{problem_name}.md"
            
            # 生成博客
            self.generate_niuke_blog(
                code_file=code_file,
                problem_url=problem_url,
                problem_name=problem_name,
                difficulty=difficulty,
                description=description,
                approach=approach,
                output_file=output_file
            )
        else:
            print("❌ 无效的选项")
            return
        
        print("\n✨ 博客生成完成！")


def main():
    """主函数"""
    parser = argparse.ArgumentParser(
        description='算法学习博客自动生成器',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
示例用法:
  
  交互式模式:
    python blog_generator.py
  
  LeetCode 模式:
    python blog_generator.py --platform leetcode --code solution.py --url https://leetcode.cn/problems/xxx --number 1437 --name "题目名称"
  
  牛客模式:
    python blog_generator.py --platform niuke --code solution.cpp --url https://www.nowcoder.com/xxx --name "题目名称"
        """
    )
    
    parser.add_argument('--platform', choices=['leetcode', 'niuke'], help='题目平台')
    parser.add_argument('--code', help='代码文件路径')
    parser.add_argument('--url', help='题目链接')
    parser.add_argument('--number', help='题目编号 (仅LeetCode)')
    parser.add_argument('--name', help='题目名称')
    parser.add_argument('--difficulty', help='难度')
    parser.add_argument('--desc', help='题目描述')
    parser.add_argument('--approach', help='解题思路')
    parser.add_argument('--output', help='输出文件路径')
    
    args = parser.parse_args()
    
    generator = BlogGenerator()
    
    # 如果提供了命令行参数，使用命令行模式
    if args.platform and args.code:
        if args.platform == 'leetcode':
            generator.generate_leetcode_blog(
                code_file=args.code,
                problem_url=args.url or "",
                problem_number=args.number or "",
                problem_name=args.name or "",
                difficulty=args.difficulty or "Medium",
                description=args.desc or "",
                approach=args.approach or "",
                output_file=args.output
            )
        elif args.platform == 'niuke':
            generator.generate_niuke_blog(
                code_file=args.code,
                problem_url=args.url or "",
                problem_name=args.name or "",
                difficulty=args.difficulty or "中等",
                description=args.desc or "",
                approach=args.approach or "",
                output_file=args.output
            )
    else:
        # 交互式模式
        generator.interactive_generate()


if __name__ == '__main__':
    main()

