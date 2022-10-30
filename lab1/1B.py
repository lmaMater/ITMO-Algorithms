with open('aplusbb.in', 'r') as f:
    data = f.read().split('\n')
a, b = map(int, data[0].split())
 
with open('aplusbb.out', 'w') as w:
    w.write(str(a + b * b))