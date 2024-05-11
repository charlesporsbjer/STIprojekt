from fastapi import FastAPI, HTTPException
from pydantic import BaseModel, UUID4

from uuid import uuid4

app = FastAPI()

class Album(BaseModel):
    name: str
    artist: "Artist"

class Artist(BaseModel):
    name: str

albums: list[Album] = []
artists : list[Artist] =[]

@app.get("/")
def read_root():
    return {"message": "Hello ... World?" }

@app.get("/albums")
def get_all_albums():
    return albums

@app.get("/artists")
def get_all_artists():
    return artists

@app.get("/album")
def get_album(searched_album: str):
    for album in albums:
        if album.name == searched_album:
            return album
    raise HTTPException(404, f"{searched_album} not found in database!")

@app.get("/artist")
def get_artist(searched_artist: str):

    for artist in artists:
        if artist.name == searched_artist:
            results = []
            for album in albums:
                if album.artist.name == searched_artist:
                    results.append({"album": album.name, "artist": artist.name})
            return results 
    raise HTTPException(404, f"{searched_artist} not found in database!")

@app.post("/albums")
def add_album(new_album: str, new_artist: str):
    created_artist = Artist(name=new_artist)
    artists.append(created_artist)

    created_album = Album(name=new_album, artist=created_artist)
    albums.append(created_album)

    return created_album, created_artist

@app.delete("/albums")
def delete_album(to_delete: str):
    for album in albums:
        if album.name == to_delete:
            albums.remove(album)
            return f"{to_delete} removed."
    raise HTTPException(404, f"{to_delete} not found in database!")

@app.put("/albums")
def update_album_info(to_update: str, new_album: str, new_artist: str):
    for album in albums:
        if album.name == to_update:
            album.name = new_album
            album.artist = new_artist
            return f"{to_update} updated."
    raise HTTPException(404, f"{to_update} not found in database!")