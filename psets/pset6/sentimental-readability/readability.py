import cs50


# Prompt for text
text = cs50.get_string("Text: ")

# Count letters
letters = 0
for char in text:
    if char.isalpha():
        letters += 1

# Count words
words = len(text.split())

# Count sentences
sentences = 0
puncts = ['.', '!', '?']
for char in text:
    if char in puncts:
        sentences += 1


# Calculate readability score
L = letters / words * 100
S = sentences / words * 100
index = round((0.0588 * L) - (0.296 * S) - 15.8)


# Print according to conditions
if index < 1:
    print("Before Grade 1")

elif index > 16:
    print("Grade 16+")

else:
    print(f"Grade ", index)