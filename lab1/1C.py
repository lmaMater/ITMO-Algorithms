with open('turtle.in', 'r') as f:
    data = list(f.read().split('\n'))
 
h, w = map(int, data[0].split())
lst = []
for el in data[1:]:
    lst.append(list(map(int, el.split())))
# start_position = [h - 1][0]
for j in range(w):
    for i in range(h - 1, -1, -1):
        if i == h - 1 and j == 0:
            continue
        elif i == h - 1 and j != 0:
            lst[i][j] = lst[i][j] + lst[i][j - 1]
        elif j == 0 and i != h - 1:
            lst[i][j] = lst[i][j] + lst[i + 1][j]
        else:
            lst[i][j] = lst[i][j] + max(lst[i + 1][j], lst[i][j - 1])
ans = lst[0][w - 1]
 
with open('turtle.out', 'w') as w:
    w.write(str(ans))