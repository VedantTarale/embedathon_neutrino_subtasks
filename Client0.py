import asyncio
import websockets
import time

async def client():
    count = 0
    initial_time = time.time()
    while True:
        try: 
            async with websockets.connect("ws://localhost:8000") as websocket:
                message = await websocket.recv()
                if message:
                    if count != 5:
                        print(f"Received message is {message} at {time.ctime()}")
                        count = count + 1
                        await asyncio.sleep(1)
                    else:
                        count = 0
                        await websocket.send(f"Client0: Received 5 Messages in {time.time()-initial_time}")
                        initial_time = time.time()
                        await asyncio.sleep(1)
        except:
            print("Server Not Responding, Attempting to reconnect...")
            await asyncio.sleep(1)

asyncio.run(client())