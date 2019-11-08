import time

bsize = int(input('Bucket size: '))
orate = int(input('Ouptut rate: '))
store = 0
print()

while(True):
    inc = int(input('Incoming packet size(<0 to stop): '))
    if(inc < 0):
        quit()
    if(store + inc > bsize):
        print('Packet dropped since bucket size exceeded')
    else:
        store += inc
    print('Transimission left: ', store)
    nex = int(input('Next packet will come in: '))
    print()
    for i in range(nex):
        time.sleep(1)
        if(store):
            if(store > orate):
                print('Transmitted packet of size: ', orate)
                store -= orate
            else:
                print('Transmitted packet of size: ', store)
                store = 0
            print('Transmission left: ', store)
        else:
            print('No packets left to trasmit')
        print('Time left: ', nex - i - 1)
        print()