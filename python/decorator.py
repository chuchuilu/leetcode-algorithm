# 一层装饰器
"""
装饰器是一个函数，它可以在不修改原函数代码的前提下，
为原函数添加额外的功能。装饰器通常用于日志记录、权限验证、
性能测试等场景。

装饰器是一个函数，它接受一个函数作为参数，并返回一个新的函数。

装饰器的语法是使用 @ 符号将装饰器函数应用于目标函数。
装饰器可以嵌套使用，形成多层装饰器。
装饰器可以接受参数，这样就形成了二层装饰器。
装饰器的返回值是一个函数，这个函数可以接受任意数量的位置参数
和关键字参数。
装饰器可以在函数执行前后添加额外的逻辑。
"""
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
"""
decorator(add)(2, 3) 等同于take一个函数作为参数，返回一个新的函数，执行后返回原函数的结果。
@decorator
def add(a, b):
    return a + b
等同于 add = decorator(add)
"""

@senior_decorator(1)
def add(a, b):
    return a + b



print(add(2, 3))
