with open("input_file.txt", "r") as f:
    words = [line.strip() for line in f]  # read file into array of strings

# sort the array of strings
words.sort()

with open("output_file.txt", "w") as f:
    for word in words:
        f.write(word + "\n")  # write sorted words to new file