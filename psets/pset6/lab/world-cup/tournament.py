# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    # Read team dicts into a list in memory from file
    teams = []
    # Filename gets second argument
    filename = sys.argv[1]
    # Hold file open and call it f
    with open(filename) as f:
        # Read f with DictReader into variable
        reader = csv.DictReader(f)
        for team in reader:
            # Convert to int
            team["rating"] = int(team["rating"])
            # Append dicts to list
            teams.append(team)

    # Simulate N tournaments and keep track of win counts
    counts = {}
    # Do N times
    for _ in range(N):
        # Winner gets dict with winner
        winner = simulate_tournament(teams)
        # Increment if winner already in counts
        if winner in counts:
            counts[winner] += 1
        else:
            # Initialize winner
            counts[winner] = 1

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # Until only one team left
    while len(teams) > 1:
        # Call simulate_round and update teams
        teams = simulate_round(teams)
        # Return first element and name using "team" key
    return teams[0]["team"]


if __name__ == "__main__":
    main()
