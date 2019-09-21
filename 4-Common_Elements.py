a = [2,5,5,5]
b = [2,2,3,5,5,7]

common_list = []
main_list = []

a_set = set(a)
b_set = set(b)

if len(a_set) < len(b_set):
    for x in a_set:
        if x in b_set:
            common_list.append(x)

else :
    for x in b_set :
        if x in a_set:
            common_list.append(x)

for x in common_list :
    if a.count(x) < b.count(x):
        for _ in range(a.count(x)):
            main_list.append(x)

    else:
        for _ in range(b.count(x)):
            main_list.append(x)


print(main_list) 