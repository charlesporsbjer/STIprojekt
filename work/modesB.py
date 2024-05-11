def get_mode():
    mode = ''
    notes = []
    while mode not in ['Ionian', 'Dorian', 'Phrygian', 'Lydian', 'Mixolydian', 'Aeolian', 'Locrian']:
        note = input('Enter a note: ').upper()
        if note in ['C', 'D', 'E', 'F', 'G', 'A', 'B']:
            notes.append(note)
        else:
            print('Invalid note. Please enter a note from the C major scale.')
            notes = []
            continue
        if len(notes) == 7:
            if notes == ['C', 'D', 'E', 'F', 'G', 'A', 'B']:
                mode = 'Ionian'
            elif notes == ['D', 'E', 'F', 'G', 'A', 'B', 'C']:
                mode = 'Dorian'
            elif notes == ['E', 'F', 'G', 'A', 'B', 'C', 'D']:
                mode = 'Phrygian'
            elif notes == ['F', 'G', 'A', 'B', 'C', 'D', 'E']:
                mode = 'Lydian'
            elif notes == ['G', 'A', 'B', 'C', 'D', 'E', 'F']:
                mode = 'Mixolydian'
            elif notes == ['A', 'B', 'C', 'D', 'E', 'F', 'G']:
                mode = 'Aeolian'
            elif notes == ['B', 'C', 'D', 'E', 'F', 'G', 'A']:
                mode = 'Locrian'
            else:
                print('Invalid scale. Please enter a valid mode from the C major scale.')
                notes = []
                mode = ''
    return mode

mode = get_mode()

if mode == 'Ionian':
    steps = ['W', 'W', 'H', 'W', 'W', 'W', 'H']
elif mode == 'Dorian':
    steps = ['W', 'H', 'W', 'W', 'W', 'H', 'W']
elif mode == 'Phrygian':
    steps = ['H', 'W', 'W', 'W', 'H', 'W', 'W']
elif mode == 'Lydian':
    steps = ['W', 'W', 'H', 'W', 'W', 'H', 'W']
elif mode == 'Mixolydian':
    steps = ['W', 'W', 'H', 'W', 'W', 'H', 'W']
elif mode == 'Aeolian':
    steps = ['W', 'W', 'H', 'W', 'H', 'W', 'W']
elif mode == 'Locrian':
    steps = ['H', 'W', 'W', 'H', 'W', 'W', 'H']

print('The entered scale is in the ' + mode + ' mode.')
print('The whole and half steps in the scale are: ' + ' '.join(steps))