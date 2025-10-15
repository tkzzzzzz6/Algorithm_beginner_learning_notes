from itertools import product


def evaluate_expression(expr, values):
    """
    使用特定的真值评估给定的逻辑表达式。
    """
    expr_eval = expr[:] # 创建一个表达式的副本
    for var, value in values.items():
        expr_eval = expr_eval.replace(var, str(value)) # 用实际值替换变量
    return eval(expr_eval)

def generate_truth_table(variables):
    """
    为给定的变量生成真值表。
    """
    return list(product([0, 1], repeat=len(variables))) # 生成所有可能的真值组合

def main():
    expr = input("请输入逻辑表达式（使用！、&、|、-、~表示非、与、或、条件和双条件）: ")
    # 替换为Python支持的逻辑运算符
    expr = expr.replace('!', 'not ').replace('&', ' and ').replace('|', ' or ').replace('-', ' <= ').replace('~', ' == ')

    # 假设变量是单个小写字母
    variables = sorted(set(filter(str.isalpha, expr)))
    print(f"变量: {variables}")

    truth_table = generate_truth_table(variables)
    pcnf_clauses = []
    pdnf_clauses = []

    print("真值表:")
    for values in truth_table:
        values_map = dict(zip(variables, values)) # 创建变量与真值的映射
        result = evaluate_expression(expr, values_map) # 评估表达式

        truth_values = [f"{k}: {v}" for k, v in values_map.items()]
        print(f"{', '.join(truth_values)} -> {result}")

        if result:
            # 真结果贡献给主析取范式
            pdnf_clauses.append('(' + ' and '.join([f"{var}" if values_map[var] else f"not {var}" for var in variables]) + ')')
        else:
            # 假结果贡献给主合取范式
            pcnf_clauses.append('(' + ' or '.join([f"not {var}" if values_map[var] else f"{var}" for var in variables]) + ')')

    # 输出主析取范式
    print("\n主析取范式 (PDNF):")
    print(' or '.join(pdnf_clauses) if pdnf_clauses else "该公式没有为真的组合")

    # 输出主合取范式
    print("\n主合取范式 (PCNF):")
    print(' and '.join(pcnf_clauses) if pcnf_clauses else "该公式没有为假的组合")

if __name__ == "__main__":
    main()
