dict = {}
input_list = input("Enter command: ").split(" ", 1)
if input_list[0] == "print":
    print(input_list[1])
if input_list[0] == "let":
    dict[input_list[1].split('=')[0]] = input_list[1].split('=')[1]
    print(dict)
