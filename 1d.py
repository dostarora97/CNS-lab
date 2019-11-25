def xor(a , b) :
    result = ''
    for i in range(len(b)) :
        if a[i] == b[i] :
            result += '0'
        else :
            result += '1'
    return result

def mod2div(dividend, divisor) :
    curr_pos = len(divisor)
    pick = dividend[0:curr_pos]
    while curr_pos < len(dividend) :
        if pick[0] == '1' :
            pick = xor(pick, divisor)[1:] + dividend[curr_pos]
        else :
            pick = xor(pick, '0'*len(divisor))[1:] + dividend[curr_pos]
        curr_pos += 1
    if pick[0] == '1' :
        return xor(pick, divisor)[1:]
    else :
        return xor(pick, '0'*len(divisor))[1:]
    
message = input("message : ")
gen_pol = input("gen_pol : ")
dividend = message + '0'*(len(gen_pol)-1)
rem = mod2div(dividend, gen_pol)
send = message + rem
print("sent : ", send)
recv = input("recv : ")
rem = mod2div(recv, gen_pol)
if '1' in rem:
    print("nto valid")
else : 
    print("valid")