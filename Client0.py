import asyncio
import websockets
import time

async def send_data(websocket):
    # count = 0
    # initial_time = time.time()
    # while True:
    #     while count%5 != 0:
    #         count = count + 1
    #         await asyncio.sleep(1)
    #     if count == 5:
    #         count = count + 1
    #         await websocket.send(f"Received 5 Messages in {time.time()-initial_time}")
    #         initial_time = time.time()
    while True:
        await websocket.send("hey Server")
        await asyncio.sleep(1)


async def receive_data(websocket):
    count = 0
    while True:
        message = await websocket.recv()
        print(f"Received message is {message} at {time.ctime()}")
        count = count + 1
        if count == 5:
            print(f"Received 5 messages")
            count = 0

async def client():
    while True:
        try: 
            async with websockets.connect("ws://localhost:8000") as websocket:
                # Create tasks to send and receive messages concurrently
                send_task = asyncio.create_task(send_data(websocket))
                receive_task = asyncio.create_task(receive_data(websocket))
                await asyncio.gather(send_task, receive_task)
        except:
            print("Server Not Responding, Attempting to reconnect...")
            await asyncio.sleep(1)

asyncio.run(client())