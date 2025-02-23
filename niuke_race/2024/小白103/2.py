import re

def is_valid_email(email):
    # 将邮箱分割为本地部分和域名部分
    parts = email.split('@')
    
    # 检查是否只有一个'@'符号
    if len(parts) != 2:
        return False
    
    local_part, domain = parts
    
    # 检查本地部分
    if not validate_local_part(local_part):
        return False
    
    # 检查域名部分
    if not validate_domain(domain):
        return False
    
    return True

def validate_local_part(local_part):
    # 检查长度
    if len(local_part) < 1 or len(local_part) > 64:
        return False
    
    # 检查字符和点的位置
    pattern = r'^[a-zA-Z0-9](?:[a-zA-Z0-9.]{0,62}[a-zA-Z0-9])?$'
    if not re.match(pattern, local_part):
        return False
    
    return True

def validate_domain(domain):
    # 检查长度
    if len(domain) < 1 or len(domain) > 255:
        return False
    
    # 检查字符和点/连字符的位置
    pattern = r'^(?!.*[.-]$)(?!^[.-])[a-zA-Z0-9.-]{1,255}$'
    if not re.match(pattern, domain):
        return False
    
    return True

# 读取输入
t = int(input())
for _ in range(t):
    email = input().strip()
    print("Yes" if is_valid_email(email) else "No")
