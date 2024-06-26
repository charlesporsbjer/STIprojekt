import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # Read database file into a variable
    file1 = sys.argv[1]
    with open(file1, "r") as f1:
        # Read f1 with DictReader into variable
        reader_CSV = csv.DictReader(f1)
        datalist = [row for row in reader_CSV]
        # Make a list with keys
        fieldnames = reader_CSV.fieldnames

    # Read DNA sequence file into a variable
    file2 = sys.argv[2]
    with open(file2, "r") as f2:
        DNA_string = f2.readline()

    # Find longest match of each STR in DNA sequence and put in a temp
    temp = [longest_match(DNA_string, field) for field in fieldnames[1:]]
    for person in datalist:
        # If temp has same values as current persons STR's
        if temp == [int(person[field]) for field in fieldnames[1:]]:
            # Print name of person
            print(person[fieldnames[0]])
            return
    print("No match found.")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
