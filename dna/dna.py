import csv
import sys

def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Incorrect number of arguments provided\n")
        return
    dbFile = sys.argv[1]
    sequenceFile = sys.argv[2]

    # TODO: Read database file into a variable
    rows = []
    with open(dbFile) as file:
        reader = csv.DictReader(file)
        for row in reader:
            rows.append(row)
    file.close()
    print(rows)

    # TODO: Read DNA sequence file into a variable
    f = open(sequenceFile, 'r')
    sequence = f.read()
    f.close()
    # print(sequence)

    # TODO: Find longest match of each STR in DNA sequence
    match = "No match"

    for row in rows:
        print("************************************")
        diff = 0
        name = ""
        print(row)
        for key, value in row.items():
            if key == "name":
                name = value
            else:
                print(value)
                diff = diff + value - longest_match(sequence, key)
        if diff == 0:
            match = name

    # TODO: Check database for matching profiles

    return match


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
