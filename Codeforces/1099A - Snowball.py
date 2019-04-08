snowballweight, snowballheight = input().split()
snowballweight = int(snowballweight)
snowballheight = int(snowballheight)

st1weight, st1height = input().split()
st1weight = int(st1weight)
st1height = int(st1height)

st2weight, st2height = input().split()
st2weight = int(st2weight)
st2height = int(st2height)

i = snowballheight
while i > 0:
    snowballweight = snowballweight + i
    if i == st1height:
        snowballweight = snowballweight - st1weight
        if snowballweight < 0:
            snowballweight = 0
    if i == st2height:
        snowballweight = snowballweight - st2weight
        if snowballweight < 0:
            snowballweight = 0
    i -= 1
print(snowballweight)
