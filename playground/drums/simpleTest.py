# TODO: Make kick an orphan node and set Right foot to it.
#       Make the two isolated nodes Close-Hat and Wash-Hat and set Left foot to it.
#       Make interface.
#       Tweak parameters for standard setting.

import random
import time
import networkx as nx
import pygame

# Initialize pygame and the mixer
pygame.init()
pygame.mixer.init(frequency=44100, size=-16, channels=2, buffer=512)

# Define the function to load sounds
def load_sounds(sound_files):
    sounds = {}
    for key, file_path in sound_files.items():
        try:
            sounds[key] = pygame.mixer.Sound(file_path)
        except Exception as e:
            print(f"Error loading sound {key} from {file_path}: {e}")
    return sounds

# Dictionary mapping drum parts to their sound files
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

# Load sounds
sounds = load_sounds(sound_files)

# Define the graph for the drum machine
G = nx.DiGraph()
nodes = ["Hi-Hat", "Snare", "Kick", "Crash", "Ride", "Hi-Tom", "Mid-Tom", "Low-Tom"]
G.add_nodes_from(nodes)
for node1 in nodes:
    for node2 in nodes:
        weight = 1 if node1 == node2 else 4
        G.add_edge(node1, node2, weight=weight)


# Define limbs and their probabilities of skipping a tick
limbs = {
    "Right-H": {"node": "Hi-Hat", "skip_prob": 0.10},
    "Left_H": {"node": "Snare", "skip_prob": 0.20},
    "Right_F": {"node": "Kick", "skip_prob": 0.30},
    "Left_F": {"node": "Crash", "skip_prob": 0.50}
}

# Define the function to play sounds
def play_sound(sound_key):
    try:
        sounds[sound_key].play()
        print(f"Sound started: {sound_key}")
    except Exception as e:
        print(f"Error playing sound {sound_key}: {e}")

# Define the function to update limbs and play sounds
def update_limbs(G, limbs):
    for limb, info in limbs.items():
        current_node = info["node"]
        should_play = random.random() > info["skip_prob"]
        if should_play:
            possible_nodes = list(G.neighbors(current_node))
            next_node = random.choice(possible_nodes)
            limbs[limb]["node"] = next_node
            play_sound(next_node)
        else:
            print(f"{limb} skips this tick.")

# Main loop to simulate the drum machine
bpm = 120
interval = 60 / bpm / 2  # Interval for eighth notes

try:
    while True:
        update_limbs(G, limbs)
        time.sleep(interval)
except KeyboardInterrupt:
    print("Drum machine stopped by user.")
except Exception as e:
    print(f"Unhandled exception occurred: {e}")

pygame.quit()
