# by sort
import random

class phone:
    def __init__(self):
        self.phone_dict = {}  # 用字典存储电话号码及其出现次数
        self.max_count = 0    # 记录最大出现次数
        
    def add_phone(self, number):
        # 确保号码长度为11位
        if len(number) != 11:
            return
            
        # 按字符串排序
        sorted_num = ''.join(sorted(number))
        
        # 更新字典计数
        if sorted_num in self.phone_dict:
            self.phone_dict[sorted_num] += 1
        else:
            self.phone_dict[sorted_num] = 1
            
        # 更新最大出现次数    
        self.max_count = max(self.max_count, self.phone_dict[sorted_num])
        
    def get_max_count(self):
        return self.max_count
    
    def get_max_phone(self):
        for phone, count in self.phone_dict.items():
            if count == self.max_count:
                return phone

def main():
    phone_obj = phone()
    # 编写一段程序，模拟输入1000条通话记录
    for _ in range(10000):
        number = random.randint(10000000000,10000000010)
        phone_obj.add_phone(str(number))

    print(f"最大通话次数为：{phone_obj.get_max_count()},电话狂魔为电话号码：{phone_obj.get_max_phone()}")

if __name__ == "__main__":
    main()

