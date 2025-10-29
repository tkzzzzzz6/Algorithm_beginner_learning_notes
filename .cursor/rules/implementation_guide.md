# Implementation Guide for Algorithm Project Rules

This guide explains how to apply the standardized rules to your existing algorithm competition and knowledge documentation project.

## Getting Started

1. **Create Required Directories**: If they don't already exist, create these directories based on the recommended structure:
   ```
   mkdir -p templates/data_structures templates/algorithms templates/graph_theory templates/math
   mkdir -p knowledge_base/articles knowledge_base/tutorials
   mkdir -p progress_tracking
   ```

2. **Reorganize Existing Content**: Gradually migrate your existing content to the new structure:

   a. For LeetCode problems:
   ```
   mv leetcode/* problems/leetcode/
   ```

   b. For CodeForces problems:
   ```
   mv code_force/* problems/codeforces/
   ```

   c. For AtCoder problems:
   ```
   mv atcoder/* problems/atcoder/
   ```

   d. For Luogu problems:
   ```
   mv luogu_code/* problems/luogu/
   ```

3. **Create Initial Tracking Files**:
   ```
   cp .cursor/rules/examples/skills_matrix_example.md progress_tracking/skills_matrix.md
   cp .cursor/rules/examples/learning_path_example.md progress_tracking/learning_path.md
   ```

## Applying the Templates to Existing Solutions

### Step 1: Convert Existing Problem Solutions

For each problem you've already solved:

1. Create a README.md in the problem directory following the problem documentation template:
   ```
   cp .cursor/rules/examples/problem_documentation_example.md problems/leetcode/1534_统计好三元组/README.md
   ```

2. Edit the README.md to match the actual problem details

3. Ensure your solution file follows the implementation standards with proper comments and documentation

### Step 2: Create Algorithm Templates

1. For algorithms you commonly use, create template files in the appropriate directories:
   ```
   cp .cursor/rules/examples/algorithm_template_example.cpp templates/algorithms/searching/binary_search.cpp
   ```

2. Create similar templates for:
   - Data structures (BST, heap, trie, etc.)
   - Graph algorithms (DFS, BFS, Dijkstra, etc.)
   - Dynamic programming patterns
   - String algorithms

### Step 3: Document Competition Experiences

After each competition:

1. Create a summary file using the contest template:
   ```
   cp .cursor/rules/examples/contest_summary_example.md contests/codeforces/round_826/contest_summary.md
   ```

2. Fill in your experiences, challenges, and learnings

3. Update your skills matrix to reflect new knowledge gained

## Project Maintenance Workflow

### Weekly Tasks:

1. **Problem Solving Documentation**:
   - Document new problems solved following the template
   - Update any incomplete documentation from previous solutions
   - Tag problems by algorithm/data structure for retrieval

2. **Progress Tracking**:
   - Update problem counts in the skills matrix
   - Note any new techniques learned
   - Review weekly goals from learning path

### Monthly Tasks:

1. **Knowledge Consolidation**:
   - Create articles for topics you've mastered
   - Update algorithm templates with optimizations discovered
   - Review and update proficiency ratings

2. **Learning Path Review**:
   - Evaluate progress on current focus area
   - Adjust upcoming topics based on strengths/weaknesses
   - Set new monthly goals

3. **Contest Performance Analysis**:
   - Compare performance across contests
   - Identify pattern of strengths and weaknesses
   - Adjust learning priorities accordingly

### Quarterly Tasks:

1. **Major Reorganization**:
   - Ensure all problems are properly documented
   - Update directory structure if needed
   - Consolidate similar templates

2. **Comprehensive Review**:
   - Revisit early problems with new knowledge
   - Optimize solutions where possible
   - Create advanced versions of basic templates

## Tips for Success

1. **Consistency is Key**: Spend a few minutes after solving each problem to document it properly. This immediate reflection enhances learning.

2. **Balance Theory and Practice**: For each new algorithm you learn, aim to:
   - Understand the theory (time/space complexity, preconditions)
   - Implement it from scratch at least once
   - Solve 3-5 problems that use it
   - Document variations and optimizations

3. **Regular Review**: Schedule regular review sessions to revisit problems you found challenging.

4. **Incremental Migration**: You don't need to reorganize everything at once. Start with new content following the templates, then gradually migrate older content.

5. **Template Evolution**: Your templates should evolve as you gain expertise. Revisit and improve them periodically.

## Using Cursor Rules for This Project

1. Open any problem file you're working on
2. Access the Cursor Rules menu
3. Select the appropriate template based on what you're working on:
   - Problem documentation
   - Algorithm template
   - Contest summary
4. The template will guide you through properly documenting your work

## Getting Help

If you encounter challenges implementing these rules:

1. Refer to the example files in `.cursor/rules/examples/`
2. Check the main rules document at `.cursor/rules/algorithm_project_rules.md`
3. Consider adding new rule templates as your project evolves 