from manim import *

class StackRPNCalculation(Scene):
    def construct(self):
        # 创建标题
        title = Text("RPN Stack Calculation: 62/3-42*+").scale(0.7).to_edge(UP)
        self.play(Write(title))
        
        # 创建一个模拟栈
        stack = VGroup()
        stack_outline = Rectangle(height=4, width=2).to_edge(LEFT)
        stack_texts = VGroup()  # 用于存放栈中元素的显示

        # 初始空栈显示
        self.play(Create(stack_outline))

        # 逐步计算后缀表达式
        expression = ["6", "2", "/", "3", "4", "-", "2", "*", "+"]
        operation_steps = [
            ("Push", "6"), 
            ("Push", "2"), 
            ("Operation", "/"),  # 6 / 2 = 3
            ("Push", "3"), 
            ("Push", "4"), 
            ("Operation", "-"),  # 3 - 4 = -1
            ("Push", "2"), 
            ("Operation", "*"),  # -1 * 2 = -2
            ("Operation", "+")   # 3 + (-2) = 1
        ]

        current_stack = []  # 模拟栈的内容

        for step in operation_steps:
            action, value = step
            if action == "Push":
                # 将元素压入栈
                current_stack.append(value)
                text = Text(value).scale(0.6).next_to(stack_outline, RIGHT, buff=1)
                stack_texts.add(text)
                self.play(Write(text))
            elif action == "Operation":
                # 执行运算操作
                num2 = current_stack.pop()
                num1 = current_stack.pop()
                result = str(eval(f"{num1}{value}{num2}"))  # 计算结果
                
                # 将运算过程显示
                op_text = Text(f"{num1} {value} {num2} = {result}").scale(0.6).to_edge(RIGHT)
                self.play(Write(op_text))
                self.play(FadeOut(op_text))
                
                # 将结果压入栈
                current_stack.append(result)
                result_text = Text(result).scale(0.6).next_to(stack_outline, RIGHT, buff=1)
                self.play(Write(result_text))

        # 显示最终结果
        final_result = Text(f"Result: {current_stack[-1]}").scale(0.8).to_edge(DOWN)
        self.play(Write(final_result))
        self.wait(2)

