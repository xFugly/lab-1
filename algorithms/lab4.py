def main():
    hash_table = {}
    with open('input.txt', 'r') as file:
        for line in file:
            for num_str in line.split():
                num = int(num_str)
                if num > 0:
                    hash_table[num] = True
                elif num < 0:
                    key = -num
                    if key in hash_table:
                        del hash_table[key]
                else:
                    sorted_numbers = sorted(hash_table.keys())
                    with open('output.txt', 'w') as out_file:
                        out_file.write(' '.join(map(str, sorted_numbers)))
                    return
main()