
def main():
    # Här körs saker

    while True:
        pass

        do_thing()



if __name__ == "__main__":
    main()

    async def simulate_temperature():
    try:
        while True:
            print("Running simulation...")
            simulate_passive_temp_change()
            simulate_appliance_heating()
            auto_toggle_appliances()
            await asyncio.sleep(60)
    except asyncio.CancelledError:
        print("Simulation task was cancelled.")

@asynccontextmanager
async def app_lifespan(app: FastAPI):
    task = asyncio.create_task(simulate_temperature())
    yield
    task.cancel()
    await task

app = FastAPI(lifespan=app_lifespan)

@app.get("/")
async def read_root():
    return {"message": "Welcome to the temperature management system!"}