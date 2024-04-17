import random
import simpleaudio as sa
import time
import networkx as nx

# Define the graph
G = nx.DiGraph()
nodes = ["Hi-Hat", "Snare", "Kick", "Crash", "Ride", "Hi-Tom", "Mid-Tom", "Low-Tom"]
G.add_nodes_from(nodes)
for node1 in nodes:
    for node2 in nodes:
        weight = 1 if node1 == node2 else 4
        G.add_edge(node1, node2, weight=weight)

# Map each node to a sound file
sound_files = {
    "Hi-Hat": "samples/convertedSamples/Hi-Hat.wav",
    "Snare": "samples/convertedSamples/Snare.wav",
    "Kick": "samples/convertedSamples/Kick.wav",
    "Crash": "samples/convertedSamples/Crash.wav",
    "Ride": "samples/convertedSamples/Ride.wav",
    "Hi-Tom": "samples/convertedSamples/Hi-Tom.wav",
    "Mid-Tom": "samples/convertedSamples/Mid-Tom.wav",
    "Low-Tom": "samples/convertedSamples/Low-Tom.wav"
}

# Define limbs and their probabilities of skipping a tick
limbs = {
    "Right-H": {"node": "Hi-Hat", "skip_prob": 0.5},
    "Left_H": {"node": "Snare", "skip_prob": 0.6},
    "Right_F": {"node": "Kick", "skip_prob": 0.7},
    "Left_F": {"node": "Crash", "skip_prob": 0.9}
}

# Store currently playing sounds
playing_sounds = []

def update_playing_sounds():
    global playing_sounds
    before_count = len(playing_sounds)
    playing_sounds = [sound for sound in playing_sounds if sound.is_playing()]
    after_count = len(playing_sounds)
    print(f"Cleaned up sounds. Before: {before_count}, After: {after_count}")

def update_limbs(G, limbs):
    global playing_sounds
    print("Updating limbs, currently active sounds:", len(playing_sounds))
    update_playing_sounds()  # Clean up finished sounds
    for limb, info in limbs.items():
        current_node = info["node"]
        should_play = random.random() > info["skip_prob"]
        print(f"{limb} at {current_node}, should play: {should_play}")

        if should_play:
            possible_nodes = list(G.neighbors(current_node))
            next_node = random.choice(possible_nodes)
            print(f"{limb} moves from {current_node} to {next_node}")
            limbs[limb]["node"] = next_node
            sound_obj = play_sound(sound_files[next_node])
            if sound_obj:
                playing_sounds.append(sound_obj)
            else:
                print(f"Failed to play sound for {next_node}")
        else:
            print(f"{limb} skips this tick.")

def play_sound(file_path):
    try:
        wave_obj = sa.WaveObject.from_wave_file(file_path)
        play_obj = wave_obj.play()
        return play_obj
    except Exception as e:
        print(f"Error playing sound: {e}")

# Main loop to simulate the drum machine
bpm = 120

# Calculate the correct interval based on BPM
interval = 60 / bpm / 2  # Interval for eighth notes if needed
print(f"Interval between ticks: {interval} seconds")

while True:
    update_limbs(G, limbs)
    time.sleep(interval)