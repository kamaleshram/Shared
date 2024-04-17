import hashlib

def F(input_data):
    # Calculate the SHA-256 hash of the input binary string
    hash_object = hashlib.sha256(input_data.encode('utf-8'))
    hash_value = hash_object.digest()

    # Convert the hash value to a binary string representation
    output_data = ''.join(format(byte, '08b') for byte in hash_value)

    # Truncate the output to match the length of the input
    output_data = output_data[:len(input_data)]

    return output_data

def H(input_data):
    # Calculate the SHA-256 hash of the input binary string
    hash_object = hashlib.sha256(input_data.encode('utf-8'))
    hash_value = hash_object.digest()

    # Convert the hash value to a binary string representation
    output_data = ''.join(format(byte, '08b') for byte in hash_value)

    trunc_length = len(input_data) // 2
    # Truncate the output to match the length of the input
    output_data = output_data[:trunc_length]

    return output_data

def Hash(input_data, salt, m):
    # Concatenate the input data and the salt
    concatenated_data = input_data.encode('utf-8') + salt.encode('utf-8')

    # Calculate the SHA-256 hash of the concatenated data
    hash_object = hashlib.sha256(concatenated_data)
    hash_value = hash_object.digest()

    # Convert the truncated hash value to a binary string representation
    output_data = ''.join(format(byte, '08b') for byte in hash_value)
    output_data = output_data[:m]

    return output_data

def G_Lambda(input_data, Lambda):
    # Calculate the SHA-256 hash of the input binary string
    hash_object = hashlib.sha256(input_data.encode('utf-8'))
    hash_value = hash_object.digest()

    # Convert the hash value to a binary string representation
    output_data = ''.join(format(byte, '08b') for byte in hash_value)

    trunc_length = len(input_data)*Lambda
    # Truncate the output to match the length of the input
    output_data = output_data[:trunc_length]

    return output_data

def F_(input_data, salt):
    # Concatenate the input data and the salt
    concatenated_data = input_data.encode('utf-8') + salt.encode('utf-8')

    # Calculate the SHA-256 hash of the concatenated data
    hash_object = hashlib.sha256(concatenated_data)
    hash_value = hash_object.digest()

    # Convert the truncated hash value to a binary string representation
    output_data = ''.join(format(byte, '08b') for byte in hash_value)
    output_data = output_data[:len(input_data)]

    return output_data

def F_Lambda(input_data, salt):
    # Concatenate the input data and the salt
    concatenated_data = input_data.encode('utf-8') + salt.encode('utf-8')

    # Calculate the SHA-256 hash of the concatenated data
    hash_object = hashlib.sha256(concatenated_data)
    hash_value = hash_object.digest()

    # Convert the truncated hash value to a binary string representation
    output_data = ''.join(format(byte, '08b') for byte in hash_value)

    trunc_length = len(input_data)*2
    output_data = output_data[:trunc_length]

    return output_data


# if __name__ == "__main__":
#     input_data = "101010100010101010"
#     salt = "100011"
#     print("Input data:", input_data)
#     print(len(input_data))
#     # Call the cryptographic function
#     output_data = F_Lambda(input_data, salt)
#     # Print the output
#     print("Output data:", output_data)
#     print(len(output_data))