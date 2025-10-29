# Algorithm Project Organization Rules

## 1. Problem Solution Structure

### 1.1 Problem Documentation Template
```markdown
# Problem [ID]: [Title]

## Problem Information
- **Platform**: [LeetCode/CodeForces/AtCoder/etc.]
- **ID**: [Problem ID]
- **Difficulty**: [Easy/Medium/Hard]
- **Tags**: [Array, DP, Graph, etc.]
- **URL**: [Problem Link]
- **Solved Date**: YYYY-MM-DD

## Problem Description
[Include a clear, concise description of the problem]

### Input
- Format and constraints

### Output
- Expected output format

### Examples
```
Input: ...
Output: ...
Explanation: ...
```

## Approach
### Intuition
- Initial thoughts on the problem
- Key observations
- Pattern recognition

### Algorithm
1. [Step-by-step solution]
2. [Key implementation details]
3. [Edge cases to handle]

### Complexity Analysis
- **Time Complexity**: O(...) - [Explanation]
- **Space Complexity**: O(...) - [Explanation]

## Implementation
```[language]
// Code implementation with detailed comments
```

## Key Learnings
- [New concepts/techniques learned]
- [Common pitfalls encountered]
- [Optimization techniques]

## Related Problems
- [Similar problem 1]
- [Similar problem 2]
```

### 1.2 File Naming Convention
- For problem solutions: `[platform]_[problem-id]_[short-description].[language-extension]`
- For implementations of specific algorithms: `[category]_[algorithm-name].[language-extension]`
- For contest solutions: `[contest-name]_[problem-id].[language-extension]`

### 1.3 Implementation Standards
- Include a clear problem statement in comments at the top
- Use meaningful variable names
- Comment on complex logic or non-obvious optimizations
- Organize code into logical sections with clear separation
- Include test cases when appropriate

## 2. Knowledge Classification System

### 2.1 Primary Categories
1. **Data Structures**
   - Arrays and Strings
   - Linked Lists
   - Stacks and Queues
   - Hash Tables
   - Trees (Binary, BST, AVL, Red-Black, etc.)
   - Heaps and Priority Queues
   - Graphs
   - Advanced Data Structures (Trie, Segment Tree, Disjoint Set, etc.)

2. **Algorithms**
   - Searching (Binary Search, DFS, BFS)
   - Sorting (Quick, Merge, Heap, Counting, Radix)
   - Dynamic Programming
   - Greedy Algorithms
   - Divide and Conquer
   - Backtracking
   - Mathematical Algorithms
   - Bit Manipulation
   - String Algorithms (KMP, Rabin-Karp, etc.)

3. **Graph Theory**
   - Graph Representation
   - Graph Traversal (DFS, BFS)
   - Shortest Path Algorithms (Dijkstra, Bellman-Ford, Floyd-Warshall)
   - Minimum Spanning Tree (Prim, Kruskal)
   - Topological Sort
   - Strongly Connected Components
   - Network Flow (Ford-Fulkerson, Dinic)
   - Bipartite Matching

4. **Competitive Programming Techniques**
   - Time-Space Tradeoffs
   - Amortized Analysis
   - Problem-Solving Strategies
   - Optimization Techniques
   - Contest Strategies

### 2.2 Directory Structure
```
/algorithm
├── problems/
│   ├── leetcode/
│   │   └── [problem-id]_[short-description]/
│   │       ├── solution.[language-extension]
│   │       └── README.md (problem documentation)
│   ├── codeforces/
│   ├── atcoder/
│   └── luogu/
├── templates/
│   ├── data_structures/
│   │   ├── trees/
│   │   ├── graphs/
│   │   └── advanced/
│   ├── algorithms/
│   │   ├── searching/
│   │   ├── sorting/
│   │   ├── dynamic_programming/
│   │   └── string_algorithms/
│   ├── graph_theory/
│   │   ├── shortest_path/
│   │   ├── minimum_spanning_tree/
│   │   └── network_flow/
│   └── math/
│       ├── number_theory/
│       ├── combinatorics/
│       └── geometry/
├── contests/
│   ├── [platform]/
│   │   └── [contest-id]/
│   │       ├── [problem-id].[language-extension]
│   │       └── contest_summary.md
├── knowledge_base/
│   ├── articles/
│   │   ├── [topic-name].md
│   └── tutorials/
│       ├── [tutorial-name]/
│           ├── README.md
│           └── examples/
└── progress_tracking/
    ├── learning_path.md
    ├── skills_matrix.md
    └── contest_records.md
```

## 3. Competition Experience Template

### 3.1 Contest Summary Template
```markdown
# [Contest Name] - [Date]

## Contest Overview
- **Platform**: [Platform Name]
- **Duration**: [Hours]
- **Number of Problems**: [Count]
- **My Rank**: [Rank]/[Total Participants]
- **Problems Solved**: [Count]/[Total]

## Problem Breakdown

### Problem A: [Title]
- **Difficulty**: [Easy/Medium/Hard]
- **Tags**: [Relevant Tags]
- **Time to Solve**: [Minutes]
- **Attempts**: [Number]
- **Approach**: [Brief description of approach]
- **Key Challenges**: [What made this problem difficult]
- **Lessons Learned**: [What I learned from this problem]

[Repeat for each problem...]

## Overall Performance Analysis
- **Strengths**: [What went well]
- **Weaknesses**: [Areas for improvement]
- **Time Management**: [How effectively time was managed]

## Action Items
1. [Specific topic/algorithm to practice]
2. [Specific skill to improve]
3. [Strategy adjustment for next contest]
```

### 3.2 Critical Thinking Documentation
- Document your thought process for each problem
- Note initial approaches, including those that didn't work
- Identify pattern recognition moments
- Record optimizations and their impact
- Document debugging strategies

## 4. Algorithm Template Library

### 4.1 Template Structure
```
/**
 * Algorithm: [Algorithm Name]
 * Category: [Category]
 * 
 * Description:
 * [Brief description of the algorithm and its purpose]
 * 
 * Time Complexity: O(...)
 * Space Complexity: O(...)
 * 
 * Parameters:
 * - param1: [Description]
 * - param2: [Description]
 * 
 * Returns:
 * - [Description of return value]
 * 
 * Example Usage:
 * [Short example of how to use this template]
 * 
 * References:
 * - [Reference 1]
 * - [Reference 2]
 * 
 * Related Problems:
 * - [Problem 1]
 * - [Problem 2]
 */

// Implementation
```

### 4.2 Template Categories
- Data Structure Implementations
- Algorithm Implementations
- Utility Functions
- Common Problem Patterns

### 4.3 Reusability Guidelines
- Make templates generic where possible
- Provide clear documentation on usage
- Include example usage
- Ensure templates are tested on multiple problems

## 5. Learning Progress Tracking

### 5.1 Skills Matrix Template
```markdown
# Algorithm Skills Matrix

## Data Structures
| Data Structure | Proficiency (1-5) | Problems Solved | Notes |
|----------------|-------------------|-----------------|-------|
| Arrays         | [rating]          | [count]         | [notes] |
| Linked Lists   | [rating]          | [count]         | [notes] |
| Trees          | [rating]          | [count]         | [notes] |
| Graphs         | [rating]          | [count]         | [notes] |
| ...            | ...               | ...             | ...   |

## Algorithms
| Algorithm      | Proficiency (1-5) | Problems Solved | Notes |
|----------------|-------------------|-----------------|-------|
| Binary Search  | [rating]          | [count]         | [notes] |
| DP             | [rating]          | [count]         | [notes] |
| ...            | ...               | ...             | ...   |
```

### 5.2 Learning Path Structure
```markdown
# Learning Path

## Current Focus (Month/Year)
- Topic: [Current topic to master]
- Goal: [Specific skill to develop]
- Target Problems: [List of problems to solve]

## Completed Topics
1. [Topic] - [Date]
   - Problems solved: [count]
   - Key learnings: [summary]

2. [Topic] - [Date]
   - Problems solved: [count]
   - Key learnings: [summary]

## Upcoming Topics
1. [Topic]
   - Prerequisite knowledge: [list]
   - Resources: [list]
   - Target completion: [date]
```

### 5.3 Spaced Repetition System
- Review previously solved problems periodically
- Implement a tagging system to mark problems for review
- Schedule regular reviews of challenging concepts

## 6. Balancing Theory and Practice

### 6.1 Theory Documentation Guidelines
- Link theoretical concepts to practical problems
- Include visual illustrations where helpful
- Reference authoritative sources
- Document time and space complexity analysis

### 6.2 Practice Guidelines
- Implement theoretical concepts in multiple problems
- Compare different approaches to the same problem
- Practice optimization of initial solutions
- Document trade-offs between different solutions

### 6.3 Knowledge Integration
- Cross-reference related problems and concepts
- Create concept maps linking theoretical knowledge to problem patterns
- Develop cheat sheets for quick reference during competitions

## 7. Information Retrieval System

### 7.1 Tagging System
- Use consistent tags across all problems and knowledge articles
- Tag by algorithm, data structure, difficulty, and special techniques
- Maintain a master list of tags to ensure consistency

### 7.2 Search Methodology
- Implement a local search system for your documentation
- Use descriptive filenames and headers for easier searching
- Maintain an index of problems by tags

### 7.3 Quick Reference Materials
- Create algorithm cheat sheets
- Develop decision trees for algorithm selection
- Maintain a collection of common code snippets

## 8. Regular Maintenance

### 8.1 Review Schedule
- Weekly review of new problems solved
- Monthly update of skills matrix
- Quarterly review of learning path
- Semi-annual reorganization and cleanup of documentation

### 8.2 Knowledge Consolidation
- Periodically summarize learnings from multiple related problems
- Create comprehensive guides on mastered topics
- Refactor templates based on accumulated experience

### 8.3 Progress Evaluation
- Track performance metrics in competitions
- Analyze patterns in problem-solving success and difficulty
- Adjust learning path based on performance data 