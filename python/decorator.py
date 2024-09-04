# 一层装饰器
def decorator(func):
    def wrapper(*args, **kwargs):
        print("decorator start")
        rest = func(*args, **kwargs)
        print("decorator complete")
        return rest
    return wrapper


# 二层装饰器
def senior_decorator(time: int):
    def inner(func):
        def wrapper(*args, **kwargs):
            res = func(*args, **kwargs)
            return res + time
        return wrapper
    return inner

@senior_decorator(1)
def add(a, b):
    return a + b;



print(add(2, 3))
