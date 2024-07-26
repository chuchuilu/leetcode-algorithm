import example_pb2

# 创建一个 Person 对象
person = example_pb2.Person()
person.name = "John Doe"
person.id = 1234
person.email = "johndoe@example.com"

# 序列化到字符串
serialized_data = person.SerializeToString()

# 反序列化回对象
person2 = example_pb2.Person()
person2.ParseFromString(serialized_data)

print(f"Name: {person2.name}")
print(f"ID: {person2.id}")
print(f"Email: {person2.email}")
