import asyncio
import websockets
from faker import Faker

faker_instace = Faker()


async def send_data(websocket):
    while True:
        await websocket.send(faker_instace.name())
        await asyncio.sleep(1)


async def receive_data(websocket):
    while True:
        msg = await websocket.recv()
        print(msg)


async def server(websocket, path):
    while True:
        try:
            send_func = asyncio.create_task(send_data(websocket))
            receive_func = asyncio.create_task(receive_data(websocket))
            await asyncio.gather(send_func, receive_func)
        except: pass


async def main():
    async with websockets.serve(server, "localhost", 8000):
        await asyncio.Future()  # run forever

asyncio.run(main())
