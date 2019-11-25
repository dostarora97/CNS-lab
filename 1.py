def xor(a, b):
    result = []
    for i in range(1, len(b)):
        if a[i] == b[i]:
            result.append('0')
        else:
            result.append('1')
    return ''.join(result)

def mod2div(dividend, divisor):
    pick = len(divisor)
    tmp = dividend[0 : pick]
    while pick < len(dividend):
        if tmp[0] == '1':
            tmp = xor(divisor, tmp) + dividend[pick]
        else:
            tmp = xor('0'*pick, tmp) + dividend[pick]
        pick += 1
    if tmp[0] == '1':
        tmp = xor(divisor, tmp)
    else:
        tmp = xor('0'*pick, tmp)
    return tmp

message = input('Message: ')
key = input('Key: ')
appended = message + '0'*(len(key)-1)
rem = mod2div(appended, key)
encoded = message + rem
print('Sent: ', encoded)
recv = input('Recieved: ')
rem = mod2div(recv, key)
if '1' in rem:
    print('wrong')
else:
    print('right')