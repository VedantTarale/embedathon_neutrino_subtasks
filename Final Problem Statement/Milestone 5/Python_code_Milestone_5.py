import httplib2
import keyboard
import mouse
import time
http = httplib2.Http()
time.sleep(2)
print("Functional")
while True:
    # time.sleep(0.0001)
    url = "http://192.168.101.11/"
    response,content = http.request(url,"GET")
    content = content.decode()
    content = content.split(",")
    x = float(content[0])
    y = float(content[1])
    button1 = int(content[2])
    button2 = int(content[3])
    print(str(x) + "\t" + str(y) + "\t" + str(button1) + "\t" + str(button2))    
    # W -> 45 to 70
    # S -> 250 to 300
    # A -> -45 to -60
    # D -> -250 to -300
    if(not(button1)):
        mouse.click('left')
    if(not(button2)):
        mouse.click('right')
    if(x>45 and x<70):
        keyboard.press('w')
        time.sleep(0.2)
        keyboard.release('w')
    elif(x>250 and x<300):
        keyboard.press('s')
        time.sleep(0.2)
        keyboard.release('s')
    if(y<-45 and y > -70):
        keyboard.press('a')
        time.sleep(0.2)
        keyboard.release('a')
    elif(y<-250 and y>-300):
        keyboard.press('d')
        time.sleep(0.2)
        keyboard.release('d')
