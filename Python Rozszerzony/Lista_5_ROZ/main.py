import itertools as it
#print(list(it.combinations_with_replacement("0001", 4)))
#print(list(it.product('ABCD', 2)))
#print(list(set(list(it.permutations('0001')))))

def obrazek(list_1 ,list_2 ):
    pom = []
    pom2=[]
    for i in list_1:
        pom.append("1"*i+"0"*(len(list_1)-i))

    for i in pom:
        pom2.append(list(set(list(it.permutations(i)))))
    kombinacje = list(it.product(*pom2))
    for i in kombinacje:

        temp = []
        for j in i:
            j = [int(a) for a in j]
            temp.append(j)
        if [sum(x) for x in zip(*temp)] == list_2:
            print(list_2)
            for a in range(len(list_1)):
                print(str(list_1[a]) + "".join(i[a]).replace("0", "□").replace("1","■"))
            print("########")
    return 1


obrazek([1,3,1,2],[2,1,3,1])