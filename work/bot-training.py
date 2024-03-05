with open("input.txt", "r") as input_file:
    words = [line.strip() for line in input_file.readlines()]

# Sort the words
words.sort()

with open("output.txt", "w") as output_file:
    for word in words:
        output_file.write(word + "\n")