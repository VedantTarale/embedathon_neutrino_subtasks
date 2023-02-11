import httplib2
import keyboard
import mouse
import time
http = httplib2.Http()
time.sleep(5)
print("Functional")
while True:
    # time.sleep(0.0001)
    url = "http://192.168.101.11/"
    response,content = http.request(url,"GET")
    content = content.decode()
    content = content.split(",")
    x = float(content[0])
    y = float(content[1])
    button = int(content[2])
    print(str(x) + "\t" + str(y) + "\t" + str(button))    
    # W -> 45 to 70
    # S -> 250 to 300
    # A -> -45 to -60
    # D -> -250 to -300
    if(not(button)):
        mouse.click('left')
    if(x>45 and x<70):
        keyboard.send('w')
    elif(x>250 and x<300):
        keyboard.send('s')
    if(y<-45 and y > -70):
        keyboard.send('a')
    elif(y<-250 and y>-300):
        keyboard.send('d')