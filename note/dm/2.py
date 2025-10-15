# -*- coding: utf-8 -*-
'''
否.......... !
合取........ &
可兼或...... |
不可兼或.... #
由...可得... >
当且仅当.... =
'''
class FindTruth:
    def __init__(self):
        #存储字母及其真值
        self.Dic = {}
        self.Lis = []
        #输入表达式
        self.__In()
        #输出真值表
        self.__Out()
    #输入
    def __In(self):
        #得到表达式Str
        self.Str = input("input your expression: \n")
        #筛出字母集合
        self.Set = set(self.Str).difference(set("()!&|>=#"))
    #求公式结果
    def __Sum(self, Str):
        i = 0 #字符位置
        s = -1#式子真值
        while i < len(Str):
            c = Str[i]
        #单操作符'！'要做特殊的分类处理
            if c == "!":
            #右边是字母
                if Str[i+1] in self.Set:
                    c = Str[i+1]
                    i = i + 1
                    s0 = self.__Add('!',self.Dic[c])   
            #右边是左括号
                else:
                    end = self.__Pei(i+1, Str)
                    s0 = self.__Add('!', self.__Sum(Str[i+1:end+1]))
                    i = end
        #字母
            elif c in self.Set:
                s0 = self.Dic[c]
        #其它运算符
            elif c in set("&|>=#"):
                operat = c
        #左括号
            elif c == '(':
                end = self.__Pei(i, Str)
                s0 = self.__Sum(Str[i+1:end])
                i = end
        #运算结果
            if s == -1:
                s = s0
                s0 = -1
            elif operat != 0 and s0 != -1:
                s1 = s
                s = self.__Add(operat, s, s0)
                operat = 0
                s0 = -1
            i = i + 1
        return s
    #配对左右括号
    def __Pei(self, cur, Str):
        kflag = 1  # 左括号的数目
        while not kflag == 0:
            cur = cur + 1
            if Str[cur] == '(':
                kflag = kflag + 1
            elif Str[cur] == ')':
                kflag = kflag - 1
        return cur    
    #运算操作
    def __Add(self, operator, a, b = -1):#b默认为-1时，表示是单操作符号' ! '
        if operator == '!':
            boo = not a
        elif operator == '&':
            boo = a and b
        elif operator == '|':
            boo = a or b
        elif operator == '#':
            boo = ((not a) or (not b)) and (a or b)
        elif operator == '>':
            boo = (not a) or b
        elif operator == '=':
            boo = ((not a) and (not b)) or (a and b)
        else:
            print("there is no such operator")
        if boo:
            return 1
        else:
            return 0
    #输出
    def __Out(self):
        #将字母放入dict和List
        S = ''
        for c in self.Set:
            self.Dic[c] = 0
            self.Lis.append(c)
            S = S + c + ' '
        print(S, self.Str)
        self.__Count(0)
    #构造2^n的序列
    def __Count(self, i):
        #是结尾，打印 + 运算
        if i == len(self.Lis):
            S = ''
            for l in self.Lis:
                S = S + str(self.Dic[l]) + ' '
            print(S,self.__Sum(self.Str))
            return
        #不是结尾，递归赋值
        self.Dic[self.Lis[i]] = 0
        self.__Count(i+1)
        self.Dic[self.Lis[i]] = 1
        self.__Count(i+1)
 
if __name__ == '__main__':
    F = FindTruth()